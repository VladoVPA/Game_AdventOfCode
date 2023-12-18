#include <iostream>
#include <string>
#include <cctype>

using namespace std;
//12 red cubes, 13 green cubes, and 14 blue cubes
const int MAX_RED = 12, MAX_GREEN = 13, MAX_BLUE = 14;


int main()
{
    string currentInput;
    int totalGamesSum = 0;
    int game = 0;

    while (getline(cin, currentInput)) {
        if (currentInput == "") break;
        
        game++;
        
        int currentNum = 0; // redSum = 0, greenSum = 0, blueSum = 0;
        bool notPositive = false;
        size_t found = currentInput.find(":");

        for (int i = found+2; i < currentInput.size(); ) {
            char c = currentInput[i];

            switch (c)
            {
            case 'r': //red + ',' or ';' + ' '
                if (currentInput[i-3] == ' ') {
                    currentNum = currentInput[i - 2] - '0';
                    if (currentNum > MAX_RED) notPositive = true;
                }
                else if (currentInput[i-4] == ' ') {
                    currentNum = (currentInput[i - 3] - '0')*10 + currentInput[i - 2] - '0';
                   if (currentNum > MAX_RED) notPositive = true;
                }
                i += 5;
                break;
            case 'g': // green + ',' or ';' + ' '
                if (currentInput[i - 3] == ' ') {
                    currentNum = currentInput[i - 2] - '0';
                    if (currentNum > MAX_GREEN) notPositive = true;
                }
                else if (currentInput[i - 4] == ' ') {
                    currentNum = (currentInput[i - 3] - '0') * 10 + currentInput[i - 2] - '0';
                    if (currentNum > MAX_GREEN) notPositive = true;
                }
                i += 7;
                break;
            case 'b': // blue + ',' or ';' + ' '
                if (currentInput[i - 3] == ' ') {
                    currentNum = currentInput[i - 2] - '0';
                    if (currentNum > MAX_BLUE) notPositive = true;
                }
                else if (currentInput[i - 4] == ' ') {
                    currentNum = (currentInput[i - 3] - '0') * 10 + currentInput[i - 2] - '0';
                    if (currentNum > MAX_BLUE) notPositive = true;
                }
                i += 6;
                break;
            default:
                i++;
                break;
            }

        } 
        //cout << "game " << game << "   red " << redSum << "   green " << greenSum << "   blue " << blueSum << endl;
        //cout << game << endl;

        if (!notPositive)
        {
            //cout << game << endl;
            totalGamesSum += game;
        }
    }

    cout << totalGamesSum << endl;
}