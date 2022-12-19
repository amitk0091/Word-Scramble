#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

void scramble(char *s);

int main()
{

    int play_againOrexit, mode, level;

    do
    {
        system("cls");
        system("color 3");
        srand(time(NULL));
        int score = 0;
        char original[100], ch;
        char scrambled[100];
        char answer[100];
        printf("\n\n");
        printf("        ------------------------------------------------WELCOME TO THE WORLD OF WORD SCRAMBLE GAME-----------------------------------------\n\n");
    label1:
        printf("\n                                                   Press \n                                  \t\t\t\t1 for Singleplayer\n                                  \t\t\t\t2 for Multiplayer\n\n                                                   --->\t\t");
        scanf("%d", &mode);
        if (mode == 2)
        {
            char player_1[30];
            char player_2[30];
            int points_1 = 0, points_2 = 0;
            printf(" Enter the name of player 1: ");
            // gets(player_1);
            scanf("%s", &player_1);
            printf("\n");
            printf(" Enter the name of player 2: ");
            // gets(player_2);
            scanf("%s", &player_2);
            printf("\n");
            for (int i = 0; i < 2; i++)
            {

                printf(" Round %d\n\n", i + 1);
                if (i == 0)
                {
                    int j;
                    printf(" %s will enter a word first:", player_1);
                    for (j = 0; (ch = getch()) != 13; j++)
                    {
                        original[j] = ch;
                        printf("*");
                    }
                    original[j] = '\0';

                    printf("\n\n");

                    strcpy(scrambled, original);
                    scramble(scrambled);

                    bool game_over = false;
                    do
                    {

                        printf(" Unscramble this word %s: %s\n\n", player_2, scrambled);

                        clock_t start, end;
                        double cpu_time_used;

                        start = clock();

                        printf(" Answer: ");
                        scanf("%s", answer);
                        end = clock();
                        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

                        if (strcmp(answer, original) == 0)
                        {
                            // printf("\nYou got it!\n");
                            printf(" %s took %.2f seconds to guess the correct answer :)\n", player_2, cpu_time_used);
                            printf("\n");
                            if (cpu_time_used < 10)
                            {
                                points_2 = points_2 + 10;
                            }
                            else if (15 > cpu_time_used > 10)
                            {
                                points_2 = points_2 + 7;
                            }
                            else if (20 > cpu_time_used > 15)
                            {
                                points_2 = points_2 + 5;
                            }
                            else if (cpu_time_used > 20)
                            {
                                points_2 = points_2 + 3;
                            }

                            printf(" Points after Round 1 are as follows:\n\n");
                            printf(" %s : %d points\n", player_1, points_1);
                            printf(" %s : %d points\n", player_2, points_2);
                            game_over = true;
                            break;
                        }
                        else
                        {
                            printf(" \nTry again!\n\n");
                            points_2--;
                        }

                    } while (!game_over);
                }
                else
                {
                    int j;
                    printf(" %s will enter a word now:", player_2);
                    for (j = 0; (ch = getch()) != 13; j++)
                    {
                        original[j] = ch;
                        printf("*");
                    }
                    original[j] = '\0';

                    printf("\n\n");
                    char scrambled[100];
                    char answer[100];

                    strcpy(scrambled, original);
                    scramble(scrambled);

                    bool game_over = false;
                    do
                    {

                        printf(" Unscramble this word %s: %s\n\n", player_1, scrambled);

                        clock_t start, end;
                        double cpu_time_used;

                        start = clock();

                        printf(" Answer: ");
                        scanf(" %s", answer);
                        end = clock();
                        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

                        if (strcmp(answer, original) == 0)
                        {
                            // printf("\nYou got it!\n");
                            printf(" %s took %.2f seconds to guess the correct answer :)\n", player_1, cpu_time_used);
                            printf("\n");
                            if (cpu_time_used < 10)
                            {
                                points_1 = points_1 + 10;
                            }
                            else if (15 > cpu_time_used > 10)
                            {
                                points_1 = points_1 + 7;
                            }
                            else if (20 > cpu_time_used > 15)
                            {
                                points_1 = points_1 + 5;
                            }
                            else if (cpu_time_used > 20)
                            {
                                points_1 = points_1 + 3;
                            }
                            printf(" Points after final round are as follows:\n\n");
                            printf(" %s : %d points\n", player_1, points_1);
                            printf(" %s : %d points\n\n\n", player_2, points_2);

                            if (points_1 > points_2)
                            {
                                printf(" %s is the winner of this match. \n", player_1);
                            }
                            else if (points_1 < points_2)
                            {
                                printf(" %s is the winner of this match.\n", player_2);
                            }
                            else if (points_1 == points_2)
                            {
                                printf(" Match Draw !!\n");
                            }

                            game_over = true;
                        }
                        else
                            printf(" \nTry again!\n\n");
                        points_1--;
                    } while (!game_over);
                }
            }
        }
        else if (mode == 1)
        {
        label2:
            printf("        ---------------------------------------------------------------Select the level--------------------------------------------------\n");
            printf("                                                   Press \n");
            printf("                                  \t\t\t 1 for Easy level \n");
            printf("                                  \t\t\t 2 for Medium level \n");
            printf("                                  \t\t\t 3 for Difficult level \n");
            printf("\n                                                   --->\t\t");
            scanf("%d", &level);
            char wrd, index;

            FILE *words;
            words = fopen("words.txt", "r");
            
            while (fgets(original, 30, words) && index--);
            

            if (level == 1)
            {
                index = rand() % 50;
            }
            else if (level == 2)
            {
                index = rand() % 50 + 50;
            }
            else if (level == 3)
            {
                index = rand() % 50 + 100;
            }
            else
            {
                printf("\n                                                   --------INVALID INPUT--------\n\n");
                goto label2;
            }

            if (words == NULL)
            {
                printf("Error");
            }
            else
            {

                // int j = 0;
                // while ((wrd = fgetc(words)) != EOF)
                // {
                //     if (wrd == num)
                //     {
                //         while ((wrd = fgetc(words)) != 32)
                //         {
                //             original[j] = wrd;
                //             j++;
                //         }
                //     }
                //     original[j] = '\0';
                // }
            }

            fclose(words);

            strlwr(original);
            strcpy(scrambled, original);
            scramble(scrambled);
            printf("Maximum Attempts : 5\n");

            bool game_over = false;
            do
            {

                printf("Unscramble the word: %s\n\n", scrambled);

                printf("Answer: ");
                scanf("%s", answer);

                if (strcmp(answer, original) == 0)
                {

                    score++;
                    printf("\nYou got it in %d attempts!\n\n", score);
                    game_over = true;
                }
                else
                {
                    printf("\nTry again!\n\n");
                    score++;

                    if (score == 5)
                    {
                        printf("You failed!!!");
                        printf("\nCorrect word : %s\n", original);
                        goto end;
                    }
                }

            } while (!game_over);
        }

        else
        {
            printf("\n                                                   --------INVALID INPUT--------\n\n");
            goto label1;
        }
    end:
        printf("Press 0 to exit and 1 to play again\n");
        scanf("%d", &play_againOrexit);
    } while (play_againOrexit == 1);

    return 0;
}

void scramble(char *s)
{
    int length = strlen(s);

    if (length == 1)
        return;

    if (length == 2)
    {
        char temp = s[0];
        s[0] = s[1];
        s[1] = temp;
        return;
    }

    char original[length + 1];
    strcpy(original, s);

    double diff = 0;
    bool same_start = false;
    bool same_end = false;
    int times_stuck = 0;

    do
    {

        int i = 0;
        while (i < length)
        {

            int pos1 = rand() % length;
            int pos2 = rand() % length;

            if (pos1 != pos2)
            {
                char temp = s[pos1];
                s[pos1] = s[pos2];
                s[pos2] = temp;
                i++;
            }
        }

        int differences = 0;
        for (int j = 0; j < length; j++)
            if (original[j] != s[j])
                differences++;

        diff = (double)differences / length;

        same_start = s[0] == original[0];
        same_end = s[length - 1] == original[length - 1];

        times_stuck++;

    } while (((same_start && same_end) || (diff < 0.5)) && (times_stuck < 100));
}
