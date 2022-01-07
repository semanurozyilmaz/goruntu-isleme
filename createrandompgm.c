#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void createRandomPGM(char* path, int m, int n, int v)
{
	FILE* fp = fopen(path, "w");
	srand(time(NULL));
	fprintf(fp, "P2\n# CREATOR: PGM\n");
	fprintf(fp, "%d %d\n", m, n);
	fprintf(fp, "%d\n", v);
	for (int i = 0; i < m * n; i++)
	{
		fprintf(fp, "%d\n", rand()%256 );

	}
	fclose(fp);
}