#include "Vec3.h"
#include <numbers>


namespace UPC {
	template <typename T> requires Number<T>
	Vec3<T>::Vec3()
	{
		x = y = z = T(0);
	}

	template <typename T> requires Number<T>
	Vec3<T>::Vec3(Vec3& other): x(other.x), y(other.y), z(other.z)
	{
	}

	template <typename T> requires Number<T>
		Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z)
	{
	}

	template <typename T> requires Number<T>
	Vec3<T> Vec3<T>::Normalized() const
	{
		const T length = 1 / Length();
		Vec3 normalized;

		//use multiplication instead
		normalized.x = x * length;
		normalized.y = y * length;
		normalized.z = z * length;

		return normalized;
	}

	template <typename T> requires Number<T>
	T Vec3<T>::distance_to(const Vec3& other) const
	{
		return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
	}

	template <typename T> requires Number<T>
	T Vec3<T>::dot_product(const Vec3& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	template <typename T> requires Number<T>
	Vec3<T> Vec3<T>::cross_product(const Vec3& other) const
	{
		Vec3 newVector;

		newVector.x = y * other.z - z * other.y;
		newVector.y = z * other.x - x * other.z;
		newVector.z = x * other.y - y * other.x;

		return newVector;
	}

	template <typename T> requires Number<T>
	T Vec3<T>::angle_between(const Vec3& other) const
	{
		//return in radians
		return acos(dot_product(other) / (Length() * other.Length()));
	}

	template <typename T> requires Number<T>
	Vec3<T> Vec3<T>::operator+(const Vec3& other) const
	{
		return Vec3(x + other.x, y + other.y, z + other.z);
	}

	template <typename T> requires Number<T>
	T Vec3<T>::Length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	template class Vec3<float>;
	template class Vec3<double>;
}

