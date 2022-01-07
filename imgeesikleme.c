#include <stdio.h>
#include <stdlib.h>
void threshold(unsigned char* data, int ncols, int nrows, unsigned thresh)
{
	if ((thresh < 0) || (thresh > 255))
	{
		printf("HATA: Imge esik degeri olan %d, 0-255 araliginda olmali.\n", thresh);
		exit(1);
	}
    for (int i = 0; i < ncols*nrows; i++) {
		 if (data[i]<thresh)
			 data[i] = 0;
		 else
			 data[i] = 255;	
	}
}
