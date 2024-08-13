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
    std::string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) { // Sprawdzenie, czy znak jest liter¹
            // Przekszta³cenie litery zgodnie ze wzorem Affine
            char base = isupper(text[i]) ? 'A' : 'a'; // Ustal bazê, czy litera jest wielka, czy ma³a
            int x = text[i] - base; // Zamiana litery na indeks w alfabecie
            char encryptedAff = (char)(((key1 * x + key2) % 26) + base); // Szyfrowanie i powrót do wielkoœci litery
            result += encryptedAff; // Dodanie zaszyfrowanego znaku do wyniku
        }
        else {
            result += text[i]; // Jeœli znak jest spacj¹, dodaj go bez zmian
        }
    }
    return result;
}
