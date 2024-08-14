#include <iostream>
#include <fstream>
#include <string>
#include "Cipher.h"
using namespace std;

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
                    cin.ignore(); 
                    cout << "ENTER TEXT : ";
                    getline(cin, text);
                    string encrypted = Cipher::CesarEncrypt(text, shift);
                    cout << "Encrypted text: " << encrypted << endl;
                    break;
                }
                case 2: {
                    int shift;
                    string text;
                    cout << "ENTER KEY : ";
                    cin >> shift;
                    cin.ignore();
                    cout << "ENTER TEXT : ";
                    getline(cin, text);
                    string decrypted = Cipher::CesarDecrypt(text, shift);
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
                    cin.ignore();
                    getline(cin, text);
                    string encrypted = Cipher::MonoEncrypt(text);
                    cout << "Encrypted text: " << encrypted << endl;
                    break;
                }
                case 2: {
                    string text;
                    cout << "ENTER TEXT : ";
                    cin.ignore();
                    getline(cin, text);
                    string decrypted = Cipher::MonoDecrypt(text);
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
                    cin.ignore();
                    getline(cin, text);
                    string encrypted = Cipher::AffineEncrypt(text,5,8);
                    cout << "Encrypted text: " << encrypted << endl;
                    break;
                }
                case 2: {
                    string text;
                    cout << "ENTER TEXT : ";
                    cin.ignore();
                    getline(cin, text);
                    string decrypted = Cipher::AffineDecrypt(text, 5, 8);;
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