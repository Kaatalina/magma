#include <stdio.h>
void sumsd(int num)
{
	int table[8][16]=                                   
{ 
  12,   4,   6,   2,   10,   5,  11,   9,  14,   8,  13,   7,   0,   3,  15,   1,
   6,   8,   2,   3,    9,  10,   5,  12,   1,  14,   4,   7,  11,  13,   0,  15,
  11,   3,   5,   8,    2,  15,  10,  13,  14,   1,   7,   4,  12,   9,   6,   0,
  12,   8,   2,   1,   13,   4,  15,   6,   7,   0,  10,   5,   3,  14,   9,  11,
   7,  15,   5,  10,    8,   1,   6,  13,   0,   9,   3,  14,  11,   4,   2,  12,
   5,  13,  15,   6,    9,   2,  12,  10,  11,   7,   8,   1,   4,   3,  14,   0,
   8,  14,   2,   5,    6,   9,   1,  12,  15,   4,  11,   0,  13,  10,   3,   7,
   1,   7,  14,  13,    0,   5,   8,   3,   4,  15,  10,   6,   9,  12,  11,   2
};  
	int i, j,a[8],k[8];
	a[0]=(num*0x10000000)>>28;
    a[1]=(num*0x01000000)>>28;
    a[2]=(num*0x00100000)>>28;
    a[3]=(num*0x00010000)>>28;
    a[4]=((num*0x00001000)>>28);
    a[5]=((num*0x00000100)>>28);
    a[6]=((num*0x00000010)>>28);
    a[7]=((num*0x00000001)>>28);
	for (i=0;i<8;i++){
		if (a[i]<0||a[i]>15)
		a[i]=a[i]+0x10;
		printf("%d ",a[i]);
	}
k[0]=table[7][a[7]];
k[1]=table[6][a[6]];
k[2]=table[5][a[5]];
k[3]=table[4][a[4]];
k[4]=table[3][a[3]];
k[5]=table[2][a[2]];
k[6]=table[1][a[1]];
k[7]=table[0][a[0]];
	printf("%x%x%x%x%x%x%x%x  ",k[0],k[1],k[2],k[3],k[4],k[5],k[6],k[7]);

int p = 0;
for (i = 0; i < sizeof(k) / sizeof(*k); ++i)
{
    p *= 16;
    p += k[i];
}
	p= p<<11|p>>21;
	printf("%x",p);
	
}
int main()
{
	int l = 0xfdcbc20c;
	int b = 0x87654321;
	int num = (l+b);
	sumsd(num);
	
}
