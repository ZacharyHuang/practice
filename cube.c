#include <stdio.h>
int map[1000][1000];
int count[1000][1000];
int S;
int r, d;
int DP(int i, int j)
{
	if (count[i][j] > 0) {
		return count[i][j];
	}

	int tmp, max = 0;
	if (i - 1 >= 0 && map[i][j] + 1 == map[i - 1][j]) {
		tmp = DP(i - 1, j);
		if (max < tmp) {
			max = tmp;
		}
	}	
	if (j - 1 >= 0 && map[i][j] + 1 == map[i][j - 1]) {
		tmp = DP(i, j - 1);
		if (max < tmp) {
			max = tmp;
		}
	}
	if (i + 1 < S && map[i][j] + 1 == map[i + 1][j]) {
		tmp = DP(i + 1, j);
		if (max < tmp) {
			max = tmp;
		}
	}
	if (j + 1 < S && map[i][j] + 1 == map[i][j + 1]) {
		tmp = DP(i, j + 1);
		if (max < tmp) {
			max = tmp;
		}
	}

	count[i][j] = ++max;
	if (d == max && r > map[i][j]) {
		r = map[i][j];
	} else if (d < max) {
		d = max;
		r = map[i][j];
	}
	return max;
}
int main(int argc, const char *argv[])
{
	FILE *fp , *fpout;
	fp = fopen("./in", "r");
	if (fp == NULL) {
		return 1;
	}
	fpout = fopen("./out", "w");
	if (fpout == NULL) {
		fpout = stdout;
	}
	int t, T;
	fscanf(fp, "%d", &T);
	for (t = 0; t < T; t++) {
		r = d = 0;
		fscanf(fp, "%d", &S);
		int i, j;
		for (i = 0; i < S; i++) {
			for (j = 0; j < S; j++) {
				fscanf(fp, "%d", &map[i][j]);
			}
		}
		
		for (i = 0; i < S; i++) {
			for (j = 0; j < S; j++) {
				DP(i,j);
			}
		}

		fprintf(fpout, "Case #%d: %d %d\n", t + 1, r, d);

		for (i = 0; i < S; i++) {
			for (j = 0; j < S; j++) {
				count[i][j] = 0;
			}
		}
	}
	return 0;
}
