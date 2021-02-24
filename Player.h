#pragma once
#include <string>
using namespace std;

class Player
{
public:
	//constructor
	Player(const string& new_name = "No Name");
	//accessors
	string name() const;
	int sums() const;
	int wins() const;
	int score() const;

	//mutators
	void name(const string& new_name);

	//custom methods
	void clear();
	void addScore(int);
	void addDie(int new_die);
	void addWin();


private:
	string _name;
	int _sums;
	int _wins;
	int _score;
};

