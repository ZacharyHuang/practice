#include <stdio.h>
const char Tmap[20][10] = 
{
	"imix",
	"ik",
	"akbal",
	"kan",
	"chicchan",
	"cimi",
	"manik",
	"lamat",
	"muluk",
	"ok",
	"chuen",
	"eb",
	"ben",
	"ix",
	"mem",
	"cib",
	"caban",
	"eznab",
	"canac",
	"ahau"
};
int sm2m(char *m)
{
	int i;
	for (i = 0; i < 18; i ++) {
		switch (m[0]) {
		case 'c':
			if (m[1] == 'h') {
				return 9;
			} else if (m[1] == 'e') {
				return 12;
			} else if (m[1] == 'u') {
				return 18;
			} else {
				printf("wrong month\n");
			}
			break;
		case 'k':
			if (m[1] == 'a') {
				return 14;
			} else if (m[1] == 'o') {
				return 17;
			} else {
				printf("wrong month\n");
			}
			break;
		case 'm':
			if (m[1] == 'a') {
				return 13;
			} else if (m[1] == 'o') {
				return 8;
			} else if (m[1] == 'u') {
				return 15;
			} else {
				printf("wrong month\n");
			}
			break;
		case 'n':			
			return 2;
			break;
		case 'p':
			if (m[1] == 'o') {
				return 1;
			} else if (m[1] == 'a') {
				return 16;
			} else {
				printf("wrong month\n");
			}
			break;
		case 't':
			return 5;
			break;
		case 'u':
			return 19;
			break;
		case 'x':
			return 6;
			break;
		case 'y':
			if (m[1] == 'a') {
				return 10;
			} else if (m[1] == 'o') {
				return 7;
			} else {
				printf("wrong month\n");
			}
			break;
		case 'z':
			if (m[1] == 'i') {
				return 3;
			} else if (m[1] == 'o') {
				return 4;
			} else if (m[1] == 'a') {
				return 11;
			} else {
				printf("wrong month\n");
			}
			break;
		}
	}
}
void h2t(int y, int m, int d, int *yy, int *mm, int *dd)
{
	int s = y * 365 + (m - 1) * 20 + d + 1;
	*yy = s / 260;
	m = s % 260;
	if (m == 0) {
		(*yy) --;
	}
	d = m % 13;
	if (d == 0) {
		d = 13;
	}
	*mm = d;
	d = m % 20;
	if (d == 0) {
		d = 20;
	}
	*dd = d;
}
int main (int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	printf("%d\n",n);
	for (; n > 0; n --) {
		int y,d,m;
		char sm[10];
		scanf("%d. %s %d", &d, sm, &y);
		m = sm2m(sm);
		int yy,dd,mm;
		h2t(y,m,d,&yy,&mm,&dd);
		printf("%d %s %d\n", mm, Tmap[dd - 1], yy);
	}
	return 0;
}
