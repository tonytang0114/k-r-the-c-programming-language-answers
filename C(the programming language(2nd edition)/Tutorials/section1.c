#include <stdio.h>
#include <stdlib.h>
#include "section1.h"

#define IN 1
#define OUT 0
#define MAXCHAR 128
#define MAXLINE 1000
#define LIMIT 80
#define TABLIM 4

void print_Farenheit_Celsius_table()
{
    float fahr, celsius;
    int lower, upper, step;
    char title[] = "Temperature conversion from Fahr to Celsius";

    lower =0;
    upper =300;
    step = 20;

    fahr = lower;
    printf("%s\n", title);
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}


void print_Celsius_Farenheit_table()
{
    float fahr, celsius;
    int lower, upper, step;
    char title[] = "Temperature conversion from Fahr to Celsius";

    lower =0;
    upper =300;
    step = 20;

    fahr = lower;
    printf("%s\n", title);
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%6.1f\t%3.0f\n", celsius, fahr);
        fahr = fahr + step;
    }
}

void copy_input_to_output()
{
    int c;
    while((c=getchar())!=EOF)
    {
        putchar(c);
    }
}

void count_char()
{
    long nc;
    nc = 0;
    //still in the loop
    while (getchar()!=EOF){
        ++nc;
    }
    printf("%ld\n", nc);
}

//1-8 finished
//1-9 Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank

void copy_input_to_output_removeblank()
{
    int c;
    int countblank;
    countblank=0;
    while((c=getchar())!=EOF)
    {
        if(c == ' ')
        {
            ++countblank;
        }
        else{
            if(countblank >= 1)
            {
                putchar(' ');
                countblank=0;
            }
            putchar(c);
        }
    }
}

void count_lines_words_characters()
{
    int c;
    int nl, nw, nc, state;
    state = OUT;

    nl = nw = nc =0;
    while((c=getchar())!= EOF) {
        ++nc;
        if(c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

//1-11 test the word count program
//Input including all types of characters

//1-12 Write a program that prints its input one word per line
void print_one_word_per_line()
{
    int c;
    while ((c=getchar())!= EOF)
    {
        putchar(c);
        printf("\n");
    }
}
//number of occurrences of digits, whitespace and other
void count_digit_whitespace_others()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i =0;i<10;++i)
    {
        ndigit[i]=0;
    }
    while ((c=getchar())!=EOF){
        if (c>= '0' && c<='9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digit =");
    for (i=0; i<10; ++i){
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

//1-13 Write a program to print a histogram of the lengths of words in its input
//It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging
void print_histogram_of_input()
{
    int c;
    while((c=getchar())!=EOF)
    {
        if(c == ' ' || c=='\n' || c=='\t')
            putchar('\n');
        else
            putchar('*');
    }
}

void print_histogram_of_frequency()
{
    int c,i,j;
    int character[MAXCHAR];

    for(i=0;i<128;i++)
    {
        character[i]=0;
    }
    while((c=getchar())!=EOF)
    {
        ++character[c];
    }
    for(i=0;i<MAXCHAR;i++)
    {
        for(j=0;j<character[i];++j)
        {
            putchar('*');
        }
        putchar('\n');
    }
}

int power(int base, int n)
{
    int i,p;
    p=1;
    for(i=1;i<=n;++i)
        p = p*base;
    return p;
}

//1-15
void conversion(float fahr, float celsius, int upper, int step)
{
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void print_longest_input_line()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max=0;
    while ((len = getline(line,MAXLINE))>0)
    {
        if(len>max)
        {
            max=len;
            copy(longest,line);
        }
    }
    if(max >0)
    {
        printf("%s", longest);
    }
}

int getline(char s[], int lim)
{
    int c, i;
    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i]=c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i=0;
    while ((to[i] = from[i])!= '\0')
    {
        ++i;
    }
}

//1-17 Write a program to print all input lines that are longer than 80 characters
void print_more_than_80()
{
    int len;
    char line[MAXLINE];

    while((len=getline(line,MAXLINE))>0)
    {
        if(len>LIMIT)
            printf("%s", line);
    }
}


//1-18 Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
//1.9
void remove_trailing_blanksandtab_and_lines()
{
    int c,len;
    char line[MAXLINE];

    while((c=getchar())!=EOF)
    {
        while((len=getline(line,MAXLINE))>0)
        {
            if(removetrail(line) > 0)
                printf("%s",line);
        }
    }
}

void removetrail(char s[])
{
    int i;
    for(i>0; s[i]!='\n';++i);
    --i;
    for(i>0; ((s[i]== ' ' ) || (s[i]=='\t'));--i)
    ;
    if(i>=0)
    {
        ++i;
        s[i]='\n';
        ++i;
        s[i]= '\0';
    }
    return i;
}

//1-19 Reverse(S) a line at a time
void reverse_org()
{
    char line[MAXLINE];
    reverse(line);
}
void reverse(char s[])
{
    int len;
    while((len=getline(s,MAXLINE))>0)
    {
        while(len-->0)
            putchar(s[len]);

        putchar('\0');
        printf("\n");
    }
}

//1-20 detab
// replace tabs in the input if proper number of blanks to space to the next tab stop

void detab()
{
    int c,i,n;
    n=0;
    while((c=getchar())!=EOF)
    {
        if(c=='\t')
        {
            for(i=n;i<TABLIM;i++)
                putchar(' ');
        }
        else{
            putchar(c);
            if(n==TABLIM)
                n=0;
            ++n;
        }
    }
}

void entab()
{
    int c = 0;
    int i = 0;
    int spaceCount = 0;
    while ( (c = getchar()) != EOF )
    {
        if (c == ' ')
        {
            ++spaceCount;
            if (spaceCount == TABLIM)
            {
                spaceCount = 0;
                putchar('\t');
            }
        }
        else
        {
            for (i = 0; i < spaceCount; ++i)
            {
                putchar(' ');
            }
            spaceCount = 0;
            putchar(c);
        }
    }
}

//1-22
void fold_lines()
{
    int c, len;
    const int MAXCHARS = 40;
    len = 0;

    while((c = getchar()) != EOF) {
        len++;
        /* add the appropriate number to len when a tab is encountered */
        if (c == '\t')
            /* subtract 1 b/c len was already incremented once */
            len = len + TABLIM - 1;
        if (len == MAXCHARS) {
            len = 0;
            putchar('\n');
        }
        else if (c == '\n')
            len = 0;
        putchar(c);
    }
}

//1-23 remove all comments in a C-Program
void remove_comments()
{
    char line[MAXLINE];
    int in_comment,len;
    int in_quote;
    int t;

    in_comment = in_quote = t =0;
    while((len = getline(line,MAXLINE))>0)
    {
        t=0;
        while(t<len)
        {
            if(line[t]=='"')
                in_quote=1;
            if(!in_quote)
            {
                if(line[t]=='/' && line[t+1]=='*')
                    t=t+2;
                    in_comment=1;
                if(line[t]=='*' && line[t+1]=='/')
                    t=t+2;
                    in_comment=0;
                if(in_comment==1)
                {
                    t++
                }else
                {
                    printf("%c", line[t]);
                    t++;
                }
            }
            else
            {
                printf("%c", line[t]);
                t++;
            }
        }
    }
}
//1-24
void determine_length()
{
    //2s complement
    printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

    printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

    printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

    /* Unsigned Maximum Values */

    printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n",(unsigned long)~0);
}
