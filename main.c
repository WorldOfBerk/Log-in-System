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
    int mmbrFound = 0;
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
                fclose(fp);
            }
            else
            {
                printf("\n\nYour password didn't match!");
                Beep(750, 300);
            }
        break;

        case 2:
            char username[50];
            char passWord[50];
            struct member mmbr;

            printf("\n Enter your username: ");
            takeinput(username);
            printf("\n Enter your password: ");
            takePassword(passWord);

            fp = fopen("Member.dat", "r");
            while(fread(&mmbr, sizeof(struct member), 1, fp));
                if(!strcmp(mmbr.username, username))
                {
                    if(!strcmp(mmbr.password, passWord))
                    {
                        printf("\n\t\t\t\tWelcome %s", mmbr.fullName);
                        printf("\n\n|Full Name: %s", mmbr.fullName);
                        printf("\n|Email: &s", mmbr.email);
                        printf("\n|User-Name: %s", mmbr.username);
                        printf("\n|Phone Number: %s", mmbr.phoneNumber);
                    }
                    else
                    {
                        printf("\n\nInvalid Password!");
                        Beep(750,300);
                    }
                    mmbrFound = 1;
                }
     

     if(!mmbrFound)
     {
        printf("\n\nThis user doesn't exist!");
        Beep(750, 300);
     }
     fcloese(fp);
     break;
    }
    
    return 0;
}