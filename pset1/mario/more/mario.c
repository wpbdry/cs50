#include <stdio.h>
#include <cs50.h>

int main(void)
{

    //Declare global var
    int h;

    //Print welcome message and ask user for input
    printf("\nHi, welcome to my Mario double half pyramid printer!\n");
    printf("Please enter the height of the pyramid you would like below.\n");
    printf("Note: The height must be a positive whole number no greater than 23.\n");

    //Ask user for input
    h = get_int("Height: ");

    while (h < 0 || h > 23)
    {
        //Helpful messages to the user if she enters an invalid number
        if (h < 0)
        {
            printf("Please enter a positive number\n");
        }

        if (h > 23)
        {
            printf("Please enter a number smaller than 23\n");
        }

        //Ask user for input
        h = get_int("Height: ");
    }

    //Print pyramid

    //Each row
    for (int i = 0; i < h; i++)
    {
        //Print row

        //Print blank spaces (h - i - 1)
        for (int j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }

        //Print #s (i + 1)
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        //Print gap
        printf("  ");

        //Print #s (i + 1)
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        //Print new line
        printf("\n");
    }
}