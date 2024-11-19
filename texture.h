#ifndef TEXTURE_H
#define TEXTURE_H

enum TextureType {
    NULL_TEXTURE,
    SKYSCRAPER_TEXTURE,
    ROAD_TEXTURE,
    GRASS_TEXTURE,
    TEXTURE_COUNT,
    NO_TEXTURE
};

class Texture{

private:

    static Texture* instance;
    unsigned int textures[TEXTURE_COUNT];
    Texture();
    ~Texture();

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

public:

    static Texture* get_instance() {
        if (instance == nullptr) {
            instance = new Texture();
        }
        return instance;
    }

    unsigned int get_texture(int index) const;

};

#endif