 #pragma once
 #include "MirrorCore.hpp"
 #include "Shaders/Shader.hpp"

 namespace Mirror
 {
     class Renderable
     {
         public:
         virtual void render(Shader &shader) = 0;
     };
 }