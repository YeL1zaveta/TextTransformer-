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

   static string AffineEncrypt(string text, int key1,int key2);
   static string AffineDecrypt(string text, int key1,int key2);

};