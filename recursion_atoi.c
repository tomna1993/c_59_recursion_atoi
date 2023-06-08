#include <cs50.h>
#include <stdio.h>

long atoi_iterative(string number_text);
long atoi_recursive(string number_text);
long atoi_recursive_call(string number_text, long number);
void shift_array_left(string text);

int main(int argc, string argv[])
{
    // Check if user inputs an argument
    if (argc != 2)
    {
        printf ("Usage: ./recursion_atoi <positive integer>\n");
        return 1;
    }

    string number_text = argv[1];

    printf ("Iterative atoi: %i\n", atoi_iterative(number_text));

    printf ("Recursive atoi: %i\n", atoi_recursive(number_text));
}

long atoi_iterative(string number_text)
{
    int sign = 1, i = 0;

    long num = 0;

    // Check any whitespace character and increment the index (i)
    while(  number_text[i] == ' ' || 
            number_text[i] == '\n' || 
            number_text[i] == '\t')
    {
        i++;
    }

    // Check for sign before number
    if (number_text[i] == '-' || number_text[i] == '+')
    {
        if (number_text[i] == '-')
        {
            sign = -1;
        }

        // Increment index - on this index a number should start
        i++;
    }

    // Iterate through the string array until end of array (NULL = '\0') or
    // any non digit character 
    while (number_text[i] != '\0' && (number_text[i] >= '0' && number_text[i] <= '9')) 
    {
        num = (num * 10) + (number_text[i] - '0');
        
        i++;
    }
    
    return num * sign;
}

long atoi_recursive(string number_text)
{
    int sign = 1, i = 0, j;

    while ( number_text[0] == ' ' || 
            number_text[0] == '\n' || 
            number_text[0] == '\t')
    {
        shift_array_left(number_text);
    }

    if (number_text[0] == '-' || number_text[0] == '+')
    {
        if (number_text[0] == '-')
        {
            sign = -1;
        }

        shift_array_left(number_text);
    }

    return atoi_recursive_call(number_text, 0) * sign;
}

long atoi_recursive_call(string number_text, long number)
{
     if (number_text[0] == '\0' || number_text[0] < '0' || number_text[0] > '9')
    {
        return number;
    }

    number = (number * 10) + (number_text[0] - '0');

    shift_array_left(number_text);

    return atoi_recursive_call(number_text, number);
}

void shift_array_left(string text)
{
    int j = 0;
    while (text[j] != '\0') 
    {
        text[j] = text[j + 1];
        j++;
    }
}