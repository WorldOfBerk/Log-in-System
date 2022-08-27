#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13
#define TAB 9
#define BACKSPC 8

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

char createUsername(char email[100], char username[50])
{
    for(int i = 0; i < strlen(email); i++)
    {
        if(email[i] == '@')
        break;

        else
        username[i] = email[i];
    }
}

void takePassword(char pass[50])
{
    int i = 0;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch == ENTER || ch == TAB)
        {
            pass[i] = '\0';
            break;
        }
        else if(ch == BACKSPC)
        {
            if(i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pass[i++] = ch;
            printf("* \b");
        }
    }
}

int main()
{
    FILE *fp;
    int choice;
    struct member member;
    char passwordVerify[50];

    printf("\n\t\t\t\t---------------Welcome to Log-in System---------------");
    printf("\nSelect one of the options>");
    printf("\n1) Sign-up");
    printf("\n2) Log-in");
    printf("\n3) Exit");

    printf("\n\nEnter your selection > ");
    scanf("%d", &choice);
    fgetc(stdin);

    switch (choice)
    {
        case 1:
            printf("\nEnter your full name: ");
            takeinput(member.fullName);
            printf("Enter your email: ");
            takeinput(member.email);
            printf("Enter your phone number: ");
            takeinput(member.phoneNumber);
            printf("Enter your password: ");
            takePassword(member.password);
            printf("\nConfirm your password: ");
            takePassword(passwordVerify);

            if(!strcmp(member.password,passwordVerify))
            {
                createUsername(member.email, member.username);
                fp = fopen("Member.dat", "a+");
                fwrite(&member, sizeof(struct member), 1, fp);
                
                if(fwrite != 0)
                printf("\n\nUser registration successfully completed. Your user-name is: %s", member.username);
                
                else
                printf("\n\nFailed!");
            }
            else
            {
                printf("\n\nYour password didn't match!");
                Beep(750, 300);
            }
     }

    return 0;
}