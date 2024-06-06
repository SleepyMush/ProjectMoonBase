#version 460 core
out vec4 FragColor;

in vec2 texturecoordinates;

uniform sampler2D Texture;

void main()
{
	//FragColor = texture(Texture,texturecoordinates);
	FragColor = vec4(texturecoordinates,0,1);
}