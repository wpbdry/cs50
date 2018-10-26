#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int const max_char_count = 5;
string const characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int iterate(string current_parent_string, string original_hash, string salt)
//Returns 0 if found, 2 if not found, and 3 if max length is exceded
{
    int parent_string_length = strlen(current_parent_string);
    int current_try_length = parent_string_length + 2;
    int const characters_len = strlen(characters);

    if (current_try_length - 1 <= max_char_count)
    {
        //Create a string for the current try with one character more than its parent
        char current_try[current_try_length];
        for (int i = 0; i < parent_string_length; i++)
        {
            current_try[i] = current_parent_string[i];
        }
        current_try[current_try_length - 1] = '\0';

        //Go through all characters and call iterate function again.
        //If password is found, it will return 0, else 2.
        for (int i = 0; i < characters_len; i++)
        {
            //Set last character of current try
            current_try[parent_string_length] = characters[i];

            //Hash and check
            string new_hash = crypt(current_try, salt);
            if (strncmp(new_hash, original_hash, 13) == 0)
            {
                printf("%s\n", current_try);
                return 0;
            }

            //Iterate again, with current try as new parent, and if password is round, return 0
            if (iterate(current_try, original_hash, salt) == 0)
            {
                return 0;
            }
        }
        //Returns if password is not found in current iteration
        return 2;
    }
    return 3;
}

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //Put this in a seperate function when you understand pointers
        //Get hash and salt
        char salt[3];
        string const hash = argv[1];
        salt[0] = hash[0];
        salt[1] = hash[1];
        salt[2] = '\0';

        //Pass to iteration: current parent string, hash, salt
        if(iterate("", hash, salt) != 0)
        {
            //Print status if password not found. If password is found it is printed by the iterate function
            printf("Password not found in string with length of up to %i characters\nusing the character set \"%s\"\n",
            max_char_count, characters);
        }
        return 0;
    }
    else
    {
        printf("Error: please pass exactly 1 argument.");
        return 1;
    }

}