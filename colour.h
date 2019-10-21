#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h> 

using namespace std;

int colour(int total)	{
	int flag = 0;
	int f = 0;
	string ans;
	int num;
	int betVal;
	srand (time(NULL));
	while(f == 0)	{ //loop until valid input given
		cout << "Do you want to bet on red or black? (Red/Black)" << endl;
		cin >> ans; //accept input
		if(ans == "Red")	{
			num = 1;
			break;
		}
		else if(ans == "Black")	{
			num = 0;
			break;
		}
		else {
			cout << ans << " is not a valid input." << endl;
		}
	}
	while(flag == 0)	{ //loop until valid input given
		cout << "Enter your bet value: ";
		cin >> betVal;
		if(betVal > total)	{
			cout << "You have $" << total << ". You cannot bet $" << betVal << "." << endl;
			continue;
		}
		else	{
			break;
		}
	}
	int actual = rand() % 39 + 1; //generate random number
	//associate 0 and 00 with integers
	if(actual == 37)	{
		cout << "You landed on 0" << endl;
	}
	else if(actual == 38)	{
		cout << "You landed on 00" << endl;
	}
	//set odd numbers to red and even numbers to black
	else if(actual%2 == 0)	{
		cout << "You landed on black."  << endl;
	}
	else	{
		cout << "You landed on red." << endl;
	}
	//check if user won or lost
	if(actual == 37 || actual == 38)	{
		cout << "You lose!" << endl;
		total = total - betVal;
	}
	else if(num == (actual%2))	{
		cout << "You win!" << endl;
		total = total + betVal;
	}
	else	{
		cout << "You lose!" << endl;
		total = total - betVal;
	}
	//output total amount of money left
	cout << "You have $" << total << "." << endl;
	return total;
}
