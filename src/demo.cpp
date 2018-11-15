#include <iostream>
#include "demo.hpp"

using namespace std;

demo::demo() {
    cout << "construct demo" << endl;
}

demo::~demo() {
    cout << "deconstruct demo" << endl;
}

bool demo::output(int arg1, int arg2) {
    if (arg1 == arg2) {
        return true;
    }
    
    return false;
}

bool demo::input(int arg1, int arg2) {
    if (arg1 == arg2) {
        return true;
    }
    
    return false;
}
