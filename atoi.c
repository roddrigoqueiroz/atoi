#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LENGHT 12 // The max_lenght of a int in C is 10 digits, but if i
                  // want to deal with negative numbers, i have to give one more
                  // byte to the string + the '\0'

int main(void)
{
    char *string = malloc (sizeof(char) * LENGHT);
    char *tmp = string;
    if (string == NULL)
    {
        printf("Something went wrong. Stopping program\n");
        return 2;
    }

    printf("Type a number to be converted: ");
    scanf("%s", string);

    int flag = 0; // Indicates that the number is positive
    if (string[0] == '-')
    {
        string = &string[1];
        flag = 1;
    }

    int digit[LENGHT];
    int final_number = 0;
    int i, n;
    for (i = 0, n = strlen(string); i < n; i++)
    {
        // Make sure the user typed a valid string
        if (string[i] < '0' || string[i] > '9')
        {
            printf("You didn't type a number. Quitting program...\n");
            return 1;
        }

        const int MULT_FACTOR = i + 1;

        // Identifies the char value corresponding to the digit being "int-lized"
        if (string[i] == '0') digit[i] = 0;
        else if (string[i] == '1') digit[i] = 1 * (int)(pow(10, n - MULT_FACTOR));
        else if (string[i] == '2') digit[i] = 2 * (int)(pow(10, n - MULT_FACTOR));
        else if (string[i] == '3') digit[i] = 3 * (int)(pow(10, n - MULT_FACTOR));
        else if (string[i] == '4') digit[i] = 4 * (int)(pow(10, n - MULT_FACTOR));
        else if (string[i] == '5') digit[i] = 5 * (int)(pow(10, n - MULT_FACTOR));
        else if (string[i] == '6') digit[i] = 6 * (int)(pow(10, n - MULT_FACTOR));
        else if (string[i] == '7') digit[i] = 7 * (int)(pow(10, n - MULT_FACTOR));
        else if (string[i] == '8') digit[i] = 8 * (int)(pow(10, n - MULT_FACTOR));
        else if (string[i] == '9') digit[i] = 9 * (int)(pow(10, n - MULT_FACTOR));

        final_number += digit[i];
    }

    if (flag == 1)
    {
        final_number *= -1;
        string = tmp;
    }

    printf("Number converted to int: %d\n", final_number);
    free(string);
    return final_number;
}