#include <stdio.h>

int main(int argc, const char *argv[])
{
	FILE *fp, *fpout;
	fp = fopen("./in", "r");
	if (fp == NULL) {
		return 1;
	}
	fpout = fopen("./out", "w");
	if (fpout == NULL) {
		fpout = stdout;
	}
	int t, T;
	int ab[500][2];
	fscanf(fp, "%d", &T);
	for (t = 0; t < T; t++) {
		int n, N, p, P;
		fscanf(fp, "%d", &N);
		for (n = 0; n < N; n++) {
			fscanf(fp, "%d %d", &ab[n][0], &ab[n][1]);
		}
		fprintf(fpout, "Case #%d:", t + 1);
		fscanf(fp, "%d", &P);
		for (p = 0; p < P; p++) {
			int c = 0, C;
			fscanf(fp, "%d", &C);
			for (n = 0; n < N; n++) {
				if (C >= ab[n][0] && C <= ab[n][1]) {
					c ++;
				}
			}
			fprintf(fpout, " %d", c);
		}
		fprintf(fpout, "\n");
	}
	return 0;
}
