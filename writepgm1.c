#include <stdio.h>
void writePGM(char* path, unsigned char* data, int m, int n, int v)
{
	FILE* fp = fopen(path, "w");

	fprintf(fp, "P2\n# CREATOR: PGM\n");
	fprintf(fp, "%d %d\n", m, n);
	fprintf(fp, "%d\n", v);
	for (int i = 0; i < m * n; i++)
	{
		fprintf(fp, "%d\n", data[i]);

	}
	fclose(fp);
	
}