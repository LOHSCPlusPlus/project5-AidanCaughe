#pragma once
#include <fstream>
using namespace std;
class Inventor{
    public:
        Inventor();
        Inventor(const Inventor &other);
        void operator = (const Inventor &other);
        ~Inventor();
        void readFromFile(istream &file);
        void readFromUser();
        void print();
        bool isAlive();
    private:
        void deleteAll();
        char *name;
        char *years;
        char *job;
        char *info;
        
};
