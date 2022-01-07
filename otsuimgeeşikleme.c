#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void threshold(unsigned char* data, int width, int height, unsigned thresh, const int n);
void writePGM(char* path, unsigned char* data, int m, int n, int v);
unsigned char* readPGM(char* path, int* m, int* n, int* v);
void otsu(const int N, char* path_in, char* path_out)
{
	double* withinClassVariances = (double*)malloc(N * sizeof(double));
	//double withinClassVariances[N];
	int ncols, nrows, maxvalue;
	unsigned char* data0 = readPGM(path_in, &ncols, &nrows, &maxvalue);
	scalePGM(data0, &ncols, &nrows, 256 / N);
	int* histogram = histogram1D(data0, ncols, nrows, N, false);
	for (int i = 0; i < N; i++) {
		withinClassVariances[i] = withinClassVariance(histogram, N, i, false);

	}
    int min_index = 0;
	double min_val = withinClassVariances[0];
	
	for (int i = 0; i < N; i++) 
	 {
		
		 if (withinClassVariances[i] < min_val) 
		 {
			 min_val = withinClassVariances[i];
			 min_index = i;
			 
		}	
		
	}
	threshold(data0, ncols, nrows, min_index, N);
	writePGM(path_out, data0, ncols, nrows, maxvalue);
    free(data0);
	free(histogram);
}

 void scalePGM(unsigned char* data, int* m, int* n, int scale)
 {
	 for (int i = 0; i < (*n); i++) {
		 for (int j = 0; j < (*m); j++){
			 data[i * (*m) + j] = data[i * (*m) + j] / scale;
		
		 }
		 
	 }
	 
 }
 
	 
	 
 int* histogram1D(unsigned char* data, int m, int n, int nbins)
{
	  int* histogram = (int*)calloc(nbins, sizeof(int));
	  for (int j = 0; j < nbins; j++) 
	  {
		  int count = 0;
		  for (int i = 0; i < ((m) * (n)); i++) 
		  {
			  if (j == data[i])
			  {
				  count++;
			  }
		  }
		  histogram[j] = count;
		

	  }
	
	  return histogram;
}
 double withinClassVariance(int* histogram, int nbins, int threshold)
{
	  double w_b, mu_b, v_b;
	  statistics(histogram, nbins, 0, threshold - 1, &w_b, &mu_b, &v_b);
	  double w_f, mu_f, v_f;
	  statistics(histogram, nbins, threshold, nbins - 1, &w_f, &mu_f, &v_f);
	  double v_withinClass = w_b * v_b + w_f * v_f; 
	  return v_withinClass;
}
 
	 
	  void statistics(int* histogram, int nbins, int binFirst, int binLast, double* w, double* mu, double* v)
	  {
		  int sum = 0;
		  for (int i = 0; i < nbins; i++) 
		  {
			  sum += histogram[i];
		  }
		  int histsum = sum;
	  
		  int totalweights = 0;
	  for (int i = binFirst; i <= binLast; i++)
		  totalweights += histogram[i];
	  * w = (double)totalweights /(double) histsum; 
	 
		  int weightedsum = 0;
	  for (int i = binFirst; i <= binLast; i++)
		  weightedsum += histogram[i] * i; 
	  if (totalweights) {
		  * mu = (double)weightedsum /(double) totalweights;
		   * v = 0;
		   for (int i = binFirst; i <= binLast; i++)
			   * v = (histogram[i] * ((i - *mu)* (i - *mu))) + *v;
		  * v = (*v) /(double) (totalweights);
		  
	  }
	  
}
	
		 
		 