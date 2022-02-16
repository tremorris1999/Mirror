 #pragma once
 #include "../MirrorCore.hpp"
 #include "../Shaders/Shader.hpp"
 #define TINYOBJLOADER_IMPLEMENTATION

 namespace Mirror
 {
     class IRenderable
     {
         public:
         virtual void render(Shader &shader) = 0;
     };
 }