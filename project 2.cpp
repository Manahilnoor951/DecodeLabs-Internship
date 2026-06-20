#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key) {
    string result = "";

    for (char ch : text) {
        if (isupper(ch)) {
            result += char((ch - 'A' + key) % 26 + 'A');
        }
        else if (islower(ch)) {
            result += char((ch - 'a' + key) % 26 + 'a');
        }
        else {
            result += ch; // Keep spaces and symbols unchanged
        }
    }

    return result;
}

string decrypt(string text, int key) {
    string result = "";

    for (char ch : text) {
        if (isupper(ch)) {
            result += char((ch - 'A' - key + 26) % 26 + 'A');
        }
        else if (islower(ch)) {
            result += char((ch - 'a' - key + 26) % 26 + 'a');
        }
        else {
            result += ch;
        }
    }

    return result;
}

int main() {
    string message;
    int key;

    cout << "===== Caesar Cipher Encryption & Decryption =====\n";

    cout << "Enter a message: ";
    getline(cin, message);

    cout << "Enter shift key (1-25): ";
    cin >> key;

    string encryptedText = encrypt(message, key);
    string decryptedText = decrypt(encryptedText, key);

    cout << "\nOriginal Text  : " << message << endl;
    cout << "Encrypted Text : " << encryptedText << endl;
    cout << "Decrypted Text : " << decryptedText << endl;

    return 0;
}