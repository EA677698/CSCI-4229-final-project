#include "texture.h"
#include "csci_lib/CSCIx229.h"

Texture* Texture::instance = nullptr;

Texture::Texture()
{
    
    textures[NULL_TEXTURE] = LoadTexBMP("textures/dev_texture.bmp");
    textures[SKYSCRAPER_TEXTURE] = LoadTexBMP("textures/skyscraper.bmp");
    textures[ROAD_TEXTURE] = LoadTexBMP("textures/road.bmp");
    textures[GRASS_TEXTURE] = LoadTexBMP("textures/grass.bmp");

}

Texture::~Texture(){}

unsigned int Texture::get_texture(int index)
{
    if(index < 0 || index >= TEXTURE_COUNT){
        return textures[NULL_TEXTURE];
    }
    
    return textures[index];
}