#include <iostream>
#include <fstream>
#include <string>
#include "Cipher.h"
using namespace std;

/*
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
*/
int main() {
    int choise;

    do {
        cout << "Choise option: " << endl;
        cout << "1.CESAR CHIPER " << endl;
        cout << "2.MONOALPHABEIC CHIPER " << endl;
        cout << "3.AFFINE CHIPER " << endl;
        cout << "4.EXIT" << endl;
        cout << "ENTER CHOISE:" << endl;
        cin >> choise;
        switch (choise) {
        case 1: {
            int x;
            do {
                cout << "1.ENCRYPT CESAR " << endl;
                cout << "2.DECRYPT CESAR " << endl;
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
                    break;
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
                    break;
                    }

                }

            } while (x != 3);
            break;
        }
        case 2: {
            int x;
            do {
                cout << "1.ENCRYPT MONOALPHABEIC " << endl;
                cout << "2.DECRYPT MONOALPHABEIC " << endl;
                cout << "3.EXIT " << endl;
                cin >> x;
                switch (x) {
                case 1: {
                    string text;
                    cout << "ENTER TEXT : ";
                    cin >> text;
                    string encrypted = Cipher::MonoEncrypt(text);

                    cout << "Original text: " << text << endl;
                    cout << "Encrypted text: " << encrypted << endl;
                    break;
                }
                case 2: {
                    string text;
                    cout << "ENTER TEXT : ";
                    cin >> text;
                    string decrypted = Cipher::MonoDecrypt(text);

                    cout << "Original text: " << text << endl;
                    cout << "Decrypted text: " << decrypted << endl;
                    break;
                }

                }

            } while (x != 3);
            break;
        }
        case 3: {
            int x;
            do {
                cout << "1.ENCRYPT AFFINE " << endl;
                cout << "2.DECRYPT AFFINE " << endl;
                cout << "3.EXIT " << endl;
                cin >> x;
                switch (x) {
                case 1: {
                    string text;
                    cout << "ENTER TEXT : ";
                    cin >> text;
                    string encrypted = Cipher::AffineEncrypt(text,5,8);

                    cout << "Original text: " << text << endl;
                    cout << "Encrypted text: " << encrypted << endl;
                    break;
                }
                case 2: {
                    string text;
                    cout << "ENTER TEXT : ";
                    cin >> text;
                    string decrypted = Cipher::AffineDecrypt(text, 5, 8);;

                    cout << "Original text: " << text << endl;
                    cout << "Decrypted text: " << decrypted << endl;
                    break;
                }

                }

            } while (x != 3);
            break;
        }
        case 4: {
            cout << "EXIT" << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;

        }

    } while (choise != 4);

    return 0;
}