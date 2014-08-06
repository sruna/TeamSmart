//
//  main.cpp
//  Slot Machine Project
//
//  Created by Don Mclean on 6/26/14.
//  Copyright (c) 2014 Don Mclean. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void display_welcome_message();

void display_instructions();

void display_instructions2();

void display_results(int& num_of_coins, string slot_reels, string& slot_reels2, double& num_of_trys, double& wins);

void check_matches(int& num_of_coins, string slot_reels, double& num_of_trys, double& wins);

int is_match(char a, char b, int& matches);

void display_thanks();

int get_user_input(int a);

void lever_pull(int& num_of_coins, string slot_reels, double& num_of_trys, double& wins);

double calculate_winrate(double& num_of_trys, double& wins);

int main()
{
    
    srand(time(NULL));
    
    display_welcome_message();
    display_instructions();
    
    int user_input = 0;
    int num_of_coins = 20;
    int user_value = 0;
    double num_of_trys = 0;
    double wins;
    double winrate = 0;
    
    string slot_reels = "$@#";
    //char slot_reels[3] = {'$','@','#'};
    string slot_reels2;
    
    while (num_of_coins > 0) {
        
        display_instructions2();
        user_value = get_user_input(user_input);
        
        switch (user_value) {
            case 1:
                lever_pull(num_of_coins, slot_reels, num_of_trys, wins);
                
                display_results(num_of_coins, slot_reels, slot_reels2, num_of_trys, wins);
                
                check_matches(num_of_coins, slot_reels2, num_of_trys, wins);
                
                //Increment and display the number of trys
                num_of_trys++;
                //cout << endl << "Trys: " << num_of_trys;
                
                //display the number of coins left
                cout << endl << num_of_coins << " coins left";
                
                
                //Calulate and display Win rate
                winrate = calculate_winrate(num_of_trys, wins);
                cout << endl << "Your Win Rate Is: " << winrate << "% Percent!!!"<< endl << endl;
                
                break;
                
            case 2:
                display_thanks();
                cout << endl;
                exit(0);
                break;
                
            default:
                cout << endl << "Sorry... Your entry was invalid... Please try again..." << endl;
                exit(0);
                break;
        }
    }
    
    return 0;
}

void display_welcome_message()
{
    cout << "Hello there! Welcome to The Magic Slot Machine, where everyone is a winner!" << endl;
}

void display_instructions()
{
    cout << endl << "Your goal here is to get three of the individual slots reels to match. " << endl << endl
    << "You start off with 20 coins, and each time you pull the lever, the " << endl
    << "slots reels will spin and you will lose 1 coin." << endl << endl << "However if you manage to get 3 matches you will win 10 extra coins!" << endl << "GOOD LUCK!" << endl;

}

void display_instructions2()
{

    cout << endl << "CHOOSE -1- TO PULL THE LEVER OR -2- TO QUIT " << endl;
}

int get_user_input(int a)
{
    a = 0;
    cin >> a;
    return a;
    
}

void display_thanks()
{
    
    cout << endl << "THANKS FOR PLAYING THE MAGIC SLOT MACHINE! " << endl;
}

void display_results(int& num_of_coins, string slot_reels, string& slot_reels2, double& num_of_trys, double& wins)
{
    
    cout << endl;
    
    //Displays randomized slot reel results & stores results in a referenced array 'slot_reels2'
    for (int i = 0; i < 3; i++) {
        
        for (int k = 0; k < 1; k++) {
            k = rand() %3;
            
            cout << slot_reels[k] << "\t";
            
            slot_reels2[i] = slot_reels[k];

        }
    }
    
    cout << endl << endl;
}

int is_match(char a, char b, int& matches)
{
    
    //Increments the number of matches from slot reel loop
    if (a == b) {
        matches++;
        return 1;
        
    } else {
        return 0;
    }
    
}

void check_matches(int& num_of_coins, string slot_reels, double& num_of_trys, double& wins)
{
    int matches = 0;
    
    // Loops Though randomized slot reel string to find matches
    for (int i = 0; i < 3; i++) {
        
        if (i == 2) {
            
            i = 0;
            is_match(slot_reels[i], slot_reels[i+2], matches);
            break;
        }
        
        is_match(slot_reels[i], slot_reels[i+1], matches);

    }
    
    //Displays user successes and failures
    switch (matches) {
        case 1:
            cout << "Sorry... Please try again... " << endl;
            break;
            
        case 2:
            cout << "Sorry... Please try again... " << endl;
            break;
        case 3:

            wins++;
            cout << "Wins: " << wins << endl;
            cout << "Congratulations!!! YOU WON THE SLOTS!!!" << endl << "You Won 10 extra coins!" << endl;

            
            // User wins 10 extra coins for matching
            num_of_coins = num_of_coins + 10;
            
            break;
            
        default:
            cout << "Sorry... Please try again... " << endl;
            break;
    }
    
}

void lever_pull(int& num_of_coins, string slot_reels, double& num_of_trys, double& wins)
{
    //Decrement the number of coins
    num_of_coins--;
    
    //Error Checking (Fallback plan)
    if (num_of_coins == 0) {
        cout << endl;
        display_thanks();
        exit(0);
    }

}

double calculate_winrate(double& num_of_trys, double& wins)
{
    
    return wins / num_of_trys * 100;
}
