#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

enum image_type {
    JPG, PNG, ERR
};

image_type get_file_type(const char* filename);

typedef class image {
public:
    uint8_t* data;      // actual image data
    int w;              // width of image
    int h;              // height of image
    int c;              // number of color channels in the image
    int size;           // size of data in bytes

    image(const char* filename);
    image(int width, int height, int channels);
    image(const image& img);
    ~image();

    bool read(const char* filename);
    bool write(const char* filename);

    image* get_selection(int x0, int y0, int x1, int y1);
} image;

#endif