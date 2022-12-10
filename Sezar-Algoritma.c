#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct
{
    char ad[20],soyad[20];
    int numara;
}mn;

void verigirisi(char isim[],char soyisim[],int no)
{
    // 2 isim girecekseniz isimler birleþik olsun(küçük harf kullanýn).s
    printf("isim girin:");scanf("%s",isim);
    printf("soyisim girin:");scanf("%s",soyisim);
}

void metinbirlestir(char isim[],char soyisim[])
{
    strcat(isim,soyisim);
}

int sonnumara(int no)
{
    int i=10;
    if(no%i!=0)
    {
        return no%i;
    }
    else
    {
        for( ; ; )
        {
            i=i*10;
            if(no%i!=0)
            {
                return (no%i)/(i/10);
            }
        }
    }
}

void sifreleme(char metin[],int basamak)
{
    int x;
    for(int i=0;i<strlen(metin);i++)
    {
        for(int j=0;j<basamak;j++)
        {
            if(metin[i]>='z')
            {
               metin[i]='a';
            }
            else
            {
                metin[i]++;
            }
        }
    }
}

void dosyayayazma()
{
    FILE *p;
    p=fopen("sifrelimetin.txt","w");
    if(p==NULL)
    {
        printf("dosya acilamadi...\nprogram kapatiliyor...\n");exit(1);
    }
    else
    {
    printf("dosya basarili bir sekilde acildi...\n");
    fputs(mn.ad,p);
    printf("dosyaya metin yazildi dosya kapatiliyor...\n\n");fclose(p);
    }
}

int asalcarpanbulma(int sayi)
{
    int i;
    for(i=2;sayi>1;i++)
    {
        while(sayi%i==0)
        {
            sayi=sayi/i;
        }
    }
    return i-1;
}

void dosyadanokuma()
{
    int k;
    FILE *p;
    p=fopen("sifrelimetin.txt","r");
    if(p==NULL)
    {
        printf("dosya acilamadi...\nprogram kapatiliyor...\n");exit(1);
    }
    else
    {
        printf("dosya basarili bir sekilde acildi...\n\n");
        printf("sifreli metin: ");
        for(k=0;k<strlen(mn.ad);k++)
        {
            printf("%c",fgetc(p));
        }printf("\n");
    }
}

void sifreyicozumleme(char sifrelimetin[],int basamak)
{
    int x,i,j;
    for(int i=0;i<strlen(sifrelimetin);i++)
    {
        for(j=0;j<basamak;j++)
        {
            if(sifrelimetin[i]<='a')
                mn.ad[i]='z';
            else
                sifrelimetin[i]--;
        }
    }
    printf("cozumlenmis metin:%s\n",sifrelimetin);
}

int main()
{
    verigirisi(mn.ad,mn.soyad,mn.numara);
    printf("ogrenci numaranizi girin:");scanf("%d",&mn.numara);
    metinbirlestir(mn.ad,mn.soyad);
    printf("\nmetinlerin birlestirilmis hali:%s\n\n",mn.ad);
    int sayi=sonnumara(mn.numara);
    sifreleme(mn.ad,sayi);
    dosyayayazma();
    int parola,sifre=asalcarpanbulma(mn.numara);
    printf("sifreyi cozumlemek icin soruyu cevaplayin...\n\n");printf("SORU: ogrenci numaranizin en buyuk asal carpani nedir?\n");
    scanf("%d",&parola);
    for( ; ; )
    {
        if(parola==sifre)
        {
            printf("cevap dogru...\nprogram aciliyor...\n");
            break;
        }
        else
        {
            printf("hatali sifre tekrar deneyin!\n");scanf("%d",&parola);
        }
    }
    dosyadanokuma();
    sifreyicozumleme(mn.ad,sayi);
    printf("ogrenci no:%d\n",mn.numara);
}
