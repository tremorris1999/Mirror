 #pragma once
 #include "../Mirror/MirrorCore.hpp"

 namespace Mirror
 {
     class RenderableObject
     {
         protected:
         RenderableObject(float* position)
         {
             this->position = position;
         }

         public:
         virtual void render() = 0;
         float* position;
     };
 }