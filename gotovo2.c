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
    long int key,k0,k1,k2,k3,k4,k5,k6;
    printf("Enter the key\n");
    fscanf(stdin, "%08x %08x %08x %08x %08x %08x %08x %08x",&key,&k0,&k1,&k2,&k3,&k4,&k5,&k6);
    K[0]=key;K[1]=k0;K[2]=k1;K[3]=k2;K[4]=k3;K[5]=k4;K[6]=k5;K[7]=k6;
    K[8]=key;K[9]=k0;K[10]=k1;K[11]=k2;K[12]=k3;K[13]=k4;K[14]=k5;K[15]=k6;
    K[16]=key;K[17]=k0;K[18]=k1;K[19]=k2;K[20]=k3;K[21]=k4;K[22]=k5;K[23]=k6;
    K[24]=k6;K[25]=k5;K[26]=k4;K[27]=k3;K[28]=k2;K[29]=k1;K[30]=k0;K[31]=key;
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
    unsigned int a=0,b=0; 
    int i;
    printf("Enter the input data\n");
    printf("for encryption, enter 1, for decryption 2\n"); 
    scanf("%x %x\n",&a,&b);
    scanf("%c",&mode);
    if (mode=='1') printf("\nyou have chosen the encryption mode\n") ;
    else printf("\nyou have chosen the descryption mode\n");
    fillkey();
    for (i=0;i<32;i++)
    {
        fest(&a,&b,i);
    }
    printf("%x %x\n",a,b);
}
