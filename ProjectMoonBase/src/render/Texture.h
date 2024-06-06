#pragma once
#include "stb/stb_image.h"
#include <glad/glad.h> 

#include <string>
#include <iostream>

class Texture {
private:
	int width, height, nrChannels;
public:
	GLuint textureID;
	unsigned char* data;

	void loadtexture(std::string filepath);
	void cleanUp() const;
	void bind(unsigned int slot);
};
