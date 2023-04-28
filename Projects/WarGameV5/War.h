#ifndef __WAR_H_
#define __WAR_H_

#include "Hand.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class War
{
public:
    //Plays a game of war. Asks the user to press enter for each round,
    // or enter a letter to zip through the rest of the game. Nobody wins
    // if a game continues for more than MAX_ROUNDS (presumed to be an infinite game).
    static void play();
    
    int totalCardsPlayed; // variable to keep track of total cards played in a game
    int minCardsPlayed; // variable to keep track of minimum cards played in a game
    int maxCardsPlayed; // variable to keep track of maximum cards played in a game
    
    // Find the minimum and maximum of the total cards played in a game
    static void findMinMaxCards(int& minCards, int& maxCards) {
    int totalCards = player1.size() + player2.size();
    minCards = totalCards;
    maxCards = totalCards;
    while (!player1.empty() && !player2.empty())
    {
        // Play a round and update the total number of cards played
        player1.drawTop();
        player2.drawTop();
        totalCards -= 2;

        // Update minimum and maximum if necessary
        if (totalCards < minCards) {
            minCards = totalCards;
        }
        if (totalCards > maxCards) {
            maxCards = totalCards;
        }
    }
}

    // Wrapper function to print the minimum and maximum of the total cards played in a game
    static void printMinMaxCards() {
        int minCards, maxCards;
        findMinMaxCards(minCards, maxCards);
        std::cout << "Minimum number of cards played in a game: " << minCards << std::endl;
        std::cout << "Maximum number of cards played in a game: " << maxCards << std::endl;
    }
    
private:
    //Default constructor
    War();
    
    //Prints out an introduction and tells the user how to play.
    static void introduction();

    //Gets names for the two players from the user and stores them in nameP1 and nameP2.
    static void getNames();

    //Precondition: Each player has at least one card in his hand.
    //Postcondition: A comparison is made between the players' first cards. If the cards
    // have the same value, a war is declared.
    static void battle();

    //Puts 3 cards "facedown" for each player and compares the next card from each player.
    // Returns 1 if player one is the winner and 2 if player two is the winner.
    static int war();

    //Precondition: One of the players has run out of cards or rounds is greater than MAX_ROUNDS.
    //Postcondition: Prints out a congratulatory message for the winner or indicates a draw.
    static void winner();

    //Asks the user if he wants to play again. Returns true if the user wants to play again.
    static bool playAgain();

    //Precondition: New information has been displayed for the user to see.
    //Postcondition: Changes skipToEnd to reflect whether the user wants to skip to the end.
    // of the game or just move to the next stage.
    static void checkForSkip();

    //Prints out the names of the players, their current hand size, and the names of the cards.
    static void printCards(const string& p1Card, const string& p2Card);

    //The names of the two players.
    static string nameP1, nameP2;

    //Instances of the Hand class that represent the players' hands.
    static Hand player1, player2;

    //A flag indicating whether the user wants to skip to the end of the game.
    static bool skipToEnd;

    //The number of rounds played so far.
    static int rounds;

    //The maximum number of rounds allowed before the game is considered to be an infinite game.
    static const int MAX_ROUNDS;

    //A list of all cards played during the game.
    std::list<Card> playedCardsHistory;
};

#endif
