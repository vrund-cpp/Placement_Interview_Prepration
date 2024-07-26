#include<bits/stdc++.h>
using namespace std;

// brute-force
// T.C - O(n^2) and S.C - O(n^2)
// generate whole pascal triangle then find the element

// better
// T.C - O(n) + O(r) + O(n-r) and S.C - O(1)
// find NcR = n!/((n-r)! * (r)!) using naive approach

// optimal
// T.C - O(r) and S.C - O(1)
// find Ncr = N*(N-1)*(N-2)*...(N-K)/(1*2*3...*k)

// rth element of nth row of pascal triangle is n-1Cr-1.

int nCr(int n, int r) {
    long long res = 1;

    // because nCr = nC(n-r)

    if(r>n-r){
        r = n-r;
    }
    
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}