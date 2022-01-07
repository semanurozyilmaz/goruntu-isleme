#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned char* readPGM(char* path, int* m, int* n, int* v)
{
	FILE* fp = fopen(path, "r");
	if (fp == NULL)
	{
		printf("HATA: Dosya acilamiyor!");
		exit(1);
	}
	
	if (getc(fp) != 'P')
	{
		printf("HATA: PGM dosyasi degil");
	}
	if (getc(fp) != '2')
	{
	printf("HATA: PGM tipi desteklenmiyor");
	}
	fscanf(fp, "\n");
	if (getc(fp) == '#')
	{	
		while (getc(fp) != '\n');
		
	}
	fscanf(fp, "%d %d %d", m, n, v);
    unsigned char* data = (unsigned char*)malloc((*m) * (*n) *sizeof(unsigned char));
	int i = 0;
	unsigned c;
	do {
	    fscanf(fp,"%d", &c);
		data[i] = c;
		i++;
	} while (i<((*m)*(*n)));
	fclose(fp);
	return data;
}

	






