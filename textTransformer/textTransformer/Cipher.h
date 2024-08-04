#pragma once
#include <string>
using namespace std;

class Cipher {
private:
    const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string MONO_KEY = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int caesarShift=3; 

public:
    Cipher (){}

   static string CesarEncrypt(string text, int shift);
   static string CesarDecrypt(string text, int shift);



};