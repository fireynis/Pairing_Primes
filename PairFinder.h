//
// Created by jeremy on 10/19/2015.
//

#ifndef PAIRING_PRIMES_PAIRFINDER_H
#define PAIRING_PRIMES_PAIRFINDER_H

#include <sstream>
#include <stdlib.h>

using namespace std;

class PairFinder {
    int n;
public:
    PairFinder(int setN):
            n(setN+1)
    {}
    void sieve() {
        bool primes[n];
        int count = 0;
        string line = "", test = "";

        for (int i = 0; i < n; ++i) {
            primes[i] = false;
        }

        // 1 is technically not a prime number, so initializing it as such
        // Zero is also similar
        primes[0] = true;
        primes[1] = true;

        while (count < n) {
            if (!primes[count]) {
                for (int i = 2; i < n; i++) {
                    int mult = count*i;
                    if (mult < n) {
                        primes[mult] = true;
                    }
                }
            }
            count++;
        }

        for (int j = 0; j < n; ++j) {
            if (!primes[j]) {
                stringstream st;
                st << j;
                test += " "+st.str();
                if (test.length() > 90) {
                    cout << line << endl;
                    line = st.str();
                } else {
                    line += " "+st.str();
                }
                test = line;
            }
        }
        cout << line << endl;
        line = "";
        test = line;

        int lineCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!primes[i]) {
                for (int j = i; j < n; ++j) {
                    if (!primes[j]) {
                        if (j - i == 2) {
                            stringstream pair;
                            pair << "(" << i << ", " << j << ")";
                            test += pair.str();
                            if (test.length() >= 90) {
                                cout << line << endl;
                                line = pair.str()+", ";
                                test = line;
                            } else {
                                line += pair.str()+", ";
                            }
                        }
                    }
                }
            }
        }
        cout << line << endl;
    }
};


#endif //PAIRING_PRIMES_PAIRFINDER_H
