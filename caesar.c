#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool check_digit(string s);

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        if (!check_digit(argv[1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]); //key
    //printf("Key: %i\n", k);
    string ptext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {
        if (islower(ptext[i])) //for lower cases
        {
            printf("%c", (96 + ((ptext[i] - 96) + k) % 26));
        }
        else if (isupper(ptext[i])) //for upper cases
        {
            printf("%c", (64 + ((ptext[i] - 64) + k) % 26));
        }
        else //for non-alphabetical
        {
            printf("%c", ptext[i]);
        }
    }
    printf("\n");
    return 0;

}
bool check_digit(string s)
{
    bool result = true;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i])) //checking for digit
        {
            result = false;
        }
    }
    return result;
}