#include <iostream>
using namespace std;
// Pass in the prompt, it will spin until the user enters an integer
int readInt(const char prompt[]);
// Pass in the prompt, it will spin until the user enters a double
double readDouble(const char prompt[]);
// Ask a y/n question returns true if user enters Y/y or false if user enters N/n
// It will spin until the user enters a y/n or Y/N
bool readBool(const char prompt[]);
// Create a new cstring of exactly the right size to hold a the string passed in
// Then fill in the data
// WARNING! Does a new, which means you must do the delete
char *createCharPtr(const char otherString[]);
// Returns a cstring exactly large enough to hold the characters
// up to the delimiter, and copies in the contens.
// WARNING! Does a new, which means you must do the delete
char *readCString(istream &in, char delimiter);
