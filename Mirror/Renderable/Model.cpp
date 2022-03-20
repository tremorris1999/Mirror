#include "Model.hpp"
#include <mirrormod/mirrormod.h>
#include <chrono>

namespace Mirror
{
    Model::Model(std::string path)
    {
        loadModel(path);
        DLOG("Model created");
    }

    Model::~Model()
    {
        DLOG("Model deleted");
    }

    void Model::render(Shader &shader)
    {
        for(unsigned int i = 0; i < meshes.size(); i++)
            meshes[i].render(shader);
    }

    void Model::loadModel(std::string path)
    {
        auto start = std::chrono::system_clock::now();
        std::vector<mirrormod::mesh_t> parsed_meshes;

        mirrormod::parseObj(path, parsed_meshes);
        for (mirrormod::mesh_t mesh : parsed_meshes)
            meshes.push_back(Mesh(mesh.position, mesh.normal, mesh.uv));

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Loaded in: " << elapsed.count() << std::endl;
    }

}