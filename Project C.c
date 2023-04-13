#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
////////////////////////////////////////////////////
#define ENTER 13 ///*
#define TAB 9    ///*
#define BKSP 8   ///*
#define SPACE 32 ///*
#define ESC 27   ///*
#define UP 72    ///*
///////////////////////////////////////////////////
#define BUFFER_SIZE 4096
/*GLOBAL LOGIN VARIABLE*/
int loggedIn = 0;
/*GLOBAL LOGIN VARIABLE*/
void printStar(int number);
void arrayMemAlloc(char **strings, int total, char *print1);
void printString(char *string, int number, int star);
void gameEngine();
void clearScreen();
void homeScreen(int *opt);
char *date(char *dateStr);
/********************************************************************
 * PLAYER AUTHENTICATION SYSTEM                                     *
 *********************************************************************/
struct player
{
    char fullName[50];
    char email[50];
    char username[50];
    char password[50];
    char phone[50];
};
struct player plyr;
void takeinput(char ch[50])
{
    fflush(stdin);
    fgets(ch, 50, stdin);
    ch[strcspn(ch, "\n")] = 0; // Replaced strlen with strcspn to remove the trailing newline character
}

void generateUserName(char email[50], char username[50])
{
    int i = 0;
    while (email[i] != '@')
    {
        username[i] = email[i];
        i++;
    }
    username[i] = 0;
}

void takepassword(char pwd[50])
{
    fflush(stdin);
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == BKSP)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == SPACE)
        {
            continue;
        }
        else
        {
            pwd[i] = ch;
            i++;
            printf("*");
        }
    }
    printf("\n"); // Added newline character at the end of password input
}

int authenticator()
{
    FILE *fp;
    int opt;
    struct player player;
    char pwdConfirm[50];
    homeScreen(&opt);

    switch (opt)
    {
    case 1:
        system("cls");
        printf("\nEnter your full name: \t");
        takeinput(player.fullName);
        printf("Enter your email: \t");
        takeinput(player.email);
        printf("Enter your phone number: \t");
        takeinput(player.phone);
        printf("Enter your password: \t");
        takepassword(player.password);
        printf("\nConfirm your password: \t");
        takepassword(pwdConfirm);
        if (strcmp(player.password, pwdConfirm) == 0)
        {
            generateUserName(player.email, player.username);
            printf("\nPassword Matched!\n");
            printf("Your username is: %s\n", player.username);

            // storing user info into a file Players.dat
            fp = fopen("Players.dat", "ab");
            if (fp == NULL)
            {
                printf("Error opening file.\n");
                exit(1);
            }
            size_t written = fwrite(&player, sizeof(struct player), 1, fp);
            if (written != 0)
                printf("Player Registered Successfully! Your username is: %s\n", player.username);
            else
                printf("Sorry! Something went bad\n");
            fclose(fp);
        }
        else
        {
            printf("\nPassword Does Not match\n");
            Beep(500, 500);
        }
        break;
    case 2:
        char username[50], password[50];
        printf("\nEnter your username: \t");
        takeinput(username);
        printf("Enter your password: \t");
        takepassword(password);
        fp = fopen("Players.dat", "rb"); // changed to "rb" to read in binary mode
        if (fp == NULL)
        {
            printf("Error opening file.\n");
            exit(1);
        }
        int loginSuccess = 0; // added a flag variable to keep track of login status
        while (fread(&plyr, sizeof(struct player), 1, fp))
        {
            if (strcmp(plyr.username, username) == 0 && strcmp(plyr.password, password) == 0)
            {
                system("cls");
                printf("\nLogin Successful!\n");
                printf("\t\t\t\t--------------------Welcome %s--------------------\n\n", plyr.fullName); // fixed variable name here
                loginSuccess = 1;                                                                        // set flag to indicate successful login
                loggedIn = 1;
                break;
            }
        }
        fclose(fp);

        if (!loginSuccess) // if flag is not set, login failed
        {
            Beep(800, 500);
            printf("\nLogin Failed!\n");
            printf("Username or Password is incorrect\n");
        }
        break;
    case 3:
        printf("Bye Bye! :)\n");
        loggedIn = 2;
        return 0;
    default:
        printf("Invalid option\n");
        break;
    }
    return 0;
}

/********************************************************************
 * END OF PLAYER AUTHENTICATION SYSTEM                                     *
 *********************************************************************/

int main()
{
    do
    {
        authenticator();
    } while (loggedIn == 0);

    if (loggedIn == 1)
    {
        // Asking the user if they want to load previous stories
        char loadStory[] = "Do you want to load a previous story? (Y/N): ";
        printString(loadStory, 10000000, 0);
        char load;
        scanf("%c", &load);
        fflush(stdin);

        if (load == 'Y' || load == 'y')
        {
            // Loading the previous stories
            loadStories();
        }
        else if (load == 'N' || load == 'n')
        {
            // Calling the game engine
            gameEngine();
        }
    }
    else if (loggedIn == 0)
    {
        char notLoggedIn[] = "You are not logged in. Please login to play the game.\n";
        printString(notLoggedIn, 10000000, 1);
    }

    return 0;
}

void gameEngine()
{
    // Displaying the welcome message

    char welcome[] = "\nWelcome to The Story Game, Enjoy Playing!\n";
    printString(welcome, 10000000, 1);

    // Taking in the number of players involved in the game
    printf("\n\n\n");
    char playerNumMsg[] = "Please enter the number of players: ";
    printString(playerNumMsg, 10000000, 0);
    int numOfPlayers, rounds;
    scanf("%d", &numOfPlayers);
    fflush(stdin);

    printf("\n\n");

    // Requesting for the number of rounds they wish to play
    while (numOfPlayers < 2)
    {
        // If the number of players is less than 2, Display warning message
        char warningMsg[] = "Sorry, number of players must be greater than 1. Enter a number greater than 1: ";
        ;
        printString(warningMsg, 10000000, 0);

        // Taking in the number of players again
        scanf("%d", &numOfPlayers);
        fflush(stdin);
        if (numOfPlayers > 1)
        {
            char successMsg[] = "\nGreat, The game is a multiplayer game, you are now ready to play!\n";
            printString(successMsg, 10000000, 0);
            printf("\n");
        }
    }
    if (numOfPlayers > 1)
    {
        struct stories
        { // struct to store the story
            char *title;
            char *date;
            char **playerNames;
            char **storyLines;
        };

        struct stories story;

        // Allocating memory for pointers to individual playernames in string array
        story.playerNames = (char **)malloc(numOfPlayers * sizeof(char *));
        arrayMemAlloc(story.playerNames, numOfPlayers, "Enter name of player");
        printf("\n");
        char listOfPlayerNames[] = "The list of players playing are: \n";
        printString(listOfPlayerNames, 10000000, 1);
        for (int i = 0; i < numOfPlayers; i++)
        {
            printf("Player %d is %s\n", i + 1, story.playerNames[i]);
        }

        printf("\n");
        printStar(5);
        printf("\nInteresting you are %d players involved\n\n\n How many rounds would you like to go: ", numOfPlayers);

        scanf("%d", &rounds);
        fflush(stdin);
        printf("\n");

        story.storyLines = (char **)malloc(numOfPlayers * rounds * sizeof(char *));

        printf("Ok then %d Rounds you'll go", rounds);
        printf("\n");
        printStar(5);

        /**************************************
         * PRINTING OUT INSTRUCTIONS          *
         ***************************************/
        printStar(5);
        clearScreen();
        char instructionsMsg[] = "*       BELOW ARE THE GAME INSTRUCTIONS:         *\n";
        printString(instructionsMsg, 10000000, 0);
        printf("*1.  The %d of you are to generate a story        *\n", numOfPlayers);
        printf("*2.  So %s will start by producing the first*\n*    line of the story                           *\n", story.playerNames[0]);
        printf("*3.  Then %s will produce the second line *\n*    of the story and so on                      *\n", story.playerNames[1]);
        printf("*4.  The %d of you will continue to produce the   *\n*    story until the %d round is reached          *\n", numOfPlayers, rounds);
        printf("*5.  The story you produce should be in sync for *\n*     example                                       *\n*     %s: Once upon a time, there lived a man\n*     %s: He was a good man so kind and nice.\n*    so you'll continue untill you finish the story at the last round*\n", story.playerNames[0], story.playerNames[1]);
        printf("*5.  The story you collectively produced would be*\n*     stored and printed out for you                *\n");
        printf("*6.  Enjoy and have fun Creating stories!        *\n");
        printStar(5);
        int round = 0;
        while (round < rounds)
        {
            printf("\n");
            printStar(5);
            printf("\n* Round %d                                        *\n", round + 1);
            if ((round + 1) == rounds)
            {
                char alert[] = "\n* ALERT! ALERT! This is the Last Round! Work     *\n* towards concluding your Story                  *\n";
                printString(alert, 10000000, 0);
            }
            printStar(5);
            printf("\n");

            int start = round * numOfPlayers;
            int end = (round + 1) * numOfPlayers;
            int index = 0;
            for (int i = start; i < end; i++)
            {

                if (i < numOfPlayers)
                {
                    index = i;
                }
                else
                {
                    index = i % numOfPlayers;
                }

                char buffer[BUFFER_SIZE];
                int length = 0;
                printf("Your turn %s : ", story.playerNames[index]);
                gets(buffer);
                length = strlen(buffer);
                story.storyLines[i] = (char *)malloc(length * sizeof(char));
                strcpy(story.storyLines[i], buffer);
            }
            round++;
        }
        clearScreen();

        // Printing out the story
        char storyDisp[] = "The story you produced is: \n";
        printString(storyDisp, 10000000, 1);
        for (int i = 0; i < (numOfPlayers * rounds); i++)
        {
            printf("%s\n", story.storyLines[i]);
        }

        printf("\n");

        // Asking if they want to save the story
        char saveStory[] = "Do you want to save the story? (y/n): ";
        printString(saveStory, 10000000, 0);
        char save;
        scanf("%c", &save);
        fflush(stdin);
        if (save == 'y' || save == 'Y')
        {
            // Asking for story title
            char storyTitle[] = "Enter the title of the story: ";
            printString(storyTitle, 10000000, 0);
            char title[BUFFER_SIZE];
            gets(title);
            story.title = (char *)malloc(strlen(title) * sizeof(char));
            strcpy(story.title, title);
            printf("\n");
            // Entering the date
            char dateStr[11];
            story.date = (char *)malloc(strlen(date(dateStr)) * sizeof(char));
            strcpy(story.date, date(dateStr));
            FILE *fp;
            fp = fopen("C:\\Users\\LAPTOP\\OneDrive\\Desktop\\C Programming 2023 L200\\PlayerData\\stories.dat", "ab");
            if (fp == NULL)
            {
                printf("Error opening file.\n");
                exit(1);
            }
            size_t written = fwrite(&story, sizeof(struct stories), 1, fp);
            if (written != 0)
                printf("Story saved Successfully! on: %s\n", date(dateStr));
            else
                printf("Sorry! Something went bad\n");
            fclose(fp);
        }
        else
        {
            char notSaved[] = "Ok then, you can always save it later\n";
            printString(notSaved, 10000000, 1);
        }

        char end[] = "THE END WE HOPE YOU ENJOYED THE GAME!\n";
        printString(end, 10000000, 1);

        // Asking if they want to play again
        char playAgain[] = "Do you want to play again? (y/n): ";
        printString(playAgain, 10000000, 0);
        char play;
        scanf("%c", &play);
        fflush(stdin);
        if (play == 'y' || play == 'Y')
        {
            gameEngine();
        }
        else
        {
            char bye[] = "Thank you for playing the game!\n";
            printString(bye, 10000000, 1);
        }

        // Freeing up the memory allocated to the player names
        for (int i = 0; i < numOfPlayers; i++)
        {
            free(story.playerNames[i]);
        }
        free(story.playerNames);
        // Freeing up the memory allocated to the story lines
        for (int i = 0; i < (numOfPlayers * rounds); i++)
        {
            free(story.storyLines[i]);
        }
        free(story.storyLines);
        // Freeing up the memory allocated to the story title
        free(story.title);
        // Freeing up the memory allocated to the story date
        free(story.date);
    }
}

void printStar(int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("**********");
        for (int j = 0; j < 10000000; j++)
        {
        }
    }

    printf("\n");
}

void arrayMemAlloc(char **strings, int total, char *print1)
{
    // Creating a temporary string to store player names
    char buffer[BUFFER_SIZE];

    int length = 0;
    for (int i = 0; i < total; i++)
    {
        printf("%s %d: ", print1, i + 1);
        gets(buffer);
        length = strlen(buffer);
        strings[i] = (char *)malloc(length * sizeof(char));
        strcpy(strings[i], buffer);
    }
}

void printString(char *string, int number, int star)
{
    if (star != 0)
        printStar(5);
    for (int i = 0; i < (int)strlen(string); i++)
    {
        printf("%c", string[i]);
        for (int i = 0; i < number; i++)
        {
        }
    }
    if (star != 0)
        printStar(5);
}

void clearScreen()
{
    system("cls");
    printf("\n\t\t\t\t--------------------Welcome %s--------------------\t\t\t\n", plyr.username);
}

void homeScreen(int *opt)
{
    char firstWelcome[] = "\n\t\t\tHELLO DEAR, WELCOME! LET'S GET YOU STARTED\n\t\t\t====================================\n\n";
    printString(firstWelcome, 10000000, 0);
    char chooseOperationMsg[] = "\nPlease choose your operation\n";
    printString(chooseOperationMsg, 10000000, 0);
    char operations[] = "\n1. Signup \n2. Login \n3. Exit\n";
    printString(operations, 10000000, 0);
    char inputChoiceMsg[] = "\n\nYour Choice: \t";
    printString(inputChoiceMsg, 10000000, 0);
    scanf("%d", opt);
    fflush(stdin);
}

char *date(char *dateStr)
{
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    // Store the date in a variable
    sprintf(dateStr, "%d-%02d-%02d", year, month, day);

    // Return the date
    return dateStr;
}


void loadStories(){
    FILE *fp;
    
    
}