#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

long atoi_iterative(string number_text);

int main(int argc, string argv[])
{
    // Check if user inputs an argument
    if (argc != 2)
    {
        printf ("Usage: ./recursion_atoi <positive integer>\n");
        return 1;
    }

    string number_text = argv[1];

    int number = atoi_iterative(number_text);

    printf ("%i\n", number);
}

long atoi_iterative(string number_text)
{
    int sign = 1, i = 0;

    long num = 0;

    while(  number_text[i] == ' ' || 
            number_text[i] == '\n' || 
            number_text[i] == '\t')
    {
        i++;
    }

    if (number_text[i] == '-' || number_text[i] == '+')
    {
        if (number_text[i] == '-')
        {
            sign = -1;
        }

        i++;
    }

    while (number_text[i] != '\0' && (number_text[i] >= '0' && number_text[i] <= '9')) 
    {
        num = (num * 10) + (number_text[i] - '0');
        
        i++;
    }

    return num * sign;
}