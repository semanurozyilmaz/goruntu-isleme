#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void filter_mean(unsigned char* data0, unsigned char* data1,
	int ncols, int nrows, int N)
{

	int* array = (int*)malloc(N * N * sizeof(int));

	for (int y = N / 2; y < nrows - (N / 2); y++) 
	{

		for (int x = N / 2; x < ncols - (N / 2); x++)
		{

			int z = 0;

			for (int j = -N / 2; j <= N / 2; j++) {

				for (int i = -N / 2; i <= N / 2; i++)
				{
					array[z] = data0[(i + N / 2) + ((j + N / 2) * ncols) + (x - N / 2) + ((y - N / 2) * ncols)];
					z++;

				}

			}

			int ortalama = mean(array, N * N);


			*(data1 + x + (long)y * ncols) = ortalama;	

		}
		

	}
	
}
int mean(int* arr, int n)
{
	int toplam = 0;
	for (int i = 0; i < n; i++)
	{
		toplam = toplam + arr[i];
	}
	int ortala = toplam / n; 
	

	return ortala;
}