#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h> 

using namespace std;

int number(int total)	{
	int flag = 0;
	int f = 0;
	string ans;
	float betVal;
	int betNum;
	srand (time(NULL));
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
	while(f == 0)	{
		cout << "Enter the number on which you want to bet: ";
		cin >> ans;
		if(ans != "0" && ans != "00")	{
			betNum = atoi(ans.c_str());
		}
		if(ans == "0")	{
			betNum = 37;
		}
		if(ans == "00")	{
			betNum = 38;
		}
		if(betNum < 1 || betNum > 38)	{
			cout << "Your bet must be between 0 and 36 or a 00." << endl;
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
	else	{
		cout << "you landed on " << actual  << endl;
	}
	if(betNum == actual)	{
		cout << "You win!" << endl;
		total = total + 35*betVal;
	}
	else if(betNum != actual)	{
		cout << "You lose!" << endl;
		total = total - betVal;
	}
	cout << "You have $" << total << "." << endl;
	return total;	
}
