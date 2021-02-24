#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include "Player.h"
using namespace std;

int findHighest(Player*, int, int);
int count(Player*, int, int, int, int&);

int main() {
	srand(time(0));
	string continu = "y";
	int rollDice, index, score, winners, win, sumWinners, sum;
	const int size = 5;
	do {
		system("cls");
		Player player[size];
		string names[size] = { "David", "Daniel", "Timothy", "Sarah", "John" };
		for (int i = 0; i < size; i++) {
			player[i].name(names[i]);
		}
		cout << "       Battle Dice Game       " << endl;
		for (int i = 0; i < size; i++) {
			cout << "------------------------------" << endl;
			cout << "<Round " << i + 1 <<">   rolling dice..." << endl;
			for (int j = 0; j < size; j++) {
				rollDice = (rand() % 6) + 1;
				player[j].addScore(rollDice);
				player[j].addDie(rollDice);
				cout << player[j].name() << " --> " << rollDice << "." << endl;
			}
			score = findHighest(player, size, 1);
			cout << "Players with the most scores: " << endl;
			winners = count(player, size, 1, score, index);
			cout << endl;
			if (winners > 1) {
				cout << "     Round " << i + 1 << " is a tie.     " << endl;
			}
			else {
				cout << "    " <<player[index].name() << " wins the round " << i + 1 << ".    " << endl;
			}
		}
		cout << "------------------------------" << endl;
		cout << "        *Final result*        " << endl;
		cout << "Name    # of win   total points " << endl;
		
		for (int l = 0; l < size; l++) {
			cout << setw(8) << left << player[l].name() << "    " << player[l].wins() << "         " << player[l].sums() << endl;
		}

		win = findHighest(player, size, 2);
		sum = findHighest(player, size, 3);

		winners = count(player, size, 2, win, index);
		if (winners > 1) {
			cout << "There are players with equal amount of wins." << endl;
			sumWinners = count(player, size, 3, sum, index);
			if (sumWinners > 1) {
				cout << "There are equal amount of sums as well." << endl;
				cout << "The game ends in tie." << endl;
			}
			else {
				cout << player[index].name() << " wins the BattleDice with the total sum of " << sum << "!" << endl;
			}		
		}
		else {
			cout << player[index].name() << " wins the BattleDice!" << endl;
		}
		
		cout << "Would you like to play again?" << endl;
		getline(cin, continu);
	} while (continu == "y" || continu == "Y");

	return 0;
}

int findHighest(Player *obj, int size, int n) {
	int highest = 0;
	switch (n) {
	case 1: //1. find highest point from dice.
		for (int i = 0; i < size; i++) {
			if (obj[i].score() > highest) {
				highest = obj[i].score();
			}
		}
		break;
	case 2: //2. find highest from wins.
		for (int i = 0; i < size; i++) {
			if (obj[i].wins() > highest) {
				highest = obj[i].wins();
			}
		}
		break;
	case 3: //3. find highest from sums.
		for (int i = 0; i < size; i++) {
			if (obj[i].sums() > highest) {
				highest = obj[i].sums();
			}
		}
		break;
	}	
	return highest;
}

int count(Player *obj, int size, int n, int value, int &index) {
	int num = 0;
	switch (n) {
	case 1: //1. count how many players have highest point.
		for (int i = 0; i < size; i++) {
			if (obj[i].score() == value) {
				obj[i].addWin();
				cout << obj[i].name() << "  ";
				index = i;
				num++;
			}
		}
		break;
	case 2: //2. count how many players have highest wins.
		for (int i = 0; i < size; i++) {
			if (obj[i].wins() == value) {
				index = i;
				num++;
			}
		}
		break;
	case 3: //3. count how many players have highest sums.
		for (int i = 0; i < size; i++) {
			if (obj[i].sums() == value) {
				index = i;
				num++;
			}
		}
	}
	return num;
}

