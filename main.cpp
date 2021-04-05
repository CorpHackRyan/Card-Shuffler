#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

const int CARDS_IN_DECK = 52;
const int NULL_CHARACTER = -1;


void deal_cards(string good_deck[], int shuffled_deck[], string CARDS[]) {

    int counter = 0, b = 0;

    cout<<"Here is the the shuffled deck: \n";
    for(counter=0; counter < CARDS_IN_DECK; counter++) {
        good_deck[counter] = CARDS[shuffled_deck[counter]];
        cout<<good_deck[counter] << endl;
    }

    // Deal to 2 players only
    string player1[2], player2[2];

    player1[0] = good_deck[0];
    player2[0] = good_deck[1];
    player1[1] = good_deck[2];
    player2[1] = good_deck[3];

    cout<<"\nPlayer one has: "<<player1[0]<<" "<<player1[1] << endl;
    cout<<"Player two has: "<<player2[0]<<" "<<player2[1]<<endl << endl;
    cout<<"The flop, turn and river is: "<<good_deck[5]<<" "<<good_deck[6]<<" "<<good_deck[7]<<" "<<good_deck[9]<<" "<<good_deck[11] << endl;
}


void shuffle_up_and_deal(string CARDS[]) {

    bool card_exists = false;
    int rnd_card;

    // Shuffling algorithm description:

    // Initialize a temp array from 0-51 that contains all nils in it.
    // Take the one number you get from the random result, make sure it isnt in
    // the temp array that stores each of the numbers picked. if it isn't picked, stick it
    // into the new_shuffle[i], where i = the index of the next insertion point

    // For the random number, this is done in the overall for loop. The shuffling will be done when i == 51.


    int counter = 0;
    int a, b = 0, c = 0;    //counters for the for loops

    int shuffled_deck[CARDS_IN_DECK];
    string good_deck[CARDS_IN_DECK];

    // This sets all the initial values in the array to null; i'm using -1 for now.

    for(a = 0; a <= CARDS_IN_DECK; a++)
        shuffled_deck[a] = NULL_CHARACTER;

    while (b < CARDS_IN_DECK) {

        //This keeps the random number it picks in the range of the cards 0-51.

        rnd_card = CARDS_IN_DECK / 51; //where n  = the number range
        rnd_card = (rand() * CARDS_IN_DECK + rnd_card);
        rnd_card = (rand() * CARDS_IN_DECK + rnd_card) / (RAND_MAX + 1);
        rnd_card = rnd_card % CARDS_IN_DECK;

        // Need to check if the current location is full, if it is then we skip slot.
        // Everytime we add a new entry to the array, we then increase the counter by one, so that
        // when the counters reaches 51 [0-51 is 52 cards], this means the deck is fully shuffled
        // and we are ready to assign the cards and deal them.

        //If the RANDOM_CARD picked is between 1 and 52 then we will check to see if this number
        //has been assigned to the array yet. If it has, then we just break and move on. If it hasn't,
        //then wherever the iterator is (b in this case), we increase it by 1 and assign the new number there.

        if (rnd_card >= 0 && rnd_card < CARDS_IN_DECK); {

            card_exists = false;

            // This is the check to see if the card already exists in the deck
            for(c = 0; c < CARDS_IN_DECK; c++) {

                if (shuffled_deck[c] == rnd_card) {
                    card_exists = true;
                }

            }

            if (card_exists == false) {
                shuffled_deck[b] = rnd_card;
                b++;
            }

        }

        // The variable 'b' is where the current index position is
        // on the deck that is being shuffled and arranged. The first
        // index will always be 0, and it will increase by 1 until it reaches
        // 51.
    }

    // Write dealt out deck to a text file for review
    ofstream tempfile;
    tempfile.open("deck_shuffled.txt");
    for(a=0; a < CARDS_IN_DECK; a++)
        tempfile << shuffled_deck[a] << endl;
    tempfile.close();

    deal_cards(good_deck, shuffled_deck, CARDS);
}


int main() {
    bool keepgoing = true;
    char input;
    srand(time(NULL));

    string CARDS[CARDS_IN_DECK] = { "Ah","2h","3h","4h","5h","6h","7h","8h","9h","10h","Jh","Qh","Kh",
                                    "Ad","2d","3d","4d","5d","6d","7d","8d","9d","10d","Jd","Qd","Kd",
                                    "Ac","2c","3c","4c","5c","6c","7c","8c","9c","10c","Jc","Qc","Kc",
                                    "As","2s","3s","4s","5s","6s","7s","8s","9s","10s","Js","Qs","Ks"
    };

    while(keepgoing) {

        shuffle_up_and_deal(CARDS);

        cout << "Do you wish to deal again? ";
        cin >> input;
        cout << endl;

        if (input == 'n' || input == 'N')
            keepgoing = false;
    }

    return 0;

}




