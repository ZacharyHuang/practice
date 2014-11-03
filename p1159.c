#include <stdio.h>
#include <string.h>

#define lf 1<<30
#define rf 1<<29
#define im 0x3FFF<<14
#define lm 0x3FFF

int s2i(char s)
{
	if (s<='9' && s>='0') {
		return (s-'0');
	}
	if (s>='A' && s<='Z') {
		return (s - 'A' + 10);
	}
	return (s - 'a' + 36);
}
int find_one_pair(char* s, int start, int end)
{
	int i = start;
	int j = end;
	int c[62];
	memset(c, 0, 62 * sizeof(int));
	while (i < j) {
		int li = s2i(s[i]);
		if (c[li] & rf) {
			return 2 + find_one_pair(s, i, (c[li]&im)>>14);
		}
		if (c[li] & lf) {
			c[li] |= i - ((c[li]&im) >> 14);
		} else {
			c[li] = i<<14;
			c[li] |= lf;
		}
		i++;
		if (j <= i ) {
			break;
		}
		int ri = s2i(s[j]);
		if (c[li] & lf) {
			return 2 + find_one_pair(s, (c[li]&im)>>14, j);
		}
		if (c[li] & rf) {
			c[li] |= ((c[li]&im) >> 14) - j;
		} else {
			c[li] = i<<14;
			c[li] |= rf;
		}
		j--;
	}
	int max = 0;
	int tmp;
	for (i = 0; i < 62; i ++) {
		if (c[i]&lm) {
			j = (c[i]&im)>>14;
			if (c[i]&lf) {
				tmp = find_one_pair(s, j, j+c[i]&lm);
			} else if (c[i]&rf) {
				tmp = find_one_pair(s, j-c[i]&lm, j);
			}
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	return max;
}
int main (int argc, char *argv[])
{
	int len;
	char s[5001];
	scanf("%d", &len);
	scanf("%s", s);
	int res = find_one_pair(s, 0, len-1);
	
	printf("%d\n",len-res-1);
	return 0;
}
