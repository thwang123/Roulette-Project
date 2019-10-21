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
	cin >> playerGameChoice; //accept input
	while(playerGameChoice != 'y')	{ //error checking input value
			cout << "I'm sorry but we only have the game roulette, would you like to play? (y/n)"<<endl;
			cin >> playerGameChoice;
	}
	while(flag == 0)	{ //loop until the player no longer wants to play
		cout << "What kind of bet would you like to place?" << endl;
		//output options and what to enter for each
		cout << "\t" << "Colour" << "\t" << "(C/Colour)" << endl;
		cout << "\t" << "Number" << "\t" << "(N/Number)" << endl;
		cout << "\t" << "Odd/even" << "\t" << "(OE)" << endl;
		cin >> ans; //accept input
		if(ans  == "OE")	{
			total = oddOrEven(total); //call odd or even function
		}
		else if(ans == "N" || ans == "Number")	{
			total = number(total); //call number function
		}
		else if(ans == "C" || ans == "Colour")	{
			total = colour(total); //call colour function
		}
		if(total == 0)	{ //if amount of money is 0 exit game
			cout << "You are out of money." << endl;
			cout << "Thank you" << endl << "Goodbye";
		}
		cout << "Repeat?" << endl; //ask if user wants to repeat
		cin >> ans;
		if(toupper(ans.at(0)) == 'N' || ans.at(0) == 'n')	{ //if user does not want to repeat Exit
			cout << "Thank you" << endl << "Goodbye";
			break;
		}
	}
}
