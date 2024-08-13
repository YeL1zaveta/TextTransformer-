#include <iostream>
#include <fstream>
#include <string>
#include "Cipher.h"

using namespace std;

const string Cipher::ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string Cipher::MONO_KEY = "QWERTYUIOPASDFGHJKLZXCVBNM";

string Cipher::CesarEncrypt(string text,int shift) {
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

string Cipher::CesarDecrypt(string text,int shift) {
    string encrypt_text = CesarEncrypt(text, 26 - shift);
    return encrypt_text;
}

string Cipher::MonoEncrypt(string text) {
    std::string ciphertext = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            size_t index = ALPHABET.find(toupper(ch));
              ciphertext += MONO_KEY[index];
            
        }
        else {
            ciphertext += ch;
        }
    }

    return ciphertext;
}

string Cipher::MonoDecrypt(string text) {
    std::string plaintext = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            size_t index = MONO_KEY.find(toupper(ch));
            plaintext += ALPHABET[index];
            
        }
        else {
            plaintext += ch;
        }
    }

    return plaintext;
}

string Cipher::AffineEncrypt(const string text, int key1, int key2){
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {

            char encryptedAff = ((((char)(key1 * (text[i] - 'A')) + key2) % 26) + 'A');
            result += encryptedAff;
        }
        else {
            result += text[i];
        }
    }
    return result;

}
