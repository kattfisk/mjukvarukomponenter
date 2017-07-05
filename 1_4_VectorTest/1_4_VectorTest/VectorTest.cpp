#include "VectorTest.h"

#include "Vector.h"
#include <cassert>
#include <sstream>

void VectorTest::run()
{
	/* Testing all functions */
	{
		double a[5] = {1,2,3,4,5};
		double b[5] = {0,1,2,3,4};
		const Vector v0(5, a);
		const Vector v1(5, b);
		Vector v2(v0);

		// Constructor, length, and const []
		assert(v0.length() == 5);
		assert(v0[0] == 1);
		assert(v0[4] == 5);

		// Copy constructor
		assert(v2.length() == 5);
		assert(v2[0] == 1);
		assert(v2[4] == 5);

		// Comparison
		assert(v0 != v1);
		assert(v0 == v2);

		// Assignment []
		v2[0] = 42;
		assert(v2[0] == 42);

		v2[v2.length() - 1] = 13;
		assert(v2[v2.length() - 1] == 13);

		// Assignment and compount assignment
		v2 = v0;
		assert(v2 == v0);

		{
			v2 = v0;
			v2 += v1;
			double cTmp[5] = {1,3,5,7,9};
			Vector vTmp(5, cTmp);
			assert(v2 == vTmp);
		}

		{
			v2 = v0;
			v2 -= v1;
			double cTmp[5] = {1,1,1,1,1};
			Vector vTmp(5, cTmp);
			assert(v2 == vTmp);
		}

		{
			v2 = v0;
			v2 *= 2;
			double cTmp[5] = {2,4,6,8,10};
			Vector vTmp(5, cTmp);
			assert(v2 == vTmp);
		}

		// Binary arithmetic
		v2 = v0;
		v2 += v1;
		assert(v0 + v1 == v2);

		v2 = v0;
		v2 -= v1;
		assert(v0 - v1 == v2);
		
		assert(v0 * v1 == 40); // Dot product

		v2 = v0;
		v2 *= 2;
		assert(v0 * 2 == v2);
		assert(2 * v0 == v2);

		// Stream
		std::stringstream s;
		s << v0;
		assert(s.str() == "1, 2, 3, 4, 5");
	}

	/* Edge cases */
	{
		{
			// Single element large values
			double a[1] = {123456789012.34567890};
			double b[1] = {-123456789.01234567890};
			const Vector v0(1, a);
			const Vector v1(1, b);
		
			assert(v0[0] == a[0]);
			assert(v1[0] == b[0]);
			assert((v0 + v1)[0] == a[0] + b[0]);
		}
		{
			// Large number of elements
			const int NUM_ELEMS = 50000;
			double a[NUM_ELEMS] = {};
			double b[NUM_ELEMS] = {};
			double sum1 = 0.0;
			double sum2 = 0.0;
			
			for(int i = 0; i < NUM_ELEMS; ++i)
			{
				a[i] = i;
				b[i] = i*2.0 + 42.0; // Fill with different numbers
				
				// sum1 will be the sum of all values in a and b
				sum1 += i;
				sum1 += i*2.0 + 42.0;
			}
			
			// Create vectors using the data
			Vector v0(NUM_ELEMS, a);
			const Vector v1(NUM_ELEMS, b);
			// Add the vectors
			v0 += v1;
			
			for(int i = 0; i < NUM_ELEMS; ++i)
			{
				// Sum up the values of v0
				sum2 += v0[i];
			}
			// If the addition worked sums should match
			assert(sum1 == sum2);
		}
	}
}

void VectorTest::fail()
{
	{
		double a[5] = {1,2,3,4,5};
		double b[5] = {0,1,2,3,4};
		const Vector v0(5, a);
		Vector v1(5, b);

		// Simulates an error in operator* by changing the value of an element
		v1[2] = -1.0;

		// This assert will fail
		assert(v0 * v1 == 40); // Dot product
	}
}