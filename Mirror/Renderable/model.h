#include "mirror_core.h"
#include "renderable.h"
#include "mesh.h"


namespace mirror
{
    class Model : public Renderable
    {
        public:
        Model(std::string path);
        ~Model();
        void loadModel(std::string path);
        void render(Shader &shader) override;

        private:
        std::vector<Mesh> meshes;
        std::string dir;
    };
}