#pragma once
#include <iostream>

class Texture
{
public:
	Texture(const std::string name);
	
	void Bind();

protected:
	unsigned int texture1;
};
