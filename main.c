#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci {
	
	char ad[200];
	char soyad[200];
	int no;
	
}karakter;

int kackez(int x){
	int a,k;

	while(x>0){
    a=x%10; 
    x = x/10;  
	if(a > 0){
		k= a;
	} else{
		continue;
	}break; 
	
	}

}


void sezarSifrele ( char *ptr, int key  ) 
{
	while( *ptr!='\0' )
	{
		*ptr = *ptr +key  ; 
		ptr++; 		
	}
	
}

int asalsayibul(int s){
	int i;
	int enbuyuk;
	for (i = 2; s != 1; i ++)
	   	{
			if (s % i == 0)
			{
		   		s /= i;
 
		        enbuyuk = i;
 
		   		i --;
			}
	   	}

}

void sezarSifreCoz ( char *ptr, int key  ) 
{
	while( *ptr!='\0' )
	{
		*ptr = *ptr - key  ; 
		ptr++; 		
	}
	
}

void dosyayaz(){
	FILE *dosya = fopen("sifrelimetin.txt","w");
	fprintf(dosya,karakter.ad);

	fclose(dosya);
}

void dosyakapat(){
	FILE *dosya;
			char karak;
			dosya = fopen("sifrelimetin.txt","r");
			do {
				karak = getc(dosya);
				printf("%c",karak);
			}
			while (karak != EOF);
			fclose(dosya);
	
}


 
int main() {
	char karakte;
    int veri1;
    int sifre;
    char ch;
	printf("turkce karakter olmadan adinizi giriniz  :");
    gets(karakter.ad);
	printf("turkce karakter olmadan soyadinizi giriniz :");
    gets(karakter.soyad);
    strcat(karakter.ad,karakter.soyad);
    printf("ogrenci numaranizi giriniz :");
	scanf("%d",&karakter.no);
	

	
	int oteleme = kackez(karakter.no);

	sezarSifrele(karakter.ad, oteleme);  
	
	dosyayaz();
     
	
    printf("ogrenci numaraniz nedir ? :");
    scanf("%d",&veri1);
	if(karakter.no == veri1){
		
		printf("parola giriniz :");
		scanf("%d",&sifre);
		int parola  = asalsayibul(karakter.no);
		
		while(sifre != parola ){
            printf("hatali parola tekrar giriniz :");
			scanf("%d",&sifre);	  
		}
		if(sifre == parola){
			
			dosyakapat();
			
			printf(" <---- sifreli hali   ve  ogrenci no ----> %d",karakter.no);
			sezarSifreCoz (karakter.ad, oteleme);  
			printf("\nCozulmus    Metin : %s \n", karakter.ad ) ; 
			
			
		}
		
	
	} else{
		printf("hatali ogrenci numarasi girdiniz !");
	}
	

	return 0;
}
