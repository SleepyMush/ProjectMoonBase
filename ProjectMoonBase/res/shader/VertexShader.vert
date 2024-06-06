#version 460 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texturepoint;

out vec2 texturecoordinates;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = projection * view * model * vec4(position, 0.0, 1.0);
	texturecoordinates = texturepoint;
}