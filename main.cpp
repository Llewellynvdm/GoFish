/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-345-81
 *
 * C++ Week 4: Discussion (first semester) - Go Fish (2020/09/20)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Collaborate on the discussion to develop a card game. “Go Fish” is a classic children’s card game
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, September 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <random>

using namespace std;

class mapper {
protected:

    /**
     * The Mapper of Specifics
     **/
    map<string, double> deck_specifics_a;

    /**
     * The Mapper for Reverse Specifics
     **/
    map<double, string> deck_specifics_b;

    /**
     * The Mapper for Ranks
     **/
    map<string, int> deck_ranks_a;

    /**
     * The Mapper for Reverse Ranks
     **/
    map<int, string> deck_ranks_b;

    /**
     * The Mapper for Display
     **/
    map<string, string> deck_display;

public:

    /**
     * Constructor to setup the mapper
     **/
    mapper() {
        // for display
        this->deck_display["H1"] = "Ace of Hearts";
        this->deck_display["D1"] = "Ace of Diamonds";
        this->deck_display["S1"] = "Ace of Spades";
        this->deck_display["C1"] = "Ace of Clubs";

        this->deck_display["H2"] = "Two of Hearts";
        this->deck_display["D2"] = "Two of Diamonds";
        this->deck_display["C2"] = "Two of Clubs";

        this->deck_display["H3"] = "Three of Hearts";
        this->deck_display["D3"] = "Three of Diamonds";
        this->deck_display["S3"] = "Three of Spades";
        this->deck_display["C3"] = "Three of Clubs";

        this->deck_display["H4"] = "Four of Hearts";
        this->deck_display["D4"] = "Four of Diamonds";
        this->deck_display["S4"] = "Four of Spades";
        this->deck_display["C4"] = "Four of Clubs";

        this->deck_display["H5"] = "Five of Hearts";
        this->deck_display["D5"] = "Five of Diamonds";
        this->deck_display["S5"] = "Five of Spades";
        this->deck_display["C5"] = "Five of Clubs";

        this->deck_display["H6"] = "Six of Hearts";
        this->deck_display["D6"] = "Six of Diamonds";
        this->deck_display["S6"] = "Six of Spades";
        this->deck_display["C6"] = "Six of Clubs";

        this->deck_display["H7"] = "Seven of Hearts";
        this->deck_display["D7"] = "Seven of Diamonds";
        this->deck_display["S7"] = "Seven of Spades";
        this->deck_display["C7"] = "Seven of Clubs";

        this->deck_display["H8"] = "Eight of Hearts";
        this->deck_display["D8"] = "Eight of Diamonds";
        this->deck_display["S8"] = "Eight of Spades";
        this->deck_display["C8"] = "Eight of Clubs";

        this->deck_display["H9"] = "Nine of Hearts";
        this->deck_display["D9"] = "Nine of Diamonds";
        this->deck_display["S9"] = "Nine of Spades";
        this->deck_display["C9"] = "Nine of Clubs";

        this->deck_display["H10"] = "Ten of Hearts";
        this->deck_display["D10"] = "Ten of Diamonds";
        this->deck_display["S10"] = "Ten of Spades";
        this->deck_display["C10"] = "Ten of Clubs";

        this->deck_display["HJ"] = "Jack of Hearts";
        this->deck_display["DJ"] = "Jack of Diamonds";
        this->deck_display["SJ"] = "Jack of Spades";
        this->deck_display["CJ"] = "Jack of Clubs";

        this->deck_display["HQ"] = "Queen of Hearts";
        this->deck_display["DQ"] = "Queen of Diamonds";
        this->deck_display["SQ"] = "Queen of Spades";
        this->deck_display["CQ"] = "Queen of Clubs";

        this->deck_display["HK"] = "King of Hearts";
        this->deck_display["DK"] = "King of Diamonds";
        this->deck_display["SK"] = "King of Spades";
        this->deck_display["CK"] = "King of Clubs";

        this->deck_specifics_a["H1"] = 1.1; // Ace of Hearts
        this->deck_specifics_a["D1"] = 1.2; // Ace of Diamonds
        this->deck_specifics_a["S1"] = 1.3; // Ace of Spades
        this->deck_specifics_a["C1"] = 1.4; // Ace of Clubs

        this->deck_specifics_a["H2"] = 2.1; // Two of Hearts
        this->deck_specifics_a["D2"] = 2.2; // Two of Diamonds
        this->deck_specifics_a["S2"] = 2.3; // Two of Spades
        this->deck_specifics_a["C2"] = 2.4; // Two of Clubs

        this->deck_specifics_a["H3"] = 3.1; // Three of Hearts
        this->deck_specifics_a["D3"] = 3.2; // Three of Diamonds
        this->deck_specifics_a["S3"] = 3.3; // Three of Spades
        this->deck_specifics_a["C3"] = 3.4; // Three of Clubs

        this->deck_specifics_a["H4"] = 4.1; // Four of Hearts
        this->deck_specifics_a["D4"] = 4.2; // Four of Diamonds
        this->deck_specifics_a["S4"] = 4.3; // Four of Spades
        this->deck_specifics_a["C4"] = 4.4; // Four of Clubs

        this->deck_specifics_a["H5"] = 5.1; // Five of Hearts
        this->deck_specifics_a["D5"] = 5.2; // Five of Diamonds
        this->deck_specifics_a["S5"] = 5.3; // Five of Spades
        this->deck_specifics_a["C5"] = 5.4; // Five of Clubs

        this->deck_specifics_a["H6"] = 6.1; // Six of Hearts
        this->deck_specifics_a["D6"] = 6.2; // Six of Diamonds
        this->deck_specifics_a["S6"] = 6.3; // Six of Spades
        this->deck_specifics_a["C6"] = 6.4; // Six of Clubs

        this->deck_specifics_a["H7"] = 7.1; // Seven of Hearts
        this->deck_specifics_a["D7"] = 7.2; // Seven of Diamonds
        this->deck_specifics_a["S7"] = 7.3; // Seven of Spades
        this->deck_specifics_a["C7"] = 7.4; // Seven of Clubs

        this->deck_specifics_a["H8"] = 8.1; // Eight of Hearts
        this->deck_specifics_a["D8"] = 8.2; // Eight of Diamonds
        this->deck_specifics_a["S8"] = 8.3; // Eight of Spades
        this->deck_specifics_a["C8"] = 8.4; // Eight of Clubs

        this->deck_specifics_a["H9"] = 9.1; // Nine of Hearts
        this->deck_specifics_a["D9"] = 9.2; // Nine of Diamonds
        this->deck_specifics_a["S9"] = 9.3; // Nine of Spades
        this->deck_specifics_a["C9"] = 9.4; // Nine of Clubs

        this->deck_specifics_a["H10"] = 10.1; // Ten of Hearts
        this->deck_specifics_a["D10"] = 10.2; // Ten of Diamonds
        this->deck_specifics_a["S10"] = 10.3; // Ten of Spades
        this->deck_specifics_a["C10"] = 10.4; // Ten of Clubs

        this->deck_specifics_a["HJ"] = 11.1; // Jack of Hearts
        this->deck_specifics_a["DJ"] = 11.2; // Jack of Diamonds
        this->deck_specifics_a["SJ"] = 11.3; // Jack of Spades
        this->deck_specifics_a["CJ"] = 11.4; // Jack of Clubs

        this->deck_specifics_a["HQ"] = 12.1; // Queen of Hearts
        this->deck_specifics_a["DQ"] = 12.2; // Queen of Diamonds
        this->deck_specifics_a["SQ"] = 12.3; // Queen of Spades
        this->deck_specifics_a["CQ"] = 12.4; // Queen of Clubs

        this->deck_specifics_a["HK"] = 13.1; // King of Hearts
        this->deck_specifics_a["DK"] = 13.2; // King of Diamonds
        this->deck_specifics_a["SK"] = 13.3; // King of Spades
        this->deck_specifics_a["CK"] = 13.4; // King of Clubs

        // setup the reverse map
        for (map<string, double>::iterator i = this->deck_specifics_a.begin(); i != this->deck_specifics_a.end(); ++i) {
            this->deck_specifics_b[i->second] = i->first;
        }

        // set the deck ranks
        this->deck_ranks_a["1"] = 1;  // Ace
        this->deck_ranks_a["2"] = 2;  // Two
        this->deck_ranks_a["3"] = 3;  // Three
        this->deck_ranks_a["4"] = 4;  // Four
        this->deck_ranks_a["5"] = 5;  // Five
        this->deck_ranks_a["6"] = 6;  // Six
        this->deck_ranks_a["7"] = 7;  // Seven
        this->deck_ranks_a["8"] = 8;  // Eight
        this->deck_ranks_a["9"] = 9;  // Nine
        this->deck_ranks_a["10"] = 10; // Ten
        this->deck_ranks_a["J"] = 11; // Jack
        this->deck_ranks_a["Q"] = 12; // Queen
        this->deck_ranks_a["K"] = 13; // King

        // setup the reverse map
        for (map<string, int>::iterator i = this->deck_ranks_a.begin(); i != this->deck_ranks_a.end(); ++i) {
            this->deck_ranks_b[i->second] = i->first;
        }
    }

    // get the double KEY
    double getDoubleKey(int rank, int shape) {
        return (double) rank + ((double) shape / 10.0f);
    }

    // check if we can find the card
    bool find(string key) {
        // the iterator search
        map<string, double>::iterator found = this->deck_specifics_a.find(key);
        // check if it is found
        if (found != this->deck_specifics_a.end()) {
            // element found;
            return true;
        }
        // the iterator search
        map<string, int>::iterator rfound = this->deck_ranks_a.find(key);
        // check if it is found
        if (rfound != this->deck_ranks_a.end()) {
            // element found;
            return true;
        }
        // element not found
        return false;
    }

    // check if we can find the card
    bool find(double key) {
        // the iterator search
        map<double, string>::iterator found = this->deck_specifics_b.find(key);
        // check if it is found
        if (found != this->deck_specifics_b.end()) {
            // element found;
            return true;
        }
        // element not found
        return false;
    }

    // get the card
    double get(string key) {
        // the iterator search
        map<string, double>::iterator found = this->deck_specifics_a.find(key);
        // check if it is found
        if (found != this->deck_specifics_a.end()) {
            // element found;
            return found->second;
        }
        // element not found
        return 0;
    }
};

class deck : public mapper {
protected:
    /**
     * mode 1 = RANK; 2 = SPECIFIC;
     **/
    int mode = 1; // default is RANK

    /**
     * To Shuffle Deck
     */
    stack<double> deck_1;
    stack<double> deck_2;
    stack<double> deck_3;
    stack<double> deck_4;
    stack<double> deck_5;

public:
    /**
     * The Deck
     **/
    stack<double> mixed;

    deck() {

        // setup the mixed deck
        for (map<string, double>::iterator i = this->deck_specifics_a.begin(); i != this->deck_specifics_a.end(); ++i) {
            // random sort the cards
            int deck_n = this->getRandom(1, 5, 0);
            switch (deck_n) {
                case 1:
                    this->deck_1.push(i->second);
                    break;
                case 2:
                    this->deck_2.push(i->second);
                    break;
                case 3:
                    this->deck_3.push(i->second);
                    break;
                case 4:
                    this->deck_4.push(i->second);
                    break;
                case 5:
                    this->deck_5.push(i->second);
                    break;
            }
        }
        // complete the shuffle
        int not_again[] = {0, 0, 0, 0, 0};
        int deck_n = 0;
        while (true) {
            // random sort the cards
            deck_n = this->getRandom(1, 5, deck_n);
            if (not_again[deck_n - 1] == 0) {
                if (1 == deck_n && !this->deck_1.empty()) {
                    // add to real deck
                    this->mixed.push(this->deck_1.top());
                    // remove from tem deck
                    this->deck_1.pop();
                } else if (2 == deck_n && !this->deck_2.empty()) {
                    // add to real deck
                    this->mixed.push(this->deck_2.top());
                    // remove from tem deck
                    this->deck_2.pop();
                } else if (3 == deck_n && !this->deck_3.empty()) {
                    // add to real deck
                    this->mixed.push(this->deck_3.top());
                    // remove from tem deck
                    this->deck_3.pop();
                } else if (4 == deck_n && !this->deck_4.empty()) {
                    // add to real deck
                    this->mixed.push(this->deck_4.top());
                    // remove from tem deck
                    this->deck_4.pop();
                } else if (5 == deck_n && !this->deck_5.empty()) {
                    // add to real deck
                    this->mixed.push(this->deck_5.top());
                    // remove from tem deck
                    this->deck_5.pop();
                } else {
                    not_again[deck_n - 1] = 1;
                }
            } else {
                // check we still have a zero
                bool exists = std::find(begin(not_again), end(not_again), 0) != end(not_again);
                // if no 0 exists then we are done
                if (!exists) {
                    break;
                }
            }
        }
    }

    /**
     * A Basic Random
     */
    int getRandom(int min, int max, int n) {
        random_device rd;
        mt19937 g(rd());
        uniform_int_distribution<int> my_random(min, max);
        // get random but make sure
        // it is not the same as n
        int r = my_random(g);
        while (r == n) {
            r = my_random(g);
        }
        return r;
    }

    /**
     * get the card rank key
     */
    int getRankKey(string key) {
        // the iterator search
        map<string, int>::iterator found = this->deck_ranks_a.find(key);
        // check if it is found
        if (found != this->deck_ranks_a.end()) {
            // element found;
            return found->second;
        }
        // element not found
        return 0;
    }

    /**
     *  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  J,  Q,  K   KEYS
     *  H1, H2, H3 ,H4, H5, H6, H7, H8, H9, H10, HJ, HQ, HK  1 = Hearts
     *  D1, D2, D3 ,D4, D5, D6, D7, D8, D9, D10, DJ, DQ, DK  2 = Diamonds
     *  S1, S2, S3 ,S4, S5, S6, S7, S8, S9, S10, SJ, SQ, SK  3 = Spades
     *  C1, C2, C3 ,C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK  4 = Clubs
     **/
    void showSelection() {
        // show all SPECIFIC options
        if (this->mode == 2) {
            cout << "H1  = Ace of Hearts" << endl;
            cout << "H2  = Two of Hearts" << endl;
            cout << "H3  = Three of Hearts" << endl;
            cout << "H4  = Four of Hearts" << endl;
            cout << "H5  = Five of Hearts" << endl;
            cout << "H6  = Six of Hearts" << endl;
            cout << "H7  = Seven of Hearts" << endl;
            cout << "H8  = Eight of Hearts" << endl;
            cout << "H9  = Nine of Hearts" << endl;
            cout << "H10 = Ten of Hearts" << endl;
            cout << "HJ  = Jack of Hearts" << endl;
            cout << "HQ  = Queen of Hearts" << endl;
            cout << "HK  = King of Hearts" << endl;

            cout << "D1  = Ace of Diamonds" << endl;
            cout << "D2  = Two of Diamonds" << endl;
            cout << "D3  = Tree of Diamonds" << endl;
            cout << "D4  = Four of Diamonds" << endl;
            cout << "D5  = Five of Diamonds" << endl;
            cout << "D6  = Six of Diamonds" << endl;
            cout << "D7  = Seven of Diamonds" << endl;
            cout << "D8  = Eight of Diamonds" << endl;
            cout << "D9  = Nine of Diamonds" << endl;
            cout << "D10 = Ten of Diamonds" << endl;
            cout << "DJ  = Jack of Diamonds" << endl;
            cout << "DQ  = Queen of Diamonds" << endl;
            cout << "DK  = King of Diamonds" << endl;

            cout << "S1  = Ace of Spades" << endl;
            cout << "S2  = Two of Spades" << endl;
            cout << "S3  = Tree of Spades" << endl;
            cout << "S4  = Four of Spades" << endl;
            cout << "S5  = Five of Spades" << endl;
            cout << "S6  = Six of Spades" << endl;
            cout << "S7  = Seven of Spades" << endl;
            cout << "S8  = Eight of Spades" << endl;
            cout << "S9  = Nine of Spades" << endl;
            cout << "S10 = Ten of Spades" << endl;
            cout << "SJ  = Jack of Spades" << endl;
            cout << "SQ  = Queen of Spades" << endl;
            cout << "SK  = King of Spades" << endl;

            cout << "C1  = Ace of Clubs" << endl;
            cout << "C2  = Two of Clubs" << endl;
            cout << "C3  = Tree of Clubs" << endl;
            cout << "C4  = Four of Clubs" << endl;
            cout << "C5  = Five of Clubs" << endl;
            cout << "C6  = Six of Clubs" << endl;
            cout << "C7  = Seven of Clubs" << endl;
            cout << "C8  = Eight of Clubs" << endl;
            cout << "C9  = Nine of Clubs" << endl;
            cout << "C10 = Ten of Clubs" << endl;
            cout << "CJ  = Jack of Clubs" << endl;
            cout << "CQ  = Queen of Clubs" << endl;
            cout << "CK  = King of Clubs" << endl;
        } else {
            // show all RANK options
            cout << "1  = Ace" << endl;
            cout << "2  = Two" << endl;
            cout << "3  = Three" << endl;
            cout << "4  = Four" << endl;
            cout << "5  = Five" << endl;
            cout << "6  = Six" << endl;
            cout << "7  = Seven" << endl;
            cout << "8  = Eight" << endl;
            cout << "9  = Nine" << endl;
            cout << "10 = Ten" << endl;
            cout << "J  = Jack" << endl;
            cout << "Q  = Queen" << endl;
            cout << "K  = King " << endl;
        }
    }
};

class hand : public mapper {
protected:
    // the deck in each and
    bool cards[13][4] = {};
    // when cards are lose
    vector<double> lose;

    // the setter
    bool set(double card, bool state) {
        int rank, shape;
        rank = (int) card;
        shape = (int) (card * 10000);
        shape = (shape - (rank * 10000)) / 1000;
        // set the state
        return this->set(rank, shape, state);
    }

    bool set(int rank, int shape, bool state) {
        // now set the card state
        this->cards[rank][shape] = state;
        // always true :)
        return true;
    }

    // remove the cards locally
    bool remove(double card, bool found = false) {
        // check if this card is in the deck
        if (found || this->find(card)) {
            // was removed so true
            return this->set(card, false);
        }
        // was not removed
        return false;
    }

    // remove the card locally (may not be needed)
    bool remove(string card, bool found = false) {
        // check if this card is in the deck
        if (found || this->find(card)) {
            // get the double
            double d_card = this->get(card);
            // was removed so true
            return this->set(d_card, false);
        }
        // was not removed
        return false;
    }

    // remove the cards locally (may not be needed)
    bool remove(int rank) {
        // there can only be four ranks
        for (int shape = 1; shape < 5; shape++) {
            this->set(rank, shape, false);
        }
        // aways true
        return true;
    }

    // the getter
    bool has(int rank, int shape) {
        // now add the card
        return this->cards[rank][shape];
    }

    // the getter RANK
    bool has(int rank) {
        bool found = false;
        for (int s = 1; s < 5; s++) {
            if (this->cards[rank][s]) {
                double r = this->getDoubleKey(rank, s);
                this->lose.push_back(r);
                found = true;
            }
        }
        // now add the card
        return found;
    }

public:
    // show players hand
    void showHand() {
        bool none = true;
        for (int r = 1; r < 14; r++) {
            for (int s = 1; s < 5; s++) {
                if (this->cards[r][s]) {
                    // get the key
                    double card = this->getDoubleKey(r, s);
                    // show this card
                    cout << this->deck_specifics_b[card] << ") " << this->deck_display[this->deck_specifics_b[card]]
                         << endl;
                    none = false;
                }
            }
        }
        // give empty hand message if no cards found
        if (none) {
            cout << "Your hand is empty :)" << endl;
        }
    }

    // set the cards locally
    bool add(double card) {
        // check if this card is in the deck
        if (this->find(card)) {
            // was set so true
            return this->set(card, true);
        }
        // was not set
        return false;
    }

    // set the cards locally (may not be needed)
    bool add(string card) {
        // check if this card is in the deck
        if (this->find(card)) {
            // get the double
            double d_card = this->get(card);
            // was set so true
            return this->set(d_card, true);
        }
        // was not set
        return false;
    }

    // set the cards locally
    bool hasCard(double card, bool give = false) {
        // check if this card is in the deck
        if (this->find(card)) {
            int rank, shape;
            rank = (int) card;
            shape = (int) (card * 10000);
            shape = (shape - (rank * 10000)) / 1000;
            // check if we must remove it at the same time
            if (give) {
                // get the card
                if (this->has(rank, shape)) {
                    // remove since it is found
                    return this->remove(card, true);
                }
                // not found
                return false;
            }
            // return if the card is found
            return this->has(rank, shape);
        }
        // not a card
        return false;
    }

    // set the card RANK locally
    bool hasCard(int card, bool give = false) {
        // always rest the lose
        this->lose.clear();
        // check if this card is in the deck
        if (card > 0 && card < 14) {
            // check if we must remove it at the same time
            if (give) {
                // get the card
                if (this->has(card)) {
                    // remove since it is found
                    for (auto c : this->lose)
                        this->remove(c, true);
                    return true;
                }
                // not found
                return false;
            }
            // return if the card is found
            return this->has(card);
        }
        // not a card
        return false;
    }

    // set the cards locally (may not be needed)
    bool hasCard(string card, bool give = false) {
        // check if this card is in the deck
        if (this->find(card)) {
            // get the double
            double d_card = this->get(card);
            int rank, shape;
            rank = (int) d_card;
            shape = (int) (d_card * 10000);
            shape = (shape - (rank * 10000)) / 1000;
            // check if we must remove it at the same time
            if (give) {
                // get the card
                if (this->has(rank, shape)) {
                    // remove since it is found
                    return this->remove(d_card);
                }
                // not found
                return false;
            }
            // return if the card is found
            return this->has(rank, shape);
        }
        // not a card
        return false;
    }

    // get your loses to those asking RANK
    vector<double> getWinnings() {
        return this->lose;
    }

    // ask for a card
    bool askCard(int card, hand &AHand) {
        if (card > 0 && AHand.hasCard(card, true)) {
            vector<double> winnings = AHand.getWinnings();
            for (auto i : winnings)
                this->add(i);
            // cards were found
            return true;
        }
        // cards were not found
        return false;
    }

    // ask for a card
    bool askCard(double card, hand &AHand) {
        if (AHand.hasCard(card, true)) {
            // cards were found
            return this->add(card);
        }
        // cards were not found
        return false;
    }

    // ask for a card
    bool askCard(string card, hand &AHand) {
        return this->askCard(this->get(card), AHand);
    }
};

class game : public deck {
protected:
    // game status
    bool status;
    // number of payers
    int players;
    // deceit in mode = 2 (can ask for a card you already have in your hand, or not)
    bool deceit;
    // allow empty deck
    bool empty_deck;
    // the deck index
    int index = 1;
    // player hands
    map<int, hand> hands;

    // opening setup
    void setupBoard() {
        // for quick testing
//        this->players = 2;
//        this->mode = 1;
//        this->empty_deck = false;
//        return;
        // string to get answers
        string tmp;
        // ask the opening questions
        while (true) {
            cout << "How many players will play?" << endl;
            cout << "[2-6]: ";
            cin >> this->players;
            if (this->players > 1 && this->players < 7) {
                break;
            }
            cin.clear();
            cin.ignore();
            cout << "Must be between 2 and 6 players." << endl;
        }
        // get the game mode
        while (true) {
            cout << "Will players be asking per [R]ank or for [S]pecific cards?" << endl;
            cout << "(r/s): ";
            cin >> tmp;
            if (tmp == "r" || tmp == "R" || tmp == "Rank" || tmp == "rank") {
                this->mode = 1;
                break;
            } else if (tmp == "s" || tmp == "S" || tmp == "Specific" || tmp == "specific") {
                this->mode = 2;
                break;
            }
            cin.clear();
            cin.ignore();
            cout << "Lets try again, please answer only r or s" << endl;
        }
        // only allow deceit when in specific this->mode
        if (this->mode == 2) {
            while (true) {
                cout << "Will players be allowed to ask for cards they have?" << endl;
                cout << "(y/n): ";
                cin >> tmp;
                if (tmp == "y" || tmp == "Y" || tmp == "yes" || tmp == "Yes") {
                    this->deceit = true;
                    break;
                } else if (tmp == "n" || tmp == "N" || tmp == "no" || tmp == "No") {
                    this->deceit = false;
                    break;
                }
                cin.clear();
                cin.ignore();
                cout << "Lets try again, please answer only y or n" << endl;
            }
        }
        // check if empty deck is allowed
        while (true) {
            cout << "Will the game continue if the deck is empty?" << endl;
            cout << "(y/n): ";
            cin >> tmp;
            if (tmp == "y" || tmp == "Y" || tmp == "yes" || tmp == "Yes") {
                this->empty_deck = true;
                break;
            } else if (tmp == "n" || tmp == "N" || tmp == "no" || tmp == "No") {
                this->empty_deck = false;
                break;
            }
            cin.clear();
            cin.ignore();
            cout << "Lets try again, please answer only y or n" << endl;
        }
    }

    // deal the cards
    void dealCards() {
        // deal cards
        int number = 6;
        if (this->players == 2) {
            number = 7;
        }
        int p = 1;
        while (p <= this->players) {
            // load only the number of cards allowed
            for (int card = 1; card <= number; ++card) {
                this->hands[p].add(this->mixed.top());
                this->mixed.pop();
            }
            // set player
            p++;
        }
    }

    // get a card (go fish)
    double getCard(int player) {
        // check if we still have cards
        if (!this->mixed.empty()) {
            // get the next card from the stack
            double card = this->mixed.top();
            this->mixed.pop();
            // add to player
            this->hands[player].add(card);
            // return the card
            return card;
        }
        return 0;
    }

public:
    game() {
        // game has started
        status = true;
        // do opening setup
        this->setupBoard();
        // deal the cards
        this->dealCards();
    }

    // play the game
    void startGame() {
        // we start with a random player
        int p = this->getRandom(1, this->players, 0);
        // get new player
        bool get_new_player = false;
        // show whole key set
        string yes;
        cout << "Before we start, here is the list of all the keys of each card." << endl;
        this->showSelection();
        while (true) {
            if (this->mode == 1) {
                cout << "So J is the key for all Jacks" << endl;
            } else {
                cout << "So H1 is the key for Ace of Hearts" << endl;
            }
            cout << "Are you ready to continue?" << endl;
            cout << "(y/n): ";
            cin >> yes;
            if (yes == "y" || yes == "Y" || yes == "yes" || yes == "Yes") {
                break;
            }
            cin.clear();
            cin.ignore();
        }
        // check if we still have cards
        while (status) {
            // check if we must get the next player
            if (get_new_player) {
                // get the next player
                p = p + 1;
                // if the player is beyond the list (start at player one)
                if (p > this->players) {
                    p = 1;
                }
                // reset getting new player
                get_new_player = false;
            }
            // asking temp INT/string
            int tmp;
            // asking who is the next player
            int ask;
            // last player
            int l = this->players;
            // first player
            int f = 1;
            // ask for the next player
            bool ask_next = true;
            if (this->players > 2) {
                // if the player is the first, then move to 2
                if (p == 1) {
                    f = 2;
                }
                // if the last is the player, that a step back
                if (l == p) {
                    l = this->players - 1;
                }
            } else {
                // do not ask for the next player
                ask_next = false;
                // just ask the next player
                ask = 1;
                if (p == 1) {
                    ask = 2;
                }
            }
            // player questions
            cout << "You are player [" << p << "]" << endl;
            cout << "We will show your hand in a moment." << endl;
            // check if we should ask for next player
            if (ask_next) {
                while (true) {
                    cout << "Please select a player you would like to ask between:" << endl;
                    cout << "[" << f << " - " << l << "] ";
                    cin >> tmp;
                    if ((tmp >= f || tmp <= l) && tmp != p) {
                        ask = tmp;
                        break;
                    }
                    cin.clear();
                    cin.ignore();
                    cout << "Lets try again, you are player [" << p << "]" << endl;
                }
            }
            // get the card to ask for
            string card;
            while (true) {
                cout << "This is your current hand:" << endl;
                this->hands[p].showHand();
                cout << "What card do you want to ask for?" << endl;
                cin >> card;
                // make string uppercase
                transform(card.begin(), card.end(), card.begin(), ::toupper);
                if (this->find(card)) {
                    break;
                }
                cin.clear();
                cin.ignore();
                cout << "Lets try again" << endl;
            }
            // make sure to get INT if RANK mode
            bool found_card = false;
            if (this->mode == 1) {
                found_card = this->hands[p].askCard(this->getRankKey(card), this->hands[ask]);
            } else {
                found_card = this->hands[p].askCard(card, this->hands[ask]);
            }
            // now lets ask
            if (found_card) {
                cout << endl;
                // load cards of RANK
                if (this->mode == 2) {
                    cout << "    Yes! Player [" << ask << "] had the card!" << endl;
                } else {
                    cout << "    Yes! Player [" << ask << "] had the card/s!" << endl;
                }
                cout << "    YOU GET TO GO AGAIN :)" << endl;
                cout << endl;
                cout << endl;
            } else {
                cout << "Go fish................................" << endl;
                // load the card from the deck and add to player
                double c = this->getCard(p);
                // we must check if we found what we where looking for
                if (c > 0) {
                    if (this->mode == 2 && c == this->get(card)) {
                        cout << endl;
                        cout << "   Wow you got the card you were looking for!" << endl;
                        cout << "   OU GET TO GO AGAIN :)" << endl;
                        cout << endl;
                        cout << endl;
                    } else {
                        cout << "The new card was added to your hand...." << endl;
                        cout << "Okay it is now the next players turn!" << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        get_new_player = true;
                    }
                } else {
                    // check if we allow empty decks
                    if (!this->empty_deck) {
                        // deck is empty so stop the game
                        status = false;
                    }
                }
            }
        }
    }
};

int main() {

    // get the game
    game *Game = new game();
    // start game
    Game->startGame();

    // clear memory
    delete(Game);

    return 0;
}
