#include "classes.h"

/*
    Manage betting
    Manage money 
    Add Split and Double Down

    Errors: 
    Aces don't become 1 when the player passes 21
*/

int main(){
    srand(time(0));

    print_man();
    int numDecks;
    cin >> numDecks;
    cout << endl;


    Shoe shoe;
    shoe.createShoe(numDecks);
    Hand player;
    Hand dealer;

    char input = 'p';
    int round = 1;

    while (input != 'q') {
        player.clear_hand();
        dealer.clear_hand();
        int num_ace_mod = 0;

        cout << "Round " << round << endl;
        round++;

        start_round(player, dealer, shoe);

        cout << "Dealer's Hand: " << endl;
        dealer.show_first_card();

        cout << "Player's Hand: " << player.calculateHandValue() << endl;
        player.displayHand();

        while ( input != 's')
        {
            cout << "What would you like to do? ";
            cin >> input;

            if (input == 'h'){
                player.hit(shoe);
                cout << "Player's Hand: " << (player.calculateHandValue() - num_ace_mod*10) << endl;
                player.displayHand();
            }

            if ( player.calculateHandValue() > 21){
                if (player.check_ace(num_ace_mod)) {
                    cout << "test" << endl;
                    player.handValue -= 10;
                    num_ace_mod++;
                }
                else {
                    break;
                }
            }
        }
        
        cout << "Dealer's Hand: "<< dealer.calculateHandValue() << endl;
        dealer.displayHand();

        if (player.calculateHandValue() > 21){
            cout << "Player Busts" << endl;
        } else {

            while (dealer.calculateHandValue() < 17) {
                dealer.hit(shoe);
                //cout << "Dealer's Hand: "<< dealer.calculateHandValue() << endl;
                //dealer.displayHand();
            }
            
            cout << "Dealer's Hand: "<< dealer.calculateHandValue() << endl;
            dealer.displayHand();
            if (dealer.calculateHandValue() > 21){
                cout << "Dealer Busts" << endl;
            }
            else if (dealer.calculateHandValue() > player.calculateHandValue()){
                cout << "Dealer Wins" << endl;
            }
            else if (dealer.calculateHandValue() < player.calculateHandValue()){
                cout << "Player Wins" << endl;
            }
            else {
                cout << "Push" << endl;
            }
        }
        cout << "Play Again: p or Quit: q " << endl;
        cin >> input;
    }
    


    return 0;
}
