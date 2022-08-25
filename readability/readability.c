#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void)
{
    string text = get_string("Text: ");
   //printf("%s\n", text);

    printf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
    printf("%i sentences\n", count_sentences(text));


    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int L = (letters / words) * 100;
    int S = (sentences / words) * 100;
    printf("%i\n",L);
    printf("%i\n",S);

    // Coleman-Liau index formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Grade Index
    if (index >= 16)
    {
        printf("Grade 16+ \n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1 \n");
    }
    else
        printf("Grade %i \n", index);
}

    // Count number of letters in text
    int count_letters(string text)
    {
        int letter_count = 0;
        for (int i = 0, len = strlen(text); i < len; i++)
        {
            //if(islower(text[i]) || isupper(text[i]))
            //if(isalpha(text[i]))

            if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
            {
                letter_count++;
            }
        }
        return letter_count;
    }

    // Count number of words in text
    int count_words(string text)
    {
        int word_count = 0;
         for (int i = 0, len = strlen(text); i < len; i++)
        {
            // We'll increment everytime we find a space (ie 32 in ASCII)
            if(text[i] == ' ')
            {
                word_count++;
            }
        }
        return word_count;
    }

    // Count number of sentences in text
    int count_sentences(string text)
    {
        int sentence_count = 0;
        for (int i = 0, len = strlen(text); i < len; i++)
        {
            // We'll increment whenever we find a .(46) !(33) ?(63)
            if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
                sentence_count++;
            }
        }
        return sentence_count;
    }

// #include <cs50.h>
// #include <stdio.h>
// #include <math.h>
// #include <string.h>

// // Functions
// int count_letters(string text);
// int count_words(string text);
// int count_sentences(string text);

// int main(void)
// {
//     string text = get_string("Text: ");
//     // printf("%s\n", text);

//     // printf("%i letters\n", count_letters(text));
//     // printf("%i words\n", count_words(text));
//     // printf("%i sentences\n", count_sentences(text));


//     int L = (count_letters(text) / count_words(text)) * 100;
//     int S = (count_sentences(text) / count_words(text)) * 100;

//     int index = round(0.0588 * (float)L - 0.296 * (float)S - 15.8);

//     if (index >= 16)
//     {
//         printf("Grade 16+ \n");
//     }
//     else if (index < 1)
//     {
//         printf("Before Grade 1 \n");
//     }
//     else
//         printf("Grade: %i \n", index);
// }

//     // Count number of letters in text
//     int count_letters(string text)
//     {
//         int letter_count = 0;
//         for (int i = 0, len = strlen(text); i < len; i++)
//         {
//             //if(islower(text[i]) || isupper(text[i]))
//             //if(isalpha(text[i]))

//             if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
//             {
//                 letter_count++;
//             }
//         }
//         return letter_count;
//     }

//     // Count number of words in text
//     int count_words(string text)
//     {
//         int word_count = 0;
//          for (int i = 0, len = strlen(text); i < len; i++)
//         {
//             // We'll increment everytime we find a space (ie 32 in ASCII)
//             if(text[i] == ' ')
//             {
//                 word_count++;
//             }
//         }
//         return word_count;
//     }

//     // Count number of sentences in text
//     int count_sentences(string text)
//     {
//         int sentence_count = 0;
//         for (int i = 0, len = strlen(text); i < len; i++)
//         {
//             // We'll increment whenever we find a .(46) !(33) ?(63)
//             if (text[i] == '.' || text[i] == '!' || text[i] == '?')
//             {
//                 sentence_count++;
//             }
//         }
//         return sentence_count;
//     }
