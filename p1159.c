#include <stdio.h>
#include <string.h>


struct node
{
	short i:14;
	short j:14;
	char  lf:1;
	char  rf:1;
};
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
void nodedeal(struct node *c, int len)
{
	int i, j;
	for (i = 0; i < len; i ++) {
		if (c[i].i >= c[i].j) {
			c[i].lf = 0;
			c[i].rf = 0;
			continue;
		}
		for (j = i + 1; j < len; j ++) {
			if (c[i].i >= c[j].i && c[i].j <= c[j].j) {
				c[i].lf = 0;
				c[i].rf = 0;
			}
		}
	}
}
int find_one_pair(char* s, int start, int end)
{
	if (start > end) {
		return -1;
	} else if (start == end) {
		return 0;
	}
	int i = start;
	int j = end;	
	int max = 0;
	int tmp;
	struct node c[62];
	memset(c, 0, 62 * sizeof(struct node));
	while (i <= end)
	{
		int li = s2i(s[i]);
		if (c[li].lf == 0) {
			c[li].i = i;
			c[li].lf = 1;
		}
		int ri = s2i(s[j]);
		if (c[ri].rf == 0) {
			c[ri].j = j;
			c[ri].rf = 1;
		}
		i++;
		j--;
	}
	nodedeal(c, 62);
	for (i = 0; i < 62; i ++) {
		if (c[i].lf == 0 || c[i].rf == 0) {
			continue;
		}
		tmp = 2 + find_one_pair(s, c[i].i + 1, c[i].j - 1);
		if (tmp > max) {
			max = tmp;					
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
