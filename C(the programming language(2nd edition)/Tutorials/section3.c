#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "section3.h"
#define MAXSIZE 1000
#define MAXLINE 1000
int binsearch(int x, int v[], int n)
{
    int low,mid,high;

    low=0;
    high=n-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(x < v[mid])
            high = mid-1;
        else if (x > v[mid])
            low = mid+1;
        else
            return mid;
    }
    return -1;
}

void count_digis_whitespace_others()
{
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 10;
    for(i=0; i< 10;i++)
        ndigit[i]=0;
    while((c=getchar())!=EOF) {
        switch(c){
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            ndigit[c-'0']++;
            break;
        case ' ':
        case '\n':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }
    printf("digit = ");
    for(i=0;i<10;i++)
        printf(" %d", ndigit[i]);
    printf(",white space = %d, other= %d\n", nwhite, nother);
}

void escapeUtil()
{
    char s[MAXSIZE];
    char t[MAXSIZE];
    int i,len;

    len=getline(t, MAXLINE);

    escape(s,t);
}
void escape(char s[], char t[])
{
    int c,i,j;
    i=j=0;
    for(c=0;t[c]!=EOF;c++)
    {
        switch(t[c])
        {
            case '\n':
                s[i]='\\';
                ++i;
                s[i]='n';
                break;
            case '\t':
                s[i]='\\';
                ++i;
                s[i]='t';
                break;
            default:
                s[i]=t[j];
                break;
        }
        ++i;
        ++j;
    }
    s[i]='\0';
    printf("%s",s);
}

int atoi_2(char s[])
{
    int i,n,sign;
    for(i=0;isspace(s[i]);i++)
        ;
    sign = (s[i]=='-') ? -1: 1;
    if(s[i]== '+' || s[i]=='-')
        i++;
    for(n=0;isdigit(s[i]);i++)
        n=10*n + (s[i]-'0');
    return sign * n;
}

void shellsort(int v[], int n)
{
    int gap, i, j,temp;
    for(gap=n/2; gap>0; gap/=2)
        for(i=gap;i<n;i++)
            for(j=i-gap;j>=0 && v[j]>v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

void reverse_2(char s[])
{
    int c,i,j;
    for(i=0; j=strlen(s)-1 && i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

void reverse_1(char *str)
{

    if (*str)
    {
       reverse(str+1);

       printf("%c", *str);
    }
}

void expandUtil()
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    int len;

    len=getline(s1,MAXLINE);

    expand(s1,s2);

}

void expand(char s1[],char s2[])
{
    char c;
    int i, j;
    i=j=0;
    //the last character will be added to s2;

    while((c=s1[i++])!='\0')
    {
        if(s1[i] =='-' && s1[i+1]>c)
        {
            i++;
            while(c < s1[i])
                s2[j++]=c++;
        }
        else
        {
            s2[j++]=c;
        }
    }
    s2[j]='\0';

    printf("%s", s2);
}

void itoa_3(int n, char s[])
{
    int i,sign;
    if((sign=n)<0)
        n = -n;
    i=0;
    do {
        s[i++]= n%10 + '0';
    } while((n/=10)>0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}




