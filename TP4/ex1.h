#ifndef ex1_h
#define ex1_h

struct Element {
    int value;
    struct Element* next;
};

struct Pile {
    struct Element* top;
};

#endif