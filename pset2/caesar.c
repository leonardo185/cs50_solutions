 /*this is the prototype of hail ceaser */

#include <stdio.h>         //hearder files
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc,string argv[])//command line arguments
{

    string key = argv[1];

    if(argc!=2)//to know if the arguments provide are correct
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    else
    {
        int k =atoi(key)%26;// this is to convert a string to an integer

        printf("plaintext: ");
        string text = get_string();

        if(text != NULL)
        {
            int txt[strlen(text)];
            int c=0;
            int i;
            int n;
            printf("ciphertext: ");
            for( i = 0,n = strlen(text); i<n; i++)
            {

                if(isalpha(text[i]))
                {
                    if(isupper(text[i]))
                    {
                        c=(((int)text[i]-65+k)%26+65);
                        txt[i]=c;
                    }
                    else if(islower(text[i]))
                    {
                        c=(((int)text[i]-97 +k)%26+97);

                        txt[i]=c;
                    }
                 }
                 else
                 {
                    txt[i]=text[i];
                 }


            }

            for(i=0,n=strlen(text);i<n;i++)
            {
                printf("%c",txt[i]);
            }

            return 0;
        }
    }
}