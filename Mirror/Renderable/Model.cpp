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
        {
            ELOG("Failed to load obj file.");
            exit(-1);
        }

        // iterate shapes
        
        for (size_t s = 0; s < shapes.size(); s++)
        {
            std::vector<float> vertices;
            std::vector<float> normals;
            std::vector<float> texCoords;
            std::vector<unsigned int> indices;
            tinyobj::mesh_t mesh = shapes[s].mesh;
            size_t offset = 0;

            // iterate faces
            for (size_t f = 0; f < mesh.num_face_vertices.size(); f++)
            {
                // iterate vertices
                for (size_t v = 0; v < 3; v++)
                {
                    tinyobj::index_t idx = mesh.indices[offset + v];

                    vertices.push_back(attrib.vertices[3 * size_t(idx.vertex_index)]);
                    vertices.push_back(attrib.vertices[3 * size_t(idx.vertex_index) + 1]);
                    vertices.push_back(attrib.vertices[3 * size_t(idx.vertex_index) + 2]);

                    if (idx.normal_index > -1)
                    {
                        normals.push_back(attrib.normals[3 * size_t(idx.normal_index)]);
                        normals.push_back(attrib.normals[3 * size_t(idx.normal_index) + 1]);
                        normals.push_back(attrib.normals[3 * size_t(idx.normal_index) + 2]);
                    }

                    if (idx.texcoord_index > -1)
                    {
                        texCoords.push_back(attrib.texcoords[2 * size_t(idx.texcoord_index)]);
                        texCoords.push_back(attrib.texcoords[2 * size_t(idx.texcoord_index) + 1]);
                    }
                }

                offset += 3;
            }

            meshes.push_back(Mesh(vertices, normals, texCoords));
        }
    }

}