#include <iostream>
#include "PairFinder.h"

using namespace std;

int main() {
    PairFinder p(30000);

    p.sieve();

    return 0;
}