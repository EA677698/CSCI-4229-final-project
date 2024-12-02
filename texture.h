#ifndef TEXTURE_H
#define TEXTURE_H

enum TextureType {
    NULL_TEXTURE,
    SKYSCRAPER_TEXTURE,
    ROAD_TEXTURE,
    INTERSECTION_TEXTURE,
    GRASS_TEXTURE,
    SKYBOX_FRONT_TEXTURE,
    SKYBOX_BACK_TEXTURE,
    SKYBOX_LEFT_TEXTURE,
    SKYBOX_RIGHT_TEXTURE,
    SKYBOX_TOP_TEXTURE,
    SKYBOX_BOTTOM_TEXTURE,

    TEXTURE_COUNT,
    NO_TEXTURE
};

class Texture {

private:

    static Texture *instance;
    unsigned int textures[TEXTURE_COUNT];

    Texture();

    ~Texture();

    Texture(const Texture &) = delete;

    Texture &operator=(const Texture &) = delete;

public:

    static Texture *get_instance() {
        if (instance == nullptr) {
            instance = new Texture();
        }
        return instance;
    }

    unsigned int get_texture(int index) const;

};

#endif