#include "transform.h"

namespace Scarlet
{
    Transform::Transform()
        :position(Vector3::Zero()), rotation(Vector3::Zero()), scale({1.0f, 1.0f, 1.0f})
    {

    }

    // Matrix4 Transform::GetMatrix()
    // {
    //     Matrix4 translation = Matrix4::Translate(position);
    //     Matrix4 rotationX = Matrix4::Rotate(rotation.x, {1.0f, 0.0f, 0.0f});
    // }
}