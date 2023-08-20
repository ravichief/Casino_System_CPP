/*
Name of project: Casino System
Description: In this project, we need to design a casino. The program asks for a betting amount and then asks the user to guess a number on rolling. If the random number generated matches the user input, he wins, else money is deducted. The user can keep playing until he loses all the amount he put in initially.
*/
#include<iostream>
#include <random>
using namespace std;
int main(){
    int bettingAmount,guess,randomNumber,numberOfGuesses;
    float percentageLoss;
    cout << "Enter the betting amount: ";
    cin >> bettingAmount;
    cout << "Enter the number of guesses: ";
    cin >> numberOfGuesses;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    randomNumber = dis(gen);
    for (int i = 0; i < numberOfGuesses; i++){
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess == randomNumber){
            cout << "You win! You get $" << bettingAmount << endl;
            break;
        }
        else
        {
            percentageLoss = (float)i / (float)numberOfGuesses * 100;
            bettingAmount -= bettingAmount * percentageLoss / 100;
            cout << "You lose! You lose $" << bettingAmount * percentageLoss / 100 << endl;
        }
    }
    if (bettingAmount == 0){
        cout << "You have lost all your betting amount!" << endl;
    }
    char playAgain;
    cout << "Do you want to play again? (Y/N) ";
    cin >> playAgain;
    if (playAgain == 'Y' || playAgain == 'y'){
        main();
    }
    return 0;
}