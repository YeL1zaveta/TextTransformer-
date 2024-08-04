#include <iostream>
#include <fstream>
#include <string>
#include "Cipher.h"

using namespace std;


string Cipher::CesarEncrypt(string text, int shift) {
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

string Cipher::CesarDecrypt(string text, int shift) {
    string encrypt_text = CesarEncrypt(text, 26 - shift);
    return encrypt_text;
}