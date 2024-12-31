#include "vector.h"

namespace Scarlet
{
    #pragma region Vector2

    Vector2::Vector2(): x(0.0f), y(0.0f) {}
    Vector2::Vector2(float x, float y): x(x), y(y) {}
    Vector2::Vector2(float x): x(x), y(x) {}

    Vector2 Vector2::operator+(const Vector2& other) const
    {
        return {x + other.x, y + other.y};
    }

    Vector2 Vector2::operator-(const Vector2& other) const
    {
        return {x - other.x, y - other.y};
    }

    Vector2 Vector2::operator*(float scalar) const
    {
        return {x * scalar, y * scalar};
    }

    Vector2 Vector2::operator/(float scalar) const
    {
        return {x / scalar, y / scalar};
    }

    Vector2 Vector2::Zero()
    {
        return {0.0f, 0.0f};
    }

    #pragma endregion
    #pragma region Vector3

    Vector3::Vector3(): x(0.0f), y(0.0f), z(0.0f) {}
    Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {}
    Vector3::Vector3(float x): x(x), y(x), z(x) {}

    Vector3 Vector3::operator+(const Vector3& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 Vector3::operator-(const Vector3& other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3 Vector3::operator*(float scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    Vector3 Vector3::operator/(float scalar) const
    {
        return {x / scalar, y / scalar, z / scalar};
    }

    Vector3 Vector3::Zero()
    {
        return {0.0f, 0.0f, 0.0f};
    }

    #pragma endregion
}