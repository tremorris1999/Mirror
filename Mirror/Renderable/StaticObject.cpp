#include "StaticObject.hpp"
#include <stb/stb_image.h>

namespace Mirror
{
    StaticObject::StaticObject(unsigned int VAO, unsigned int* VBO, unsigned int EBO, float* position, float* vertices, int numVerts, int* indices, int numInd, float* textureCoords, int numTC)
    {
        this->verts = vertices;
        this->numVerts = numVerts;
        this->indices = indices;
        this->numInd = numInd;
        this->textureCoords = textureCoords;
        this->numTC = numTC;

        int w, h, nrc;
        unsigned char* img_data = stbi_load("../Mirror/Textures/container.jpg", &w, &h, &nrc, 0);

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(1, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(img_data);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glBufferData(GL_ARRAY_BUFFER,this->numVerts * 4, this->verts, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(0);

       glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glBufferData(GL_ARRAY_BUFFER,this->numTC * 4, this->textureCoords, GL_STATIC_DRAW);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->numInd * 6, this->indices, GL_STATIC_DRAW);
    }

    void StaticObject::render(Shader &shader)
    {
        shader.use();
        //glDrawArrays(GL_TRIANGLES, 0, 36);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

}