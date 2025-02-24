//Encryption 

#include <iostream>
#include <string>

#include "functions.h"

using namespace std; 

int main() {
    string message, key, result;
    int choice;
    
    cout << "Enter the file name containing the message: ";
    string filename;
    cin >> filename;
    
    message = ReadFile(filename);
    
    cout << "Enter the key for encryption/decryption: ";
    cin >> key;
    
    cout << "Press 1 for encryption\nPress 2 for decryption\n";
    cin >> choice;

    if (choice == 1) { 
        result = Encrypt(message, key);
        cout << "Here is your Encrypted Message:\n" << result << endl;
    } else if (choice == 2) {
        result = Decrypt(message, key); 
        cout << "Here is your Decrypted Message:\n" << result << endl;
    } else { 
        cout << "Invalid Choice!" << endl;
    }
    
    return 0;
}