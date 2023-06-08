#include <cs50.h>
#include <stdio.h>

#define null '\0'

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

    printf ("Recursive atoi: %i\n", atoi_recursive(number_text));

    printf ("Iterative atoi: %i\n", atoi_iterative(number_text));
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
    while (number_text[i] != null && (number_text[i] >= '0' && number_text[i] <= '9')) 
    {
        num = (num * 10) + (number_text[i] - '0');
        
        i++;
    }

    return num * sign;
}

long atoi_recursive(string number_text)
{
    // Arrays are passed by reference, so it is important to
    // move the original string array's content to a locally used buffer
    char buffer[30];

    int sign = 1, i = 0;

    // Copy the original array to buffer
    while (number_text[i] != null) 
    {
        buffer[i] = number_text[i];
        i++;
    }
    buffer[i] = null;

    i = 0;

    // Check any whitespace character, shift array left by one index if found 
    while ( buffer[0] == ' ' || 
            buffer[0] == '\n' || 
            buffer[0] == '\t')
    {
        shift_array_left(buffer);
    }

    // Check for sign before number
    if (buffer[0] == '-' || buffer[0] == '+')
    {
        if (buffer[0] == '-')
        {
            sign = -1;
        }

        shift_array_left(buffer);
    }

    // Convert text to number
    return atoi_recursive_call(buffer, 0) * sign;
}

// Recursive solution to convert text to number
long atoi_recursive_call(string number_text, long number)
{
    // Base-case, exit condition from recursion
    if (number_text[0] == null || number_text[0] < '0' || number_text[0] > '9')
    {
        return number;
    }

    number = (number * 10) + (number_text[0] - '0');

    // Exclude the already converted digit from the string array
    shift_array_left(number_text);

    return atoi_recursive_call(number_text, number);
}

// Shift array to left by one index
void shift_array_left(string text)
{
    int j = 0;
    while (text[j] != null) 
    {
        text[j] = text[j + 1];
        j++;
    }
}