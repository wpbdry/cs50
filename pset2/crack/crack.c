#define _XOPEN_SOURCE
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//Function to iterate through characters
void iterate(int current_it, int last_it, char current_parent[], int parent_length, string characters, string orig_hash, string salt)
{
    //If we haven't yet reached the max digit length
    if (current_it <= last_it)
    {
        //Make an array for the current try with one more space and copy the parent to it, leaving the last space blank
        char current_try[parent_length + 1];
        for (int i = 0; i < parent_length; i++)
        {
            current_try[i] = current_parent[i];
        }

        //Go through all characters and call the functino again
        for (int i = 0, l = strlen(characters); i < l; i++)
        {
            current_try[parent_length] = characters[i]; //current_try[parent_length] is the last position

            //Hash and check
             printf("%s, ", current_try);
            string new_hash = crypt(current_try, salt);
            if (new_hash == orig_hash)
            {

            }

            //Call the function again, with increased iteration number and the current try as parent
            iterate(current_it + 1, last_it, current_try, parent_length + 1, characters, orig_hash, salt);

        }
    }
}

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        //Program

        //Get hash and salt
        string hash = argv[1];
        char salt[3];
        salt[0] = hash[0];
        salt[1] = hash[1];
        salt[2] = '\0';

        //cycle through possibilities
        int const max_char_count = 3;
        string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int char_len = strlen(characters);
        iterate(1, max_char_count, "", 0, characters, hash, salt);

        return 0;
    }
    else
    {
        printf("Error: please pass exactly 1 argument.");
        return 1;
    }

}