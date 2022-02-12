#version 420 core
layout (location = 0) in vec3 layout_Position;
layout (location = 1) in vec2 layout_TexCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(layout_Position, 1.0);
    //gl_Position = model * vec4(layout_Position, 1.0);
    TexCoord = layout_TexCoord;
}
