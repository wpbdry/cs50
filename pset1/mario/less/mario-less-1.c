#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Sudo code
    //Take positive number x as input
    //Output x - 1 blank spaces and then 1 #
    //x -2 blank and then 2 #s
    //etc
    //until number of #s is x

    //Declare global var
    int h;

    //Print welcome message and ask user for input
    printf("Welcome to my pyramid printer (the dumb one)!\n");
    printf("Please enter the height of the pyramid below as a positive whole number no greater than 23.\n");
    do
    {
        h = get_int("Height: ");
    }
    while (h <= 1 || h > 23);

    //Print pyramid

    //Each row
    for (int n = 1; n <= h; n++)  // Initialize variable n to be the number of #s in a row, starting at 1, ending at h
    {
        //Print row

        //Print blank spaces (h - n). Pyramid has the same width as height
        for (int i = 0; i < h - n; i++)
        {
            printf(" ");
        }

        //Print #s
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }

        //Print new line
        printf("\n");
    }
}