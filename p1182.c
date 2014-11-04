#include <stdip.h>
struct animal
{	
	unsigned short this;
	unsigned short eat;
	unsigned short beate;
	unsigned short state;
};
#define tf 1
#define ef 2
#define bf 4
struct animal* a;
int N = 0;
int findthis(int n)
{
	while (a[n].this != n) {
		n = a[n].this;
	}
	return n;
}
int check(int D, int X, int Y)
{
	if (X > N || Y > N)
		return 1;
	unsigned char state = (a[x].state << 4) | a[Y].state;
	if (D == 1) {
		switch (state)
		{
		case 0x00://X is NULL and Y is NULL
			a[X].this = a[Y].this = X;
			a[X].state |= tf;
			a[Y].state |= tf;
			return 0;
		break;
		case 0x01://X is NULL and Y has this
		case 0x03://X is NULL and Y has eat and this
		case 0x05://X is NULL and Y has beate and this
		case 0x07://X is NULL and Y has all
			a[X].this = a[Y].this;
			a[X].state |= tf;
			return 0;
		case 0x10://Y is NULL and X has this
		case 0x30://Y is NULL and X has eat and this
		case 0x50://Y is NULL and X has beate and this
		case 0x70://Y is NULL and X has all
			a[Y].this = a[X].this;
			a[Y].state |= tf;
			return 0;
		case 0x11//X has this and Y has this
			if (a[X].this != a[Y].this)
				{ return 1; }
			a[Y].this = a[X].this
		break;
		}//switch
	} else if (D == 2) {
		switch (state)
		{
		case 0x00://X is NULL and Y is NULL
			a[X].eat = Y;
			a[X].this = X;
			a[X].state |= tf|ef;
			a[Y].beate = X;
			a[Y].this = Y;
			a[Y].state |= tf|ef;
			return 0;
		break;
		case 0x01://Y has this and X is NULL
			
		break;
		case 0x02://Y has eat and X is NULL
			
		break;
		case 0x03://X is NULL and Y has this and eat
			
		break;
		case 0x04://X is NULL and Y has beate
		
		break;
		}//switch
				
	}
	
}
int main (int argc, char *argv[])
{
	int K;
	int lie = 0;
	scanf("%d %d", &N, &K);
	a = (struct animal *)calloc(N, sizeof(struct animal));
	while ((K--) > 0) {
		int D, X, Y;
		scanf("%d %d %d", &D, &X, &Y);
		if (check(D, X, Y))
			lie++;
	}
	free(a);
	return 0;
}
