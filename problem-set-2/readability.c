#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


    int count_letters(string text);
    int count_words(string text);
    int count_sentences(string text);

int main(void)
{
    // Prompt user to input text
    string text = get_string("Text: ");

    // Keep track of how many letters in a text
    int letters = count_letters(text);

    // Keep track of how many words in a text
    int words = count_words(text);

    // Keep track of how many sentences in a text
    int sentences = count_sentences(text);

    // L = is the average number of letters per 100 words in the text
    float L = (letters * 100.0) / words;
    // S = is the average number of sentences per 100 words in the text
    float S = (sentences * 100.0) / words;
    // Calculate index
        // index = 0.0588 * L - 0.296 * S - 15.8
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index < 1)
    {
         printf("Before Grade 1\n");
    }
    else if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text1)
{
    int letter = 0;
    for(int i = 0, n = strlen(text1); i < n; i++)
    {
        if(isalpha(text1[i]))
        {
            letter++;
        }
    }
    return letter;
}

int count_words(string text2)
{
    int word = 0;
    for(int j = 0, n = strlen(text2); j < n; j++)
    {
        if(isspace(text2[j]))
        {
            word++;
        }
    }
    word++;
    return word;
}

int count_sentences(string text3)
{
    int sentence = 0;
    for(int i = 0, n = strlen(text3); i < n; i++)
    {
        if(text3[i] == '?' || text3[i] == '!' || text3[i] == '.')
        {
            sentence++;
        }
    }
    return sentence;
}
