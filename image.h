#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

struct image {
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
};

#endif