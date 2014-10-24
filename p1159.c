#include <stdio.h>
int s2i(char s)
{
	if (s<='9' && s>='0') {
		return (s-'0');
	}
	if (s<='A' && s>='Z') {
		return (s - 'A' + 10);
	}
	return (s - 'a' + 36);
}
int find_one_pair(char *s, int start, int end)
{
	int i = start;
	int j = end;
	int res = 0;
	int lc[62], rc[62];
	memset(lc, -1, 62);
	memset(rc, -1, 62);
	while (j - i > 1) {
		int li = s2i(s[i]);
		if (rc[li] > 0) {
			res += i - start + end - rc[li];
			start = i + 1;
			end = rc[li] - 1;
		}
		if (lc[li] < 0) {
			lc[li] = i;
		}
		i ++;
		if (j - i > 1) {
			break;
		}
		int ri = s2i(s[j]);
		if (lc[ri] > 0) {
			res += lc[ri] - start + end - j;
			start = lc[ri] + 1;
			end = j - 1;
			return res;
		}
		if (rc[ri] < 0) {
			rc[ri] = j;
		}
		j --;
	}
	res += start - end - 1;
}
int main (int argc, char *argv[])
{

	int len;
	char str[5001];
	scanf("%d", len);
	scanf("%s", str);
	int res = 0, count = 0;
	int i = 0, j = len - 1;
	while ((res = find_one_pair(str, &i, &j)) >= 0) {
		count += res;
	}
	count -= res;
	printf("%d\n",res);
	return 0;
}
