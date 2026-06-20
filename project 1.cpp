#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string password;
    
    cout << "Enter your password: ";
    cin >> password;

    bool hasUpper = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    // Check each character
    for (char ch : password) {
        if (isupper(ch))
            hasUpper = true;
        else if (isdigit(ch))
            hasNumber = true;
        else if (!isalnum(ch))
            hasSymbol = true;
    }

    int score = 0;

    // Check length
    if (password.length() >= 8)
        score++;

    // Check uppercase
    if (hasUpper)
        score++;

    // Check number
    if (hasNumber)
        score++;

    // Check symbol
    if (hasSymbol)
        score++;

    // Display password strength
    cout << "\n----- Password Analysis -----" << endl;
    cout << "Length: " << password.length() << endl;
    cout << "Contains Uppercase: " << (hasUpper ? "Yes" : "No") << endl;
    cout << "Contains Number: " << (hasNumber ? "Yes" : "No") << endl;
    cout << "Contains Symbol: " << (hasSymbol ? "Yes" : "No") << endl;

    if (score <= 1)
        cout << "Password Strength: Weak" << endl;
    else if (score <= 3)
        cout << "Password Strength: Medium" << endl;
    else
        cout << "Password Strength: Strong" << endl;

    return 0;
}