#pragma once
#include <ostream>
#include <concepts>

namespace UPC {
	template <typename T> concept Number = std::integral<T> or std::floating_point<T>;

	template< typename T> requires Number<T>
	class Vec3
	{
	private:
		T x, y, z;
		T Length() const;
	public:

		Vec3();
		Vec3(Vec3& other);
		Vec3(T x, T y, T z);
		~Vec3() = default;

		Vec3 Normalized() const;
		T distance_to(const Vec3& other) const;
		T dot_product(const Vec3& other) const;
		Vec3 cross_product(const Vec3& other) const;
		T angle_between(const Vec3& other) const;
		Vec3<T> operator+(const Vec3& vec3) const;

		friend std::ostream& operator<<(std::ostream& _stream, Vec3<T> const& v)
		{
			return _stream << "(" << v.x << "," << v.y << "," << v.z << ")";
		}

		
	};

}