/*This program allows users to play rock paper scissors with the computer. The user's hand is given by the user
while the computer's hand is given by a random number generator. After both player's have chosen their hands, they
are compared to see who won*/

#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

/*This function takes a random number uses a switch statement to choose which hand (rock, paper, or scissors)
the user's opponent throws. It also has a string which will hold the name of the hand to be printed.*/
string handSelect(int c) {
string comp;
   switch (c) {
   case 1:
      comp = "rock";
      break;
   case 2:
      comp = "paper";
      break;
   case 3:
      comp = "scissors";
      break;
   default :
      comp = "code is broken";
   }
   return comp;
}

/*This function takes the first letter of the user's hand and the randomly generated hand, converts them
into integers, then compares them to see who won and who lost, and outputs the result.*/
void decision(char user, char comp){
   int x = user - 'a'; /*int x represents the users hand. I minus 'a' so the numerical value
                       accurately represents where in the alphabet the letter is. It's just easier for me that way*/
   int y = comp - 'a';

   if (x == 15 || x == 17 || x == 18) {
      if (user == comp) {
         cout << "Draw\n";
      } else if (x == 17 && y == 18) {
         cout << "Player Wins!\n";
      } else if (x == 18 && y == 15) {
         cout << "Player Wins!\n";
      } else if (x == 15 && y == 17) {
         cout << "Player Wins!\n";
      } else {
         cout << "The computer wins\n";
      }
   } else {
      cout << "That input isn't valid. This game is a bust. Next time, please type either Rock, Paper, or Scissors\n";
   }
}

/*The main function handles all of the user interactions, asking them for input, recieving the input, etc*/
int main() {

   srand(time(NULL));

   string responce;
   string playerHand;

   cout << "Want to play Rock, Paper, Scissors? (yes or no): ";
   askUser:
   cin >> responce;

   if (responce == "yes") {
      cout << "The computer is deciding it's hand now.\n";
      int c = (rand()%3)+1;
      string comp = handSelect(c);
      cout << "What is your hand?\n";
      cin >> playerHand;

      transform(playerHand.begin(), playerHand.end(), playerHand.begin(), ::tolower);
      char a = playerHand[0];
      char b = comp[0];
      cout << "The computer chose: " << comp <<endl;
      decision(a, b);

      cout << "\nDo you want to play again?\n";
      goto askUser;
   }
   else if (responce == "no") {
      cout << "Alright, have a nice day.\n";
      return 0;
   }
   else {
      cout << "That answer isn't valid, please answer again (yes or no): ";
      goto askUser;
   }
}

