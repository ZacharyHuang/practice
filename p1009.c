#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned char byte;
byte rdata = 0;
long  rlen = 0;
byte ddata = 0;
long  dlen = 0;
struct line_struct
{
	byte *p;
	struct line_struct *next;
	struct line_struct *prior;
};

int push(byte *p, int size)
{
	if (rlen < 0) {
		printf("rlen<0\n");
		exit(-1);
	}
	if (rlen == 0) {
		scanf("%d %ld", &rdata, &rlen);
		if (rdata == 0 && rlen == 0) {
			return 0;
		}
	}
	if (rlen > 0) {
		if (rlen >= size) {
			if (ddata == 0 && dlen >= size && rdata == p[0]) {
				dlen += rlen;
				rlen %= size;
				dlen -= rlen;
				return push(p, size);
			}
			memset(p, rdata, size);
			rlen -= size;
		} else {
			memset(p, rdata, rlen);
			size -= rlen;
			p += rlen;
			rlen = 0;
			return push(p, size);
		}
	}
	return 1;
}
#define dist(a,b) a>b?a-b:b-a
byte getdata(struct line_struct *l, int i, int size)
{
	byte max = 0;
	byte pd = l->p[i];
	byte tmp;
	max = dist(pd, l->next->p[i]);
	tmp = dist(pd, l->prior->p[i]);
	max = max < tmp ? tmp : max;
	if (i != 0) {
		tmp = dist(pd, l->p[i-1]);
		max = max < tmp ? tmp : max;
		tmp = dist(pd, l->prior->p[i-1]);
		max = max < tmp ? tmp : max;
		tmp = dist(pd, l->next->p[i-1]);
		max = max < tmp ? tmp : max;
	}
	if (i != size - 1) {
		tmp = dist(pd, l->p[i+1]);
		max = max < tmp ? tmp : max;
		tmp = dist(pd, l->prior->p[i+1]);
		max = max < tmp ? tmp : max;
		tmp = dist(pd, l->next->p[i+1]);
		max = max < tmp ? tmp : max;
		
	}
	return max;
}
void deal(struct line_struct *l, int size)
{
	int i = 0;

	for (i = 0; i < size; i ++) {
		byte data = getdata(l, i, size);
		if (data == ddata) {
			dlen ++;
		} else {
			if (dlen > 0) {
				printf("%d %ld\n", ddata, dlen);
			}
			ddata = data;
			dlen = 1;
		}
	}
}
int main (int argc, char *argv[])
{
	struct line_struct ll[3];
		ll[0].p = (byte *)calloc(1, sizeof(byte));
		ll[0].next = &ll[1];
		ll[0].prior = &ll[2];
		ll[1].p = (byte *)calloc(1, sizeof(byte));
		ll[1].next = &ll[2];
		ll[1].prior = &ll[0];
		ll[2].p = (byte *)calloc(1, sizeof(byte));
		ll[2].next = &ll[0];
		ll[2].prior = &ll[1];
		struct line_struct * l = &ll[0];
	while (1) {
		rdata = 0;
		rlen = 0;
		ddata = 0;
		dlen = 0;
		int size;
		scanf("%d", &size);
		printf("%d\n", size);
		if (size == 0) {
			break;
		}
		ll[0].p = (byte *)realloc(ll[0].p, size*sizeof(byte));
		ll[1].p = (byte *)realloc(ll[1].p, size*sizeof(byte));
		ll[2].p = (byte *)realloc(ll[2].p, size*sizeof(byte));

		push(l->p, size);
		memcpy(l->prior->p, l->p, size);
		l = l->next;
		while (push(l->p, size)) {
			deal(l->prior, size);
			l = l->next;
		}
		memcpy(l->p, l->prior->p, size);
		l = l->prior;
		deal(l->prior, size);
		printf("%d %ld\n0 0\n", ddata, dlen);
	}
		free(ll[0].p);
		free(ll[1].p);
		free(ll[2].p);
	return 0;
}
