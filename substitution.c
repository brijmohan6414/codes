#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool check_alpha(string s);
bool exactly_once(string s);

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        if (strlen(argv[1]) != 26) //checking for length as 26
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        if (!check_alpha(argv[1])) //checking all are alphabetic characters
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        if (!exactly_once(argv[1])) //checking if characters repeat
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // proceed when all ok with key --->

    string ptext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {
        if (islower(ptext[i])) //for lower cases
        {
            int position = ptext[i] % 97;
            if (isupper(argv[1][position]))
            {
                argv[1][position] += 32;
            }
            printf("%c", argv[1][position]);
        }
        else if (isupper(ptext[i])) //for upper cases
        {
            int position = ptext[i] % 65;
            if (islower(argv[1][position]))
            {
                argv[1][position] -= 32;
            }
            printf("%c", argv[1][position]);
        }
        else //for non-alphabetical
        {
            printf("%c", ptext[i]);
        }
    }
    printf("\n");
    return 0;

}
bool check_alpha(string s)
{
    bool result = true;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isalpha(s[i])) //checking for alphabetic
        {
            result = false;
        }
    }
    return result;
}
bool exactly_once(string s)
{
    bool result = true;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] == s[i])
            {
                result = false; // considering repeatation
            }
        }
    }
    return result;
}