#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int numbers(int total)	{
	int betOne;
	int betTwo;
	int valOne;
	int valTwo;
	string ans;
	string ansOne;
	string ansTwo;
	int f = 0;
	while(f == 0)	{
		cout << "Enter the first number upon which you want to bet and the amount you wish to bet on it (space separated): "; //accept first bet number and value;
		cin.ignore();
		getline(cin, ans);
		//split string into bet and value separate strings
		ansOne = ans.substr(0, ans.find(" "));
		ansTwo = ans.substr(ans.find(" "), string::npos);
		//cast bet value string string to integer;
		betOne = atoi(ansTwo.c_str());
		//check if bet number is 0 or double 0
		//set integer value
		if(ansOne != "0" && ans != "00")	{
			valOne = atoi(ansOne.c_str());
		}
		if(ansOne == "0")	{
			valOne = 37;
		}
		if(ansOne == "00")	{
			valOne = 38;
		}
		if(valOne < 1 || valOne > 38)	{
			cout << "Your bet must be between 0 and 36 or a 00." << endl;
			continue;
		}
		if(betOne > total)	{
			cout << "You have $" << total << ". You cannot bet $" << betOne << "." << endl;
			continue;
		}
		break;
	}
	f = 0;
	while(f == 0)	{ //accept second bet number and value
		cout << "Enter the second number upon which you want to bet and the amount you wish to bet on it (space separated): ";
		getline(cin, ans);
		ansOne = ans.substr(0, ans.find(" "));
		ansTwo = ans.substr(ans.find(" "), string::npos);
		betTwo = atoi(ansTwo.c_str());
		if(ansOne != "0" && ans != "00")	{
			valTwo = atoi(ansOne.c_str());
		}
		if(ansOne == "0")	{
			valTwo = 37;
		}
		if(ansOne == "00")	{
			valTwo = 38;
		}
		if(valTwo < 1 || valTwo > 38)	{
			cout << "Your bet must be between 0 and 36 or a 00." << endl;
			continue;
		}
		if(betTwo > total)	{
			cout << "You have $" << total << ". You cannot bet $" << betTwo << "." << endl;
			continue;
		}
		break;
	}
	//generate random number and enter the number landed on
	int actual = rand() % 39 + 1;
	if(actual == 37)	{
		cout << "You landed on 0" << endl;
	}
	else if(actual == 38)	{
		cout << "You landed on 00" << endl;
	}
	else	{
		cout << "You landed on " << actual  << endl;
	}
	
	//update the total
	
	int temp = total;
	
	if(valOne == actual)	{
		total = total + 35*betOne;
	}
	if(valTwo == actual)	{
		total = total + 35*betTwo;
	}
	if(valOne != actual)	{
		total = total - betOne;
	}
	if(valTwo != actual)	{
		total = total - betTwo;
	}
	
	if(temp < total)	{
		cout << "You win!" << endl;
	}
	else if(temp == total)	{
		cout << "You netted 0 dollars." << endl;
	}
	else	{
		cout << "You lose!" << endl;
	}
	
	cout << "You have $" << total << "." << endl;
	
	return total;
}
