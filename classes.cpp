#include "classes.h"


// Card Functions
void Card::displayCard(){
    cout << "   Suit: " << Suit << endl;
    cout << "   Rank: " << Rank << endl;
}

// Deck Functions   
void Deck::createDeck(){
    for (string s : {"Spades", "Heart", "Diamonds", "Clubs"}){
        for (int r = 1; r <= 13; r++){
            Card c;
            c.Suit = s;
            c.Rank = r;
            deck.push(c);
        }
    }
}

void Deck::shuffleDeck(){
    for (int i = 0; i < 52; i++){
        int random = rand() % 52;
        Card temp = deck.front();
        deck.pop();
        deck.push(temp);
    }
}   

// Shoe Functions
void Shoe::createShoe(int numDecks){
    for (int i = 0; i < numDecks; i++){
        Deck d;
        d.createDeck();
        d.shuffleDeck();
        while (!d.deck.empty()){
            shoe.push(d.deck.front());
            d.deck.pop();
        }
    }
}        

// Hand Functions
void Hand::displayHand(){
    for (Card c : hand){
        c.displayCard();
    }
}

int Hand::calculateHandValue(){
    int sum = 0;
    for (Card c : hand){
        if (c.Rank == 1){
            sum += 11;
        }
        else if (c.Rank > 10){
            sum += 10;
        }
        else {
            sum += c.Rank;
        }
    }
    handValue = sum;
    return sum;
}

void Hand::hit(Shoe& s){
    Card c = s.shoe.front();
    s.shoe.pop();
    hand.push_back(c);
}

void Hand::show_first_card(){
    hand[0].displayCard();
}

void Hand::clear_hand(){
    hand.clear();
}

int Hand::check_ace(int numAce){
    int count = 0;
    for (Card c : hand){
        if (c.Rank == 1 && count == numAce){
            return 1;
        } else if (c.Rank == 1){
            count++;
        }
    }
    return 0;
}

// Game Functions
void start_round(Hand& player, Hand& dealer, Shoe& shoe){
    player.hit(shoe);
    dealer.hit(shoe);
    player.hit(shoe);
    dealer.hit(shoe);
}

void print_man(){
    cout << "Blackjack" << endl;
    cout << "Use the following commands to play: " << endl;
    cout << "Hit: h" << endl;
    cout << "Stand: s" << endl;
    cout << "Double Down: d" << endl;
    cout << "Split: p" << endl;
    cout << "Stand: s" << endl;
    cout << "Play Again: p" << endl;
    cout << "Quit: q" << endl;
    cout << "You can't quit until the end of the round" << endl;
    cout << "With how many decks would you like to play? " ;
}