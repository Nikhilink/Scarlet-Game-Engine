#pragma once

namespace Scarlet
{
    class Vector2
    {
        public:
            float x, y;

            Vector2();
            Vector2(float x, float y);
            Vector2(float x);

            Vector2 operator+(const Vector2& other) const;
            Vector2 operator-(const Vector2& other) const;
            Vector2 operator*(float scalar) const;
            Vector2 operator/(float scalar) const;

            static Vector2 Zero();

    };

    class Vector3
    {
        public:
            float x, y, z;

            Vector3();
            Vector3(float x, float y, float z);
            Vector3(float a);

            Vector3 operator+(const Vector3& other) const;
            Vector3 operator-(const Vector3& other) const;
            Vector3 operator*(float scalar) const;
            Vector3 operator/(float scalar) const;

            static Vector3 Zero();
    };
}