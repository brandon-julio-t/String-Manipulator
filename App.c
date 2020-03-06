#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void getInputForStr();
void pause();

void printMenu();
int getInteger();
void reverseStr();
void uppercaseStr();
void substring();
void splitStr();

char str[30];

int main()
{
    getInputForStr();

    while (true)
    {
        switch (getInteger())
        {
        case 1:
            getInputForStr();
            break;

        case 2:
            reverseStr();
            break;

        case 3:
            uppercaseStr();
            break;

        case 4:
            printf("Length: %d\n", strlen(str));
            pause();
            break;

        case 5:
        {
            substring();
            break;
        }

        case 6:
            splitStr();
            break;

        case 7:
            return 0;
        }
    }
}

void getInputForStr()
{
    do
    {
        printf("Enter string [5-30 characters]: ");
        gets(str);
    } while (strlen(str) < 5 || strlen(str) > 30);
}

void pause()
{
    puts("Press ENTER to continue.");
    getchar();
}

void printMenu()
{
    puts("");
    printf("Current string: \"%s\"\n", str);
    puts("===============================");
    puts("");
    puts("String Manipulator");
    puts("===============================");
    puts("1. Input new string");
    puts("2. Reverse the string");
    puts("3. Transform string to uppercase");
    puts("4. Get the length of the string");
    puts("5. Get substring from the string");
    puts("6. Split the string word by word");
    puts("7. Exit");
}

int getInteger()
{
    int input = 0;

    do
    {
        printMenu();
        printf("> ");
        scanf("%d", &input);
        getchar(); // Removes \n from input buffer
    } while (input < 1 || input > 7);

    return input;
}

void reverseStr()
{
    int left = 0;
    int right = strlen(str) - 1;

    for (int i = 0; i < strlen(str) / 2; i++)
    {
        char leftChar = str[left];
        char rightChar = str[right];

        str[left] = rightChar;
        str[right] = leftChar;

        left++;
        right--;
    }
}

void uppercaseStr()
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
    }
}

void substring()
{
    char input[30];

    do
    {
        printf("Substring: ");
        gets(input);
    } while (strlen(input) > 30);

    printf(strstr(str, input) ? "%s found.\n" : "%s not found\n", input);
    pause();
}

void splitStr()
{
    char copy[30];
    strcpy(copy, str);

    char *words = strtok(copy, " ");

    for (int i = 1; words != NULL; i++, words = strtok(NULL, " "))
    {
        printf("Word #%d: %s\n", i, words);
    }

    pause();
}
