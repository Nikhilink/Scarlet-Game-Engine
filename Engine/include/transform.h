#pragma once

#include "vector.h"
#include "matrix.h"

namespace Scarlet
{
    class Transform
    {
        public:
            Vector3 position;
            Vector3 rotation;
            Vector3 scale;

            Transform();

            Matrix4 GetMatrix() const;
    };
}