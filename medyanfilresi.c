#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void filter_median(unsigned char* data0, unsigned char* data1,
	int ncols, int nrows,int N)
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

			sortarray(array, N * N);


			*(data1 + x + (long)y * ncols) = array[N * N / 2];
		}


	}

}
void sortarray(int* arr,int count)
{
	int temp, k, l, m;
	for (int k = 0; k < count; k++)
	{
		for (int l = 0; l < count; l++)
		{
			if (arr[k] < arr[l])
			{
				temp = arr[k];
				arr[k] = arr[l];
				arr[l] = temp;
			}
		}
	}
}
