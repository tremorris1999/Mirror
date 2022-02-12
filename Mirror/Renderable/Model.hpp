#include "../Mirror/MirrorCore.hpp"
#include "IRenderable.hpp"
#include "Mesh.hpp"
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Mirror
{
    class Model : public IRenderable
    {
        public:
        Model(std::string path);
        void render(Shader &shader) override;

        private:
        std::vector<Mesh> meshes;
        std::string dir;

        void loadModel(std::string path);
        void processNode(aiNode* node, const aiScene* scene);
        Mesh processMesh(aiMesh* mesh, const aiScene* scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial* material, aiTextureType type, std::string typeName);
    };
}