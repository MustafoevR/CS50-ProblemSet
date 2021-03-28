#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // use atoi to convert string into integer


bool is_valid_key(string s);
void encrypt(string plaintext, string ciphertext, int k);

int main(int argc, string argv[])
{
   if(argc != 2 || !is_valid_key(argv[1]))
   {
       printf("Usage: ./caesar key\n");
       return 1;
   }
   int key = atoi(argv[1]);
   // Get the plaintext
   string s = get_string("plaintext: ");

   // Encrypte
   int n = strlen(s);
   char ciphertext[n + 1];
   encrypt(s, ciphertext, key);

   // Get the ciphertext
   printf("ciphertext: %s\n", ciphertext);

   return 0;
}

bool is_valid_key(string s)
{
    for(int i = 0; i < strlen(s); i++)
    {
        if(!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

void encrypt(string plaintext, string ciphertext, int k)
{
    int i = 0;
    for(  ; i < strlen(plaintext); i++)
    {
        char ch = plaintext[i];
        if(isalpha(ch))
        {
            // Encrypt
            // ci = (pi + k) % 26
            char temp = tolower(ch);
            int pi = temp - 'a';
            int ci = ((pi + k) % 26) + 'a';
            ciphertext[i] = islower(ch) ? ci : toupper(ci);
        }
        else
        {
            ciphertext[i] = ch;
        }
    }
     ciphertext[i] = '\0';
}
