//Nicholas Altice
//This program reads a line of text and counts how many times a user-specified
//character appears in the text.

#include <iostream>
using namespace std;
#include <math.h>

char *readLine();
int count( char *line , char find );
int getAgain();
int strLen( char *s );

int main( )
{
	char find;
	char *line;
	int num, again;
	
	cout << "Letter counting program." << endl << endl;
	
	do
	{
		line = readLine();
		do
		{
			cout << "Enter a character: ";
			cin >> find;
			cout << endl;
			num = count( line, find );
			cout << "Line contains " << num;
			cout << " instances of " << find << endl;
			cout << endl;
			cout << "Would you like to try another character?(y or n): ";
			again = getAgain();
			cout << endl;
			
		}while(again);
		cout<<"Would you like to enter a new line?(y or n): ";
		again = getAgain();
		cout << endl;
		delete line;
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
	cout << "Enter a line of text: ";
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
int count( char *line , char find )
{
	int num = 0;
	while ( *line != '\0' )
	{
		if (find == *line) ++num;
		++line;
	}
	return num;
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
