#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool findSpecial(int i, int index, string str1, string str2, string str3);

int main()
{
    string inputOne = "empty", inputTwo = "empty", inputTree = "empty";
    int sumTotal = 0, length = 0;
    stringstream currentNum;
    bool foundNum = false;
    bool specialNum = false;
    
    while (true) {
        getline(cin, inputTree);

        for (int i = 0; i < inputTwo.size(); i++) {
            char c = inputTwo[i];

            if (isdigit(c)) {
                currentNum << c;
                length++;
                foundNum = true;
            }
            else if (!isdigit(c) && foundNum == true) {
                int index;
                if ((i - length - 1) >= 0)
                    index = (i - length - 1);
                else
                    index = 0;

                if (findSpecial(i, index, inputOne, inputTwo, inputTree)) {
                    int num;
                    currentNum >> num;
                    currentNum.clear();
                    currentNum.str("");
                    foundNum = false;
                    length = 0;
                    sumTotal += num;
                }
                else {
                    currentNum.clear();
                    currentNum.str("");
                    foundNum = false;
                    length = 0;
                }
            }
            if (i == inputTwo.size() - 1 && foundNum == true) {
                int index = i - length;
                if (findSpecial(i, index, inputOne, inputTwo, inputTree)) {
                    int num;
                    currentNum >> num;
                    currentNum.clear();
                    currentNum.str("");
                    foundNum = false;
                    length = 0;
                    sumTotal += num;
                }
                else {
                    currentNum.clear();
                    currentNum.str("");
                    foundNum = false;
                    length = 0;
                }
            }
        }
        inputOne = inputTwo;
        inputTwo = inputTree;

        if (inputTree == "end") break;
    }
    cout << endl << sumTotal << endl;
}
bool findSpecial(int i, int index, string str1, string str2, string str3) {
            bool specialNum = false;
            if (ispunct(str2[i]) && str2[i] != '.') {
                specialNum = true;
            }
            else if (ispunct(str2[index]) && str2[index] != '.') {
                specialNum = true;
            }

            for (int j = (index); j <= i; j++) {
                char b;
                if (str1 == "empty")
                    b = '.';
                else
                    b = str1[j];

                if (ispunct(b) && b != '.') {
                    specialNum = true;
                    break;
                }
            }

            for (int k = (index); k <= i; k++) {
                char l;
                if (str3 == "end")
                    l = '.';
                else
                    l = str3[k];

                if (ispunct(l) && l != '.') {
                    specialNum = true;
                    break;
                }
            }

            return specialNum;            
}
