#include <iostream>
#include <string>
#include <cctype>

using namespace std;
//12 red cubes, 13 green cubes, and 14 blue cubes
//const int MAX_RED = 12, MAX_GREEN = 13, MAX_BLUE = 14;


int main()
{
    string currentInput;
    int totalSum = 0;
    int  redMax = 0, greenMax = 0, blueMax = 0;

    while (getline(cin, currentInput)) {
        if (currentInput == "") break;

        redMax = 0, greenMax = 0, blueMax = 0;

        int currentNum = 0;
        //bool notPositive = false;
        size_t found = currentInput.find(":");

        for (int i = found + 2; i < currentInput.size(); ) {
            char c = currentInput[i];

            switch (c)
            {
            case 'r': //red + ',' or ';' + ' '
                if (currentInput[i - 3] == ' ') {
                    currentNum = currentInput[i - 2] - '0';
                    if (currentNum > redMax) 
                        redMax = currentNum;
                }
                else if (currentInput[i - 4] == ' ') {
                    currentNum = (currentInput[i - 3] - '0') * 10 + currentInput[i - 2] - '0';
                    if (currentNum > redMax)
                        redMax = currentNum;
                }
                i += 5;
                break;
            case 'g': // green + ',' or ';' + ' '
                if (currentInput[i - 3] == ' ') {
                    currentNum = currentInput[i - 2] - '0';
                    if (currentNum > greenMax)
                        greenMax = currentNum;
                }
                else if (currentInput[i - 4] == ' ') {
                    currentNum = (currentInput[i - 3] - '0') * 10 + currentInput[i - 2] - '0';
                    if (currentNum > greenMax)
                        greenMax = currentNum;
                }
                i += 7;
                break;
            case 'b': // blue + ',' or ';' + ' '
                if (currentInput[i - 3] == ' ') {
                    currentNum = currentInput[i - 2] - '0';
                    if (currentNum > blueMax)
                        blueMax = currentNum;
                }
                else if (currentInput[i - 4] == ' ') {
                    currentNum = (currentInput[i - 3] - '0') * 10 + currentInput[i - 2] - '0';
                    if (currentNum > blueMax)
                        blueMax = currentNum;
                }
                i += 6;
                break;
            default:
                i++;
                break;
            }

        }
        
            totalSum += (redMax * greenMax * blueMax);
    }


    cout << totalSum << endl;
}