#include "Model.hpp"
#define TINYOBJLOADER_IMPLEMENTATION
#include <tinyobjloader/tiny_obj_loader.h>

namespace Mirror
{
    Model::Model(std::string path)
    {
        LoadModel(path);
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

    void Model::LoadModel(std::string path)
    {
        tinyobj::attrib_t attrib;
        std::vector<tinyobj::shape_t> shapes;
        std::vector<tinyobj::material_t> materials;
        std::string warnings;
        std::string errors;

        bool loaded = tinyobj::LoadObj(&attrib, &shapes, &materials, &warnings, &errors, path.c_str(), NULL, true, true);

        if (!warnings.empty())
            WLOG(warnings);
        if (!errors.empty())
            ELOG(errors);
        if (!loaded)
            return;

        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> textureCoordinates;
        std::vector<unsigned int> indices;

        tinyobj::mesh_t mesh = shapes[0].mesh;
        for (size_t j = 0; j < mesh.indices.size(); j ++)
        {
            if (j < attrib.vertices.size())
                vertices.push_back(attrib.vertices[j]);

            if (j < attrib.normals.size())
                normals.push_back(attrib.normals[j]);

            if (j < attrib.texcoords.size())
                textureCoordinates.push_back(attrib.texcoords[j]);

            indices.push_back(mesh.indices[j].vertex_index);
            }

            Mesh new_mesh(vertices, normals, textureCoordinates, indices);
            meshes.push_back(new_mesh);
    }

}