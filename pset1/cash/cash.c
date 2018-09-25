#include <stdio.h>
#include <cs50.h>
#include <math.h>

//int function(int n);

int main(void)
{
    /*
        SUDO CODE
        ask user for float
        make sure that it is not negative and does not have more than 2 decmial places

        Coins availabe: 0.25, 0.1, 0.05, 0.01

        create var coins
        add float % 25¢ to var
        add float % 10¢ to var
        etc
        output var
    */

    //Declare variables
    float changef; //Change in dollars as float
    int changei4; //Change in dollars with 4 decimal places
    int changei2; //Change in dollars with 2 decimal places

    //Ask user for input, until positive number with not more than 2 decimal places is received.
    do
    {
        changef = get_float("Change owed: ");

        //Round to 2 decimal places and convert to int
        changef = changef * 100;
        changei2 = (int)changef;

        //Round to 4 decimal places and convert to int
        changef = changef * 100;
        changei4 = (int)changef;
    }
    while (changef < 0                      //If change entered is negative
        || changei2 * 100 != changei4);     //Or if 2 dec and 4 dec rounding are not equal)

    //Convert change to integer
    int c = changei2;

    //Calculate n
    int n = 0; //Number of coins

    //temporary variable
    int t = c % 25;
    n += (c - t) / 25;
    c = t;

    t = c % 10;
    n += (c - t) / 10;
    c = t;

    t = c % 5;
    n += (c - t) / 5;
    c = t;

    t = c % 1;
    n += (c - t) / 1;
    c = t;

    //Print it

    printf("%i\n", n);
}
