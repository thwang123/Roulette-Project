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
	cout << "Do you want to bet on red or black? (Red/Black)" << endl;
	cin >> ans;
	if(ans == "Red")	{
		num = 1;
	}
	if(ans == "Black")	{
		num = 0;
	}
	while(flag == 0)	{
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
	int actual = rand() % 39 + 1;
	if(actual == 37)	{
		cout << "You landed on 0" << endl;
	}
	else if(actual == 38)	{
		cout << "You landed on 00" << endl;
	}
	else if(actual%2 == 0)	{
		cout << "You landed on black."  << endl;
	}
	else	{
		cout << "You landed on red." << endl;
	}
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
	cout << "You have $" << total << "." << endl;
	return total;
}
