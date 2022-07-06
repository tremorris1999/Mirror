 #pragma once
 #include "mirror_core.h"
 #include "Shaders/shader.h"

 namespace mirror
 {
     class Renderable
     {
         public:
         virtual void render(Shader &shader) = 0;
         Renderable() = default;
         ~Renderable() = default;
     };
 }