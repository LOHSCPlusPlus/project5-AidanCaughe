#pragma once
#include "Node.h"

class InventorDB {
    public:
        InventorDB();
        ~InventorDB();
        void reload();
        void insertInFront(Inventor inventor);
        void append(Inventor inventor);
        void removeFront();
        void print();
        void printAlive();
        void deleteAllNodes();
        void dbMenu();
    private:
        void readFile(const char fileName[]);
        Node *head;
        Node *tail;
};
