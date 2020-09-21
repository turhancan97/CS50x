#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string k = argv[1]; 
    int lenk = strlen(k);
    for (int i = 0;i<lenk;i++)
    {
        if(!isalpha(k[i]))
        {
            printf("Invalid Key\n");
            return 1;
        }
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, index = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char m = 'A';
            if(islower(c))
                m = 'a';
            printf("%c",(c-m + toupper(k[index])-'A') % 26 + m);
            index = (index + 1 ) % lenk;
        }
        else
            printf("%c",c);
    }
    printf("\n");

}
