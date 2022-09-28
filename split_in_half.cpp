#include "image.h"
#include <vector>
#include <cstdio>
#include <iostream>

image** vertical_split(image* img, int num_splits) {
    int sp_w = img->w / num_splits;

    image** imgs = new image*[num_splits + 2];
    imgs[num_splits+1] = nullptr;

    for(int i = 0; i < num_splits; i++) {
        std::cout << "(" << i*sp_w << ", " << 0 << "), (" << (i+1)*sp_w << ", " << img->h << ")\n";
        image* f_img = img->get_selection(i*sp_w, 0, (i+1)*sp_w, img->h);
        imgs[i] = f_img;
    }
    imgs[num_splits] = img->get_selection(num_splits*sp_w, 0, img->w, img->h);

    return imgs;
}

int main() {
    image img("test.png");
    image** imgs = vertical_split(&img, 2);

    char filename[50];
    for(int i = 0; imgs[i] != nullptr; i++) {
        sprintf(filename, "vsplit/v%d.png", i);
        if(imgs[i]->size != 0) imgs[i]->write(filename);
    }

    return 0;
}