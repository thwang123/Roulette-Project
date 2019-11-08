#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h> 
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int colour(int total)	{
	int flag = 0;
	int f = 0;
	string ans;
	int num;
	int betVal;
	int result;
	map<string, vector<int> > m;
	vector<int> blackNum = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
	vector<int> redNum = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
	m.insert(pair<string,vector<int> > ("Black", blackNum));
	m.insert(pair<string,vector<int> > ("Red", redNum));
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
	//compare values to determine what was landed on
	if(actual == 37 || actual == 38)	{
		if(actual == 37)	{
			cout << "You landed on 0." << endl;
		}
		else	{
			cout << "You landed on 00." << endl;
		}
		cout << "You landed on green." << endl;
	}
	
	//check map
	else	{
		for(auto i = m.find("Black")->second.begin(); i != m.find("Black")->second.end(); i++)	{
			if(*i == actual)	{
				cout << "You landed on " << actual << " which is black." << endl;
				result = 0;
				break;
			}
		}
		for(auto i = m.find("Red")->second.begin(); i != m.find("Red")->second.end(); i++)	{
			if(*i == actual)	{
				cout << "You landed on " << actual << " which is red." << endl;
				result = 1;
				break;
			}
		}
	}
	
	//check if user won or lost
	if(actual == 37 || actual == 38)	{
		cout << "You lose!" << endl;
		total = total - betVal;
	}
	else if(num == result)	{
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
