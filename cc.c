#include <stdio.h>
#include <string.h>
int main()
{
    int guessp1, attemptsp1, number, guessp2, attemptsp2;
    attemptsp1 = 0;
    attemptsp2 = 0;
    char player1[50], player2[50];
    printf("welcome to guess the number!\n");
    printf("Enter the name of Player 1: ");
    scanf("%s", player1);
    printf("Enter the name of Player 2: ");
    scanf("%s", player2);
    printf("player 1 choose a number between 1 and 100.\n");
    number = (guessp1 * 67 + 29) % (50 - 10 + 1) + 10;

    do
    {
        printf("take a guess: ");
        scanf("%d", &guessp1);
        attemptsp1++;
        if (guessp1 < number)
            printf("low! Try again.\n");
        else if (guessp1 > number)
            printf("high! Try again.\n");

        else if (guessp1 == number)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attemptsp1);
            break;
        }
    } while (guessp1 != number);

    printf("player 2 choose a number between 1 and 100.\n");
    number = (guessp2 * 67 + 29) % (50 - 10 + 1) + 10;
    do
    {
        printf("take a guess: ");
        scanf("%d", &guessp2);
        attemptsp2++;
        if (guessp2 < number)
            printf("low! Try again.\n");
        else if (guessp2 > number)
            printf("high! Try again.\n");

        else if (guessp2 == number)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attemptsp2);
            break;
        }
    } while (guessp2 != number);

    if (attemptsp1 > attemptsp2)
    {
        printf("%s wins by %d attempts.\n", player2, attemptsp1 - attemptsp2);
    }
    else if (attemptsp2 > attemptsp1)
    {
        printf("%s wins by %d attempts.\n", player1, attemptsp2 - attemptsp1);
    }
    else
    {
        printf("It's a tie with %d attempts.\n", attemptsp1);
    }

    return 0;
}
