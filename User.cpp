#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <regex>
#include <vector>
#include "User.h"

using namespace std;


bool User::isValidEmail(string e) {
    if (regex_match(e, regex(("^(([^<>()[\\]\\.,;:\\s@\"]+(\\.[^<>()[\\]\\.,;:\\s@\"]+)*)|(\".+\"))@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\])|(([a-zA-Z\\-0-9]+\\.)+[a-zA-Z]{2,}))$"))))
        return true;
    else
        return false;
}

bool User::isValidUsername(string u) {
    if (regex_match(u, regex(("^([a-zA-Z]|-)+$"))))
        return true;
    else
        return false;
}

bool User::isValidPhoneNumber(string p) {
    if (regex_match(p, regex(("^(010|011|012|015)[0-9]{8}$"))))
        return true;
    else
        return false;
}

bool User::isValidPassword(string p) {
    string specialchars = "!@#?";
    int i = 0, upper = 0, lower = 0, special = 0, digit = 0;
    for (i = 0; i < p.length(); i++) {
        if (isdigit(p[i]))
            digit++;
        else if (islower(p[i]))
            lower++;
        else if (isupper(p[i]))
            upper++;
        else if (specialchars.find(p[i]) < p.length() && specialchars.find(p[i]) > 0)
            special++;
        else
            return false;
    }
    if (p.length() > 8 && upper > 0 && lower > 0 && special > 0 && digit > 0)
        return true;
    else
        return false;
}

bool User::isFoundedUsername(string username) {
    for (auto tempUsername : usernames) {
        if (username.compare(tempUsername) == 0) {
            return true;
        }
    }
    return false;
}

bool User::isFoundedEmail(string email) {
    for (auto tempEmail : emails) {
        if (email.compare(tempEmail) == 0) {
            return true;
        }
    }
    return false;
}

string User::getUsernamePasswords(string username) {
    for (int i = 0; i < usernames.size(); i++) {
        if (username.compare(usernames.at(i)) == 0) {
            return passwords.at(i);
        }
    }
    return "";
}

string User::encryptPassword(string p) {
    string keyWord = "aby";
    string result = "";
    //Block 1 // Make Length keyword equal to length password
    while (keyWord.length() < p.length()) {
        keyWord += keyWord;
    }
    keyWord = keyWord.substr(0, p.length() - 1);
    // End Of Block 1
    for (int i = 0; i < p.length() - 1; i++) {
        p[i] = toupper(p[i]);
        keyWord[i] = toupper(keyWord[i]);
        if (p[i] >= 65 && p[i] <= 90) {
            result += char(65 + ((p[i] + keyWord[i]) % 26));
        }
        else {
            result += p[i];
        }
    }
    return result;
}

void User::saveChanges(string changes, string type) {
    if (type.compare("u") == 0) {
        usernames.push_back(changes);
    }
    else if (type.compare("e") == 0) {
        emails.push_back(changes);
    }
    else if (type.compare("ph") == 0) {
        phoneNumbers.push_back(changes);
    }
    else if (type.compare("p") == 0) {
        passwords.push_back(changes);
    }
}

void User::setUsername() {
    string u;
    while (true) {
        cout << "\nPlease, Enter your username: ";
        cin >> u;
        if (isValidUsername(u) && !isFoundedUsername(u)) {
            username = u;
            break;
        }
        else if (isFoundedUsername(u)) {
            cout << "\nSorry, Username already taken, Try Again!!..\n";
        }
        else {
            cout << "Please, Enter valid username and Try Again!!..\n";
        }

    }
}

void User::setEmail() {
    string e;
    while (true) {
        cout << "Please, Enter your email: ";
        cin >> e;
        if (isValidEmail(e) && !isFoundedEmail(e)) {
            email = e;
            break;
        }
        else if (isFoundedEmail(e)) {
            cout << "\nSorry, Email already taken, Try Again!!..\n";
        }
        else {
            cout << "Please, Enter valid email address and Try Again!!..\n";
        }
    }
}

void User::setPhoneNumber() {
    string p;
    while (true) {
        cout << "Please, Enter your Phonenumber: ";
        cin >> p;
        if (isValidPhoneNumber(p)) {
            phoneNumber = p;
            break;
        }
        else {
            cout << "\nPlease, Enter valid Phone Number and Try Again!!..\n";
        }

    }
}

void User::setPassword() {
    string p = "", pconf = "";
    int i;
    char ch;
    cout << "Please, Enter your Password: ";
    for (i = 0; (ch = _getch()) != '\r';) {
        if (ch != 8) {
            p += ch;
            cout << "*";
            i++;
        }
        else {
            i--;
            p = p.substr(0, i);
            if (i < 0) {
                i++;
            }
            else {
                cout << "\b \b";
            }
        }
    }
    if (isValidPassword(p)) {
        cout << "\nPlease, Confirm  your password: ";
        for (i = 0; (ch = _getch()) != '\r';) {
            if (ch != 8) {
                pconf += ch;
                cout << "*";
                i++;
            }
            else {
                i--;
                pconf = pconf.substr(0, i);
                if (i < 0) {
                    i++;
                }
                else {
                    cout << "\b \b";
                }
            }
        }
        if (p.compare(pconf) == 0) {
            password = encryptPassword(p);
        }
        else {
            cout << "\nYou Entered two different passwords, Try Again!!..\n";
            setPassword();
        }
    }
    else {
        cout << "\nPlease, Enter strong password\nat least 8 characters\ncontains upper & lower letters\ncontain special character e.g: @#!?\ncontain digits";
        setPassword();
    }
}

void User::registration() {
    setUsername();
    setEmail();
    setPhoneNumber();
    setPassword();
    saveChanges(username, "u");
    saveChanges(email, "e");
    saveChanges(phoneNumber, "ph");
    saveChanges(password, "p");
}

void User::login() {
    string name, pass = "";
    int i;
    char ch;

    cout << "username: ";
    cin >> name;
    if (isFoundedUsername(name)) {
        username = name;
        cout << "password: ";
        for (i = 0; (ch = _getch()) != '\r';) {
            if (ch != 8) {
                pass += ch;
                cout << "*";
                i++;
            }
            else {
                i--;
                pass = pass.substr(0, i);
                if (i < 0) {
                    i++;
                }
                else {
                    cout << "\b \b";
                }
            }
        }
        password = encryptPassword(pass);
        if (password.compare(getUsernamePasswords(username)) == 0) {
            cout << "\nSuccessful login, welcome " << username << endl;
        }
        else {
            cout << "\nFailed login. Try again.\n";
            trail += 1;
            if (trail == 3) {
                cout << "You is denied access to the system\n";
                exit(0);
            }
            login();
        }
    }
    else {
        cout << "username is not exit\n";
        login();
    }
}

User::User()
{
    fstream dataFile;
    string temp;
    dataFile.open("data.txt", ios::in);
    while (!dataFile.eof() && dataFile.peek() != EOF) {
        getline(dataFile, temp);
        usernames.push_back(temp);
        getline(dataFile, temp);
        emails.push_back(temp);
        getline(dataFile, temp);
        phoneNumbers.push_back(temp);
        getline(dataFile, temp);
        passwords.push_back(temp);
    }
    dataFile.close();
}

User::~User()
{
    fstream dataFile;
    dataFile.open("data.txt", ios::out);
    for (int i = 0; i < usernames.size(); i++) {
        dataFile << usernames.at(i);
        dataFile << endl;
        dataFile << emails.at(i);
        dataFile << endl;
        dataFile << phoneNumbers.at(i);
        dataFile << endl;
        dataFile << passwords.at(i);
        dataFile << endl;
    }
    dataFile.close();
}



void User::changePassword() {
    string user, oldPass, newPass, confPass, tempUsername;
    int i;
    char ch;
    cout << "Username: ";
    cin >> user;
    if (isFoundedUsername(user)) {
        username = user;
        cout << "Old password: ";
        for (i = 0; (ch = _getch()) != '\r';) {
            if (ch != 8) {
                oldPass += ch;
                cout << "*";
                i++;
            }
            else {
                i--;
                oldPass = oldPass.substr(0, i);
                if (i < 0) {
                    i++;
                }
                else {
                    cout << "\b \b";
                }
            }
        }
        password = encryptPassword(oldPass);
        if (password.compare(getUsernamePasswords(username)) == 0) {
            cout << "New Password: ";
            for (i = 0; (ch = _getch()) != '\r';) {
                if (ch != 8) {
                    newPass += ch;
                    cout << "*";
                    i++;
                }
                else {
                    i--;
                    newPass = newPass.substr(0, i);
                    if (i < 0) {
                        i++;
                    }
                    else {
                        cout << "\b \b";
                    }
                }
            }
            if (isValidPassword(newPass)) {
                cout << "Confirm Password: ";
                for (i = 0; (ch = _getch()) != '\r';) {
                    if (ch != 8) {
                        confPass += ch;
                        cout << "*";
                        i++;
                    }
                    else {
                        i--;
                        confPass = confPass.substr(0, i);
                        if (i < 0) {
                            i++;
                        }
                        else {
                            cout << "\b \b";
                        }
                    }
                }
                if (newPass.compare(oldPass) == 0) {
                    cout << "Password Has Been Successfully changed";
                    password = newPass;
                    for (int i = 0; i < usernames.size(); i++) {
                        if (username.compare(usernames.at(i)) == 0) {
                            passwords.at(i) = password;
                        }
                    }
                }
            }
            else {
                cout << "\nFailed login. Try again.\n";
                trail += 1;
                if (trail == 3) {
                    cout << "You is denied access to the system\n";
                    exit(0);
                }
                changePassword();
            }
        }
        else {
            cout << "username is not exit\n";
            changePassword();
        }
    }

}
