#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Make sure that user only entered one parameter, else throw error
    if (argc == 2)
    {
        //Program functioality
        int shift = strtol(argv[1], NULL, 10);
        //Throw error for non numerics
        if(shift == 0 && strcmp(argv[1], "0") != 0)
        {
            printf("Error: please pass a valid whole number.\n");
            return 1;
        }

        string input = get_string("plaintext: ");
        int l = strlen(input);
        char encr[l + 1];
        strcpy(encr, input);

        //go thorough each character
        for (int i=0; i<l; i++)
        {
            //Set zero offset depending on case
            int offset;
            if (isupper(input[i]))
            {
                offset = 65;
            }
            //Check for lowercase or lower case
             else if (islower(input[i]))
            {
                offset = 97;
            }
            //If not letter, leave character as it is and skip encrytion
            else
            {
                continue;
            }

            //Encrypt letters
            int base0 = input[i] - offset;
            base0 += shift;
            base0 = base0 % 26;
            char ascii = base0 + offset;
            encr[i] = ascii;
        }

        printf("ciphertext: %s\n", encr);
        return 0;
    }
    else
    {
        printf("Error: Please pass exaclty one parameter.\n");
        return 1;
    }
}
