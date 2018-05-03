#include <stdio.h>
#include <math.h>
unsigned int K[32];
unsigned int c,p,mode;
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
unsigned long x;

void fillkey(){
     K[0] = 0xffeeddcc, K[8]  = 0xffeeddcc, K[16] = 0xffeeddcc, K[24] = 0xfcfdfeff,
     K[1] = 0xbbaa9988, K[9]  = 0xbbaa9988, K[17] = 0xbbaa9988, K[25] = 0xf8f9fafb,
     K[2] = 0x77665544, K[10] = 0x77665544, K[18] = 0x77665544, K[26] = 0xf4f5f6f7,
     K[3] = 0x33221100, K[11] = 0x33221100, K[19] = 0x33221100, K[27] = 0xf0f1f2f3,
     K[4] = 0xf0f1f2f3, K[12] = 0xf0f1f2f3, K[20] = 0xf0f1f2f3, K[28] = 0x33221100,
     K[5] = 0xf4f5f6f7, K[13] = 0xf4f5f6f7, K[21] = 0xf4f5f6f7, K[29] = 0x77665544,
     K[6] = 0xf8f9fafb, K[14] = 0xf8f9fafb, K[22] = 0xf8f9fafb, K[30] = 0xbbaa9988,
     K[7] = 0xfcfdfeff, K[15] = 0xfcfdfeff, K[23] = 0xfcfdfeff, K[31] = 0xffeeddcc;
}

int getkey(int i){
    if (mode=='1')                                      
        x=K[(i)];
    if (mode=='2')                   
        x=K[(31-i)];
}

int fest(unsigned int *a,unsigned int *b,int i){
    int k1 =i;
    getkey(i);
    unsigned int p = *b+x; 
    unsigned int aa,k,o,t,t1;
    for (i=0;i<8;i++)
    {
        aa=((p&(0xf<<4*i))>>4*i);
        o=pow(0x10,i);
        t=table[i][aa];
        k=aa*o;
        t1=t*o;
        p=p-k;
        p=p|t1;
    } 
    p= p<<11|p>>21;	
    c=*b;
    *a=p^*a;
    if (k1!=31)
    {
       *b=*a;
       *a=c;
    }
}

int main(){
    unsigned int a=0xfedcba98,b=0x76543210;
    int i;
    printf("%x %x\n",a,b);
    printf("for encryption, enter 1, for decryption 2\n"); 
    mode=getchar();
    if (mode=='1') printf("\nyou have chosen the encryption mode\n") ;
    else printf("\nyou have chosen the descryption mode\n");
    fillkey();
    for (i=0;i<32;i++)
    {
        fest(&a,&b,i);
    }
    printf("%x %x\n",a,b);
}
