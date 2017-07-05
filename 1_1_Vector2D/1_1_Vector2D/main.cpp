#include "StandardVector2D.h"
#include "UnitVector2D.h"

#include <iostream>

/* This is a simple mockup of how a game entity could use the classes for movement */
struct GameEntity
{
	/* Holding pointers to these vectors doesn't really make a lot of sense in this 
	   context, but we are more or less forced to as the base class is abstract. */
	Vector2D *position, *direction;
	float speed;

	GameEntity(float speed, Vector2D *position, Vector2D *direction)
		: speed(speed), position(position), direction(direction)
	{
	}

	void move(float deltaTime)
	{
		/* Here we can see the simple usage of the vector classes for movement. */
		StandardVector2D step(*direction);
		step.multiply(speed * deltaTime);
		position->add(step);
	}

	~GameEntity()
	{
		delete position;
		delete direction;
	}
};

int main()
{
	GameEntity entity1(2, new StandardVector2D(0, 0), new UnitVector2D(2, 1));
	GameEntity entity2(1, new StandardVector2D(1, 1), new UnitVector2D());

	float deltaTime = 0;
	for(int i = 0; i < 10; ++i)
	{
		deltaTime = 1.0f; 
		// Delta time would normally be set to the time since last update.
		
		std::cout<<"Entity1 Position: "<<entity1.position->getX()<<", "<<entity1.position->getY()
			<<" \tDirection: "<<entity1.direction->getX()<<", "<<entity2.direction->getY()<<std::endl;
		std::cout<<"Entity2 Position: "<<entity2.position->getX()<<", "<<entity2.position->getY()
			<<" \tDirection: "<<entity2.direction->getX()<<", "<<entity2.direction->getY()<<std::endl;
		std::cout<<std::endl;
		
		entity1.move(deltaTime);
		entity2.move(deltaTime);

		/* To show off the power and simplicity of the solution
		   let's have entity2 change its direction away from entity1
		   each iteration. Effectively fleeing from it. */
		StandardVector2D v(*entity2.position);
		v.subtract(*entity1.position);
		entity2.direction->set(v.getX(), v.getY());
	}

	char a;
	std::cin>>a; // Wait for input as a hack so the console stays open

	return 0;
}