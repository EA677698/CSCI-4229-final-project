#ifndef TEXTURE_H
#define TEXTURE_H

#define NO_MATERIAL -1
#define GLASS_MATERIAL 0
#define NATURAL_MATERIAL 1
#define STONE_MATERIAL 2
#define SKYBOX_MATERIAL 3
#define METAL_MATERIAL 4

enum TextureType
{
    NULL_TEXTURE,
    // Glass
    SKYSCRAPER_TEXTURE,
    OFFICE_TEXTURE,
    OLD_OFFICE_TEXTURE,
    // Natural
    OLD_WOOD_TEXTURE,
    GRASS_TEXTURE,
    // Stone/Rock/Concrete
    APARTMENT_TEXTURE,
    BRICK_APARTMENT_TEXTURE,
    ROAD_TEXTURE,
    INTERSECTION_TEXTURE,
    SIDEWALK_TEXTURE,
    CONCRETE1_TEXTURE,
    // Skybox
    SKYBOX_FRONT_TEXTURE,
    SKYBOX_BACK_TEXTURE,
    SKYBOX_LEFT_TEXTURE,
    SKYBOX_RIGHT_TEXTURE,
    SKYBOX_TOP_TEXTURE,
    SKYBOX_BOTTOM_TEXTURE,
    // Metals
    GALVANIZED_METAL_TEXTURE,
    CHIPPED_METAL_TEXTURE,
    GOLDEN_GATE_TEXTURE,
    SCRATCHED_METAL_TEXTURE,
    BRASS_TEXTURE,

    TEXTURE_COUNT,
    NO_TEXTURE
};

// singleton class for loading textures
class Texture
{
private:
    static Texture* instance;
    unsigned int textures[TEXTURE_COUNT];

    Texture();

    ~Texture();

    Texture(const Texture&) = delete;

    Texture& operator=(const Texture&) = delete;

public:
    static Texture* get_instance()
    {
        if (instance == nullptr)
        {
            instance = new Texture();
        }
        return instance;
    }

    unsigned int get_texture(int index) const;

    int get_material_type(int index) const;
};

#endif
