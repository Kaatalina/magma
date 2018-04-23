#include <stdio.h>
unsigned int K[32];
unsigned int c,p;
 int fillkey(int i){
 	
K[1] = 0xffeeddcc, K[9] = 0xffeeddcc, K[17] = 0xffeeddcc, K[25] = 0xfcfdfeff,
K[2] = 0xbbaa9988, K[10] = 0xbbaa9988, K[18] = 0xbbaa9988, K[26] = 0xf8f9fafb,
K[3]= 0x77665544,  K[11]   = 0x77665544, K[19]=0x77665544, K[27] = 0xf4f5f6f7,
K[4] = 0x33221100, K [12]= 0x33221100, K[20] = 0x33221100, K[28] = 0xf0f1f2f3,
K[5] = 0xf0f1f2f3, K [13]= 0xf0f1f2f3, K[21] = 0xf0f1f2f3, K[29] = 0x33221100,
K[6] = 0xf4f5f6f7, K[14] = 0xf4f5f6f7, K[22] = 0xf4f5f6f7, K [30]= 0x77665544,
K[7] = 0xf8f9fafb, K[15] = 0xf8f9fafb, K [23]= 0xf8f9fafb, K[31]= 0xbbaa9988,
K[8] = 0xfcfdfeff, K[16] = 0xfcfdfeff, K [24]= 0xfcfdfeff, K [32]= 0xffeeddcc;
return(K[i]);
 }


int fest(unsigned int *a,unsigned int *b,int i){
	printf("\nthis is i %d\n",i);
	int k1 =i;
 	fillkey(i);
 	printf(" key =%x ",K[i]);
	unsigned int num = *b+K[i]; 

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
	unsigned int  a1[8]={0,0,0,0,0,0,0,0},k[8]={0,0,0,0,0,0,0,0};
	a1[0]=(num*0x10000000)>>28;
    a1[1]=(num*0x01000000)>>28;
    a1[2]=(num*0x00100000)>>28;
    a1[3]=(num*0x00010000)>>28;
    a1[4]=((num*0x00001000)>>28);
    a1[5]=((num*0x00000100)>>28);
    a1[6]=((num*0x00000010)>>28);
    a1[7]=((num*0x00000001)>>28);
	for (i=0;i<8;i++){
		if (a1[i]<0||a1[i]>15)
		a1[i]=a1[i]+0x10;
	}
k[0]=table[7][a1[7]];
k[1]=table[6][a1[6]];
k[2]=table[5][a1[5]];
k[3]=table[4][a1[4]];
k[4]=table[3][a1[3]];
k[5]=table[2][a1[2]];
k[6]=table[1][a1[1]];
k[7]=table[0][a1[0]];
					 
unsigned int p = 0;
for (i = 0; i < sizeof(k) / sizeof(*k); ++i)
{
    p *= 16;
    p += k[i];
}
	p= p<<11|p>>21;
	c=*b;
		*a=p^*a;
 	printf(" %x ",*a);
 	
	
 	if (k1!=32){
	  *b=*a;
 	*a=c;

 }
 	printf("   %x %x ",*a,*b);
	  	
}

int main(){
unsigned int a=0xfedcba98,b=0x76543210;
int i;
for (i=1;i<33;i++){
fest(&a,&b,i);

}
}
