#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Get String input
    string text = get_string("Input a string: ");

    // Initialisation
    int letters = 0;
    int words = 1;
    int sentence = 0;

    // TODO: Finding number of words,letters,sentences
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }

    // Initialising L and S
    float L = letters / (float) words * 100;
    float S = sentence / (float) words * 100;

    // Formulae
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Testing Grades
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}