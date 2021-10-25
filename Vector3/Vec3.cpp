#include "Vec3.h"
#include <numbers>


namespace UPC {
	template <typename T> requires Number<T>
	Vec3<T>::Vec3()
	{
		x = y = z = 0;
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
	Vec3<T> Vec3<T>::Normalize() const
	{
		const T length = Length();
		Vec3 normalized;

		normalized.x = x / length;
		normalized.y = y / length;
		normalized.z = z / length;

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
		return acos(dot_product(other) / (Length() * other.Length())) * 180 / std::numbers::pi;
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

	template class Vec3<char>;
	template class Vec3<unsigned char>;
	template class Vec3<short int>;
	template class Vec3<unsigned short int>;
	template class Vec3<int>;
	template class Vec3<unsigned int>;
	template class Vec3<long int>;
	template class Vec3<unsigned long int>;
	template class Vec3<long long int>;
	template class Vec3<unsigned long long int>;
	template class Vec3<float>;
	template class Vec3<double>;
	template class Vec3<long double>;
}

