// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <conio.h>
// #include <windows.h>

// #define ENTER 13
// #define TAB 9
// #define BKSP 8
// #define SPACE 32
// #define ESC 27
// #define UP 72

// struct player
// {
//     char fullName[50];
//     char email[50];
//     char username[50];
//     char password[50];
//     char phone[50];
// };

// void takeinput(char ch[50])
// {
//     fflush(stdin);
//     fgets(ch, 50, stdin);
//     ch[strcspn(ch, "\n")] = 0; // Replaced strlen with strcspn to remove the trailing newline character
// }

// void generateUserName(char email[50], char username[50])
// {
//     int i = 0;
//     while (email[i] != '@')
//     {
//         username[i] = email[i];
//         i++;
//     }
//     username[i] = 0;
// }

// void takepassword(char pwd[50])
// {
//     fflush(stdin);
//     int i = 0;
//     char ch;
//     while (1)
//     {
//         ch = getch();
//         if (ch == ENTER || ch == TAB)
//         {
//             pwd[i] = '\0';
//             break;
//         }
//         else if (ch == BKSP)
//         {
//             if (i > 0)
//             {
//                 i--;
//                 printf("\b \b");
//             }
//         }
//         else if (ch == SPACE)
//         {
//             continue;
//         }
//         else
//         {
//             pwd[i] = ch;
//             i++;
//             printf("*");
//         }
//     }
//     printf("\n"); // Added newline character at the end of password input
// }

// int main()
// {
//     FILE *fp;
//     int opt;
//     struct player player;
//     char pwdConfirm[50];
//     printf("\n\t\t\tWELCOME TO THE LOGIN SYSTEM\n"); // Fixed a typo in welcome message
//     printf("\t\t\t============================\n\n");
//     printf("\nPlease choose your operation"); // Fixed a typo in message
//     printf("\n1. Signup \n2. Login \n3. Exit");
//     printf("\n\nYour Choice: \t");
//     scanf("%d", &opt);
//     fflush(stdin);

//     switch (opt)
//     {
//     case 1:
//         system("cls");
//         printf("\nEnter your full name: \t");
//         takeinput(player.fullName);
//         printf("Enter your email: \t");
//         takeinput(player.email);
//         printf("Enter your phone number: \t");
//         takeinput(player.phone);
//         printf("Enter your password: \t");
//         takepassword(player.password);
//         printf("\nConfirm your password: \t");
//         takepassword(pwdConfirm);
//         if (strcmp(player.password, pwdConfirm) == 0)
//         {
//             generateUserName(player.email, player.username);
//             printf("\nPassword Matched!\n");
//             printf("Your username is: %s\n", player.username);

//             // storing user info into a file Players.dat
//             fp = fopen("Players.dat", "a+");
//             if (fp == NULL)
//             {
//                 printf("Error opening file.\n");
//                 exit(1);
//             }
//             size_t written = fwrite(&player, sizeof(struct player), 1, fp);
//             if (written != 0)
//                 printf("Player Registered Successfully! Your username is: %s\n", player.username);
//             else
//                 printf("Sorry! Something went bad\n");
//             fclose(fp);
//         }
//         else
//         {
//             printf("\nPassword Does Not match\n");
//             Beep(500, 500);
//         }
//         break;
//     case 2:
//         char username[50], password[50];
//         struct player plyr;
//         printf("\nEnter your username: \t");
//         takeinput(username);
//         printf("Enter your password: \t");
//         takepassword(password);
//         fp = fopen("Players.dat", "rb"); // changed to "rb" to read in binary mode
//         if (fp == NULL)
//         {
//             printf("Error opening file.\n");
//             exit(1);
//         }
//         int loginSuccess = 0; // added a flag variable to keep track of login status
//         while (fread(&plyr, sizeof(struct player), 1, fp))
//         {
//             if (strcmp(plyr.username, username) == 0 && strcmp(plyr.password, password) == 0)
//             {
//                 system("cls");
//                 printf("\nLogin Successful!\n");
//                 printf("Welcome %s\n", plyr.fullName); // fixed variable name here
//                 loginSuccess = 1;                      // set flag to indicate successful login
//                 break;
//             }
//         }
//         fclose(fp);

//         if (!loginSuccess) // if flag is not set, login failed
//         {
//             Beep(800, 500);
//             printf("\nLogin Failed!\n");
//             printf("Username or Password is incorrect\n");
//         }
//         break;
//     case 3:
//         printf("Bye Bye! :)\n");
//         return 0;
//     default:
//         printf("Invalid option\n");
//         break;
//     }

//     return 0;
// }

#include <windows.h>

int main() {
    // Define the notes and their durations
    int c = 523;
    int d = 587;
    int e = 659;
    int f = 698;
    int g = 784;
    int gS = 830;
    int a = 880;
    int aS = 932;
    int b = 987;
    int cH = 1046;
    int noteDuration = 250;

    // Play the Super Mario Bros. theme
    Beep(e, noteDuration); // E
    Beep(e, noteDuration); // E
    Sleep(noteDuration);
    Beep(e, noteDuration); // E
    Sleep(noteDuration);
    Beep(c, noteDuration); // C
    Beep(e, noteDuration); // E
    Beep(g, noteDuration); // G
    Sleep(noteDuration);
    Beep(g, noteDuration); // G
    Sleep(noteDuration / 2);
    Beep(cH, noteDuration); // C high
    Sleep(noteDuration / 2);
    Beep(g, noteDuration); // G
    Sleep(noteDuration / 2);
    Beep(e, noteDuration); // E
    Sleep(noteDuration);
    Beep(a, noteDuration); // A
    Beep(b, noteDuration); // B
    Beep(aS, noteDuration); // A sharp
    Beep(a, noteDuration); // A
    Sleep(noteDuration / 2);
    Beep(g, noteDuration); // G
    Sleep(noteDuration / 2);
    Beep(e, noteDuration); // E
    Sleep(noteDuration);
    Beep(g, noteDuration); // G
    Beep(a, noteDuration); // A
    Beep(f, noteDuration); // F
    Beep(g, noteDuration); // G
    Sleep(noteDuration);
    Beep(e, noteDuration); // E
    Beep(c, noteDuration); // C
    Beep(d, noteDuration); // D
    Beep(b, noteDuration); // B
    Sleep(noteDuration / 2);
    Beep(c, noteDuration); // C
    Beep(g, noteDuration); // G
    Beep(f, noteDuration); // F
    Beep(e, noteDuration); // E
    Sleep(noteDuration);
    Beep(c, noteDuration); // C
    Beep(d, noteDuration); // D
    Beep(b, noteDuration); // B
    Beep(cH, noteDuration); // C high
    Sleep(noteDuration);
    Beep(g, noteDuration); // G
    Beep(a, noteDuration); // A
    Beep(f, noteDuration); // F
    Beep(g, noteDuration); // G
    Sleep(noteDuration);
    Beep(e, noteDuration); // E
    Beep(c, noteDuration); // C
    Beep(d, noteDuration); // D
    Beep(b, noteDuration); // B
    Sleep(noteDuration / 2);
    Beep(c, noteDuration); // C
    Beep(g, noteDuration); // G
    Beep(f, noteDuration); // F
    Beep(e, noteDuration); // E
    Sleep(noteDuration);
    Beep(c, noteDuration); // C
    Beep(d, noteDuration); // D
    Beep(b, noteDuration); // B
    Beep(cH, noteDuration); // C high
Sleep(noteDuration);
Beep(g, noteDuration); // G
Beep(a, noteDuration); // A
Beep(f, noteDuration); // F
Beep(g, noteDuration); // G
Sleep(noteDuration);
Beep(e, noteDuration); // E
Beep(c, noteDuration); // C
Beep(d, noteDuration); // D
Beep(b, noteDuration); // B
Sleep(noteDuration / 2);
Beep(e, noteDuration); // E
Sleep(noteDuration);
Beep(e, noteDuration); // E
Sleep(noteDuration);
Beep(e, noteDuration); // E
Sleep(noteDuration);
Beep(c, noteDuration); // C
Beep(e, noteDuration); // E
Beep(g, noteDuration); // G
Sleep(noteDuration);
Beep(g, noteDuration); // G
Sleep(noteDuration / 2);
Beep(cH, noteDuration); // C high
Sleep(noteDuration / 2);
Beep(g, noteDuration); // G
Sleep(noteDuration / 2);
Beep(e, noteDuration); // E
Sleep(noteDuration);
Beep(a, noteDuration); // A
Beep(b, noteDuration); // B
Beep(aS, noteDuration); // A sharp
Beep(a, noteDuration); // A
Sleep(noteDuration / 2);
Beep(g, noteDuration); // G
Sleep(noteDuration / 2);
Beep(e, noteDuration); // E
Sleep(noteDuration);
Beep(g, noteDuration); // G
Beep(a, noteDuration); // A
Beep(f, noteDuration); // F
Beep(g, noteDuration); // G
Sleep(noteDuration);
Beep(e, noteDuration); // E
Beep(c, noteDuration); // C
Beep(d, noteDuration); // D
Beep(b, noteDuration); // B
Sleep(noteDuration / 2);
Beep(c, noteDuration); // C
Beep(g, noteDuration); // G
Beep(f, noteDuration); // F
Beep(e, noteDuration); // E
Sleep(noteDuration);
Beep(c, noteDuration); // C
Beep(d, noteDuration); // D
Beep(b, noteDuration); // B
Beep(cH, noteDuration); // C high
Sleep(noteDuration);
Beep(g, noteDuration); // G
Beep(a, noteDuration); // A
Beep(f, noteDuration); // F
Beep(g, noteDuration); // G
Sleep(noteDuration);
Beep(e, noteDuration); // E
Beep(c, noteDuration); // C
Beep(d, noteDuration); // D
Beep(b, noteDuration); // B
Sleep(noteDuration / 2);
Beep(c, noteDuration); // C
Beep(g, noteDuration); // G
Beep(f, noteDuration); // F
Beep(e, noteDuration); // E
Sleep(noteDuration);
Beep(c, noteDuration); // C
Beep(d, noteDuration); // D
Beep(b, noteDuration); // B
Beep(cH, noteDuration); // C high

// Second section
Sleep(noteDuration);
Beep(gS, noteDuration); // G sharp
Beep(aS, noteDuration); // A sharp
Beep(cH, noteDuration); // C high
Sleep(noteDuration);
Beep(aS, noteDuration); // A sharp
Beep(cH, noteDuration); // C high
Beep(dH, noteDuration); // D high
Beep(dHS, noteDuration); // D high sharp
Beep(eH, noteDuration); // E high
Sleep(noteDuration);
Beep(cHS, noteDuration); // C high sharp
Beep(eH, noteDuration); // E high
Beep(fH, noteDuration); // F high
Beep(fHS, noteDuration); // F high sharp
Beep(fH, noteDuration); // F high
Beep(gH, noteDuration); // G high
Sleep(noteDuration / 2);
Beep(aS, noteDuration); // A sharp
Beep(f, noteDuration); // F
Beep(g, noteDuration); // G
Beep(aS, noteDuration); // A sharp
Beep(cH, noteDuration); // C high
Sleep(noteDuration);
Beep(aS, noteDuration); // A sharp
Beep(cH, noteDuration); // C high
Beep(dH, noteDuration); // D high
Beep(dHS, noteDuration); // D high sharp
Beep(eH, noteDuration); // E high
Sleep(noteDuration);
Beep(cHS, noteDuration); // C high sharp
Beep(eH, noteDuration); // E high
Beep(fH, noteDuration); // F high
Beep(fHS, noteDuration); // F high sharp
Beep(fH, noteDuration); // F high
Beep(gH, noteDuration); // G high
Sleep(noteDuration / 2);
Beep(aS, noteDuration); // A sharp
Beep(f, noteDuration); // F
Beep(g, noteDuration); // G
Beep(aS, noteDuration); // A sharp
Beep(cH, noteDuration); // C high
Sleep(noteDuration);
Beep(aS, noteDuration); // A sharp
Beep(cH, noteDuration); // C high
Beep(dH, noteDuration); // D high
Beep(dHS, noteDuration); // D high sharp
Beep(eH, noteDuration); // E high
Sleep(noteDuration);
Beep(cHS, noteDuration); // C high sharp
Beep(eH, noteDuration); // E high
Beep(fH, noteDuration); // F high
Beep(fHS, noteDuration); // F high sharp
Beep(fH, noteDuration); // F high
Beep(gH, noteDuration); // G high

return 0;

}