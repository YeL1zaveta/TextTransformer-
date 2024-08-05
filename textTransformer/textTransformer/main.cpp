#include <iostream>
#include <fstream>
#include <string>
#include "Cipher.h"
using namespace std;

string readFile(const string& filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "the file could not be found or could not be opened" << endl;
        return " ";
    }
    string result;
    string line;
    while (getline(inputFile, line)) {
        result = line ;
    }
    inputFile.close();
    return result;
}

string saveFile(string filename, string result) {
    ofstream outputFile(filename);

    if (!outputFile) {
        cout << "the file could not be found or could not be opened" << endl;
        return " ";
    }

    outputFile << result;
    outputFile.close();

}

int main2() {
    string inputFileName = "input.txt";
    string text = readFile(inputFileName);
    int shift = 3;
    string encrypted = Cipher::CesarEncrypt(text, shift);
    string decrypted = Cipher::CesarDecrypt(encrypted, shift);

    cout << "Original text: " << text << endl;
    cout << "Encrypted text: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted << endl;
    return 0;

}

int main() {
    int choise;

    do {
        cout << "Choise option: " << endl;
        cout << "1.CESAR CHIPER " << endl;
        cout << "2.MONOALPHABEIC CHIPER " << endl;
        cout << "3.EXIT" << endl;
        cout << "ENTER CHOISE:" << endl;
        cin >> choise;
        switch (choise) {
        case 1: {
            int x;
            do {
                cout << "1.ENCRYPT CESAR " << endl;
                cout << "2. DECRYPT CESAR " << endl;
                cout << "3.EXIT " << endl;
                cin >> x;
                switch (x) {
                case 1:{
                    int shift;
                    string text;
                    cout << "ENTER KEY : ";
                    cin >> shift;
                    cout << "ENTER TEXT : ";
                    cin >> text;
                    string encrypted = Cipher::CesarEncrypt(text, shift);

                    cout << "Original text: " << text << endl;
                    cout << "Encrypted text: " << encrypted << endl;

                }
                case 2: {
                    int shift;
                    string text;
                    cout << "ENTER KEY : ";
                    cin >> shift;
                    cout << "ENTER TEXT : ";
                    cin >> text;
                    string decrypted = Cipher::CesarDecrypt(text, shift);

                    cout << "Original text: " << text << endl;
                    cout << "Decrypted text: " << decrypted << endl;
                }

                }

            } while (x != 3);

        }
        case 2: {

        }
        case 3: {

        }

        }

    } while (choise != 4);
    return 0;
}