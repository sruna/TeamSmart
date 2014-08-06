//
//  main.cpp
//  Working
//
//  Created by Don Mclean on 6/25/14.
//  Copyright (c) 2014 Don Mclean. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

string flipcoin(string x, double& num_of_flips);

void printresult(int a, double& num_of_flips);

double findsrate(double num_of_flips, double matches);

int main()
{
    int user_input = 0;
    srand(time(NULL));
	string result;
	string value;
    double srate = 0;
    double num_of_flips = 0;
    double matches = 0;
	
	while (true) {
		cout << "Press 1 for Heads or 2 for Tails | Also Press 3 to end" << endl << endl;
		cin >> user_input;
		
        switch (user_input) {
            case 1:
                value = "Heads";
                break;
            case 2:
                value = "Tails";
                break;
            
            case 3:
                cout << endl << "Thanks for flipping! " << endl << endl;
                return 0;
                
            default:
                cout << endl << "Sorry... You failed to enter one of the following numbers: 1, 2, or 3. " << endl << endl;
                return 1;
        }
        

		result = flipcoin(result, num_of_flips);
		
		if (value == result) {
			cout << "Congrats u matched with " << result << endl << endl;
            matches++;
		} else {
			cout << "Sorry u didn't match with " << result << endl << endl;
		}
        
        srate = findsrate(num_of_flips, matches);
        
        cout << "Your Success Rate Is: " << srate << " percent!!!"<< endl << endl;
	}

    
    return 0;
}


double findsrate(double num_of_flips, double matches)
{
    
    return matches / num_of_flips * 100;
}

void printresult(int a, double& num_of_flips)
{
	string heads = "IT'S HEADS!!!";
	string tails = "IT'S TAILS!!!";
	
	cout << endl << "COIN FLIPPED" << endl << "............." << endl << endl;
	if (a == 1) {
		cout << heads << endl << endl;
	} else {
		cout << tails << endl << endl;
	}
	
	cout << "number of flips : " << num_of_flips << endl;
}

string flipcoin(string x, double& num_of_flips)
{
	string heads = "Heads";
	string tails = "Tails";
	string message1 = "COIN FLIPPED";
	int a = 0;
	a = rand() %2;
    
    //cout << endl << " a = " << a << endl;
	switch (a) {
		case 1:
			num_of_flips++;
			printresult(a, num_of_flips);
			return heads;
			
		case 0:
			num_of_flips++;
			printresult(a, num_of_flips);
			return tails;

		default:
			break;
	}
}
