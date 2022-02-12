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
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

        if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            std::cout << "Error loading asset: " << importer.GetErrorString() << std::endl;
        }
        else
        {
            dir = path.substr(0, path.find_last_of('/'));
            processNode(scene->mRootNode, scene);
        }
    }

    void Model::processNode(aiNode* node, const aiScene* scene)
    {
        for(unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(mesh, scene));
        }

        for(unsigned int i = 0; i < node->mNumChildren; i++)
        {
            processNode(node->mChildren[i], scene);
        }
    }

    Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
    {
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec3> normals;
        std::vector<glm::vec2> texCoords;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        for(unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            glm::vec3 vertex;
            glm::vec3 normal;
            glm::vec2 tCoord;

            vertex.x = mesh->mVertices[i].x;
            vertex.y = mesh->mVertices[i].y;
            vertex.z = mesh->mVertices[i].z;

            normal.x = mesh->mNormals[i].x;
            normal.y = mesh->mNormals[i].y;
            normal.z = mesh->mNormals[i].z;

            if (mesh->mTextureCoords[0])
            {
                tCoord.x = mesh->mTextureCoords[0][i].x;
                tCoord.y = mesh->mTextureCoords[0][i].y;
            }

        for(unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];
            // retrieve all indices of the face and store them in the indices vector
            for(unsigned int j = 0; j < face.mNumIndices; j++)
            {
                //printf("%d:\t%d\n", i, face.mIndices[j]);
                indices.push_back(face.mIndices[j]);
            }        
        }

            vertices.push_back(vertex);
            normals.push_back(normal);
            texCoords.push_back(tCoord);

            /*if(mesh->mMaterialIndex >= 0)
            {
                aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
                std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
                std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
                textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
                textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
            }*/
        }

        return Mesh(vertices, normals, texCoords, indices);
    }

    std::vector<Texture> Model::loadMaterialTextures(aiMaterial* material, aiTextureType type, std::string typeName)
    {
        std::vector<Texture> textures;
        for(unsigned int i = 0; i < material->GetTextureCount(type); i++)
        {
            aiString str;
            material->GetTexture(type, i, &str);
            Texture tex;
           // tex.id = TextureFromFile(str.C_Str(), dir);
        }
    }
}