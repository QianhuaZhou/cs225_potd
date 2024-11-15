#include <vector>
#include <cmath>
#include <iostream>
#include "Primes.h"

std::vector<int> *genPrimes(int M) {//return all primes from 2 to M
    std::vector<int> *v = new std::vector<int>();
    // your code here
    std::vector<bool> isPrime(M, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < M; i++){
        if(isPrime[i]){
            v->push_back(i);
            for(int j = i * 2; j < M; j += i){
                isPrime[j] = false;
            }
        }
    }
    return v;
}

