#include <cs50.h>
#include <stdio.h>

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
}

int atoi(string number_text)
{
    
    return 0;
}

int power_of_ten(int exponent)
{
    if (exponent <= 0)
    {
        return 1;
    }

    return 10 * power_of_ten(exponent - 1); 
}