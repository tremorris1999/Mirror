#include "../Mirror/MirrorCore.hpp"

namespace Mirror
{
    class FlyCamera
    {
        public:
        glm::vec3 position;
        glm::vec3 target;
        glm::vec3 direction;
        glm::vec3 right;
        glm::vec3 up;
    };
}