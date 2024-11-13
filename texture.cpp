#include "texture.h"

Texture* Texture::instance = nullptr;

Texture::Texture()
{
    textures[0] = LoadTexBMP("textures/dev_texture.bmp");

}

Texture::~Texture(){}

unsigned int Texture::get_texture(int index)
{
    return textures[index];
}