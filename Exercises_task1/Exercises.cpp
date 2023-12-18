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
        
        for (int i = 0; i < currentInput.size(); i++) {
            char c = currentInput[i];
            
            if (isdigit(c) && haveFirst == false) {
                first = c - '0';
                last = c - '0';
                haveFirst = true;
            }
            else if (isdigit(c) && haveFirst == true) {
                last = c - '0';
            }
        }

        totalSum = totalSum + (first * 10 + last);
    }

    cout << "SUM is: " << totalSum << endl;
    return 0;

}
