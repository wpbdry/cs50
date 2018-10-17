
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //Get credit card number as a string
    //Divvy it up into an array
    //Get first two digits to see if it's even valid
    //check array length, if even, start on first item, else start on second
    //Go though array, converting to int, and performing math

    //Get credit card number
    string ccn = get_string("\nHi. Please enter your credit card number below:\n");

    //Check type based on firts two numbers
    string type;
    //AmEx
    if (ccn[0] == '3' && (ccn[1] == '4' || ccn[1] == '7')) {
        type = "AMEX";
    }
    //Master
    else if (ccn[0] == '5' && ccn[1] >= '1' && ccn[1] <= '5') {
        type = "MASTERCARD";
    }
    //Visa
    else if (ccn[0] == '4') {
        type = "VISA";
    }
    else {
        type = "INVALID";
    }

    //Verify checksum
    int checksum = 0;
    for (int i = 0, l = strlen(ccn); i < l; i++) {

        //First check that it is a number, not something else
        if (!(ccn[i] >= '0' && ccn[i] <= '9')) {
            type = "INVALID";
            break;
        }

        //Multiply by 2 and add these digits to checksum if it's a digit where you have to do that
        if ((l - i) % 2 == 0) {
            int temp = (ccn[i] - '0') * 2;
            if (temp > 9) {
                temp = temp - 9;
            }
            checksum += temp;
        }

        //Otherwise just add it.
        else {
            checksum += (ccn[i] - '0');
        }
    }

    //Then check if the checksum is correct at the end
    if (checksum % 10 != 0) {
        type = "INVALID";
    }

    printf("%s\n", type);

    return 0;
}
