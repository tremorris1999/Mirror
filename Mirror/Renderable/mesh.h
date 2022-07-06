#pragma once
#include "MirrorCore.hpp" 
#include "renderable.h"
#include "Shaders/Shader.hpp"

namespace Mirror
{
    struct texture_t
    {
        unsigned int id;
        std::string type;
    };

    class Mesh : public Renderable
    {
        public:
            Mesh(std::vector<float> vertices, std::vector<float> normals, std::vector<float> tcoords, std::vector<unsigned int> indices);//, std::vector<Texture> textures);
            Mesh(std::vector<float> vertices, std::vector<float> normals, std::vector<float> tcoords);
            ~Mesh();
            void render(Shader &shader) override;

        private:
            bool uses_ebo;
            unsigned int VAO;
            unsigned int* VBO;
            unsigned int EBO;
            std::vector<float> vertices;
            std::vector<float> normals;
            std::vector<float> tcoords;
            std::vector<unsigned int> indices;
            std::vector<texture_t> textures;
    };
}