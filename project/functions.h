#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_ 

#include <iostream> 
#include <fstream> 
#include <string> 
#include <cctype> 

using namespace std;

string Encrypt(const std::string& plaintext, const string& key);
string Decrypt(const std::string& encrypted_text, const string& key);
string ReadFile(const string& filename);

#endif