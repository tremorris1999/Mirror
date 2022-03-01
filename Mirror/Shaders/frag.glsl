#version 420 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D tex;

void main()
{
    //FragColor = texture(tex, TexCoord);
    FragColor = vec4(1, 0, 1, 1);
}
