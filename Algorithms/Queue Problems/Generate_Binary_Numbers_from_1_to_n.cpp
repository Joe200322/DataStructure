#include <iostream>
#include <algorithm>
#include "../../DataStructure/Queue/Queue.h"

using namespace std;

string getBinaryCode(int value){
    string binaryCode = "";
    bool reverseCode = false;

    if (value %2 == 0){
        reverseCode = true;
    }

    while (value){
        int reminder = value % 2;
        binaryCode += to_string(reminder);
        value /= 2;
    }
    if (reverseCode){
        reverse(binaryCode.begin(), binaryCode.end());
    }
    return binaryCode;
}

void generateBinaryCodeInQueue(Queue<string> &Binaries, int value){
    int binaryCode = 1;
    while (binaryCode <= value){
        Binaries.enqueue(getBinaryCode(binaryCode));
        binaryCode++;
    }
}

void BinaryCodeGenerateProgram(){
    while(true){
        cout << "enter your number to generate binary code for it, if you want to exit enter -1 : ";
        string input;
        getline(cin, input);
        try {
            int intInput = stoi(input);
            if (intInput == -1)
                break;
            else if (intInput >= 0){
                Queue<string>Binaries;
                generateBinaryCodeInQueue(Binaries, intInput);
                Binaries.print();
            }
            else{
                cout << "please enter valid number";
            }
        }
        catch (...){
            cout << "please enter integer input" << endl;
        }
    }
}

int main() {
    BinaryCodeGenerateProgram();
}