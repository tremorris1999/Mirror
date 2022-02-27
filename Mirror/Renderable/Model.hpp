#include "MirrorCore.hpp"
#include "IRenderable.hpp"
#include "Mesh.hpp"


namespace Mirror
{
    class Model : public IRenderable
    {
        public:
        Model(std::string path);
        ~Model();
        void LoadModel(std::string path);
        void render(Shader &shader) override;

        private:
        std::vector<Mesh> meshes;
        std::string dir;
    };
}