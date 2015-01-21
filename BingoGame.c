/*Game created by Conner Toney*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LIM 5 // Max cells in array
#define FIRST_VALUE_LIMIT 15 // Max value in column 'B'
#define SECOND_VALUE_LIMIT 30 // Max value in column 'I'
#define THIRD_VALUE_LIMIT 45 // Max value in column 'N'
#define FOURTH_VALUE_LIMIT 60 // Max value in column 'G'
#define FIFTH_VALUE_LIMIT 75 // Max value in column 'O'
#define TEXT_SPACE 25 // Used for fgets character space limit

/*Function protocols*/
void random_value_array_generator(int bingo_card[ARRAY_LIM][ARRAY_LIM]);
void display_arrays(int bingo_card[ARRAY_LIM][ARRAY_LIM]);
int explanation();
int random_number_generator();
void check_winner(int bingo_card[ARRAY_LIM][ARRAY_LIM]);

int
main()
{
    srand(time(NULL)); // Causes unique random numbers.
    char play_again;
    /*Loop used so that players can decide
     *whether or not they want to continue playing*/
    do {
        if (explanation() == 0) { // Shows explanation and asks if you want to play.
            return 0;
        }

        putchar('\n');

        int card1[ARRAY_LIM][ARRAY_LIM];
        int card2[ARRAY_LIM][ARRAY_LIM];

        random_value_array_generator(card1); //Assigns random values to cells in array
        random_value_array_generator(card2);
        card1[2][2] = 0; // Sets center cell as a free space
        card2[2][2] = 0;
        printf("The first card is:\n");
        display_arrays(card1); // Calls function to display first card.
        putchar('\n');
        printf("The second card is:\n");
        display_arrays(card2); // Calls function to display second card.
        putchar('\n');
        printf("You can now decide who will get which card.\n");
        printf("You are allowed to use a 3-character name.\n");
        fflush(stdin);
        char first_player[TEXT_SPACE];
        printf("Who will be using the first card?: ");
        fgets(first_player, TEXT_SPACE, stdin); // Sets first player's username
        char second_player[TEXT_SPACE];
        printf("Who will be using the second card?: ");
        fgets(second_player, TEXT_SPACE, stdin); // Sets second player's username
        printf("%c%c%c will be using the first card.\n", first_player[0], first_player[1], first_player[2]);
        printf("%c%c%c will be using the second card.\n", second_player[0], second_player[1], second_player[2]);
        putchar('\n');
        char upper_choice;
        /*Loop used to mark cards until player wins*/
        do {
            int rand_num;
            rand_num = random_number_generator(); //Generates random number to be drawn.
            printf("The number drawn is: %i\n", rand_num);
            int r, c;
            /*Loop marks specific cells if they match
             *the number in the cell*/
            for (r = 0 ; r < ARRAY_LIM ; r++) {
                for (c = 0 ; c < ARRAY_LIM ; c++) {
                    if (rand_num == card1[r][c]) {
                        card1[r][c] = 0;
                    }
                    if (rand_num == card2[r][c]) {
                        card2[r][c] = 0;
                    }
                }
            }

            printf("%c%c%c's card:\n", first_player[0], first_player[1], first_player[2]);
            display_arrays(card1);
            putchar('\n');
            printf("%c%c%c's card:\n", second_player[0], second_player[1], second_player[2]);
            display_arrays(card2);
            check_winner(card1);
            check_winner(card2);
            printf("Has anybody won yet? (Y/N): ");
            char choice;
            scanf("%c", &choice);
            printf("\n---------------------------------------------\n");
            upper_choice = toupper(choice);
        } while (upper_choice != 'Y'); //Ends loop once somebody has won.
        char winner[TEXT_SPACE];
        printf("\nWho won?: ");
        fflush(stdin);
        fgets(winner, TEXT_SPACE, stdin);
        printf("+-------------+\n");
        printf("|  CONGRATS!  |\n");
        printf("|     %c%c%c     |\n", winner[0], winner[1], winner[2]);
        printf("+-------------+\n");
        printf("%c%c%c and %c%c%c, ",
               first_player[0],
               first_player[1],
               first_player[2],
               second_player[0],
               second_player[1],
               second_player[2]);
        printf("would you like to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again != 'n'); //Ends loop once players have decided to stop playing.
    printf("Thank you for playing BINGO.\n");
    printf("brought to you by Conner Toney.");
    putchar('\n');
}

int explanation() // Explains game and asks if you want to play.
{
    printf("[project_1] by Conner L. Toney\n");
    putchar('\n');
    printf("+----------------+\n");
    printf("|                |\n");
    printf("|      BINGO     |\n");
    printf("|                |\n");
    printf("+----------------+\n");
    putchar('\n');
    printf("You are playing the game BINGO.\n");
    printf("This is a 2-player game.\n");
    printf("A random number (1-75) will be chosen.\n");
    printf("If your card has the generated number, \n");
    printf("    that number will become an '0' on your card.\n");
    printf("A player wins the game if any of the following things happen: \n");
    printf("  1. All the spaces in any row are an '0'.\n");
    printf("  2. All the spaces in any column are an '0'.\n");
    printf("  3. All the spaces in a diagonal are an '0'.\n");
    printf("  4. The four corner spaces are an '0'.\n");
    putchar('\n');
    printf("Still want to play? Enter Y/N: ");
    char choice;
    scanf("%c", &choice);
    char upper_choice;
    upper_choice = toupper(choice);
    if (upper_choice == 'N') { // Allows player choice to leave.
        printf("OK. Reopen the program if you change your mind!");
        return 0;
    }
    else {
        return 1;
    }

}

void random_value_array_generator(int bingo_card[ARRAY_LIM][ARRAY_LIM])
{
    int r, c;
    /*Generates random values dependent on which column the cell is in.*/
    for (r = 0 ; r < ARRAY_LIM ; r++) {
        for (c = 0 ; c < ARRAY_LIM ; c++) {
            if (c == 0)
                bingo_card[r][c] = (rand() % FIRST_VALUE_LIMIT + 1);
            if (c == 1)
                bingo_card[r][c] = (rand() % FIRST_VALUE_LIMIT + 1) + FIRST_VALUE_LIMIT;
            if (c == 2)
                bingo_card[r][c] = (rand() % FIRST_VALUE_LIMIT + 1) + SECOND_VALUE_LIMIT;
            if (c == 3)
                bingo_card[r][c] = (rand() % FIRST_VALUE_LIMIT + 1) + THIRD_VALUE_LIMIT;
            if (c == 4)
                bingo_card[r][c] = (rand() % FIRST_VALUE_LIMIT + 1) + FOURTH_VALUE_LIMIT;
        }
    }
}

void display_arrays(int bingo_card[ARRAY_LIM][ARRAY_LIM])
{
    int r, c;
    /*Displays array in a table*/
    for (r = 0 ; r < ARRAY_LIM ; r++) {
        for (c = 0 ; c < ARRAY_LIM ; c++) {
            printf("%2i ", bingo_card[r][c]);
        }
    putchar('\n');
    }
}

int random_number_generator()
{
    /*Gererates random number in range 1-75*/
    int random_number;
    random_number = rand() % FIFTH_VALUE_LIMIT + 1;
    return (random_number);
}

void check_winner(int bingo_card[ARRAY_LIM][ARRAY_LIM])
{
    int r, c;
    /*Makes it very clear that someone has won.*/
    for (r = 0 ; r < ARRAY_LIM ; r++) {
        for (c = 0 ; c < ARRAY_LIM ; c++) {
            if (bingo_card[0][0] == 0
                && bingo_card[0][4] == 0
                && bingo_card[4][0] == 0
                && bingo_card[4][4] == 0)
                    printf("\n***WE HAVE A WINNER!!!***\n");
            if (bingo_card[r][0] == 0
                && bingo_card[r][1] == 0
                && bingo_card[r][2] == 0
                && bingo_card[r][3] == 0
                && bingo_card[r][4] == 0)
                    printf("\n***WE HAVE A WINNER!!!***\n");
            if (bingo_card[0][c] == 0
                && bingo_card[1][c] == 0
                && bingo_card[2][c] == 0
                && bingo_card[3][c] == 0
                && bingo_card[4][c] == 0)
                    printf("\n***WE HAVE A WINNER!!!***\n");
            if (bingo_card[0][0] == 0
                && bingo_card[1][1] == 0
                && bingo_card[2][2] == 0
                && bingo_card[3][3] == 0
                && bingo_card[4][4] == 0)
                    printf("\n***WE HAVE A WINNER!!!***\n");
            if (bingo_card[0][4] == 0
                && bingo_card[1][3] == 0
                && bingo_card[2][2] == 0
                && bingo_card[3][1] == 0
                && bingo_card[4][0] == 0)
                    printf("\n***WE HAVE A WINNER!!!***\n");
        }
    }
}
