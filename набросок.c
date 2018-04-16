#include <stdio.h>
#include <math.h> 
FILE * open;
FILE * save;
int block[64],A[32],B[32],S[32],K[32],N[8]={0,0,0,0,0,0,0,0},flag,Number_blok,N1[32],F[32],C[32],ALL[64],i,j,nom;
char mode;
unsigned char chr;
unsigned long key[8]=                               
{
    123456,
    231564,
    435612,
    354621,
    261453,
    645132,
    513426,
    351623
};  
int table[8][16]=                                   
{ 
  4, 10,  9,  2, 13,  8,  0, 14,  6, 11,  1, 12,  7, 15,  5,  3,
 14, 11,  4, 12,  6, 13, 15, 10,  2,  3,  8,  1,  0,  7,  5,  9,
  5,  8,  1, 13, 10,  3,  4,  2, 14, 15, 12,  7,  6,  0,  9, 11,
  7, 13, 10,  1,  0,  8,  9, 15, 14,  4,  6, 12, 11,  2,  5,  3,
  6, 12,  7,  1,  5, 15, 13,  8,  4, 10,  9, 14,  0,  3, 11,  2,
  4, 11, 10,  0,  7,  2,  1, 13,  3,  6,  8,  5,  9, 12, 15, 14,
 13, 11,  4,  1,  3, 15,  5,  9,  0, 10, 14,  7,  6,  8,  2, 12,
  1, 15, 13,  0,  5,  7, 10,  4,  9,  2,  3, 14,  6, 11,  8, 12
};  



  void fill64(int a,FILE *open)                        //Заполнение блока по 64 
{
if((a==Number_blok-1)&&(flag==1)) 
{       //Если идёт последний блок и число символов в файле не кратно 8
perevod2(nom,open);
printf("->%d<-",B[i]);
float kl=8*(nom%8);
for( i=kl;i<64;i++)     //Заполняем оставшуюся часть блока нулями.
ALL[i]=0;
}
else    {
perevod2(8,open);
printf("->%d<-",ALL[i]);
}
printf("\nfill64 complete!\n");
}

 long FileSize(FILE *open)         //Узнаем размер файла
{
    long strelka , length;
    strelka= ftell(open);         //Сохраняем значение указателя на символ
    fseek(open, 0, SEEK_END); 
    length = ftell(open);
    fseek(open, strelka, SEEK_SET);//Возвращяемся на исходное место
    return length;
}  	
 void fillBA()                      //Заполнение блока B и A
{   
        for(i=0;i<32;i++)
        {
            B[i]=ALL[i];
            A[i]=ALL[32+i];
            printf("%d",A[i]);

        }
    printf("\nfillBA complete!!\n");
}

void fillkey(int b)                //Заполнение одного ключика
{
unsigned long x=0;  
    if (mode=='1')                   //Если мы решили шифровать
    {                               
        if((b>24)&&(b<=32))      
        x=key[7-(b-1)%8];  //то наоборот с 8 ключа
        else
        x=key[(b-1)%8]; //обычно
    printf("\nkey->%d\n",x);
    }

    if (mode=='2')                   //Если мы выбрали режим шифрования
    {                               
        if((b>=1)&&(b<=8))
            x=key[(b-1)%8];
        else
            x=key[7-(b-1)%8];
            printf("\nkey->%d\n",x);
    }
    perevod(x);
printf("\nfillkey complete!!!\n");
}
 int Numb(FILE *open, int size)             //Определение числа блоков
{
    int n;
    size=FileSize(open);
    n=size/8;                                   //Сохраняем число  (8-символьных) блоков
    if(size%8!=0)                               //Если число символов в файле не кратно 8, то увеличивыем число блоков
    {
        n=n+1;
        flag=1;
    }
    printf("numb complete!size=%d n=%d\n",size,n);
    return n;
}

 
 void summa32()                       
{
int flag2=0;
    for(i=31;i>=0;i--)      //Поразрядное сложение блоков
    {
       if ((A[i]+K[i]+flag2)>=2) 
	   { 
            S[i]=A[i]+K[i]+flag2-2;
            flag2=1;
        }
        else                        //если все норм
        {
            S[i]=A[i]+K[i]+flag2;
            flag2=0;
        }
        printf("%d",S[i]);
    }
    
    
printf("\nsumma32 complete!!!!\n");
}
void fillnakop1()                      
{
for(i=0;i<8;i++)            //В накопителе 8 чисел
    {
    for(j=0;j<4;j++)        //Преобразуем 4 бита  с конца в 10-чное число
        if(S[31-4*i-j]==1)
         N[i]=N[i]+pow(2,j);
         printf("%d",N[i]);
    }
printf("\nfillnakop1 complete!!!!!\n");
}
 
void changenode()                 
{
int k;
for(i=0;i<8;i++)
    {
    k=N[i];
    N[i]=table[i][k]; 
	printf("%d",N[i]);          
    }
printf("\nchangenode complete!!!!!!\n");
}
void fillnakop2()                     //Преобразование узла в накопитель 
{
for(i=0;i<8;i++)            //Все 8 чисел накопителя N
    for(j=0;j<4;j++)        //переводим в двоичный вид
    {
        if(N[i]/pow(2,3-j)>=1)
        {
        N1[4*i+j]=1;
        N[i]=N[i]-pow(2,3-j);
        }
    else
    N1[4*i+j]=0;
    printf("%d",N1[i]);
    }
printf("\nfill nakop2 complete!!!!!!!\n");
}
 
void shift11()                      // Результат сдвига - результа функции Фейстеля F(Ai,Ki)
{
for( i=0;i<21;i++)
{
F[i]=N1[i+11];          //Сохраняем биты с 12 по 32
if (i<11)
F[i+21]=N1[i];
}          //Сохраняем биты с 1 по 11
printf("\nshift11 complete!!!!!!!!\n");
}

void XOR()                    
{
    for(i=0;i<32;i++){
        A[i]=F[i]^B[i]; 
		printf("%d",A[i]);
		}
printf("\nXOR complete!!!!!!!!!\n") ;           //Двоичное исключающее "ИЛИ"
}
  
void kleiAB()                 //Склеивание блоков в одно
{
for(i=0;i<64;i++){
    if (i<32 )ALL[i]=A[i];
    else ALL[i]=B[i-32];
printf("%d",ALL[i]);
    }
printf("\nkleiAB complete!!!!!!!!!!\n");
}
 
void conclusiontext(int a,FILE * save)                    
{
    int d,n;
    if((a==Number_blok-1)&&(flag==1)&&(mode=='2'))    //Если последний блок,исло екратно то
        d=FileSize(open)%8;                           //выводим первые d=FileSize(fi)%8 символов.
    else                                            
        d=8;  
		
		                                      // выводим 8 символов
for(i=0;i<d;i++)
    {
    	n=0;
  for(j=0;j<8;j++)                        //Преобразование из 8 бит в  символ
            if (ALL[8*i+j]==1)
                n=n+pow(2,7-j); 
        chr=n;
        if (mode == '2'){
		
		if(n == 255) 	 chr=" ";
	}
        printf("%d->%c",n,chr);
        fprintf(save,"%c",chr);
        printf("\nconclusiotext complete!!!!!!!!!!!\n");
    }
}
	
void perevod(unsigned long x)
 {
 	
 	 for(i=0;i<32;i++)           //Переводим в двоичную сис
    {
        if(x/pow(2,31-i)>=1)
        {
            K[i]=1;
            x=x-pow(2,31-i);
        }
        else
            K[i]=0;
            printf("%d",K[i]);
    }
 
 }
 

int perevod2(int x, FILE*open)
 {
int nomer;
 	for(i=0;i<x;i++)
    {           
    chr=fgetc(open);               //Берем символ->узнаем его номер из аски-переовдим в двоичную систему(по 8 бит)
    printf("\nsymbol->%c\n",chr);
	nomer=chr;  
	printf("his number->%d\n",nomer);       
   for(j=0;j<8;j++)        
    {
	  if(nomer/pow(2,7-j)>=1)     
        {
          ALL[8*i+j]=1;
          nomer=nomer-pow(2,7-j);
          }
           else
           ALL[8*i+j]=0;                
		    }
		}
 }
  
void Save()              //Bi+1 = Ai
{
    for( i=0;i<32;i++)
        B[i]=C[i];
}
 
 void saveAc()              //Bi+1 = Ai
{
    for( i=0;i<32;i++)
        C[i]=A[i];
}

int main(int argc, char **argv){

	
	int size,Number_blok,a,b,i;	
 nom=FileSize(open)%8;//выбрать режим (шифровать или расшифровывать)
printf("for encryption, enter 1, for decryption 2\n"); 
mode=getch();
if (mode=='1') printf("\nyou have chosen the encryption mode\n") ;
else printf("\nyou have chosen the descryption mode\n");
    
     printf("\n your input file is taken from (argv[1])\n");
     FILE *open= fopen(argv[1],"rb");
      FILE *save=fopen(argv[2],"ab+");
     printf("\n your input file is taken from argv[2]\n");
    Number_blok=Numb(open,size);     //Определение числа блоков    
 //основная часть
    for( a=0;a<Number_blok;a++)        
    {
fill64(a,open);                //заполняем блоки по 64 бита
fillBA();                  //заполняем блок БА                     
    for (b=1;b<=32;b++)     //функция фестеля и тд
{
fillkey(b);            //Заполнение ключика
summa32();           //Сумма по модулю 2^32
fillnakop1();              //Заполнение накопителя
changenode();            //узлы замен
fillnakop2();             // Заполнение выходного накопителя
shift11();              // Сдвиг на 11 битов влево    
//END FES
saveAc();
 XOR();
 Save(); 
 }                           //Конец основного цикла.
kleiAB();             //Склеивание блоков 
conclusiontext(a,save);            //Вывод зашифрованного текста 
    }                      
}

