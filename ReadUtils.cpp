#include <iostream>
#include <cstring>
#include "ReadUtils.h"
using namespace std;

void commonErrorCode(const char prompt[]) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
}

int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        commonErrorCode(prompt);
        cin >> temp;
    }
    return temp;
}
double readDouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        commonErrorCode(prompt);
        cin >> temp;
    }
    return temp;
}
bool readBool(const char prompt[]){
    char temp;
    cout << prompt;
    cin >> temp;
    temp = toupper(temp); 
    while (temp != 'Y' && temp != 'N') {
        commonErrorCode(prompt);
        cin >> temp;
        temp = toupper(temp);
    }
    return temp == 'Y';
}
char *createCharPtr(const char otherString[]) {
    char *ptr = nullptr;
    if (otherString != nullptr) {
        // We add 1 because of the \0 at the end of the string
        int sizeNeeded = strlen(otherString) + 1;
        ptr = new char[sizeNeeded];
        // After we allocate it, we can treat like a regular array.
        strcpy(ptr, otherString);
    }
    return ptr;
}

char *readCString(istream &in, char delimeter) {
    char temp[1000];
    in.getline(temp, 1000, delimeter);
    return createCharPtr(temp);
}
