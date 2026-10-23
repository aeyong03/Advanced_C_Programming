#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* Shuffle() {
	int* deck = (int*)malloc(sizeof(int) * 20);
	for (int i = 0; i < 20; i++) {
		deck[i] = (rand() % 13) + 1;
	}


	return deck;
}

void Initialization(int** user, int** dealer, int* deck, int* deck_idx) {
	*user = (int*)malloc(sizeof(int) * 2);
	*dealer = (int*)malloc(sizeof(int) * 2);


	(*user)[0] = deck[(*deck_idx)++];
	(*dealer)[0] = deck[(*deck_idx)++];
	(*user)[1] = deck[(*deck_idx)++];
	(*dealer)[1] = deck[(*deck_idx)++];
}

int GetCardValue(int card) {
	if (card >= 10) return 10;

	return card;
}

void PrintCardName(int card) {
	if (card == 1) printf("A");
	else if (card == 11) printf("J");
	else if (card == 12) printf("Q");
	else if (card == 13) printf("K");
	else printf("%d", card);


}

int CalculateSum(int* cards, int count) {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += GetCardValue(cards[i]);
	}

	return sum;
}

void Status(int* user, int user_cnt, int* dealer, int dealer_cnt) {
	printf("Dealer: ");
	for (int i = 0; i < dealer_cnt; i++) {
		PrintCardName(dealer[i]);
		if (i < dealer_cnt - 1) printf(", ");
	}


	printf(" (гу: %d)\n", CalculateSum(dealer, dealer_cnt));



	printf("User: ");
	for (int i = 0; i < user_cnt; i++) {
		PrintCardName(user[i]);
		if (i < user_cnt - 1) printf(", ");
	}


	printf(" (гу: %d)\n", CalculateSum(user, user_cnt));
}

void Hit(int** user, int* user_cnt, int* deck, int* deck_idx) {
	(*user_cnt)++;
	*user = (int*)realloc(*user, sizeof(int) * (*user_cnt));
	(*user)[(*user_cnt) - 1] = deck[(*deck_idx)++];
}

void End(int** dealer, int* dealer_cnt, int* deck, int* deck_idx) {
	while (CalculateSum(*dealer, *dealer_cnt) <= 16) {
		(*dealer_cnt)++;

		*dealer = (int*)realloc(*dealer, sizeof(int) * (*dealer_cnt));

		(*dealer)[(*dealer_cnt) - 1] = deck[(*deck_idx)++];
	}
}

void Result(int* user, int user_cnt, int* dealer, int dealer_cnt) {
	int user_sum = CalculateSum(user, user_cnt);
	int dealer_sum = CalculateSum(dealer, dealer_cnt);

	if (user_sum > 21) {
		printf("Busted! Over 21! Dealer Wins.\n");
	}
	else if (dealer_sum > 21) {
		printf("User Wins! Dealer Busted!\n");
	}
	else if (user_sum == 21) {
		printf("BlackJack! Winner Winner Chicken Dinner! User Win!\n");
	}
	else if (user_sum > dealer_sum) {
		printf("User Wins!\n");
	}
	else if (user_sum < dealer_sum) {
		printf("Dealer Wins!\n");
	}
	else {
		printf("Draw!\n");
	}

	free(user);
	free(dealer);
}

int main() {
	char command[20];
	srand((unsigned int)time(NULL));

	while (1) {
		printf("Game Start? ");
		scanf("%s", command);

		if (strcmp(command, "End") == 0 || strcmp(command, "Quit") == 0) {
			break;
		}
		else if (strcmp(command, "Start") != 0) {
			printf("Error: Wrong Input, Try Again.\n");
			continue;
		}

		int* deck = Shuffle();
		int deck_idx = 0;

		int* user = NULL;
		int* dealer = NULL;
		int user_cnt = 2, dealer_cnt = 2;

		Initialization(&user, &dealer, deck, &deck_idx);
		Status(user, user_cnt, dealer, dealer_cnt);

		int user_busted = 0;
		while (1) {
			if (CalculateSum(user, user_cnt) > 21) {
				user_busted = 1;
				break;
			}

			printf("\nMore Card? ");
			scanf("%s", command);

			if (strcmp(command, "Hit") == 0) {
				Hit(&user, &user_cnt, deck, &deck_idx);
				printf("\n");


				Status(user, user_cnt, dealer, dealer_cnt);
				printf("\n");printf("\n");

			}
			else if (strcmp(command, "Stay") == 0) {
				break;
			}
			else {
				printf("Error: Wrong Input, Try Again.\n");
			}
		}

		if (!user_busted) {

			End(&dealer, &dealer_cnt, deck, &deck_idx);
			Status(user, user_cnt, dealer, dealer_cnt);
		}

		Result(user, user_cnt, dealer, dealer_cnt);
		free(deck);
		printf("\n");
	}

	return 0;






}