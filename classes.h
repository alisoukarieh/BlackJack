#include <iostream>
using namespace std;

#include <string>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>

class Card {    
    public:
        string Suit; 
        string rank_name[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        int Rank; // 1 for Ace, 2-10, 11 for Jack, 12 for Queen, 13 for King
        void displayCard();
};

class Deck {
    public:

        queue<Card> deck; 
        
        void createDeck();

        void shuffleDeck();
};

class Shoe {
    public:
        queue<Card> shoe;
        void createShoe(int numDecks);    
};

class Hand {
    public: 
        vector<Card> hand;
        int handValue;
        void displayHand();
        int calculateHandValue();
        void hit(Shoe& s);
        void show_first_card();
        void clear_hand();
        int check_ace(int numAce);
};

void start_round(Hand& player, Hand& dealer, Shoe& shoe);

void print_man();