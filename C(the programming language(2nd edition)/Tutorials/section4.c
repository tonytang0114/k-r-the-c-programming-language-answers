#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <ctype.h>
#include "section3.h"
#define MAXSIZE 1000
#define MAXLINE 1000
#define MAXOP 100
#define NUMBER '0'
void itoa_2(int n, char s[]) {
    int i, sign;
    sign = n;

    i = 0;
    do {
    //n cannot be negative
        s[i++] = abs(n % 10) + '0';
    } while ( n /= 10 );
    //n
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int trim(char s[])
{
    int n;

    for (n=strlen(s)-1; n>=0; n--)
        if(s[n]!=' ' && s[n]!= '\t' && s[n] !='\n')
            break;
    s[n+1] = '\0';
    return n;
}

double atof_3(char s[])
{
    double val, power;
    int i, sign;

    for(i=0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 :1;
    if(s[i]== '+' || s[i]=='-')
        i++;
    for(power=1.0; isdigit(s[i]);i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val/power;
}
//Stack
#define MAXVAL 100
int sp=0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, can't push%g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;

    while((s[0] = c =getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';

    i=0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;
    if(c == '-')
        if(isdigit(c = getch()) || c=='.')
        s[++i]=c;
    else
    {
        if(c!=EOF)
            ungetch(c);
        return '-';
    }

    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
        ;
    if(c=='.')
        while(isdigit(s[++i]=c=getch()))
        ;
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

void clearsp(void)
{
    sp = 0;
}
//EX-4.3,4.4
void calculator()
{
    int type;
    double op2,op1;
    char s[MAXOP];

    while((type=getop(s))!=EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop()+pop());
            case '*':
                push(pop()*pop());
                break;
            case '-':
                op2 = pop();
                push(pop()-op2);
                break;
            case '/':
                op2 = pop();
                if(op2!=0.0)
                    push(pop()/op2);
                else
                    printf("error:zero divisor\n");
                break;
            case '%':
                op2=pop();
                if(op2!=0.0)
                    push(fmod(pop(),op2));
                else
                    printf("error, zero divisor\n");
                break;
            case '?':
                op2=pop();
                printf("\t%.8g\n",op2);
                push(op2);
                break;
            case 'c':
                clearsp();
                break;
            case 'd':
                op2=pop();
                push(op2);
                push(op2);
                break;
            case 's':
                op1=pop();
                op2=pop();
                push(op1);
                push(op2);
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }
}


void ungets(char s[])
{
    int i;

    i = strlen(s);


    while(i>0)
        ungetch(s[--i]);
}

//skip 4.7-4.11

void reverse_4(char s[])
{
    void reverser(char s[],int i,int len);

    reverser(s,0,strlen(s));
}

/* reverser: reverse string s in place; recursive */

void reverser(char s[],int i,int len)
{
    int c,j;

    j = len - (i + 1);

    if( i < j )
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;

        reverser(s,++i,len);
    }
}
void itoa_recur(int n,char s[])
{
    static int i;

    if(n/10)
        itoa_recur(n/10,s);
    else
    {
        i = 0;
        if( n < 0)
            s[i++]='-';
    }

    s[i++] = abs(n) % 10 + '0';

    s[i] = '\0';

}


