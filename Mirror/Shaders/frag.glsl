#version 420 core

in vec3 Normal;
in vec3 mPosition;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D tex;
uniform vec3 light_position;
uniform vec3 view_position;

void main()
{
	vec3 color = vec3(1, 0, 1);
	vec3 nNormal = normalize(Normal);

	float ambient_strength = 0.15;
	vec3 ambient = ambient_strength * vec3(1, 1, 1);

	vec3 light_direction = normalize(light_position - mPosition);
	float diffuse_strength = max(dot(nNormal, light_direction), 0.0);
	vec3 diffuse = diffuse_strength * vec3(1, 1, 1);

	vec3 view_direction = normalize(view_position - mPosition);
	vec3 reflection_direction = reflect(-light_direction, nNormal);
	float specular_strength = 0.5;
	float specular_power = pow(max(dot(view_direction, reflection_direction), 0.0), 32);
	vec3 specular = specular_strength * specular_power * vec3(1.0, 1.0, 1.0);

	vec3 result = (ambient + diffuse + specular) * color;
	FragColor = vec4(result, 1.0);
}
