// Helper functions for music

#include <cs50.h>
#include <math.h>
#include "helpers.h"
#include <string.h>
#include <stdio.h>

// Converts a fraction formatted as "X/Y" to eighths
int duration(string fraction)
{
    int numerator = (int)fraction[0];
    int denominator = (int)fraction[2];
    int multiplier = 8 / denominator;
    numerator = numerator * multiplier;
    printf("%i", numerator);
    return numerator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //Get number of semitones from this note in the fourth octave to A4
    int semitones;
    if (note[0] == 'A')
    {
        semitones = 0;
    }
    if (note[0] == 'B')
    {
        semitones = 2;
    }
    if (note[0] == 'C')
    {
        semitones = -9;
    }
    if (note[0] == 'D')
    {
        semitones = -7;
    }
    if (note[0] == 'E')
    {
        semitones = -5;
    }
    if (note[0] == 'F')
    {
        semitones = -4;
    }
    if (note[0] == 'G')
    {
        semitones = -2;
    }

    //Accidentals
    int octave;
    if (note[1] == '#')
    {
        semitones ++;
        octave = note[2] - '0';
    }
    else if (note[1] == 'b')
    {
        semitones -= 1;
        octave = note[2] - '0';
    }
    else
    {
        octave = note[1] - '0';
    }

    //correct semitone according to actual octave
    octave = octave - 4;
    semitones += octave * 12;

    int frequency = round(pow(2.00, (float)semitones / 12.00) * 440);
    return frequency;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return (strcmp(s, ""));
}
