#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

void putDataToVector(istream& stream, vector<int>& vv) {
    int i;
    while (stream >> i) {
        vv.push_back(i);
        i++;
    }
}
int main()
{
    string currentInput;
    int totalGamesSum = 0;
    int game = 0;


    while (getline(cin, currentInput)) {
        if (currentInput == "") break;
        int points = 0;

        game++;
        size_t foundDots = currentInput.find(":");
        size_t foundLine = currentInput.find("|");

        string winingCardsTxt = currentInput.substr(foundDots +1 , (foundLine-1)- (foundDots+1));
        string listCardsTxt = currentInput.substr(foundLine + 1);

        stringstream wCardsstream (winingCardsTxt);
        stringstream liststream (listCardsTxt);

        vector <int> winingCards;
        vector <int> listCards;

        putDataToVector(wCardsstream, winingCards);
        putDataToVector(liststream, listCards);

        vector<int>::iterator it1;
        vector<int>::iterator it2;

        for (it1 = winingCards.begin(); it1 != winingCards.end(); it1++) {
            for (it2 = listCards.begin(); it2 != listCards.end(); it2++) {
                if (*it1 == *it2)
                    points++;
            }
        }
        totalGamesSum = totalGamesSum + pow(2, (points - 1));
    }

    cout << "Points in total: " << totalGamesSum << endl;
}