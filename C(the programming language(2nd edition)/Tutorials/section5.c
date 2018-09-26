#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <ctype.h>
#include "section3.h"
#define MAXSIZE 1000
#define MAXLINE 1000
#define MAXOP 100
#define NUMBER '0'
#define MAXLEN 1000 /* max length of any input line */
#define MAXSTOR 5000

//5.1
int getint(int *pn)
{
    int c, sign,sawsign;
    while(isspace(c=getch()))
        ;
    if(!isdigit(c) && c!=EOF && c!='+' && c!='-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c== '-') ? -1:1;
    if(sawsign = (c == '+' || c=='-'))
        c = getch();
    if (!isdigit(c)) {
        ungetch(c);
        if (sawsign)
            ungetch((sign == -1) ? '-' : '+');
        return 0;
    }
    for (*pn=0; isdigit(c); c=getch())
        *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if(c!=EOF)
        ungetch(c);
    return c;
}

//5.2

int getfloat(float *pn)
{
    int c,sign;
    float power;

    while(isspace(c=getch()))
        ;

    if( !isdigit(c) && c!=EOF && c!= '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }

    sign = ( c == '-') ? -1: 1;

    if( c == '+' || c == '-')
        c = getch();

    for(*pn = 0.0 ; isdigit(c);c=getch())
        *pn = 10.0 * *pn + (c - '0');
    if( c == '.')
        c = getch();

    for(power=1.0;isdigit(c);c=getch())
    {
        *pn = 10.0 * *pn + (c - '0');   /* fractional part */
        power *= 10.0;
    }

    *pn  *= sign / power;

    if( c != EOF)
        ungetch(c);

    return c;
}

#define ALLOSIZE 10000
static char allocbuf[ALLOSIZE];
    //allocbuf points to the first element
static char *allocp = allocbuf;

char *alloc(int n)
{
    //allocbuf points to the first element
    if (allocbuf + ALLOSIZE - allocp >= n) {
        allocp += n;
        return allocp -n; //old p
    }else{
        return 0;
    }
}

void afree(char *p)
{
    if(p >= allocbuf && p < allocbuf + ALLOSIZE)
        allocp = p;
}

int strlen_pointer(char *s)
{
    char *p = s;
    while(*p!='\0')
        //p to the next character
        p++;
    return p-s;
}

void strcopy_pointer(char *s, char *t)
{
    while((*s++=*t++)!='\0')
        ;

}

void strcmp_pointer(char *s, char *t)
{
    for(; *s==*t; s++,t++)
        if(*s=='\0')
            return 0;
    return *s-*t;
}

void strcat_pointer(char *s, char *t)
{
    while (*s++ !='\0')
    while ((*s++ = *t++)!= '\0')
        ;
}

void strend_pointer(char *s, char *t)
{
    while(*s++ != '\0')

}

void strncpy_pointer(char *dest, char *source, int n)
{
    while(*source && n-- > 0)
        *dest++ = *source++;

    int extra = strlen_pointer(dest) - n;

    while (extra-- > 0) {
        *dest++;
    }

    *dest = '\0';
}

int strncmp_pointer(char *lhs,char *rhs, int n)
{
    for(; *lhs == *rhs; lhs++,rhs++)#define MAXLEN 1000 /* max length of any input line */
#define MAXSTOR 5000
        if( *lhs == '\0' || --n <=0)
            return 0;
    return *lhs - *rhs;

}

void strncat_pointer(char *str1, char *str2, char *dest, int n) {
    while(*str1) {
        *dest++ = *str1++;
    }

    while(n-- >0) {
        *dest++ = *str2++;
    }

    *dest = '\0';
}

void qsort(int *v, int left, int right)
{
    int i, *last;

    if (right <= left)
        return;
    last = v + left; //choosing the first element as the pivot
    for (i = left + 1; i <= right; i++)
        if (*(v + i) < *(v + left))
            swap(++last, v + i); //swapping the numbers < pivot
    swap(v + left, last);
    qsort(v, left, last - v - 1); //sub-array containing numbers < pivot
    qsort(v, last - v + 1, right); //sub-array containing numbers >= pivot
}

void swap_1(int *i, int *j)
{
    int temp;

    temp = *i;
    *i = *j;
    *j = temp;
}

int readlines(char *lineptr[],char *linestor,int maxlines)
{
    int len,nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines=0;

    while((len=mgetline(line,MAXLEN)) > 0)
        if(nlines >= maxlines || p+len > linestop)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
            p+=len;
        }
    return nlines;
}


//5.6 skip
