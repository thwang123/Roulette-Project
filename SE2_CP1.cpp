#include "oddOrEven.h"
#include "number.h"
#include "colour.h"

using namespace std;

int main()	{
	string ans;
	int total = 300;
	int flag = 0;
	char playerGameChoice;
	int playerRouletteChoice;
	cout << "Hello and welcome to Command Line Casino! At the moment we have the game roulette to play. Would you like to play? (y/n)" << endl;
	cin >> playerGameChoice;
	while(playerGameChoice != 'y')	{
			cout << "I'm sorry but we only have the game roulette, would you like to play? (y/n)"<<endl;
			cin >> playerGameChoice;
	}
	while(flag == 0)	{
		cout << "What kind of bet would you like to place?" << endl;
		cout << "\t" << "Colour" << "\t" << "(C/Colour)" << endl;
		cout << "\t" << "Number" << "\t" << "(N/Number)" << endl;
		cout << "\t" << "Odd/even" << "\t" << "(OE)" << endl;
		cin >> ans;
		if(ans  == "OE")	{
			total = oddOrEven(total);
		}
		else if(ans == "N")	{
			total = number(total);
		}
		else if(ans == "C" || ans == "Colour")	{
			total = colour(total);
		}
		if(total == 0)	{
			cout << "You are out of money." << endl;
			cout << "Thank you" << endl << "Goodbye";
		}
		cout << "Repeat?" << endl;
		cin >> ans;
		if(toupper(ans.at(0)) == 'N')	{
			cout << "Thank you" << endl << "Goodbye";
			break;
		}
	}
}
