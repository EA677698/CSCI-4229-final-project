#ifndef TEXTURE_H
#define TEXTURE_H

#include "csci_lib/CSCIx229.h"

#define TEXTURE_COUNT 1

#define TEXTURE_NULL 0

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

    unsigned int get_texture(int index);

};

#endif