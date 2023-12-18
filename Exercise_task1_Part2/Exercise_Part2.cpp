#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string currentInput;
    int totalSum = 0;

    while (getline(cin, currentInput)) {
        if (currentInput == "") break;

        int first = 0, last = 0;
        bool haveFirst = false;

        for (int i = 0; i < currentInput.size(); ) {
            char c = currentInput[i];
                       
            if (isdigit(c)) {
                if (haveFirst == false) {
                    first = c - '0';
                    last = c - '0';
                    haveFirst = true;
                }
                else
                    last = c - '0';

                i++;
            }
            else if (c != 'o' && c != 't' && c != 'f' && c != 's' && c != 'e' && c != 'n')
                i++;
            else {
                if (c =='o') {
                size_t found = currentInput.find("one", i, 3);
                if (found != std::string::npos && found == i) {
                    if (haveFirst == false) {
                        first = 1;
                        last = 1;
                        haveFirst = true;
                    }
                    else
                        last = 1;
                    i += 2;
                }
                else 
                    i++;
            }
            else if (c == 't') {
                    size_t found2 = currentInput.find("two", i, 3);
                    size_t found3 = currentInput.find("three", i, 5);

                //if (currentInput[i+1]=='w' && currentInput[i + 2] == 'o') {
                if (found2 != std::string::npos && found2 == i) {
                    if (haveFirst == false) {
                        first = 2;
                        last = 2;
                        haveFirst = true;
                    }
                    else
                        last = 2;
                    i += 2;
                }
                //else if (currentInput.find("three", i, 5) != std::string::npos) {
                else if (found3 != std::string::npos && found3 == i) {
                    if (haveFirst == false) {
                        first = 3;
                        last = 3;
                        haveFirst = true;
                    }
                    else
                        last = 3;
                    i += 4;
                }
                else
                    i++;
            }
            else if (c == 'f') {
                size_t found4 = currentInput.find("four", i, 4);
                size_t found5 = currentInput.find("five", i, 4);

                //if (currentInput[i+1] == 'o' && currentInput[i + 2] == 'u' && currentInput[i + 3] == 'r') {
                if (found4 != std::string::npos && found4 == i) {
                    if (haveFirst == false) {
                        first = 4;
                        last = 4;
                        haveFirst = true;
                    }
                    else
                        last = 4;
                    i += 3;
                }
                //else if (currentInput.find("five", i, 4) != std::string::npos) {
                else if (found5 != std::string::npos && found5 == i) {
                    if (haveFirst == false) {
                        first = 5;
                        last = 5;
                        haveFirst = true;
                    }
                    else
                        last = 5;
                    i += 3;
                }
                else
                    i++;
            }
            else if (c == 's') {
                    size_t found6 = currentInput.find("six", i, 3);
                    size_t found7 = currentInput.find("seven", i, 5);

                    //if (currentInput[i+1] == 'i' && currentInput[i + 2] == 'x') {
                if(found6 != std::string::npos && found6 == i){
                    if (haveFirst == false) {
                        first = 6;
                        last = 6;
                        haveFirst = true;
                    }
                    else
                        last = 6;
                    i += 2;
                }
                //else if (currentInput.find("seven", i, 5) != std::string::npos) {
                else if(found7 != std::string::npos && found7 == i){
                    if (haveFirst == false) {
                        first = 7;
                        last = 7;
                        haveFirst = true;
                    }
                    else
                        last = 7;
                    i += 4;
                }
                else
                    i++;
            }
            else if (c == 'e') {
                size_t found = currentInput.find("eight", i, 5);
                if (found != std::string::npos && found == i) {
                    if (haveFirst == false) {
                        first = 8;
                        last = 8;
                        haveFirst = true;
                    }
                    else
                        last = 8;
                    i += 4;
                }
                else
                    i++;
            }
            else if (c == 'n') {
                size_t found = currentInput.find("nine", i, 4);
                if (found != std::string::npos && found == i) {
                    if (haveFirst == false) {
                        first = 9;
                        last = 9;
                        haveFirst = true;
                    }
                    else
                        last = 9;
                    i += 3;
                }
                else
                    i++;
            }
            }
        }



        totalSum = totalSum + (first * 10 + last);
    }

    cout << "SUM is: " << totalSum << endl;
    return 0;
}
