#include <stdio.h>
#include <stdlib.h>
char *last  = NULL;
int   count = 1;
void sort(int *array, int n)
{
	int i,j;
	int *tmp;
	int c[256] = {0};
	int *b = malloc(n * sizeof(int));
	unsigned char *a = (unsigned char *)array;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 256; j++) {
			c[j] = 0;
		}
		for (j = i; j < 4 * n; j += 4) {
			c[a[j]] ++;
		}
		for (j = 1; j < 256; j++) {
			c[j] += c[j - 1];
		}
		for (j = 4 * (n - 1) + i; j >= 0; j -= 4) {
			b[c[a[j]] - 1] = array[j / 4];
			c[a[j]] --;
		}
		for (j = 0; j < n; j++) {
			array[j] = b[j];
		}
	}
	free(b);
	return;
}

int main()
{
	int n, N, i, j;
	int table[100];
	table['0'] = 0;
	table['1'] = 1;
	table['A'] = table['B'] = table['C'] = table['2'] = 2;
	table['D'] = table['E'] = table['F'] = table['3'] = 3;
	table['G'] = table['H'] = table['I'] = table['4'] = 4;
	table['J'] = table['K'] = table['L'] = table['5'] = 5;
	table['M'] = table['N'] = table['O'] = table['6'] = 6;
	table['P'] = table['R'] = table['S'] = table['7'] = 7;
	table['T'] = table['U'] = table['V'] = table['8'] = 8;
	table['W'] = table['X'] = table['Y'] = table['9'] = 9;
	char buf[256];
	scanf("%d", &N);
	if (N < 1) {
		printf("No duplicates. \n");
		return 0;
	}
	int *tel = malloc(N * sizeof(int));
	for (n = 0; n < N; n++) {
		scanf("%s", buf);
		tel[n] = 0;
		for (i = 0, j = 0; i < 7; j++) {
			if ((buf[j] >= 'A' && buf[j] < 'Z') || (buf[j] >= '0' && buf[j] <= '9')) {
				tel[n] *= 10;
				tel[n] += table[buf[j]];
				i++;
			}
		}
	}
	sort(tel, N);
	char flag = 0;
	for (n = 1; n < N; n ++) {
		j = 1;
		while (tel[n] == tel[n-1] && n < N) {
			j ++;
			n ++;
		}
		if (j > 1) {
			printf("%03d-%04d %d\n", tel[n-1]/10000, tel[n-1]%10000, j);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("No duplicates. \n");
	}
	free(tel);
	return 0;

}
