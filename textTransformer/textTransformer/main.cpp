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

int main() {
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