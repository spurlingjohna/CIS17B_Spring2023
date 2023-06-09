#ifndef __HAND_H_
#define __HAND_H_

#include "Card.h"
#include <list>
#include <algorithm>
#include <deque>
#include <iterator>

using std::list;

class Hand
{
public:
    	//Default constructor. An empty hand.
	Hand();

        //bool findCard(const Card &card);
        
	//Returns a full deck of cards        
	static Hand fullDeck();
        
        //Mixes up the cards   
	void shuffle();
	
	Card drawTop();
        
        //Returns the card from the top or bottom of the hand, removes that card
	Card drawBottom();
	
        //Places the card on the top or bottom of the hand
	void placeTop(Card c);
	
        //Returns true if the hand is empty, returns false otherwise
	bool empty();
	
        //Returns how many cards are in the hand
	int size();
	
        // Returns a deque of the cards in the hand.
        std::deque<Card> getCards() const { return cards; }
        
        // Inserts a range of cards at the bottom of the hand.
        template <typename InputIt>
        void placeBottom(InputIt first, InputIt last);
        
        // Inserts a range of cards at the bottom of the hand.
        void placeBottom(Card c);
        
        // Function to find a specific card in the hand
        std::deque<Card>::iterator findCard(const Card &card);
        
        // Swaps the cards at the given indices in the hand.
        void swapCards(int index1, int index2);
        
    
   
private:
        // Deque to store the cards in the hand.
        std::deque<Card> cards;
};

#endif
