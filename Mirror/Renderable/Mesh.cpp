#include "Mesh.hpp"

namespace Mirror
{
    Mesh::Mesh(std::vector<float> vertices, std::vector<float> normals, std::vector<float> tcoords, std::vector<unsigned int> indices)//, std::vector<Texture> textures)
    {
        this->uses_ebo = true;
        this->vertices = vertices;
        this->normals = normals;
        this->tcoords = tcoords;
        this->indices = indices;
        //this->textures = textures;

        glGenVertexArrays(1, &VAO);
        VBO = (unsigned int*)malloc(3 * sizeof(unsigned int));
        glGenBuffers(3, VBO);
        glGenBuffers(1, &EBO);

        if (!VBO)
        {
            ELOG("Failed to allocate VBO");
            exit(-1);
        }

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * 4, &vertices[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glBufferData(GL_ARRAY_BUFFER, normals.size() * 4, &normals[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glBufferData(GL_ARRAY_BUFFER, tcoords.size() * 4, &tcoords[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * 4, &indices[0], GL_STATIC_DRAW);

        glBindVertexArray(0);
        DLOG("Mesh created");
    }

    Mesh::Mesh(std::vector<float> vertices, std::vector<float> normals, std::vector<float> tcoords)
    {
        this->uses_ebo = false;
        this->vertices = vertices;
        this->normals = normals;
        this->tcoords = tcoords;
        //this->textures = textures;

        glGenVertexArrays(1, &VAO);
        VBO = (unsigned int*)malloc(3 * sizeof(unsigned int));
        glGenBuffers(3, VBO);

        if (!VBO)
        {
            ELOG("Failed to allocate VBO");
            exit(-1);
        }

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * 4, &vertices[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        if (!normals.empty())
        {
            glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
            glBufferData(GL_ARRAY_BUFFER, normals.size() * 4, &normals[0], GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        }

        if (!tcoords.empty())
        {
            glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
            glBufferData(GL_ARRAY_BUFFER, tcoords.size() * 4, &tcoords[0], GL_STATIC_DRAW);
            glEnableVertexAttribArray(2);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
        }

        glBindVertexArray(0);
        DLOG("Mesh created");
    }

    Mesh::~Mesh()
    {
        //delete VBO;
        DLOG("Mesh deleted.");
    }

    void Mesh::render(Shader &shader)
    {
        shader.use();
        glBindVertexArray(VAO);
        if (uses_ebo)
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        else
            glDrawArrays(GL_TRIANGLES, 0, vertices.size());
        glBindVertexArray(0);
    }
}