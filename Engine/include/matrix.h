#pragma once

#include "vector.h"

namespace Scarlet
{
    class Matrix4
    {
        public:
            static Matrix4 Identity();
            static Matrix4 Translate(const Vector3& position);
            static Matrix4 Scale(const Vector3& scale);
            static Matrix4 Rotate(float angle, const Vector3& axis);

            Matrix4 operator*(const Matrix4& other) const;
            
    };
}