#include <stdio.h>

unsigned short int getNotation(char* argv[])
{
    // Find the top of 'i' in argv[1][i]
    int count = 0;
    for(int i = 0; argv[1][i] != 0; i++)
        count++;

    // Convert string to integer
    int step = 1;
    unsigned short int notation = 0; // remove trash
    for(int i = count - 1; i >= 0; i--)
    {
        notation += (argv[1][i] - 48) * step; // 48 is ASCII error; step is a digit of number

        step *= 10;
    }
    return notation;
}

void printNotation(unsigned short int notation, char* argv[])
{
    // Find the top of 'i' in argv[2][i]
    int count = 0;
    for(int i = 0; argv[2][i] != 0; i++)
        count++;

    // Convert string to integer
    int step = 1;
    unsigned int number = 0; // remove trash
    for(int i = count - 1; i >= 0; i--)
    {
        number += (argv[2][i] - 48) * step; // 48 is ASCII error; step is a digit of number
        step *= 10;
    }

    if(number < notation)
    {
        printf("x%d: ", notation);
        for(int i = 0; i < count; i++)
            printf("%c", argv[2][i]);
        printf("\n");
    }

    else // it's so bad that even my cat died
    {
        // Find count elements final number
        count = 0;
        unsigned int tmp = number;
        while(1 == 1) // infinity cycle
        {
            if(tmp / notation == 0) break;
            if(tmp / notation < notation)
            {
                count += 2;
                break;
            }
            count++;
            tmp /= notation;
        }

        // Find final number
        char result[count];
        tmp = number;
        for(int i = 0; i < count; i++)
        {
            if(tmp / notation == 0) break;
            else if(tmp / notation < notation)
            {
                if(tmp % notation > 9) result[count - 1 - i] = tmp % notation + 55; // 56 is a 48 and 8 ASCII errors
                else result[count - 1 - i] = tmp % notation + 48; // 48 is ASCII error
                if(tmp / notation > 9) result[count - 2 - i] = tmp / notation + 55;
                else result[count - 2 - i] = tmp / notation + 48;
                break;
            }
            if(tmp % notation > 9) result[count - 1 - i] = tmp % notation + 55;
            else result[count - 1 - i] = tmp % notation + 48;
            tmp /= notation;
        }

        // Print final number
        printf("x%d: ", notation);
        for(int i = 0; i < count; i++)
            printf("%c", result[i]);
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    unsigned short int notation;
    if(argc < 3)
    {
        printf("Use the: notation [notation] [dec_number]\n");
        return 0;
    }
    notation = getNotation(argv);
    if(notation > 1)
        printNotation(notation, argv);
    else
        printf("Notation must be greater than 1, you entered: %d\n", notation);
    return 0;
}
