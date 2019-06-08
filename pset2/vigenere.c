/******************************************************************************************************
 *                                         VIGENERE CYPHER                                                                                        *
 ******************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>



int main(int argc, string argv[])
{
    //declare values cyphering
   float keyvalue;
   int shift;

  // to run only if there is a second command line argument
  if(argc!=2)
  {//to check if the given command line argument is according to the progeam
      printf("usage: ./vigenere <key>");
      return 1;
  }
  else
  {
     //to capture second command line argument as a string
     string key=argv[1];

   //to check if all the leters in the key are alphabets
   for(int i=0; i<strlen(key); i++)
   {
       if(!isalpha(key[i]))
       {
           printf("\nyou should enter a key which only has alphabets and not special charecters!!!!!!");
           return 1;
       }
   }

   printf("plaintext:"); //this gets the plaintext from the user
   string plaintext=get_string();


   for(int i=0,j=0,length=strlen(plaintext); i<length;i++,j++)
   {
    if(j>=strlen(key)) //this is to set the limit of the key counter
    {
        j=0;
    }

    keyvalue=key[j]; //this is to set the value for the key


    if(!isalpha(plaintext[i]))  //this is to assign values for only the charecters and not the "SPACES"
    {
        j=j-1;
    }

    //makes A to 0 and Z to 25 for uppercase letters
    if((keyvalue >= 'A') && (keyvalue <= 'Z'))
    {
        keyvalue=(keyvalue-'A');
    }

    //makes A to 0 and Z to 25 for uppercase letters
    if((keyvalue>='a')&&(keyvalue<='z'))
    {

        keyvalue=(keyvalue-'a');

    }

    shift = plaintext[i]-keyvalue;//for encryption

    //this is for wrapping around uppercase letters greater than 'Z'
    if(isupper(plaintext[i]) && shift>'Z')
    {
        shift = (shift-26);
    }
    //this is for wrapping around lowercase letters greater than 'z'
    if(islower(plaintext[i]) && shift>'z')
    {
        shift = (shift-26);
    }

    //this is to print encyphered messages converted from alphabets
    if(isalpha(plaintext[i]))
    {
        printf("%c",shift);
    }

    //this is to print non-encypherable messages
    if(!isalpha(plaintext[i]))
    {
        printf("%c",plaintext[i]);
    }
   }
  }

   printf("\n");
   return 0;
}