#include <iostream>
#include "Vec3.h"
using namespace std;
using namespace UPC;

int main()
{
	Vec3<float> empty;
	Vec3<float> a(2, 0, 1);
	Vec3<float> b(1, -1, 3);
	Vec3 c(b);

	cout << "Empty vector: " << empty << endl;

	cout << "Copy constructor: " << c << endl;

	Vec3<float> normalized = a.Normalized();
	cout << "Normalized: " << a << " => " << normalized << endl;

	float distance = a.distance_to(b);
	cout << "Distance to: " << a << " , " << b << " = " << distance << endl;

	float dot = a.dot_product(b);
	cout << "Dot product: " << a << " * " << b << " = " << dot << endl;

	Vec3<float> cross = a.cross_product(b);
	cout << "Cross product: " << a << " x " << b << " = " << cross << endl;

	float angle = a.angle_between(b);
	cout << "Angle between (radians): " << a << " , " << b << " = " << angle << endl;

	Vec3<float> s = a + b;
	cout << "Adding vectors: " << a << " + " << b << " = " << s << endl;

	return 0;
}
