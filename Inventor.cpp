#include "Inventor.h"
#include "ReadUtils.h"
#include <iostream>
#include <cstring>
using namespace std;
/**
Clear all the values to nullptr
*/
Inventor::Inventor(){
    name = nullptr;
    job = nullptr;
    years = nullptr;
    info = nullptr;
}

Inventor::~Inventor(){
    deleteAll();
}
Inventor::Inventor(const Inventor &other) {
    name = nullptr;
    job = nullptr;
    years = nullptr;
    info = nullptr;
    name = createCharPtr(other.name);
    job = createCharPtr(other.job);
    years = createCharPtr(other.years);
    info = createCharPtr(other.info);
}
void Inventor::operator = (const Inventor &other) {
    deleteAll();
    name = createCharPtr(other.name);
    job = createCharPtr(other.job);
    years = createCharPtr(other.years);
    info = createCharPtr(other.info);
    
}

void Inventor::deleteAll() {
    delete [] name;
    delete [] job;
    delete [] years;
    delete [] info;
    name = nullptr;
    job = nullptr;
    years = nullptr;
    info = nullptr;
}
/**
Loads the information from the file specified
*/
void Inventor::readFromFile(istream &file) {
    deleteAll();
    name = readCString(file, ';');
    years = readCString(file, ';');
    job = readCString(file, ';');
    info = readCString(file, '\n');
}
/**
Very similar to readFromFile, but we are prompting the user
for the values.
*/
void Inventor::readFromUser(){
    deleteAll();
    cin.ignore(100,'\n');
    cout << "Inventors Name: ";
    name = readCString(cin, '\n');
    cout << "Years alive (DOB-DOD): ";
    years = readCString(cin, '\n');
    cout << "Occupation: ";
    job = readCString(cin, '\n');
    cout << "Accomplishments: ";
    info = readCString(cin, '\n');
}
/**
Print the data to the screen
*/
void Inventor::print(){
    cout << endl;
    cout << "Name            = \"" <<  name << "\"" << endl;
    cout << "DOB/Death       = \"" <<  years << "\"" << endl;
    cout << "Occupations     = \"" <<  job << "\"" << endl;
    cout << "Accomplishments = \"" <<  info << "\"" << endl;
}

/**
 Returns true if the Inventor is still alive
*/
bool Inventor::isAlive(){
    char letter = years[strlen(years) - 1];
    return letter == '-';
}
