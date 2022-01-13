#include "StaticObject.hpp"

namespace Mirror
{
    StaticObject::StaticObject(float* position, float* vertices, int numVerts)
    : RenderableObject(position)
    {
        this->verts = vertices;
        this->numVerts = numVerts;
        glBufferData(GL_ARRAY_BUFFER,(this->numVerts) * 4, this->verts, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
        glEnableVertexAttribArray(0);
    }

    void StaticObject::render()
    {
        glDrawArrays(GL_TRIANGLES, 0, numVerts / 3);
    }

}