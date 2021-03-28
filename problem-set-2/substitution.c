#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


bool is_valid_key(string s);
bool alpha_sim(string t);
void encrypt(string plaintext, string ciphertext);
char mapping[26];

// Validate the key: check for length, for non-alphabetical characters, for repeated characters
int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }
    if(!is_valid_key(argv[1]))
    {
        printf("Key must only contain alphabetical characters\n");
        return 1;
    }
    if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if(!alpha_sim(argv[1])) // Write this function again
    {
        printf("Key must not contain repeated characters\n");
        return 1;
    }

    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        mapping[i] = tolower(argv[1][i]);
    }

    // Get plaintext
    string text = get_string("plaintext: ");

       // Encrypte
   int n = strlen(text);
   char ciphertext[n + 1];
   encrypt(text, ciphertext);

   // Get the ciphertext
   printf("ciphertext: %s\n", ciphertext);

   return 0;
}

bool is_valid_key(string s)
{
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool alpha_sim(string t)
{
int buf[26];
for(int i = 0; i < 26; i++)
{
    buf[i] = -1;
}
for(int j = 0; j < strlen(t); j++)
{
    char ch = t[j];
    if(buf[tolower(ch) - 'a'] != -1)
    {
        return false;
    }
    else
    {
    buf[tolower(ch) - 'a'] = 1;
    }
}
return true;
}

void encrypt(string plaintext, string ciphertext)
{
    int i = 0;
    for(int n = strlen(plaintext); i < n; i++)
    {
        char ch = plaintext[i];
        if(isalpha(ch))
        {
            // Encrypt
            char temp = tolower(ch);
            int pi = temp - 'a';
            char ci = mapping[pi];
            ciphertext[i] = islower(ch) ? ci : toupper(ci);
        }
        else
        {
            ciphertext[i] = ch;
        }
    }
     ciphertext[i] = '\0';
}
