#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void login();
void registration();
void forgot();

int main() {
    int c;
    cout << "\t\t\tWelcome to the login page!\n";
    cout << "\t\t\tMenu\n\n";
    cout << "\t| Enter 1 to LOGIN\t\t\t\t|\n";
    cout << "\t| Enter 2 to REGISTER\t\t\t\t|\n";
    cout << "\t| Enter 3 if you forgot your PASSWORD\t\t|\n";
    cout << "\t| Enter 4 to EXIT\t\t\t\t|\n";
    cout << "\n\t\t\tPlease enter your choice: ";
    cin >> c;
    cout << "\n";
    
    switch(c) {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "Exit successful!\n";
            return 0;
        default:
            system("cls");
            cout << "\t\t\tPlease select an option from the menu above.\n\n";
            main();
    }
}

void login() {
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\tPlease enter the username and password: \n";
    cout << "\t\t\tUSERNAME: ";
    cin >> userId;
    cout << "\t\t\tPASSWORD: ";
    cin >> password;

    ifstream input;
    input.open("records.txt");

    while(input >> id >> pass) {
        if(id == userId && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();
    if(count == 1) {
        system("cls");
        cout << "Your login was successful " << userId << "!\n";
        cout << "Thanks for logging in!\n";
        main();
    } else {
        cout << "\nLOGIN Error\n Please check your username and password.\n";
        main();
    }
}

void registration() {
    string registerUserId, registrationPassword, registrationId, registrationPass;
    system("cls");
    cout << "\t\t\tEnter the username: ";
    cin >> registerUserId;
    cout << "\t\t\tEnter the password: ";
    cin >> registrationPassword;

    ofstream fileOpen("records.txt", ios::app);
    fileOpen << registerUserId << ' ' << registrationPassword << endl;
    system("cls");
    cout << "\n\t\t\tRegistration successful! You can now login.\n";
    main();

}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\tForgot Password?\n";
    cout << "Press 1 to search your ID by username.\n";
    cout << "Press 2 to go back to the main menu.\n";
    cout << "\tEnter your choice: ";
    cin >> option;


    switch(option) {
        case 1: {
            int count = 0;
            string stringUserId, stringId, stringPass;
            cout << "\n\t\t\tEnter your username: ";
            cin  >> stringUserId;
            ifstream fileOpen2("records.txt");
            while(fileOpen2 >> stringId >> stringPass) {
                if(stringId == stringUserId) {
                    count = 1;
                    break;
                }
            }
            fileOpen2.close();
            if(count == 1) {
                cout << "\n\nYour account has been found.\n";
                cout << "\nYour password is: " << stringPass;
                cout << "\n";
                main();
            } else {
                cout << "\n\tSorry! Your account could not be found!\n";
                main();
            }
            break;   
        }
        case 2:
            main(); 
            break;
        default:
            forgot();

    }
}