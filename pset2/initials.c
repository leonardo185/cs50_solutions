#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    string s=get_string();
    char h[50];

    for(int i=0; i<strlen(s); i++)
    {
       if(s[i]==s[0])
       printf("%c",toupper(s[0]));
       if(s[i]==' '&&s[i]!='\0')
       {
           h[i]=s[i];
       }
    }
    printf("\n");
    for(int i=0; i<strlen(s);i++)
    {
    printf("%c",h[i]);
    }
}