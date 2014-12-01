#include <stdio.h>
struct city_t
{
	short next;
	short nnext;
	char  state;
} city[26*26*26 + 1];

short path[10001];

short getcityno(char *c)
{
	short no = c[0] - 'A';
	no *= 26;
	no += c[1] - 'A';
	no *= 26;
	no += c[2] - 'A' + 1;
	return no;
}

void getcityname(char *c, short no)
{
	--no;
	c[0] = no / 26 / 26 + 'A';
	c[1] = (no % (26 * 26)) / 26 + 'A';
	c[2] = no % 26 + 'A';
	c[3] = 0;
}

int dfs(int n, int i)
{
	if (city[n].next == 0) {
		path[i] = n;
		return 1;
	}

	if (city[n].state >= 0x10) {
		return 0;
	}
	city[n].state |= 0x10;

	if (dfs(city[n].next, i + 1)) {
		path[i] = n;
		return 1;
	}

	while (city[n].nnext) {
		if (dfs(city[n].nnext, i + 1)) {
			path[i] = n;
			return 1;
		}
	}
	return 0;
	
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
		int n, N;
		for (n = 1; n < 26*26*26 + 1; n++) {
			city[n].next = city[n].nnext = city[n].state = 0;
		}
		for (n = 0; n < 10001; n++) {
			path[n] = 0;
		}
		fscanf(fp, "%d", &N);
		for (n = 0; n < N; n++) {
			char tmp[5];
			fscanf(fp, "%s", tmp);
			int src = getcityno(tmp);
			city[src].state |= 1;
			fscanf(fp, "%s", tmp);
			int dst = getcityno(tmp);
			city[dst].state |= 2;
			if (city[src].next == 0) {
				city[src].next = dst;
			} else {
				int next = src;
				while (city[next].nnext && next != dst) {
					next = city[next].nnext;
				}
				if (city[next].nnext == 0) {
					city[next].nnext = dst;
				}
			}
		}

		for (n = 0; n < 26*26*26 + 1; n++) {
			if (city[n].state == 1) {
				break;
			}
		}

		dfs(n, 0);
		fprintf(fpout, "Case #%d:", t + 1);
		for (n = 1; path[n]; n++) {
			char tmp1[4], tmp2[4];
			getcityname(tmp1, path[n - 1]);
			getcityname(tmp2, path[n]);
			fprintf(fpout, " %s-%s", tmp1, tmp2);
		}
		fprintf(fpout, "\n");
	}
	return 0;
}
