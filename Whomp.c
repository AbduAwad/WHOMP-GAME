#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Bold
#define STYLE_BOLD "\033[1m"
#define STYLE_NO_BOLD "\033[22m"

// Underline
#define underline "\033[4m"
#define nounderline "\033[0m"

// text colour
#define green text "\033[0;32m"
#define blue text "\033[0;34m"
#define red text "\033[1;31m"
#define yellow text "\033[1;33m"
#define nocolour "\033[0m"

int main();
int scoreboard(int roll[6], int num_rolls, int *rolls_left);

void print_scoreboard_and_round_header(char name[15], int player_total_score, char computer_name[15], int computer_total_score, int roundnum) {
    printf("\033[1;33m%-15s = %d                       %-10s = %d\n\n\033[0m", name, player_total_score, computer_name, computer_total_score);
    printf("*******************     ROUND   %i     *******************\n\n", roundnum);
    return;
}

void print_die(int roll[6], int num_rolls) {
    int i = 0;
    printf("\nRolls: \n\n");
    for (i=0; i<num_rolls; i++) {
        switch (roll[i]) {
    
        case 1:
            printf(" 1:|       *     | \n");
         break;
        
        case 2:
            printf(" 2:|      * *    | \n");
         break;
         
         case 3:
            printf(" 3:|     * * *   | \n");
        break;
        
        case 4:
            printf(" 4:|   * * * *   | \n");
            break;
            
        case 5:
            printf(" 5:|  * * * * *  | \n");
            break;
            
        case 6:
            printf(" 6:| * * * * * * | \n");
            break;
        }	 	  	 	  	 	     	     	 	
    }
    printf("\n\n");
}

/**************************************************** 
Function: start_game 
Does: clears the main menu and places the user into the game
Receives: nothing
Uses: Nothing 
Returns: Nothing
****************************************************/

int roll_die() {
    return rand() % (6 - 1 + 1) + 1;
}

void main_game() {

    int selection, max_score_choice, max_score = 0, roundnum = 1, i = 0, roll[6];
    char name[15];
    int player_total_score = 0, cpu_total_score = 0, player_round_score = 0, cpu_round_score = 0;
    int round_finished = 0, rolls_left = 6, points_this_roll = 0;
    char ask;

    system("clear");
    printf("choose a name...");
    printf("\n\n1) Pedro");
    printf("\n2) Einstein");
    printf("\n3) Bruce Wayne");
    printf("\n4) Clark Kent");
    printf("\n5) Venom");
    printf("\n\033[1mentry:\033[22m ");
    scanf("%i", & selection);

    if (selection == 1) {
        sprintf(name, "%s", "Pedro");
    } else if (selection == 2) {	 	  	 	  	 	     	     	 	
        sprintf(name, "%s", "Einstein");
    } else if (selection == 3) {
        sprintf(name, "%s", "Bruce Wayne");
    } else if (selection == 4) {
        sprintf(name, "%s", "Clark Kent");
    } else if (selection == 5) {
        sprintf(name, "%s\n", "Venom\n");
    }

    sleep(1);
    while (getchar() != '\n'); // ignore any other key press except enter "\n"
    fflush(stdout);

    printf("\n\n\n");
    printf("\033[4mHello %s, please enter a maximum score, recommended (2,500 - 20,000)\033[0m ", name);
    printf("\n\033[1mentry:\033[22m ");
    scanf("%i", &max_score_choice);
    
    max_score = max_score_choice;

    printf("\033[1;33mMax score: %i\033[0m\n\n", max_score);
    sleep(1);

    do {
        // Player turn new round
        player_round_score = 0;
        rolls_left = 6;
        system("clear");
        print_scoreboard_and_round_header(name, player_total_score, "Computer", cpu_total_score, roundnum);
        printf("\n\n");
        printf("Your Turn!\n\n");
        do {
            for (i = 0; i < rolls_left; i++) {
                roll[i] = roll_die();
            }
            
            // test code
            // roll[0]=1;roll[1]=1;roll[2]=1;roll[3]=5;roll[4]=5;roll[5]=6;
            
            print_die(roll, rolls_left);
            points_this_roll = scoreboard(roll, rolls_left, &rolls_left);
            player_round_score += points_this_roll;
            printf("Points: %i\n\n", player_round_score);

            if (points_this_roll == 0) { // Whomp
                printf("\033[1;31m--- WHOMP! WHOMP! ---\033[0m\n\n");
                printf("Points: 0\n\n");
                player_round_score = 0;
                break;
            }	 	  	 	  	 	     	     	 	

            if ((player_total_score < 500) && (player_round_score < 500)) {
                printf("You need 500 points to get on the score board, you only have %i\n\n", player_round_score);
            }

            if (rolls_left > 0) {
                printf("You have %i dice remaining. Would you like to roll again? (y/n)", rolls_left);
                ask = 0;
                while (ask != 'y' && ask != 'n' && ask != 'Y' && ask != 'N') {
                    scanf(" %c", &ask);
                }
                if (ask == 'n' || ask == 'N') {
                    break;
                }
            }
        } while (rolls_left > 0);
        
             if ((ask != 'n') && (ask != 'N')) {
                (void)getchar(); // clear input buffer
                printf("Press Enter to continue...");
                sleep(1);
                while (getchar() != '\n'); // ignore any other key press except enter "\n"
            fflush(stdout);
        }
        
        if ((player_total_score >= 500) || (player_round_score >= 500)) {
            player_total_score += player_round_score;
        }
        
        // Computer turn new round
        rolls_left = 6;
        cpu_round_score = 0;
        system("clear");
        print_scoreboard_and_round_header(name, player_total_score, "Computer", cpu_total_score, roundnum);
        printf("\n\n");
        printf("Computers Turn!\n");
        do {	 	  	 	  	 	     	     	 	
            for (i = 0; i < rolls_left; i++) {
                roll[i] = roll_die();
            }
            print_die(roll, rolls_left);
            points_this_roll = scoreboard(roll, rolls_left, &rolls_left);
            cpu_round_score += points_this_roll;
            printf("Points: %i\n\n", cpu_round_score);
            if (points_this_roll == 0) { // Whomp
                printf("\033[1;31m--- WHOMP! WHOMP! ---\033[0m\n");
                printf("Points: 0\n");
                cpu_round_score = 0;
                break;
            }

            if ((cpu_total_score < 500) && (cpu_round_score < 500)) {
                printf("CPU needs 500 points to get on the score board, it only has %i\n\n", points_this_roll);
                if (rolls_left > 0) {
                    // Computer will always decide to contnue if it has not reached 500 points for the first time
                    printf("Computer decided to continue since it has not yet ever reached 500 points.\n");
                    continue;
                }
            } else {
                cpu_round_score += points_this_roll;
            }

            if (rolls_left > 0) {
                // roll a two sides dice to see if the computer will contiue; 1 he continues and 2 he stops rolling
                if ((rand() % (2 - 1 + 1) + 1) == 2) {
                    printf("Computer decided not to continue\n");
                    break;
                } else {
                    printf("Computer decided to continue\n")
                }
            }
        } while (rolls_left > 0);

        if ((cpu_total_score >= 500) || (cpu_round_score >= 500)) {	 	  	 	  	 	     	     	 	
            cpu_total_score += cpu_round_score;
        }
        
        printf("Press \033[1;31m'ENTER'\033[0m to continue...\n\n");
        sleep(1);
        while (getchar() != '\n'); // ignore any other key press except enter "\n"
        fflush(stdout);
        roundnum++;
    } while ((player_total_score < max_score) && (cpu_total_score < max_score));

    if (player_total_score >= max_score) { // player ones
   
     printf("\t\t");
        
        printf("\t\t\t\t\t\n\n\n\n\n \033[1;33m %s WINS\033[0m\n\n\n\n\n\n", name);
    } else { //computer wins
        printf("\t\t\t\t\t\n\n\n\n\n\033[1;31mComputer wins\033[0m\n\n\n\n\n\n\n\n\n");
    }
    sleep(2);
} // end main    

/**************************************************** 
Function: scoreboard
Does: tracks the users score in the game 
Receives: two integers
Uses: Nothing 
Returns: An integer
****************************************************/

int scoreboard(int roll[6], int num_rolls, int *rolls_left) {

    int i, roll_score = 0, num_of_each_dice_side[7]; // only using positions 1 through 6 for readiability
    int num_of_each_side = 0;
    int check_one_through_six = 1;
    int num_times_pair_rolled = 0;
    int num_times_triplet_rolled = 0;
    int num_times_four_rolled = 0;

    *rolls_left = num_rolls; // Assume that non of the dice generated points

    for (i = 1; i <= 6; i++) {	 	  	 	  	 	     	     	 	
        num_of_each_dice_side[i] = 0;
    }

    for (i = 0; i < num_rolls; i++) {
        (num_of_each_dice_side[roll[i]])++;
        switch (roll[i]) {
        case 1:
            roll_score += 100;
            (*rolls_left)--;
            break;
        case 5:
            roll_score += 50;
            (*rolls_left)--;
            break;
        default:
            break;
        }
    }

    for (i = 1; i <= 6; i++) {
        switch (num_of_each_dice_side[i]) {
        case 3:
            switch (i) {
            case 1:
                roll_score = roll_score + 300 - 300;
                break;
            case 2:
            case 3:
            case 4:
            case 6:
                roll_score += (i * 100);
                *rolls_left = (*rolls_left) - 3;
                break;
            case 5:
                roll_score = (roll_score + (i * 100)) - 150;
                break;
            default:
                break;
            }	 	  	 	  	 	     	     	 	
            break;
        case 4:
            roll_score += 1000;
            if ((i != 1) && (i != 5)) {
                *rolls_left = (*rolls_left) - 4;
            } else if (i == 1) {
                roll_score -= 400;
            } else if (i == 5) {
                roll_score -= 200;
            }
            break;
        case 5:
            roll_score += 2000;
            if ((i != 1) && (i != 5)) {
                *rolls_left = (*rolls_left) - 5;
            } else if (i == 1) {
                roll_score -= 500;
            } else if (i == 5) {
                roll_score -= 250;
            } 
            break;
        case 6:
            roll_score += 3000;
            *rolls_left = 0;
            if (i == 1) {
                roll_score -= 600;
            } else if (i = 5) {
                roll_score -= 300;
            }
            break;
        default:
            break;
        } // end switch
    } // end for

    int num_one_pairs=0, num_five_pairs=0;
    int num_one_tripplets=0, num_five_tripplets=0;
    int num_one_quadruplets=0, num_five_quadruplets=0;
    
    /*
    printf("\n\nnum_of_each_dice_side: ");
    for (i = 1; i <= num_rolls; i++) {	 	  	 	  	 	     	     	 	
        printf("%i, ", num_of_each_dice_side[i]);
    }
    printf("\n");
    */
    
    if (num_rolls == 6) {
        for (i = 1; i <= num_rolls; i++) {
            if (num_of_each_dice_side[i] != 1) {
                check_one_through_six = 0;
            }
            if (num_of_each_dice_side[i] == 2) {
                num_times_pair_rolled++;
                // printf("\nWe found a pair: %d\n", i);
                if (i == 1) {
                    num_one_pairs++;
                } else if (i == 5) {
                    num_five_pairs++;
                }
            }
            if (num_of_each_dice_side[i] == 3) {
                num_times_triplet_rolled++;
                if (i == 1) {
                    num_one_tripplets++;
                } else if (i == 5) {
                    num_five_tripplets++;
                }                
            }
            if (num_of_each_dice_side[i] == 4) {
                num_times_four_rolled++;
                if (i == 1) {
                    num_one_quadruplets++;
                } else if (i == 5) {
                    num_five_quadruplets++;
                }                  
            }
        }	 	  	 	  	 	     	     	 	

        if (check_one_through_six == 1) {
            roll_score += 1500 - 150;
            *rolls_left = 0;
        }

        if (num_times_pair_rolled == 3) { // three pairs
            roll_score += 1500;
            *rolls_left = 0;
            roll_score -= (num_one_pairs*2*100);
            roll_score -= (num_five_pairs*2*50);
        }

        if ((num_times_four_rolled == 1) && (num_times_pair_rolled == 1)) { // only gives 1000 points
            roll_score += 1500;
            *rolls_left = 0;
            roll_score -= (num_one_pairs*2*100);
            roll_score -= (num_five_pairs*2*50);
            roll_score -= (num_one_quadruplets*4*100);
            roll_score -= (num_five_quadruplets*4*50);
            
        }

        if (num_times_triplet_rolled == 2) { // Doesent give 2500 points only gives 600
            roll_score += 2500;
            *rolls_left = 0;
            roll_score -= (num_one_tripplets*3*100);
            roll_score -= (num_five_tripplets*3*50);
        }
    }
    return roll_score;
} // end main

void exit_game() {
    system("clear");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\033[1m\033[1;33m  Thank you for playing, come back soon.\033[22m\033[0m");
    sleep(1);
}	 	  	 	  	 	     	     	 	

void gamerules() {
    char enter_ch;

    //Game rules:
    printf("\t\t\t\033[4m\033[1mGame Rules:\n\n\n");
    printf("> \033[0m\033[22mTo initially display your points tally on the scoreboard, you must have a \nrunning total of 500 points before you stop rolling.\n\n");
    printf("> Dice cannot be joined together on multiple rolls. Each roll collects its \nindividual points that are added to make a final round score.\n\n");
    printf("> If you cannot score from any dice after a roll, that is a WHOMP! and your \nfinal score that round becomes 0.\n\n");
    printf("> The player who reaches the max score first wins the game!\n\n\n");

    //Points:
    printf("\t\t\t\033[4m\033[1mPoints Added When:\n\n\n");
    printf("\033[0m\033[22m--> 1 or 5\n");
    printf("--> Three of a kind\n");
    printf("--> Three pairs\n");
    printf("--> Two triplets\n");
    printf("--> A six-dice straight (1,2,3,4,5,6)\n");
    printf("--> 4 of a kind and one pair\n");
    printf("--> Any 4, 5 or 6 of a kind\n\n\n");

    //points chart:
    printf("\t\t\t\033[1m\033[4mPoints Per Roll:\n\n");
    printf("\033[0m\033[22munused 1: 100 points\t\t|\t     unused 5: 50 points\n");
    printf("1-1-1: 300 points\t\t|\t     3 pairs: 1500 points\n");
    printf("2-2-2: 200 points\t\t|\t     2 triplets: 2500 points\n");
    printf("3-3-3: 300 points\t\t|\t     1-6 straight: 1500 points\n");
    printf("4-4-4: 400 points\t\t|\t     4 same + pair: 1500 points\n");
    printf("5-5-5: 500 points\t\t|\t     4 of a kind: 1000 points\n");
    printf("6-6-6: 600 points\t\t|\t     5 of a kind: 2000 points\n");

    //Exit Game Rules:
    printf("\n\nPress the \033[1m\033[1;31m'ENTER'\033[0m key\033[22m to return to Main menu...");
    while (getchar() != '\n'); // ignore any other key press except enter "\n"
    system("clear");
} // end game rules

void menu() {	 	  	 	  	 	     	     	 	

    char choice;
    int i, j;
    int cont = 1;

    //Title Box

    while (cont != 0) {
        //Top line
        printf("\t\t");
        for (i = 1; i <= 41; i++) {
            printf("\033[0;32m=\033[0m");
        }

        printf("\n");

        //Whomp Title
        printf("\t\t");
        printf("\033[0;34m|\033[0m     Welcome To Abdu's Game of         \033[1;31m|\033[0m\n");
        printf("\t\t");
        printf("\t\t  \033[0;34mW\033[0;32mH\033[0;33mO\033[0;31mM\033[0;34mP\033[0m!                 ");

        //columns
        for (i = 1; i <= 2; i++) {
            printf("\n\t\t");
            printf("\033[0;34m|\033[0m\t\t\t\t\t\033[1;31m|\033[0m\n");
        }

        //Bottom Line
        printf("\t\t");
        for (i = 1; i <= 41; i++) {
            printf("\033[1;33m=\033[0m");
        }

        printf("\n\n\n\033[0;34m--> 1) WHOMP Rules:\n");
        printf("\033[0;33m--> 2) Start Game:\n");
        printf("\033[0;32m--> 3) Exit Game:\n\n");
        printf("\033[0mChoice Entry: ");
        scanf(" %c", &choice);
        getchar(); // Eat up extra Enter character

        switch (choice) {	 	  	 	  	 	     	     	 	
        case '1':
            fflush(stdout);
            sleep(1);
            gamerules();
            break;

        case '2':
            fflush(stdout);
            sleep(1);
            main_game();
            break;

        case '3':
            fflush(stdout);
            sleep(1);
            exit_game();
            cont = 0;
            break;
        }
    }
    sleep(1);
    system("clear");
}

int main(void) {
    srand((unsigned int) time(NULL)); // Do this only once
    menu();
    return 0;
}	 	  	 	  	 	     	     	 	
