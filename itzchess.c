#include <stdio.h>
struct chessStruct
{
	char row;
	char col;
	char type;
} chess[64];
int count;
int N;
void check(int n)
{
	int i;
	int row = chess[n].row;
	int col = chess[n].col;
	unsigned char dir = 0;
	for (i = 0; i < N; i++) {
		if (i == n) {
			continue;
		}

		switch (chess[n].type)
		{
		case 'K':
			if (chess[i].row <= row + 1 && chess[i].row >= row - 1
			&& chess[i].col <= col + 1 && chess[i].col >= col - 1) {
				count ++;
			}
			break;
		case 'Q':

			if (!(dir & 0x01) && chess[i].row == row  && chess[i].col < col) {
				count ++;
				dir |= 0x01;
			}
			if (!(dir & 0x02) && chess[i].row == row  && chess[i].col > col) {
				count ++;
				dir |= 0x02;
			}
			if (!(dir & 0x04) && chess[i].col == col  && chess[i].row < row) {
				count ++;
				dir |= 0x04;
			}

			if (!(dir & 0x08) && chess[i].col == col  && chess[i].row > row) {
				count ++;
				dir |= 0x08;
			}
			if (!(dir & 0x10) && chess[i].row < row  && chess[i].col < col && chess[i].row - row == chess[i].col - col) {
				count ++;
				dir |= 0x10;
			}
			if (!(dir & 0x20) && chess[i].row < row  && chess[i].col > col && chess[i].row - row == col - chess[i].col) {
				count ++;
				dir |= 0x20;
			}
			if (!(dir & 0x40) && chess[i].row > row  && chess[i].col > col && chess[i].row - row == chess[i].col - col) {
				count ++;
				dir |= 0x40;
			}
			if (!(dir & 0x80) && chess[i].row > row  && chess[i].col < col && chess[i].row - row == col - chess[i].col) {
				count ++;
				dir |= 0x80;
			}
			break;
		case 'R':
			if (!(dir & 0x01) && chess[i].row == row && chess[i].col < col) {
				count ++;
				dir |= 0x01;
			}
			if (!(dir & 0x02) && chess[i].row == row && chess[i].col > col) {
				count ++;
				dir |= 0x02;
			}
			if (!(dir & 0x04) && chess[i].col == col && chess[i].row < row) {
				count ++;
				dir |= 0x04;
			}
			if (!(dir & 0x08) && chess[i].col == col && chess[i].row > row) {
				count ++;
				dir |= 0x08;
			}
			break;
		case 'B':
		if (!(dir & 0x10) && chess[i].row < row  && chess[i].col < col && chess[i].row - row == chess[i].col - col) {
				count ++;
				dir |= 0x10;
			}
			if (!(dir & 0x20) && chess[i].row < row  && chess[i].col > col && chess[i].row - row == col - chess[i].col) {
				count ++;
				dir |= 0x20;
			}
			if (!(dir & 0x40) && chess[i].row > row  && chess[i].col > col && chess[i].row - row == chess[i].col - col) {
				count ++;
				dir |= 0x40;
			}
			if (!(dir & 0x80) && chess[i].row > row  && chess[i].col < col && chess[i].row - row == col - chess[i].col) {
				count ++;
				dir |= 0x80;
			}
			break;
		case 'N':
			if (((chess[i].row - row == 2 || chess[i].row - row == -2) && (chess[i].col - col == 1 || chess[i].col - col == -1))
			|| ((chess[i].row - row == 1 || chess[i].row - row == -1) && (chess[i].col - col == 2 || chess[i].col - col == -2)))
 {
				count ++;
			}
			break;
		case 'P':
			if (chess[i].row == row + 1 && (chess[i].col == col - 1 || chess[i].col == col + 1)) {
				count ++;
			}
			break;
		}
	}
	return;
}

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
	fscanf(fp, "%d", &T);
	for (t = 0; t < T; t++) {
		int n;
		fscanf(fp, "%d\n", &N);
		for (n = 0; n < N; n++) {
			char r;
			fscanf(fp, "%c%hhd-%c\n", &r, &chess[n].col, &chess[n].type);
			chess[n].row = r - 'A' + 1;
		}
		count = 0;
		for (n = 0; n < N; n++) {
			check(n);
		}
	}
	return 0;
}
