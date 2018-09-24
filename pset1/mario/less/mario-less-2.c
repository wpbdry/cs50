#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Sudo code
    //Take positive number x as input
    //Pyramid must start with 2 #s, and must have x lines, therefore last line must have x + 1 #s
    //Output x - 1 blank spaces and then 2 #s
    //x - 2 blank and then 3 #s
    //x - 3 blank then 4 #s
    //etc
    //until number of #s is x + 1 (or number of blanks is 0)

    //Declare global var
    int h;

    //Print welcome message and ask user for input
    printf("\nHi, welcome to my Mario half pyramid printer!\n");
    printf("Please enter the height of the pyramid you would like below.\n");
    printf("Note: The height must be a positive whole number no greater than 23.\n");

    //Ask user for input
    h = get_int("Height: ");

    while (h <= 1 || h > 23)
    {
        //Helpful messages to the user if she enters an invalid number
        if (h <= 1)
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
    printf("\n");

    //Each row
    for (int i = 0; i < h; i++)
    {
        //Print row

        //Print blank spaces (h - i - 1)
        for (int j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }

        //Print #s (i + 2)
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }

        //Print new line
        printf("\n");
    }

    //Print new line at the end to make things look cleaner
    printf("\n");
}