#include "Model.hpp"

namespace Mirror
{
    Model::Model(std::string path)
    {
        loadModel(path);
    }

    void Model::render(Shader &shader)
    {
        for(unsigned int i = 0; i < meshes.size(); i++)
            meshes[i].render(shader);
    }

    void Model::loadModel(std::string path)
    {
        tinyobj::attrib
    }

}