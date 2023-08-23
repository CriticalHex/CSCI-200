/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Kyle Kubaska
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <random>
#include <ctime>
#include <map>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;
// using std::cout; // was telling me cout was ambiguous despite no compiler errors;

// Define any constants below this comment.
const char computerChoices[] = {'R', 'P', 'S'};

char promptUser();
char choose();

void pWin()
{
    cout << "Player wins!" << endl;
}
void cWin()
{
    cout << "Computer wins!" << endl;
}
void tiesWith(string played)
{
    cout << played << " ties with " << played << "." << endl;
    cout << "It's a tie!" << endl;
}
void thisBeatsThat(string winner, string loser)
{
    cout << winner << " beats " << loser << "." << endl;
}

// Must have a function named "main", which is the starting point of a C++ program.
int main()
{

    /******** INSERT YOUR CODE BELOW HERE ********/
    srand(time(NULL));

    // cout << "Hello world!" << endl; // print Hello world! to the screen

    char userIn, computerChoice;
    int won = 0, lost = 0, tied = 0;
    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}};
    map<char, string> getWord = {{'R', "Rock"}, {'P', "Paper"}, {'S', "Scissors"}};

    do
    {
        userIn = promptUser();
        computerChoice = choose();
        cout << "Player choose " << getWord[userIn] << endl;
        cout << "Computer choose " << getWord[computerChoice] << endl
             << endl;

        if (userIn == computerChoice)
        {
            tiesWith(getWord[userIn]);
            tied++;
        }
        else if (beats[userIn] == computerChoice)
        {
            thisBeatsThat(getWord[userIn], getWord[computerChoice]);
            pWin();
            won++;
        }
        else
        {
            thisBeatsThat(getWord[computerChoice], getWord[userIn]);
            cWin();
            lost++;
        }

        cout << endl
             << "Do you want to play again? (Y/N) ";
        cin >> userIn;
        cout << endl;

    } while (userIn == 'Y');

    cout << "Thanks for playing!" << endl
         << "You won " << won
         << " game(s), lost " << lost
         << " game(s), and tied " << tied
         << " game(s).";

    /******** INSERT YOUR CODE ABOVE HERE ********/

    return 0; // signals the operating system that our program ended OK.
}

char promptUser()
{
    char userIn;
    cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl;
    cout << "Player one: ";
    cin >> userIn;
    cout << endl;
    return userIn;
}

char choose()
{
    const int random = rand() % 3;
    return computerChoices[random];
}
