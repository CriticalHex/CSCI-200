/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Kyle Kubaska
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what
 * capacity):
 *     My roommate suggested that my switch statements looked messy, so I'm not
 * using switch statements.
 *
 * A program that generates a random rock paper scissors+ move, prompts the user
 * for a move, and evaluates the winner.
 */
// The include section adds extra definitions from the C++ standard library.
#include <ctime>    // seeding random
#include <iostream> // For cin, cout, etc.
#include <map>      // a way to link two variables
#include <random>   // generate random numbers

// We will (most of the time) use the standard library namespace in our
// programs.
using namespace std;

// declared here so that it's in scope for the class
map<const char, const string> GET_WORD = { // map the input to the full word
    {'R', "Rock"},
    {'P', "Paper"},
    {'S', "Scissors"},
    {'L', "Lizard"},
    {'K', "Spock"}};

class Move { // a class for determining game results based on the move
  public:
    char played;
    char beats[2];
    Move(){};
    Move(const char theMove, const char beatsOne, const char beatsTwo) {
        played = theMove;
        beats[0] = beatsOne;
        beats[1] = beatsTwo;
    }
    int evaluate(char versus) { // return result: 1-win, -1-loss, 0-tie
        const string playedWord = GET_WORD[played],
                     versusWord = GET_WORD[versus];
        if (played == versus) { // print a tie
            cout << playedWord << " ties with " << versusWord << "." << endl;
            cout << "It's a tie!" << endl;
            return 0;
        } else if (versus == beats[0] || versus == beats[1]) { // a win
            cout << playedWord << " beats " << versusWord << "." << endl;
            cout << "Player wins!" << endl;
            return 1;
        } else { // a loss
            cout << versusWord << " beats " << playedWord << "." << endl;
            cout << "Computer wins!" << endl;
            return -1;
        }
    }
};

const char COMPUTER_CHOICES[] = {'R', 'P', 'S', 'L', 'K'}; // the options

char promptUser() { // get the move from the user
    char userIn;
    cout << "Welcome one and all to a round of Rock, Paper, Scissors, Lizard, "
            "Spock! (Enter P, R, S, L, or K)"
         << endl;
    cout << "Player one: ";
    cin >> userIn;
    cout << endl;
    return userIn;
}

char choose() { // computer picks a move at random
    const int random = rand() % 5;
    return COMPUTER_CHOICES[random];
}

// Must have a function named "main", which is the starting point of a C++
// program.
int main() {

    srand(time(NULL)); // seed random number gen

    map<const char, const Move> MOVES = {// map a move to a move object
                                         {'R', Move('R', 'S', 'L')},
                                         {'P', Move('P', 'R', 'K')},
                                         {'S', Move('S', 'P', 'L')},
                                         {'L', Move('L', 'K', 'P')},
                                         {'K', Move('K', 'R', 'S')}};

    char userIn, computerChoice; // declare variables
    Move move;
    int won = 0, lost = 0, tied = 0; // declare and define result counters

    do {
        // get the move even if the user didn't capitalize their input (shame on
        // them)
        userIn = toupper(promptUser());
        computerChoice = choose();
        cout << "Player choose " << GET_WORD[userIn] << endl;
        cout << "Computer choose " << GET_WORD[computerChoice] << endl << endl;
        move = MOVES[userIn];
        switch (move.evaluate(computerChoice)) { // check what happened
        case 1:
            won++;
            break;
        case -1:
            lost++;
            break;
        case 0:
            tied++;
            break;
        }
        cout << endl << "Do you want to play again? (Y/N) "; // go again
        cin >> userIn;
        userIn = toupper(userIn);
        cout << endl;

    } while (userIn == 'Y');

    cout << "Thanks for playing!" << endl
         << "You won " << won << " game(s), lost " << lost
         << " game(s), and tied " << tied << " game(s).";

    return 0; // signals the operating system that our program ended OK.
}