#version 420 core
layout (location = 0) in vec3 layout_Position;
layout (location = 1) in vec3 layout_Normal;
layout (location = 2) in vec2 layout_TexCoord;

out vec3 Normal;
out vec3 mPosition;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(layout_Position, 1.0);
    Normal = layout_Normal;
    mPosition = vec3(model * vec4(layout_Position, 1.0));
    TexCoord = layout_TexCoord;
}
