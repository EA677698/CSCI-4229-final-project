#include "texture.h"

Texture* Texture::instance = nullptr;

Texture::Texture()
{
    textures[TEXTURE_NULL] = LoadTexBMP("textures/dev_texture.bmp");
    textures[TEXTURE_SKYSCRAPER] = LoadTexBMP("textures/skyscraper.bmp");

}

Texture::~Texture(){}

unsigned int Texture::get_texture(int index)
{
    if(index < 0 || index >= TEXTURE_COUNT){
        return textures[TEXTURE_NULL];
    }
    
    return textures[index];
}