//Nicholas Altice
//This program predicts the growth of a bank account due to compunded interest.

#include <iostream>
using namespace std;
#include <math.h>

double comBal( double proChar, double thresh, int table,
               double initBal, double annInt, int investLen );
void comYears( double proChar, double thresh, int table, int& investLen,
            double& finalBal, double annInt, double goalBal );
int getInt();
double getDouble();
int getTable();
int getYesNo();
int getOption();

int main( )
{
	double proChar, thresh, initBal, annInt, goalBal, finalBal;
	int investLen, table, yesNo, oneOrTwo;
	
	cout << "Bank account growth prediction." << endl << endl;
	
	do
	{
		cout << "Please enter a processing charge(dollars): ";
		proChar = getDouble();
		cout << endl;
		
		cout << "Pleas enter a threshold(dollars): ";
		thresh = getDouble();
		cout << endl;
		
		cout << "Please enter the inital balance(dollars): ";
		initBal = getDouble();
		cout << endl;
		
		cout << "Please enter the annual interest rate(decimal): ";
		annInt = getDouble();
		cout << endl;
		
		do
		{
			cout << "Enter 1 to get the final balance ";
			cout << "in a number of years" << endl;
			cout << "or enter 2 to get the number of ";
			cout << "years to reach a goal balance: ";
			cin >> oneOrTwo;
			cout << endl;
			if ( oneOrTwo == 1 )
		    {
			   cout << "Please enter length of investment(years): ";
			   investLen = getInt();
			   cout << endl;
			   cout << "Would you like a table(y or n)?: ";
			   table = getYesNo();
			   cout << endl;
			   finalBal = comBal( proChar, thresh, table,
			                      initBal, annInt, investLen );
			   if(!table)
			   {
			   	  cout << "The final balance is $" << finalBal << "." << endl;
				  cout << endl;
			   }
		    }
		    else if ( oneOrTwo == 2 )
		    {
			   finalBal = initBal;
			   investLen = 0;
			   cout << "Please enter goal balance(dollars): ";
			   goalBal = getDouble();
			   cout << endl;
			   cout << "Would you like a table(y or n)?: ";
			   table = getYesNo();
			   cout << endl;
			   comYears( proChar, thresh, table, investLen, 
			             finalBal, annInt, goalBal );
			   if(!table)
			   {
			   	  cout << "It took " << investLen << " years ";
			   	  cout << "to reach $" << finalBal << ".";
				  cout << endl << endl;
			   }
		    }
		    else
		    {
		    	cout << "Please enter 1 or 2." << endl << endl;
			}
		}
		while ( oneOrTwo != 1 && oneOrTwo != 2 );
		
		cout << "Would you like to run another account?(y or n): ";
		yesNo = getYesNo();
		cout << endl;
		
	}
	while ( yesNo );
	cout << "End of program." << endl << endl;
	return 0;
}
double comBal( double proChar, double thresh, int table,
               double initBal, double annInt, int investLen )
{
	int ix;
	double bal, interest;
	bal = initBal;
	for ( ix = 1; ix <= investLen; ++ix )
	{
		interest = bal * annInt;
		bal = bal + interest;
		if ( bal < thresh )
		   bal = bal - proChar;
	    if ( table && ix == 1 )
	    {
	    	cout << "Year\tBalance" << endl << endl;
	    	cout << ix << "\t" << bal << endl << endl;
		}
		else if ( table )
		{
			cout << ix << "\t" << bal << endl << endl;
		}
	}
	return bal;
}
void comYears( double proChar, double thresh, int table, int& investLen,
            double& finalBal, double annInt, double goalBal )
{
	double interest;
	while ( finalBal < goalBal )
	{
		interest = finalBal * annInt;
		finalBal = finalBal + interest;
		++investLen;
		if ( finalBal < thresh )
		   finalBal = finalBal - proChar;
	    if ( table && investLen == 1 )
	    {
	    	cout << "Year\tBalance" << endl << endl;
	    	cout << investLen << "\t" << finalBal << endl << endl;
		}
		else if ( table )
		{
			cout << investLen << "\t" << finalBal << endl << endl;
		}
	}
}
double getDouble()
{
	double input;
	do
	{
		cin >> input;
		if( input < 0 )
		{
			cout << endl;
			cout << "Error. Please enter a positive number: ";
		}
	}
	while ( input < 0 );
	return input;
}
int getInt()
{
	int input;
	do
	{
		cin >> input;
		if( input < 0 )
		{
			cout << endl;
			cout << "Error. Please enter a positive number: ";
		}
	}
	while ( input < 0 );
	return input;
}
int getYesNo()
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
