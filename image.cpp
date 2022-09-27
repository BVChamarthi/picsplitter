#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "image.h"
#include "stb_image.h"
#include "stb_image_write.h"

bool image::read(const char* filename) {
    data = stbi_load(filename, &w, &h, &c, 0);
    return (data != nullptr);
}

image::image(const char* filename) {
    read(filename);
}

image::image(int width, int height, int channels) : w(width), h(height), c(channels) {
    size = w*h*c;
    data = new uint8_t[size];
}

image::image(const image& img) {
    image(img.w, img.h, img.c);
    memcpy(data, img.data, size);
}

image::~image() {
    stbi_image_free(data);
}