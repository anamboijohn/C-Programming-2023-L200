#include <stdio.h>

#define MAX_CHOICE 5
#define MAX_NAME 20

int get_choice(char *question, char *choices[], int num_choices);

int main()
{
    int i, outcome, current_progress = 0;
    char player_name[MAX_NAME];

    printf("Enter your name: ");
    scanf("%s", player_name);

    // Create a file with the player's name to store progress data
    FILE *fp = fopen(player_name, "w");
    fprintf(fp, "%d", current_progress);
    fclose(fp);

    char *choices[MAX_CHOICE] = {
        "Choice 1",
        "Choice 2",
        "Choice 3",
        "Choice 4",
        "Choice 5"
    };

    // Continue game until user reaches an ending
    while (1) {
        // Present the user with a choice
        outcome = get_choice("What do you want to do?", choices, MAX_CHOICE);

        // Update progress based on user choice
        switch (outcome) {
            case 1:
                current_progress += 10;
                break;
            case 2:
                current_progress += 20;
                break;
            case 3:
                current_progress += 30;
                break;
            case 4:
                current_progress += 40;
                break;
            case 5:
                current_progress += 50;
                break;
        }

        // If user has reached an ending, display the ending and break out of the loop
        if (current_progress >= 100) {
            printf("You have reached the end!\n");
            break;
        }
    }
}

// Prompt the user with a question and choices, and return the user's choice
int get_choice(char *question, char *choices[], int num_choices)
{
    int i, choice;

    printf("%s\n", question);
    for (i = 0; i < num_choices; i++) {
        printf("%d. %s\n", i + 1, choices[i]);
    }

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}
