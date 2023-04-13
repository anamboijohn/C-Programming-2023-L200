#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define DELAY 10000000
/****************************************
 *          GLOBAL VARIABLES            *
 ****************************************/
struct GameState {
    int stage1;
    int stage2;
    int stage3;
    int stage4;
    int stage5;
    int health;
} gameState;
int tempChoices;
/****************************************
 *   End Of GLOBAL VARIABLES            *
 ****************************************/
void printStar(int number);
void printString(char *string, int number, int star);
void printChoices(char *choices[], int len);
void makeChoice(int *tempChoices);
void gameBeat(int num);
void invalidMsg();
void save_game(struct GameState* state, const char* filename);
void load_game(struct GameState* state, const char* filename);
char* getFullPath(const char* filename);

// first layer
void gameStage1();
void gameStage11(BOOL proceed);
void gameStage12(BOOL proceed);
void gameStage13(BOOL proceed);
void gameStage14(BOOL proceed);
void gameStage15(BOOL proceed);

// Second layer//
// one
void gameStage111(BOOL proceed);
void gameStage112(BOOL proceed);
void gameStage113(BOOL proceed);
void gameStage114(BOOL proceed);
void gameStage115(BOOL proceed);

// two
void gameStage121(BOOL proceed);
void gameStage122(BOOL proceed);
void gameStage122(BOOL proceed);
void lily();

// ThirdLayer//
//  three
void gameStage1132(BOOL proceed);
void gameStage11321(BOOL proceed);
char path[] ="C:\\Users\\LAPTOP\\OneDrive\\Desktop\\C Programming 2023 L200\\PlayerData\\gameStates.dat";
int main()
{
    printStar(10);
    printf("%s", getFullPath("PlayerData\\gameStates.dat"));
    //system("cls");
    char storyIntroMsg[] = "You find yourself in a dark forest with no memory of how you got there. As you wander through the trees, you hear a faint melody in the distance. It sounds like the chorus of a song you vaguely remember. Intrigued, you decide to follow the sound and see where it leads you.\n";
    printString(storyIntroMsg, 10000000, 0);
    gameStage1();
    lily();
    return 0;
}

void gameStage1()
{
    BOOL proceed = TRUE;
    do
    {
        proceed = TRUE;
        char *choices[] = {"1 - Follow the melody deeper into the forest.\n", "2 - Ignore the melody and try to find your way out of the forest.\n", "3 - Investigate the rustling sound coming from behind a nearby tree.\n", "4 - Climb a nearby tree to get a better view of your surroundings.\n", "5 - Call out for help and hope someone hears you.\n"};
        printChoices(choices, 5);
        switch (tempChoices)
        {
        case 1:
            save_game(&gameState,  getFullPath("PlayerData\\gameStates.dat"));
            gameStage11(proceed);
            break;
        case 2:
            gameStage12(proceed);
            break;
        case 3:
            gameStage13(proceed);
            break;
        case 4:
            gameStage14(proceed);
            break;
        case 5:
            gameStage15(proceed);
            break;
        default:
            invalidMsg();
            proceed = FALSE;
            break;
        }

        // char stage2Msg[] = "As John continued to navigate the complex social dynamics of his university classes, he realized that he needed to learn how to balance his academic and social life without compromising his values or hurting others. He took the time to reflect on his actions and to listen to the feedback, John found himself in a difficult situation. He was torn between his programming project and the girls. He had to make a choice.\n";
        // printString(stage2Msg, DELAY, 0);
    } while (!proceed);
}

/***********************************************************************************
 *              GAME STAGE 1 SET OF FUNCTIONS                                      *
 ***********************************************************************************/
void gameStage11(BOOL proceed)
{
    char choice11IntroMsg[] = "You come across a beautiful clearing with a shimmering pond at its center. In the middle of the pond, you see a lily pad with a single white flower. You feel drawn to the flower and reach out to touch it, but as soon as your finger makes contact, you feel a jolt of electricity and black out.\n";
    printString(choice11IntroMsg, 10000000, 0);
    do
    {
        char *choice11OptMsg[] = {"1 - Wake up in a different part of the forest with a newfound ability to communicate with animals.\n", "2 - Wake up in a mysterious laboratory with no memory of how you got there.\n", "3 - Wake up in a mystical realm filled with magical creatures.\n", "4 - Wake up in a futuristic city and discover you have been transported to a parallel universe.\n", "5 -  Wake up in a mysterious underground bunker and must solve a series of puzzles to escape.\n"};
        printChoices(choice11OptMsg, 5);
        gameState.stage1 = tempChoices;
        switch (gameState.stage1)
        {
        case 1:
            save_game(&gameState, "gameState.bat");
            gameStage111(proceed);
            break;
        case 2:
            gameStage112(proceed);
            break;
        case 3:
            gameStage113(proceed);
            break;
        case 4:
            gameStage114(proceed);
            break;
        case 5:
            gameStage115(proceed);
            break;
        default:
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage12(BOOL proceed)
{
    char choice2IntroMsg[] = "You wander for hours, trying to find a way out of the forest, but every path you take seems to lead you in circles. Eventually, you grow exhausted and collapse on the ground, where you remain for days until you are rescued by a passing hiker.\n";
    printString(choice2IntroMsg, DELAY, 0);
    do
    {
        char *choice2OptMsg[] = {"1 - focus on having fun with his friends\n", "2 - try to flirt with all five of them\n"};
        printChoices(choice2OptMsg, 2);
        switch (tempChoices)
        {
        case 1:
            gameStage121(proceed);
            break;
        case 2:
            gameStage122(proceed);
            break;
        default:
            invalidMsg();
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage13(BOOL proceed)
{
    char choice13IntroMsg[] = "You cautiously approach the tree, and as you peek around the trunk, you see a small squirrel frantically digging in the dirt. Curious, you decide to help the squirrel, and as you dig deeper, you find a small chest buried in the ground. Inside the chest, you find a map that leads you to a hidden treasure deep in the forest.\n";
    printString(choice13IntroMsg, 10000000, 0);
    do
    {
        char *choice1OptMsg[] = {"1 - go home and rest\n", "2 - try to make it to the party after the competition\n"};
        printChoices(choice1OptMsg, 2);
        switch (tempChoices)
        {
        case 1:
            gameStage111(proceed);
            break;
        case 2:
            gameStage112(proceed);
            break;
        default:
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage14(BOOL proceed)
{
    char choice14IntroMsg[] = "As you climb higher and higher, you notice a glimmer of light in the distance. Intrigued, you decide to investigate, and after a long trek, you find yourself at the entrance of a mysterious cave. As you enter the cave, you hear the sound of rushing water in the distance.\n";
    printString(choice14IntroMsg, 10000000, 0);
}
void gameStage15(BOOL proceed)
{
    char choice15IntroMsg[] = " Your calls for help echo through the forest, but no one answers. As the sun sets, you resign yourself to spending the night in the forest. As you settle down for the night, you hear the faint sound of the melody from before, and it soothes you to sleep.\n";
    printString(choice15IntroMsg, 10000000, 0);
}

/***********************************************************************************
 *              GAME STAGE 2 SET OF FUNCTIONS                                      *
 ***********************************************************************************/

void gameStage111(BOOL proceed)
{
    char choice111IntroMsg[] = "As you regain consciousness, you hear the chirping of birds and the rustling of leaves. To your surprise, you realize you can understand them perfectly. With this newfound ability, you navigate through the forest with ease, making new animal friends along the way.\n";
    printString(choice111IntroMsg, 10000000, 0);
    do
    {
        char *choice111OptMsg[] = {"1 - Use your newfound ability to form a strong bond with a loyal animal companion.\n", "2 - Use your newfound ability to help a group of animals in need.\n"};
        printChoices(choice111OptMsg, 2);
        gameState.stage2 = tempChoices;
        switch (gameState.stage2)
        {
        case 1:
            char choice1111IntroMsg[] = "As you journey through the forest, you come across a wolf pup who has been abandoned by its pack. Using your ability to communicate with animals, you befriend the pup and become its surrogate parent. As you explore the forest together, you encounter various challenges that you overcome as a team. The wolf grows up to be a loyal companion, always by your side on your adventures.\n";
            printString(choice1111IntroMsg, DELAY, 0);
            break;
        case 2:
            char choice1112IntroMsg[] = "As you journey through the forest, you come across a group of animals in distress. A family of rabbits is trapped under a fallen log, and a group of birds is being terrorized by a hawk. Using your ability to communicate with the animals, you coordinate a rescue mission and save the day. The animals are grateful for your help and reward you with a special gift - a magical charm that will protect you on your future adventures.\n";
            printString(choice1112IntroMsg, DELAY, 0);
            break;
        default:
            invalidMsg();
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage112(BOOL proceed)
{
    char choice12IntroMsg[] = "You open your eyes to a bright light and the sound of beeping machines. You look around and see that you are in a laboratory, surrounded by unfamiliar equipment and technology. As you try to make sense of what happened, you discover that you have been the subject of a bizarre experiment.\n";
    printString(choice12IntroMsg, 10000000, 0);
}
void gameStage113(BOOL proceed)
{
    char choice113IntroMsg[] = "You open your eyes to a world of wonder, with glittering unicorns, colorful dragons, and mischievous fairies all around you. As you explore this mystical realm, you learn about the magical powers that reside within you.\n";
    printString(choice113IntroMsg, 10000000, 0);
    do
    {
        char *choice113OptMsg[] = {"1 - You meet a charming unicorn who takes a liking to you and wants to show you around the realm.\n", "2 - You come across a mysterious human who seems to have been transported to this realm just like you\n"};
        printChoices(choice113OptMsg, 2);
        gameState.stage2 = tempChoices;

        switch (gameState.stage2)
        {
        case 1:
            char choice1131IntroMsg[] = "You spend your days exploring the realm with your new unicorn friend. As you grow closer, you begin to realize that there might be something more between you and the unicorn. The two of you embark on a romantic adventure, filled with magic and wonder.\n";
            printString(choice1131IntroMsg, DELAY, 0);
            break;
        case 2:
            gameStage1132(proceed);
            break;
        default:
            invalidMsg();
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage114(BOOL proceed)
{
    char choice14IntroMsg[] = "You find yourself in a bustling metropolis filled with skyscrapers and flying cars. As you try to find your bearings, you realize that everything is different, from the language people speak to the technology they use. You realize that you have somehow been transported to a parallel universe.\n";
    printString(choice14IntroMsg, 10000000, 0);
}
void gameStage115(BOOL proceed)
{
    char choice15IntroMsg[] = "You wake up in a dimly lit room with no windows or doors. As you explore the bunker, you discover a series of puzzles and riddles that you must solve to escape. With each puzzle you solve, you uncover more secrets about the bunker and the people who built it.\n";
    printString(choice15IntroMsg, 10000000, 0);
}

void gameStage121(BOOL proceed)
{
    char choice21IntroMsg[] = "John decided to focus on having fun with his friends and not worry about the girls for the night. He had a great time dancing and hanging out with his friends, and he felt relaxed and carefree. However, the next day, he found out that all of the girls had noticed that he hadn't paid attention to them at the party, and they were all upset with him. John realized that he had hurt their feelings and that he needed to make it up to them.\n";
    printString(choice21IntroMsg, DELAY, 0);
}
void gameStage122(BOOL proceed)
{
    char choice22IntroMsg[] = "John decided to try to flirt with all five of the girls at the party. He spent the night trying to impress them with his wit and charm, but he soon realized that he was in over his head. He couldn't keep track of all the conversations he was having, and he kept accidentally saying the wrong name to the wrong girl. By the end of the night, he had managed to offend all of them in some way or another, and he was feeling defeated and embarrassed.\n";
    printString(choice22IntroMsg, DELAY, 0);
    do
    {
        char *choice22OptMsg[] = {"1 - apologize to the girls and explain that he was just trying to have fun\n", "2 - make up excuses for his behavior and try to blame it on the alcohol\n", "3 - try to make up for it by asking the girls out on individual dates\n"};
        printChoices(choice22OptMsg, 3);

        switch (tempChoices)
        {
        case 1:
            char choice221IntroMsg[] = "John decided to apologize to the girls and explain that he was just trying to have fun. He sent them a message the next day, saying that he was sorry for any offense he had caused and that he had not intended to hurt anyone's feelings. The girls were understanding, but they made it clear that they didn't appreciate being treated like objects to be flirted with. They told John that he needed to learn how to treat women with respect if he wanted to have any chance with them in the future.\n";
            printString(choice221IntroMsg, DELAY, 0);
            break;
        case 2:
            char choice222IntroMsg[] = "John decided to make up excuses for his behavior and try to blame it on the alcohol. He sent the girls a message saying that he didn't remember everything that had happened at the party and that he had been drinking heavily. The girls were not impressed by his excuses and told him that he needed to take responsibility for his actions. John realized that he had messed up and that he needed to make amends if he wanted to salvage his relationships with them.\n";
            printString(choice222IntroMsg, DELAY, 0);
            break;
        case 3:
            char choice223IntroMsg[] = "John decided to try to make up for his mistake by asking the girls out on individual dates. He thought that this would show them that he was sincere and that he valued their company. However, the girls were not impressed by his approach. They felt that he was trying to use them to make up for his mistake and that he wasn't truly sorry for what he had done. John realized that he had to find another way to make things right.\n";
            printString(choice223IntroMsg, DELAY, 0);
            break;

        default:
            char invalidMsg[] = "Invalid Option Please Start Again.\n";
            printString(invalidMsg, DELAY, 0);
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}

/**********************************************************
 *                      STAGE 3 OF STORY                  *
 **********************************************************/
void gameStage1132(BOOL proceed)
{
    char choice1132IntroMsg[] = "You are surprised and relieved to come across another human in this strange realm. As you get to know each other, you begin to feel a strong connection. You spend your days exploring the realm together, and the more time you spend with each other, the more you realize your feelings for each other. The two of you embark on a romantic adventure, navigating the dangers of the magical realm together.\n";
    printString(choice1132IntroMsg, 10000000, 0);
    do
    {
        char *choice1132OptMsg[] = {"1 - You and the other human quickly become close and fall in love, exploring the magical realm together and facing its challenges side-by-side.\n", "2 - As you and the other human explore the realm together, you begin to notice that they seem distant and preoccupied. When you ask what's wrong, they confess that they're already in love with someone else from their own world, and they're afraid they'll never be able to return to them.\n"};
        printChoices(choice1132OptMsg, 2);
        gameState.stage3 = tempChoices;

        switch (gameState.stage3)
        {
        case 1:
            gameStage11321(proceed);
            break;
        case 2:
            char choice11322IntroMsg[] = "You are heartbroken to learn that the other human is already in love with someone else from their own world. You try to convince them to stay with you, but they insist that they must return to their own world. You are left heartbroken, but you know that you will always have the memories of your time together in the magical realm.\n";
            printString(choice11322IntroMsg, 10000000, 0);
            break;
        default:
            invalidMsg();
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}

/***********************************************************************************
 *              GAME STAGE 4 SET OF FUNCTIONS                                      *
 ***********************************************************************************/
void gameStage11321(BOOL proceed)
{
    char choice11321IntroMsg[] = "Your love continues to grow stronger as you explore the magical realm together. Eventually, you both discover a way to return to your own world, and you leave the mystical realm hand-in-hand, excited to begin your new life together.\n";
    printString(choice11321IntroMsg, 10000000, 0);
    do
    {
        char *choice11321OptMsg[] = {"1 - You both decide to stay in the magical realm forever, forsaking your old lives for a chance at eternal love and adventure.\n", "2 -  You both decide to return to your own worlds, promising to find a way to be together despite the distance.\n"};
        printChoices(choice11321OptMsg, 2);
        gameState.stage4 = tempChoices;
        switch (gameState.stage4)
        {
        case 1:
            char choice113211IntroMsg[] = "You and the other human live happily ever after in the magical realm, growing old together but never losing the spark of your love. You face countless dangers and challenges, but you always overcome them together, knowing that your love will conquer all.\n";
            printString(choice113211IntroMsg, DELAY, 0);
            break;
        case 2:
            char choice113212IntroMsg[] = "You both try everything in your power to make the long-distance relationship work, but the strain and difficulties prove too much. You both become increasingly frustrated and lonely, and eventually, you break up. You're left heartbroken and alone, wishing that you could go back to the magical realm and stay there forever. As time goes by, you find it hard to let go of the memory of the other human and the love you shared in the magical realm. You start to lose interest in your own life and become increasingly depressed, until one day, you decide to go back to the mystical realm and never return. You spend the rest of your days living in the magical realm, reminiscing about your lost love and the adventures you had together.\n";
            printString(choice113212IntroMsg, DELAY, 0);
            break;
        default:
            invalidMsg();
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
/***********************************************************************************
 *              GAME STAGE 5 SET OF FUNCTIONS                                      *
 ***********************************************************************************/

/***********************************************************************************
 *              GAME STAGE 15 SET OF FUNCTIONS                                      *
 * *******************************************************************************/



void printString(char *string, int number, int star)
{
    if (star != 0)
        printStar(5);
    for (int i = 0; i < (int)strlen(string); i++)
    {
        printf("%c", string[i]);
        gameBeat(1);
        for (int i = 0; i < number; i++)
        {
        }
    }
    if (star != 0)
        printStar(5);
}

void printChoices(char *choices[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printString(choices[i], 10000000, 0);
    }

    makeChoice(&tempChoices);
}

void makeChoice(int *tempChoices)
{
    char makeChoiceMsg[] = "\nPlease make a choice: ";
    printString(makeChoiceMsg, 10000000, 0);
    scanf("%d", tempChoices);
    fflush(stdin);
    printf("\n");
}

void gameBeat(int num)
{
    int tempo = 120;                  // beats per minute
    int duration = 1000 * 60 / tempo; // duration of a quarter note in milliseconds
    int half_duration = duration / 2; // duration of an eighth note in milliseconds
    int round = 0;                    // number of rounds
    while (round < 1)
    {
        switch (num)
        {
        // play the first note of the beat
        case 1:
            Beep(7, 2);
            break;
        // play the second note of the beat
        case 2:
            Beep(440, half_duration);
            break;
        case 3:
            Beep(440, half_duration);
            break;
        // play the third note of the beat
        case 4:
            Beep(440, half_duration);
            break;

        // play the fourth note of the beat
        case 5:
            Beep(440, duration);
            break;
        }
        round++;
    }
}
void invalidMsg()
{
    char invalidMsg[] = "Invalid Option Please Start Again.\n";
    printString(invalidMsg, DELAY, 0);
}

void lily()
{
    char lily1[] = "          /\\           \n";
    printString(lily1, DELAY, 0);
    char lily2[] = "        //  \\\\         \n";
    printString(lily2, DELAY, 0);
    char lily3[] = "      //      \\\\       \n";
    printString(lily3, DELAY, 0);
    char lily4[] = "    //          \\\\     \n";
    printString(lily4, DELAY, 0);
    char lily5[] = "   //    /\\      \\\\    \n";
    printString(lily5, DELAY, 0);
    char lily6[] = " //____/__\\ \\______\\\\  \n";
    printString(lily6, DELAY, 0);
    char lily7[] = " //____/__\\ \\______\\\\  \n";
    printString(lily7, DELAY, 0);
    char lily8[] = " \\   --/    \\\\      /  \n";
    printString(lily8, DELAY, 0);
    char lily9[] = "  \\____      \\\\____/   \n";
    printString(lily9, DELAY, 0);
    char lily10[] = "       `\\     /`       \n";
    printString(lily10, DELAY, 0);
    char lily11[] = "        `\\ /`         \n";
    printString(lily11, DELAY, 0);
    char lily12[] = "          `V`          \n";
    printString(lily12, DELAY, 0);
}

void save_game(struct GameState* state, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }

    size_t saved = fwrite(state, sizeof(struct GameState), 1, file);
    if(saved != 1) {
        printf("Failed to save game\n");
    }else{
        printf("Game saved successfully\n");
    }

    fclose(file);
}

void load_game(struct GameState* state, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file for reading\n");
        return;
    }

   size_t read = fread(state, sizeof(struct GameState), 1, file);
   if(read != 1) {
       printf("Failed to load game\n");
    }else{
        printf("Game loaded successfully\n");
    }

    fclose(file);
}

char* getFullPath(const char* filename) {
    char* fullpath = NULL;

    // Get the full path to the current directory
    DWORD length = GetFullPathName(".", 0, NULL, NULL);
    if (length == 0) {
        printf("Failed to get full path\n");
        return NULL;
    }

    fullpath = malloc(length + strlen("\\") + strlen(filename) + 1);
    if (fullpath == NULL) {
        printf("Failed to allocate memory for full path\n");
        return NULL;
    }

    if (GetFullPathName(".", length, fullpath, NULL) == 0) {
        printf("Failed to get full path\n");
        free(fullpath);
        return NULL;
    }

    // Append the filename to the full path
    if (strcat_s(fullpath, length + strlen("\\") + strlen(filename) + 1, "\\") != 0) {
        printf("Failed to append filename\n");
        free(fullpath);
        return NULL;
    }
    if (strcat_s(fullpath, length + strlen("\\") + strlen(filename) + 1, filename) != 0) {
        printf("Failed to append filename\n");
        free(fullpath);
        return NULL;
    }

    return fullpath;
}
