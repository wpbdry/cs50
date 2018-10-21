#define _XOPEN_SOURCE
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    string hash = crypt(argv[1], argv[2]);
    printf("%s\n", hash);
}