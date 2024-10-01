#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void logInMenu();
void signUpMenu();
void menu();

//Need to Add Database

bool verify_password(string password){
    bool is_length = false;
    bool has_lowercase = false;
    bool has_uppercase = false;
    bool has_symbol = false;
    bool has_digit = false;

    int length = password.length();
    if (length >= 8 && length <= 15){
        is_length = true;
    }
    for(int i = 0; i < length; i++){
        try{
            if(islower(password[i])) {
                has_lowercase = true;
                throw 510;
            } else if(isupper(password[i])) {
                has_uppercase = true;
                throw 511;
            } else if(ispunct(password[i])) {
                has_symbol = true;
                throw 512;
            } else if(isdigit(password[i])) {  
                has_digit = true;
                throw 513;            
            }
        }
        catch(int i){
            cout << "Invalid Input - Please Choose Option 1 or 2" << endl;
            cout << "Error number: " << i;
            cout << endl;
            menu();
        }
    }
    return is_length && has_lowercase && has_uppercase && has_symbol && has_digit;
}

void menu(){
    try {
        int input;

        cout << "\nHello User, Please Choose One of the Following." << endl;
        cout << "1. Log In" << endl;
        cout << "2. Sign Up" << endl;
        cout << "Option: ";
        cin >> input;
        cout << endl;
        if (input == 1){
            logInMenu();
        } else if (input == 2){
            signUpMenu();
        } else {
            throw 505;
        }
    }
    catch (int i){
        cout << "Invalid Input - Please Choose Option 1 or 2" << endl;
        cout << "Error number: " << i;
        cout << endl;
        menu();
    }
}

void logInMenu(){
    string username;
    string password;
    cout << "Log in Menu" << endl;
    cout << "Please Input Username: ";
    cin >> username;
    cout << "Please Input Password: ";
    cin >> password;
    menu();
}

void signUpMenu(){
    cout << "Sign Up Menu" << endl;
    cout << endl;
    string username;
    string password;
    cout << "Sign Up Menu" << endl;
    cout << "Please Input Username: ";
    cin >> username;
    cout << "Please Input Password: ";
    cin >> password;
    bool valid_password = verify_password(password);
    if (valid_password == true){
        cout << "Valid Password" << endl;
    } else {
        cout << "Invalid Password" << endl;
    }

    menu();
}

int main(){
    menu();
}