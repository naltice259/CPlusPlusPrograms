//Nicholas Altice
//Defines a class for an NBA player
//and a main program to test it

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>

char *readLine();
int getAgain();
int strLen( char *s );

//NBAPlayer.h

class NBAPlayer
{
	char *_name;
	int _gamesplayed;
	int _totalpoints;
	public:
		NBAPlayer( char *name);
		~NBAPlayer();
		void show();
		char *getName();
		int getGames();
		int getPoints();
		double getAverage(int points, int games);
		void update(int score);
		int compare( NBAPlayer *other);
};

NBAPlayer::NBAPlayer(char *name)
{
	_name = new char[ strlen(name) + 1 ];
	strcpy(_name,name);
	_gamesplayed = 0;
	_totalpoints = 0;
}

NBAPlayer::~NBAPlayer()
{
	delete[] _name;
}

void NBAPlayer::show()
{
	cout << endl;
	cout << "        name: " << _name << endl;
	cout << "games played: " << _gamesplayed << endl;
	cout << "total points: " << _totalpoints << endl;
	cout << endl;
}

char *NBAPlayer::getName()
{
	char *tName = new char[strlen(_name) + 1];
	strcpy(tName, _name);
	return tName;
}

int NBAPlayer::getGames()
{
	return _gamesplayed;
}

int NBAPlayer::getPoints()
{
	return _totalpoints;
}

double NBAPlayer::getAverage(int points, int games)
{
	return (1.0 * points / games);
}

void NBAPlayer::update(int score)
{
	_totalpoints = _totalpoints + score;
	++_gamesplayed;
}

int NBAPlayer::compare(NBAPlayer *other)
{
	int success;
	double ave1, ave2;
	ave1 = getAverage(other->_totalpoints, other->_gamesplayed);
	ave2 = getAverage(_totalpoints, _gamesplayed);
	if (ave1 > ave2)
	{
		success = 1;
	}
	else
	   success = 0;
	return success;
}

int main( )
{
	char *name1, *name2;
	int points1, points2, again;
	NBAPlayer *player1;
	NBAPlayer *player2;
	
	cout << "NBA player program." << endl << endl;
	
	do
	{
		name1 = readLine();
		name2 = readLine();
		player1 = new NBAPlayer(name1);
		player2 = new NBAPlayer(name2);
		do
		{
			cout << "Enter the points scored by Player1: ";
			cin >> points1;
			cout << endl;
			player1->update(points1);
			cout << "Enter the points scored by Player2: ";
			cin >> points2;
			cout << endl;
			player2->update(points2);
			player1->show();
			player2->show();
			if(player1->compare(player2))
			{
			   cout << "Player2 has the higher average" << endl;
			}
			else
			   cout << "Player1 has the higher average" << endl;
			cout << endl;
			cout << "Would you like to add another score?(y or n): ";
			again = getAgain();
			cout << endl;
			
		}while(again);
		cout<<"Would you like to create two more players?(y or n): ";
		again = getAgain();
		cout << endl;
		delete player1;
		delete player2;
		cin.get();
	} while(again);
	cout<<"End of program";
	return 0;
}
char *readLine()
{
	char *line1;
	char *line1base;
	char c;
	line1 = new char[81];
	line1base = line1;
	cout << "Enter a name: ";
	do
	{
		c = cin.get();
		if(c == '\n')
		{
			c = '\0';
		}
		else if (c == ' ')
		{
			c = '_';
		}
		*(line1++) = c;
	}while(c != '\0');
	line1 = line1base;
	char *line2;
	line2 = new char[strLen(line1base) + 1];
	char *base;
	base = line2;
	while( *line1base != '\0')
	{
		*(line2++) = *(line1base++);
	}
	*line2 = '\0';
	delete line1;
	cout << endl;
	return base;
}
int getAgain()
{
	int input;
	char yesNo;
	do
	{
		cin >> yesNo;
		if(yesNo == 'y')
		{
			input = 1;
		}
		else if (yesNo == 'n')
		{
			input = 0;
		}
		else
		{
			input = 2;
			cout << endl;
			cout << "Error. Please enter y or n: " << endl << endl;
		}
	}
	while ( input != 0 && input != 1 );
	return input;
}
int strLen( char *s )
{
	char *start;
	start = s;
	while ( *s != '\0' )++s;
	return (s - start);
}
