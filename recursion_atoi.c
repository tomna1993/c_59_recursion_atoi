#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int atoi(string number_text);
int power_of_ten(int exponent);

int main(int argc, string argv[])
{
    // Check if user inputs an argument
    if (argc != 2)
    {
        printf ("Usage: ./recursion_atoi <positive integer>\n");
        return 1;
    }

    string number_text = argv[1];

    int number = atoi(number_text);

    printf ("%i\n", number);
}

int atoi(string number_text)
{
    int sum = 0;

    int length = strlen(number_text);
    int exponent = length - 1;

    for (int i = 0; i < length; i++) 
    {
        sum += (number_text[i] - 48) * power_of_ten(exponent--);   
    }

    return sum;
}

int power_of_ten(int exponent)
{
    if (exponent <= 0)
    {
        return 1;
    }

    return 10 * power_of_ten(exponent - 1); 
}