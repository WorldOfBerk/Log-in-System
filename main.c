#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct member{
    char fullName[100];
    char email[100];
    char username[50];
    char password[50];
    char phoneNumber[50];
};

void takeinput(char ch[100])
{
    fgets(ch, 100, stdin);
    ch[strlen(ch) - 1] = 0;
}

void createUsername(char email[100], char username[50])
{
    for(int i = 0; i < strlen(email); i++)
    {
        if(email[i] = '@')
        break;

        else
        username[i] = email[i];
    }
}

int main()
{
    int choice;

    printf("\n\t\t\t\t---------------Welcome to Log-in System---------------");
    printf("\nSelect one of the options>");
    printf("\n1) Sign-up");
    printf("\n2) Log-in");
    printf("\n3) Exit");

    printf("\n\nEnter your selection > ");
    scanf("%d", &choice);
    fgetc(stdin);

    return 0;
}