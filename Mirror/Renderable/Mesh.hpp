#pragma once
#include "../Mirror/MirrorCore.hpp" 
#include "IRenderable.hpp"
#include "../Mirror/Shaders/Shader.hpp"

namespace Mirror
{
    struct Texture
    {
        unsigned int id;
        std::string type;
    };

    class Mesh : public IRenderable
    {
        public:
        Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals, std::vector<glm::vec2> tcoords, std::vector<unsigned int> indices);//, std::vector<Texture> textures);
        void render(Shader &shader) override;

        private:
        unsigned int VAO;
        unsigned int* VBO;
        unsigned int EBO;
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec3> normals;
        std::vector<glm::vec2> tcoords;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
    };
}