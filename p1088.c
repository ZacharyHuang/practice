#include <stdio.h>

int map[100][100] = {0};
int row, col;

int pl[100][100] = {0};

int DP(int i, int j)
{
	if (pl[i][j] > 0) {
		return pl[i][j];
	}

	int tmp, max = 0;
	if (i - 1 >= 0 && map[i-1][j] < map[i][j]) {
		tmp = DP(i - 1, j);
		if (tmp > max) {
			max = tmp;
		}
	}

	if (j - 1 >= 0 && map[i][j - 1] < map[i][j]) {
		tmp = DP(i, j - 1);
		if (tmp > max) {
			max = tmp;
		}
	}

	if (i + 1 < row  && map[i + 1][j] < map[i][j]) {
		tmp = DP(i + 1, j);
		if (tmp > max) {
			max = tmp;
		}
	}

	if (j + 1 < col && map[i][j + 1] < map[i][j]) {
		tmp = DP(i, j + 1);
		if (tmp > max) {
			max = tmp;
		}
	}
	
	pl[i][j] = ++max;

	return max;
}

int main(int argc, const char *argv[])
{

	scanf("%d %d", &row, &col);

	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf("%d", &map[i][j]);
			pl[i][j] = 0;
		}
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			DP(i, j);
		}
	}

	int max = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (max < pl[i][j]) {
				max = pl[i][j];
			}
		}
	}

	printf("%d\n", max);
	return 0;
}
