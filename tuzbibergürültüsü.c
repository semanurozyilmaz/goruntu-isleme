#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
enum saltpepper {
    SALT, PEPPER, BOTH
};
void add_saltpepper(double pnoise, unsigned char* data, int ncols, int nrows, int maxval, unsigned saltpepper)
{
    srand(time(NULL));
    int nnoise = (int)(pnoise*ncols*nrows);
    bool salt = true;
    bool pepper = true;

    for (int i = 0; i < nnoise; i++) {
        switch (saltpepper) {
        case SALT:
            data[rand() % ((ncols * nrows))] = 255;
            break;
        case PEPPER:
            data[rand()% ((ncols * nrows))] = 0;
            break;
        default:
            if (salt) {
                data[rand()% ((ncols * nrows))] = 255;
                salt = false;
                pepper = true;

            }
            else {
                data[rand()% ((ncols * nrows))] = 0;
                salt = true;
                pepper = false;

            }

        }

    }
  
}