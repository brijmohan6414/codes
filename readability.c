#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string text = get_string("Text: ");
    //printf("%s\n", text);
    float cl = count_letters(text); //counting no. of letters.
    //printf("Letters: %i\n", cl);
    float cw = count_words(text); //counting no. of words.
    //printf("Words: %i\n", cw);
    float cs = count_sentences(text); //counting no. of words.
    //printf("Sentences: %i\n", cs);
    float L = (cl / cw) * 100, S = (cs / cw) * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}
int count_letters(string s)
{
    int countl = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (isalpha(s[i]))
        {
            countl++;
        }
    }
    return countl;
}
int count_words(string s)
{
    int countw = 0;
    for (int i = 0, l = strlen(s); i <= l; i++)
    {
        if (isspace(s[i]))
        {
            countw++;
        }
    }
    return ++countw;
}
int count_sentences(string s)
{
    int counts = 0;
    for (int i = 0, l = strlen(s); i <= l; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            counts++;
        }
    }
    return counts;
}