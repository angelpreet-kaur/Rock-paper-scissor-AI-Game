#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

string getAIMove(vector<string>& history) {
    // Random choice for first few rounds
    if (history.size() < 3) {
        int randomChoice = rand() % 3;
        if (randomChoice == 0) return "rock";
        else if (randomChoice == 1) return "paper";
        else return "scissors";
    }

    // Count player's most frequent move
    int rockCount = count(history.begin(), history.end(), "rock");
    int paperCount = count(history.begin(), history.end(), "paper");
    int scissorsCount = count(history.begin(), history.end(), "scissors");

    string mostPlayed;
    if (rockCount >= paperCount && rockCount >= scissorsCount)
        mostPlayed = "rock";
    else if (paperCount >= rockCount && paperCount >= scissorsCount)
        mostPlayed = "paper";
    else
        mostPlayed = "scissors";

    // AI plays the counter move
    if (mostPlayed == "rock") return "paper";
    else if (mostPlayed == "paper") return "scissors";
    else return "rock";
}

string checkWinner(string player, string ai) {
    if (player == ai) return "It's a tie!";
    if ((player == "rock" && ai == "scissors") ||
        (player == "paper" && ai == "rock") ||
        (player == "scissors" && ai == "paper"))
        return "You win!";
    else
        return "AI wins!";
}

int main() {
    srand(time(0));
    vector<string> history;
    string playerMove, aiMove;

    cout << "---Rock, Paper, Scissors AI Game---" << endl;
    cout << "Type 'rock', 'paper', or 'scissors'\n" << endl;

    while (true) {
        cout << "Your move: ";
        cin >> playerMove;

        if (playerMove == "quit") break;
        if (playerMove != "rock" && playerMove != "paper" && playerMove != "scissors") {
            cout << "Invalid input! Try again." << endl;
            continue;
        }

        aiMove = getAIMove(history);
        cout << "AI move: " << aiMove << endl;
        cout << checkWinner(playerMove, aiMove) << endl << endl;

        history.push_back(playerMove);
    }

    cout << "\nGame Over. Thanks you." << endl;
    return 0;
}
