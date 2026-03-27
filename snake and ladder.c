#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define WIN_POSITION 100

int rollDice(){
	return(rand() % 6)+1;
}

// Check for snake or ladder, print message

int checkSnakesAndLadders(int position){
	int old_position = position;
	switch(position){
		case 4: position = 14;break;	//ladder
		case 9: position = 31;break;	//ladder
		case 17: position = 7;break;	//snake
		case 20: position = 38;break;	//ladder
		case 28: position = 84;break;	//ladder
		case 40: position = 59;break;	//ladder
		case 51: position = 67;break;	//ladder
		case	54: position = 34;break;	//snake
		case 62: position = 19;break;	//snake
		case 63: position = 81;break;	//ladder
		case 64: position = 60;break;	//snake
		case 71: position = 91;break;	//ladder
		case 87: position = 24;break;	//snake
		case 93: position = 73;break;	//snake
		case 95: position = 75;break;	//snake
		case 99: position = 78;break;	//snake
	}

	if (position > old_position)
		printf("Climbed a ladder to %d!\n", position);
	else if (position < old_position)
		printf("Bitten by a snake! Slide down to %d!\a\n",position);

	return position;
}

void playGame() {
	int pos1 = 0,pos2 = 0;
	int dice,turn =1;
	char temp;

	while (pos1 < WIN_POSITION && pos2 < WIN_POSITION){
		printf("\n--- Player %d's Turn ---\n",turn);
		printf("Press Enter to roll the dice...");
		getchar();

		dice=rollDice();
		printf("Rolled a %d\n",dice);

		if (turn ==1) {
			if ( pos1+ dice <= WIN_POSITION) {
				pos1 += dice;
				pos1 = checkSnakesAndLadders(pos1);
			}
			printf("Player 1 is now at position %d\n",pos1);
			if (pos1 == WIN_POSITION) {
				printf("\n PLAYER 1 WINS THE GAME! \n");
				break;
			}
			turn =2;
		   } else {
			if (pos2 + dice <WIN_POSITION) {
				pos2+= dice;
				pos2 = checkSnakesAndLadders(pos2);
			}
			printf("Player 2 is now at position %d\n",pos2);
			if ( pos2 == WIN_POSITION) {
				printf("\n PLAYER 2 WINS THE GAME! \n");
				break;
			    }
			    turn =1;
			}
		}
}

int main() {
	char choice;
	srand(time(NULL));  //seed for randomness

	do{
	   playGame();
	   printf("\nDo you want to play again? (y/n): ");
	   scanf(" %c",&choice);
	   while(getchar() != '\n'); // clear input buffer
	}while(tolower(choice) == 'y');

    printf("Thanks for playing!\n");
    return 0;
}
