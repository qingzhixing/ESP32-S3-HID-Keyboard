#pragma once
#ifndef _VECTOR_3_H
#define _VECTOR_3_H

template <typename T>
class Vector3
{
public:
	T x, y, z;
	Vector3(T x, T y, T z) : x(x), y(y), z(z) {}
	Vector3() : x(), y(), z() {}
	Vector3(const Vector3 &other) : x(other.x), y(other.y), z(other.z) {}
	Vector3 &operator=(const Vector3 &other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	Vector3 operator+(const Vector3 &other) const
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}
	Vector3 operator-(const Vector3 &other) const
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}
	Vector3 operator*(T scalar) const
	{
		return Vector3(x * scalar, y * scalar, z * scalar);
	}
	Vector3 operator/(T scalar) const
	{
		return Vector3(x / scalar, y / scalar, z / scalar);
	}
	T dot(const Vector3 &other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}
	Vector3 cross(const Vector3 &other) const
	{
		return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}
	T magnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}
	Vector3 normalized() const
	{
		return *this / magnitude();
	}
	Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}
	Vector3 &operator+=(const Vector3 &other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	Vector3 &operator-=(const Vector3 &other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	Vector3 &operator*=(T scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}
	Vector3 &operator/=(T scalar)
	{
		if (scalar == 0)
		{
			x = y = z = 0;
			return *this;
		}
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	// linear interpolation
	Vector3 lerp(const Vector3 &other, float t) const
	{
		return Vector3(x + (other.x - x) * t, y + (other.y - y) * t, z + (other.z - z) * t);
	}
};

#endif //! _VECTOR_3_H