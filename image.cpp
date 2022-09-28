#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "image.h"
#include "stb_image.h"
#include "stb_image_write.h"

image_type get_file_type(const char* filename) {
    const char* ext = strrchr(filename, '.');
    if(ext != nullptr) {
        if(strcmp(ext, ".png"))
            return PNG;
        else if(strcmp(ext, ".jpg"))
            return JPG;
        else
            return ERR;
    }
    return ERR;
}

bool image::read(const char* filename) {
    data = stbi_load(filename, &w, &h, &c, 0);
    return (data != nullptr);
}

bool image::write(const char* filename) {
    image_type type = get_file_type(filename);
    int success;
    switch (type)
    {
        case PNG:
            success = stbi_write_png(filename, w, h, c, data, w*c);
            break;
        case JPG:
            success = stbi_write_jpg(filename, w, h, c, data, 100);
            break;

        default:
            success = 0;
            break;
    }
    return (success != 0);
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

image* image::get_selection(int x0, int y0, int x1, int y1) {
    if(x0 < 0 || y0 < 0 || x1 >= w || y1 >= h || x0 > x1 || y0 > y1) {

    }
}