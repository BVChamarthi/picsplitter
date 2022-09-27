#include "image.h"

int main() {
    image img("test.png");

    image left_split(img.w/2, img.h, img.c);
    image right_split(img.w/2, img.h, img.c);

    int w = left_split.w, h = left_split.h, c = left_split.c;


    for(int x = 0; x < w; x ++) {
        for(int y = 0; y < h; y++) {
            for(int z = 0; z < c; z++) {
                left_split.data[y*w*c + x*c + z] = img.data[y*w*2*c + x*c + z];
                right_split.data[y*w*c + x*c + z] = img.data[y*w*2*c + w*c + x*c + z];
            }
        }
    }

    left_split.write("test_left.png");
    right_split.write("test_right.png");

    return 0;
}