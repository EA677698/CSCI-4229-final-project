#include "texture.h"
#include "csci_lib/CSCIx229.h"

Texture* Texture::instance = nullptr;

Texture::Texture()
{
    textures[NULL_TEXTURE] = LoadTexBMP("textures/dev_texture.bmp");
    textures[RED_TEXTURE] = LoadTexBMP("textures/red.bmp");
    textures[GREEN_TEXTURE] = LoadTexBMP("textures/green.bmp");
    textures[YELLOW_TEXTURE] = LoadTexBMP("textures/yellow.bmp");
    textures[WATER_TEXTURE] = LoadTexBMP("textures/water.bmp");
    textures[SKYSCRAPER_TEXTURE] = LoadTexBMP("textures/facades/skyscraper.bmp");
    textures[OFFICE_TEXTURE] = LoadTexBMP("textures/facades/office.bmp");
    textures[OLD_OFFICE_TEXTURE] = LoadTexBMP("textures/facades/old_office.bmp");
    textures[APARTMENT_TEXTURE] = LoadTexBMP("textures/facades/apartment.bmp");
    textures[BRICK_APARTMENT_TEXTURE] = LoadTexBMP("textures/facades/brick_apartment.bmp");
    textures[OLD_WOOD_TEXTURE] = LoadTexBMP("textures/old_wood.bmp");
    textures[ROAD_TEXTURE] = LoadTexBMP("textures/road.bmp");
    textures[INTERSECTION_TEXTURE] = LoadTexBMP("textures/intersection.bmp");
    textures[GRASS_TEXTURE] = LoadTexBMP("textures/grass.bmp");
    textures[SKYBOX_FRONT_TEXTURE] = LoadTexBMP("textures/sky_front.bmp");
    textures[SKYBOX_BACK_TEXTURE] = LoadTexBMP("textures/sky_back.bmp");
    textures[SKYBOX_LEFT_TEXTURE] = LoadTexBMP("textures/sky_left.bmp");
    textures[SKYBOX_RIGHT_TEXTURE] = LoadTexBMP("textures/sky_right.bmp");
    textures[SKYBOX_TOP_TEXTURE] = LoadTexBMP("textures/sky_top.bmp");
    textures[SKYBOX_BOTTOM_TEXTURE] = LoadTexBMP("textures/sky_bottom.bmp");
    textures[SIDEWALK_TEXTURE] = LoadTexBMP("textures/sidewalk.bmp");
    textures[CONCRETE1_TEXTURE] = LoadTexBMP("textures/concrete1.bmp");
    textures[GALVANIZED_METAL_TEXTURE] = LoadTexBMP("textures/galvanized_metal.bmp");
    textures[CHIPPED_METAL_TEXTURE] = LoadTexBMP("textures/chipped_metal.bmp");
    textures[GOLDEN_GATE_TEXTURE] = LoadTexBMP("textures/golden_gate.bmp");
    textures[SCRATCHED_METAL_TEXTURE] = LoadTexBMP("textures/scratched_metal.bmp");
    textures[BRASS_TEXTURE] = LoadTexBMP("textures/brass.bmp");
}

Texture::~Texture()
{
}

unsigned int Texture::get_texture(const int index) const
{
    if (index < 0 || index >= TEXTURE_COUNT)
    {
        return textures[NULL_TEXTURE];
    }

    return textures[index];
}

int Texture::get_material_type(int index) const
{
    if(index >= SKYSCRAPER_TEXTURE && index <= OLD_OFFICE_TEXTURE)
    {
        return GLASS_MATERIAL;
    }
    if(index == GRASS_TEXTURE)
    {
        return GRASS_MATERIAL;
    }
    if(index == OLD_WOOD_TEXTURE)
    {
        return WOOD_MATERIAL;
    }
    if(index >= APARTMENT_TEXTURE && index <= CONCRETE1_TEXTURE)
    {
        return STONE_MATERIAL;
    }
    if(index >= SKYBOX_FRONT_TEXTURE && index <= SKYBOX_BOTTOM_TEXTURE)
    {
        return SKYBOX_MATERIAL;
    }
    if(index >= GALVANIZED_METAL_TEXTURE && index <= BRASS_TEXTURE)
    {
        return METAL_MATERIAL;
    }
    return NO_MATERIAL;
}
