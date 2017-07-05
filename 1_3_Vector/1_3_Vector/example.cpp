#include "Vector.h"
#include <iostream>

int main()
{
	double a[5] = {1,2,3,4,5};
	double b[5] = {1,0,1,0,1};
	double c[5] = {1,2,1,2,1};
	Vector u(5, a);
	Vector v(5, b);
	Vector w(5, c);

	std::cout << "u: " << u << "\nv: " << v << "\nw: " << w << "\n";
	std::cout << "\n";

	std::cout << "u + v = " << u + v << "\n";
	std::cout << "\n";

	std::cout << "u * v = "<< u * v << "\n";
	std::cout << "\n";

	std::cout << "u - 2*v = "<< u - 2*v << "\n";
	std::cout << "\n";

	u *= 2;
	std::cout << "u *= 2" << "\nu: " << u <<"\n";
	std::cout << "\n";

	v += w;
	std::cout << "v += w" << "\nv: " << v <<"\n";
	std::cout << "\n";

	w -= v;
	std::cout << "w -= v" << "\nw: " << w <<"\n";
	std::cout << "\n";

	// This method will violate its contract
	u.addVectorBroken(v);

	std::cin.get();

	return 0;
}