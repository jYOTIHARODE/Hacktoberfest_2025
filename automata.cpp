#include <iostream>
#include <string>
using namespace std;

// Define states
enum State {
    START,
    SEEN_0,
    SEEN_1,
    ACCEPT,
    REJECT
};

// Function to simulate the automaton
bool isAccepted(const string& input) {
    State state = START;

    for (char ch : input) {
        switch (state) {
            case START:
                if (ch == '0') state = SEEN_0;
                else if (ch == '1') state = SEEN_1;
                else return false; // Invalid character
                break;

            case SEEN_0:
                if (ch == '0') state = SEEN_0;
                else if (ch == '1') state = ACCEPT;
                else return false;
                break;

            case SEEN_1:
                if (ch == '0') state = SEEN_0;
                else if (ch == '1') state = SEEN_1;
                else return false;
                break;

            case ACCEPT:
                if (ch == '0') state = SEEN_0;
                else if (ch == '1') state = SEEN_1;
                else return false;
                break;

            default:
                return false;
        }
    }

    // Accept only if last two characters were "01"
    return state == ACCEPT;
}

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;

    if (isAccepted(input))
        cout << "String accepted by the automaton." << endl;
    else
        cout << "String rejected by the automaton." << endl;

    return 0;
}
