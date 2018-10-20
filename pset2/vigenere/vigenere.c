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

        //Get key as array of integers
        string input = argv[1];
        int kl = strlen(input);
        int key[kl];
        for (int i = 0; i < kl; i++)
        {
            if (isupper(input[i]))
            {
                key[i] = input[i] - 65;
            }
            else if (islower(input[i]))
            {
                key[i] = input[i] - 97;
            }
            else
            {
                printf("Error: Please enter a key containing only alpha characters.\n");
                return 1;
            }
        }

        //Get plaintext from user and create arr for encrypted text
        string plaintext = get_string("plaintext: ");
        int pl = strlen(plaintext);
        char encr[pl];
        strcpy(encr, plaintext);

        //go through each character
        int k = 0; //counter for key
        for (int i = 0; i < pl; i++)
        {
            //Set zero offset depending on case
            int offset;
            if (isupper(plaintext[i]))
            {
                offset = 65;
            }
            //Check for lowercase or lower case
            else if (islower(plaintext[i]))
            {
                offset = 97;
            }
            //If not letter, leave character as it is and skip encrytion
            else
            {
                continue;
            }

            //Get shift
            int shift = key[k];
            k ++;
            //Make k cycle if it reaches the end
            if (k == kl)
            {
                k = 0;
            }

            //Encrypt letters
            int base0 = plaintext[i] - offset;
            base0 += shift;
            base0 = base0 % 26;
            char ascii = base0 + offset;
            encr[i] = ascii;
        }

        //Print result
        printf("ciphertext: %s\n", encr);
        return 0;
    }
    else
    {
        printf("Error: Please pass exaclty one parameter.\n");
        return 1;
    }
}
