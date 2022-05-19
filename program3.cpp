// Nicholas Altice - Compute total volume of oblate spheroids

#include <iostream>
using namespace std;
#include <math.h>

int main( )
{
	double volume, majorA, minorA;
	int spheroidsN;
	const double PI = 3.14159;
	
	cout << endl << "Calculating the total volume";
	cout << " of a number of oblate spheroids" <<endl << endl;
	
	do
	{
		cout << "Enter the number of spheroids: ";
		cin >> spheroidsN;
		if ( spheroidsN <= 0 )
		cout << endl << "Enter a positive number" << endl << endl;
	}
	while ( spheroidsN <= 0 );
	cout << endl;
	for ( int i = 1; i <= spheroidsN; ++i )
	{
		do
		{
			cout << "Enter the major axis of spheroid " << i << " (feet): ";
			cin >> majorA;
			if ( majorA <= 0 )
 		  	cout << endl << "Enter a positive number" << endl << endl;
		}
		while ( majorA <= 0 );
		cout << endl;
		do
		{
			cout << "Enter the minor axis of spheroid " << i << " (feet): ";
			cin >> minorA;
			if ( minorA <= 0 )
			cout << endl << "Enter a positive number" << endl << endl;
		}
		while ( minorA <= 0 );
		cout << endl;
		volume = volume + ( (4.0 / 3) * ( PI * majorA * pow(minorA,2) ) );
	}
	cout << "Total volume of " << spheroidsN << " spheroids: " << volume;
	cout << "cubic feet" << endl << endl;
	cout << "End of program." << endl;
	return 0;
}
