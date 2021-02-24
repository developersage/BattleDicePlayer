/*
Battle Dice is an 2 player game where 2 players each toss a die 3 times. 
At each toss, the player whose die shows the larger number wins the toss. 
If the numbers are equal then no one wins the toss - the toss is tied. 
The player who wins the greater number of tosses wins the game. 
if no player wins the greater number of tosses then the player whose die numbers'  sum is larger wins the game. 
If the die numbers' sums are equal then the game is tied. 
Write a program that simulates one game of Battle Dice. Use arrays and use the Player class in your solution.
*/
#include "Player.h"
#include <ctime>
#include <random>
#include <string>
#include <iostream>
using namespace std;

Player::Player(const string& new_name)
{
	_name = new_name;
	_sums = 0;
	_wins = 0;
	_score = 0;
}

//accessors
string Player::name() const
{
	return _name;
}
int Player::sums() const
{
	return _sums;
}
int Player::wins() const
{
	return _wins;
}
int Player::score() const {
	return _score;
}
void Player::name(const string& new_name) {
	_name = new_name;
}

//custom methods
void Player::clear()
{
	_sums = 0;
	_wins = 0;
	_score = 0;
}
void Player::addScore(int new_score) {
	_score = new_score;
}
void Player::addDie(int new_die)
{
	_sums += new_die;
}
void Player::addWin()
{
	_wins++;
}