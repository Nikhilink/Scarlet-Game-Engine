#include "matrix.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Scarlet
{
    Matrix4 Matrix4::Identity()
    {
        glm::mat4 identity= glm::mat4(1.0f);
        return *(Matrix4*)&identity;
    }

    Matrix4 Matrix4::Translate(const Vector3& position)
    {
        glm::mat4 translation = glm::translate(glm::mat4(1.0f), {position.x, position.y, position.z});

        return *(Matrix4*)&translation;
    }

    Matrix4 Matrix4::Scale(const Vector3& scale)
    {
        glm::mat4 scaling = glm::scale(glm::mat4(1.0f), {scale.x, scale.y, scale.z});
        return *(Matrix4*)&scaling;
    }

    Matrix4 Matrix4::operator*(const Matrix4& other) const
    {
        glm::mat4 result = (*(glm::mat4*)this) * (*(glm::mat4*)&other);

        return *(Matrix4*)&result;
    }
}