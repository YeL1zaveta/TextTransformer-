#pragma once
#include <string>
using namespace std;

class Cipher {
private:
    const static string ALPHABET;  
    const static string MONO_KEY;
    static int shift; 

public:
    Cipher (){}

   static string CesarEncrypt(string text, int shift);
   static string CesarDecrypt(string text, int shift);

   static string MonoEncrypt(string text);
   static string MonoDecrypt(string text);

};