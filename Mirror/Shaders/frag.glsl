#version 420 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D tex;

void main()
{
    //FragColor = texture(tex, TexCoord);
    FragColor = vec4(0, vec2(1), 1);
}
