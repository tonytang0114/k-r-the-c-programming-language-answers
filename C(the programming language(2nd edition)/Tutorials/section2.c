#include <stdio.h>
#include <stdlib.h>
#include "section2.h"
#define MAXLINE 100

#define YES 1
#define NO 0
#define BYTESIZE 8

int strlen(char s[])
{
    int i;

    i=0;
    while(s[i] != '\0')
        ++i;
    return i;
}

//2-2 skip

int atoi_1(char s[])
{
    int i,n;
    n=0;
    for(i=0; s[i]>='0' && s[i]<='9'; ++i)
        n= 10*n+ (s[i]-'0');
    return n;
}

int lower(int c)
{
    if(c >= 'A' && c<='Z')
        return c+ 'a' - 'A';
    else
        return c;
}

int htoi_util()
{
    char line[MAXLINE];
    int value;

    getline(line,MAXLINE);
    value=htoi(line);
    printf("The value of %s is %d",line,value);
}
//2.22
int htoi(char s[])
{
    int hexdigit, i ,inhex,n;
    i=0;
    if(s[i]=='0')
    {
        ++i;
        if(s[i] == 'x' || s[i]=='X')
            ++i;
    }

    n=0;
    inhex=YES;

    for(; inhex==YES;++i)
    {
        if(s[i]>='0' && s[i]<='9')
            hexdigit = s[i]-'0';
        else if(s[i]>='a' && s[i]<='f')
            hexdigit =s[i] -'a'+10;
        else if(s[i]>='A' && s[i]<='F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex=NO;
        if(inhex = YES)
            n = 16 *n + hexdigit;
    }

    return n;
}

//squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i,j;
    for(i=j=0; s[i]!='\0'; i++)
        if(s[i]!=c)
            s[j++]=s[i];
    s[j]='\0';
}

void strcat(char s[], char t[])
{
    int i,j;
    i=j=0;
    while (s[i]!='\0')
        i++;
    while ((s[i++]=t[j++])!= '\0')
        ;
}

//2-4
void squeeze_1(char s1[], char s2[])
{
    int i,j,k;
    k=0;
    for(i=0;s1[i]!='\0';i++)
    {
        for(j=0;s2[j]!='\0';j++)
        {
            if(s1[i]!=s2[j])
            {
                s1[k++]=s1[i];
            }
        }
    }
    s1[k]='\0';
}

//2.5 Write the function any(s1,s2)
int any(char s1[],char s2[])
{
    int i,j;
    for(i=0; s1[i]!='\0';i++)
    {
        for(j=0; s2[j]!='\0';j++)
        {
            if(s1[i]==s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, int y) {
   return x | (~(~0 << n) << p);
}

unsigned invert(unsigned x, int p, int n)
{
     return   x ^ (~(~0 << n) << (p + 1 - n));
}

unsigned rightrot(unsigned x, int n)
{
    int size;
    unsigned y;
    size=0;
    while(y!=0)
    {
        y = y<<BYTESIZE;
        size++;
    }
    size = size * BYTESIZE;

    return (x << (size-n)) | (x >> n);
}
//count the number of 1-bit in x
int bitcount(unsigned x)
{
    int b;
    for(b=0; x!=0; x>>=1)
        if(x & 01)
            b++;
    return b;
}

int bitcount_2(unsigned x)
{
    int b;

    for(b=0; x!=0; x &= x-1)
        ++b;

    return b;
}
