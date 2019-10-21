#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h> 
#include "numbers.h"

using namespace std;

int number(int total)	{
	//variable declarations
	int flag = 0;
	int f = 0;
	int loop = 0;
	string ans;
	float betVal;
	int betNum;
	int secondBet;
	int singleVal = 0;
	string firstVal;
	string secondVal;
	srand (time(NULL));
	while(loop == 0)	{ //loop until valid number entered
		cout << "How many numbers would you like to bet on?: ";
		cin >> singleVal;
		if(singleVal == 2)	{ //call function for multiple numbers
			total = numbers(total);
			return total;
		}
		else if(singleVal == 1)	{
				while(flag == 0)	{
					cout << "Enter your bet value: ";
					cin >> betVal; //accept single bet value
					if(betVal > total)	{ //check if within proper range
						cout << "You have $" << total << ". You cannot bet $" << betVal << "." << endl;
						continue;
					}
					else	{
						break;
					}
				}
				while(f == 0)	{ //accept bet number
					cout << "Enter the number on which you want to bet: ";
					cin >> ans;
					//convert to appropriate integer
					if(ans != "0" && ans != "00")	{
						betNum = atoi(ans.c_str());
					}
					if(ans == "0")	{
						betNum = 37;
					}
					if(ans == "00")	{
						betNum = 38;
					}
					if(betNum < 1 || betNum > 38)	{ //check if in range
						cout << "Your bet must be between 0 and 36 or a 00." << endl;
					}
					else	{
						break;
					}
				}
				//generate random number
				int actual = rand() % 39 + 1;
				//output which number was landed on
				if(actual == 37)	{
					cout << "You landed on 0" << endl;
				}
				else if(actual == 38)	{
					cout << "You landed on 00" << endl;
				}
				else	{
					cout << "you landed on " << actual  << endl;
				}
				//compute the new total
				if(betNum == actual)	{
					cout << "You win!" << endl;
					total = total + 35*betVal;
				}
				else if(betNum != actual)	{
					cout << "You lose!" << endl;
					total = total - betVal;
				}
				//output total
				cout << "You have $" << total << "." << endl;
				return total;	
		}
		else	{
			cout << "You must enter either 1 or 2." << endl;
		}
	}
}
