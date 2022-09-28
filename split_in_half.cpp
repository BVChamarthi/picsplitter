#include "image.h"
#include <vector>
#include <cstdio>
#include <iostream>

image** vertical_split(image* img, int num_splits) {
    int sp_w = img->w / num_splits;

    image** imgs = new image*[num_splits + 2];
    imgs[num_splits+1] = nullptr;

    for(int i = 0; i < num_splits; i++) {
        image* f_img = img->get_selection(i*sp_w, 0, (i+1)*sp_w, img->h);
        imgs[i] = f_img;
    }
    imgs[num_splits] = img->get_selection(num_splits*sp_w, 0, img->w, img->h);

    return imgs;
}

image** horizontal_split(image* img, int num_splits) {
    int sp_h = img->h / num_splits;

    image** imgs = new image*[num_splits + 2];
    imgs[num_splits+1] = nullptr;

    for(int i = 0; i < num_splits; i++) {
        image* f_img = img->get_selection(0, i*sp_h, img->w, (i+1)*sp_h);
        imgs[i] = f_img;
    }
    imgs[num_splits] = img->get_selection(0, num_splits*sp_h, img->w, img->h);

    return imgs;
}

int main() {
    image img("1.png");
    image** imgs = horizontal_split(&img, 6);

    char filename[50];
    for(int i = 0; imgs[i] != nullptr; i++) {
        sprintf(filename, "hsplit/h%d.png", i);
        if(imgs[i]->size != 0) imgs[i]->write(filename);
    }

    return 0;
}