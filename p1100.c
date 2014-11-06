#include <stdio.h>
char optc[4] = {0,'+','-','*'};
int cal(int res, int *a, char *opt, int len)
{
	if (len == 1) {
		return (res == a[0]);
	}
	if (cal(res - a[0], a - 1, opt - 1, len - 1)) {
		*opt = '+';
		return 1;
	}
	if (cal(res + a[0], a - 1, opt - 1, len - 1)) {
		*opt = '-';
		return 1;
	}
	if (res % a[0] == 0 && cal(res / a[0], a - 1, opt - 1, len - 1)) {
		*opt = '*';
		return 1;
	}
	return 0;
}
int main (int argc, char *argv[])
{
	char s[81];
	int n = 0;
	while (++ n) {
		gets(s);
		int ret = 0;
		int res;
		int a[12] = {0};
		char s[13][80];
		ret = sscanf(s, "%d = %d%[^0-9\n ]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d", &res, a, a+1, a+2, a+3, a+4, a+5, a+6, a+7, a+8, a+9, a+10, a+11);
		if (ret <= 1) {
			break;
		}
		printf("Equation #%d:\n", n);
		if (cal(res, a + ret - 2, optc + ret - 3, ret - 1)) {
			int i;
			printf("%d=",res);
			for (i = 0; i < ret - 2; i ++) {
				printf("%d%c",a[i],optc[i]);
			}
			printf("%d\n\n",a[i]);
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}
