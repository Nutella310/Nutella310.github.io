#include <iostream>
#include <fstream>
#include <cctype>

#include "functions.h"

using namespace std;

string Encrypt(const std::string& plaintext, const string& key) {
    string encrypted_text = "";
    int key_length = key.length();
    
    for (int i = 0; i < plaintext.length(); ++i) {
        char char_to_encrypt = plaintext[i];
        int shift = key[i % key_length] % 10;
        
        if (isalpha(char_to_encrypt)) {
            char base = isupper(char_to_encrypt) ? 'A' : 'a';
            encrypted_text += char(base + (char_to_encrypt - base + shift) % 26);
        } else {
            encrypted_text += char(char_to_encrypt + shift);
        }
    }
    
    return encrypted_text;
}

string Decrypt(const string& encrypted_text, const string& key) {
    string decrypted_text = "";
    int key_length = key.length();
    
    for (int i = 0; i < encrypted_text.length(); ++i) {
        char char_to_decrypt = encrypted_text[i];
        int shift = key[i % key_length] % 10;
        
        if (isalpha(char_to_decrypt)) {
            char base = isupper(char_to_decrypt) ? 'A' : 'a';
            decrypted_text += char(base + (char_to_decrypt - base - shift + 26) % 26);
        } else {
            decrypted_text += char(char_to_decrypt - shift);
        }
    }
    
    return decrypted_text;
}

string ReadFile(const string& filename) {
    ifstream File(filename);
    string content, line;
    
    if (File.is_open()) {
        while (getline(File, line)) {
            content += line + '\n';
        }
        File.close();
    }
    return content;
}