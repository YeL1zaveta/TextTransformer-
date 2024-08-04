#include <iostream>
#include <fstream>
#include <string>
using namespace std;


string CesarEncrypt(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift) % 26 + base;
        }
        result += c;
    }
    return result;
}

string CesarDecrypt(string text, int shift) {
    string encrypt_text = CesarEncrypt(text, 26 - shift);
    return encrypt_text;
}

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
    string encrypted = CesarEncrypt(text, shift);
    string decrypted = CesarDecrypt(encrypted, shift);

    cout << "Original text: " << text << endl;
    cout << "Encrypted text: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted << endl;
    return 0;

}