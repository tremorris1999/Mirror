 #pragma once
 #include "../Mirror/MirrorCore.hpp"
 #include "../Mirror/Shaders/Shader.hpp"

 namespace Mirror
 {
     class IRenderable
     {
         public:
         virtual void render(Shader &shader) = 0;
     };
 }