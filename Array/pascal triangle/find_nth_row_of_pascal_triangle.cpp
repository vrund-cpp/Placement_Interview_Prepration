#include<bits/stdc++.h>
using namespace std;

// brute-force
// T.C - O(n^2) and S.C - O(n^2)
// generate whole pascal triangle then return the row

// better
// T.C - O(n^2) and S.C - O(n)
// each i th row in pascal triangle is only dependent on i-1th row
// use two array generate all rows

// optimal
// T.C - O(n*r) and S.C - O(1)
// find Ncr = N*(N-1)*(N-2)*...(N-K)/(1*2*3...*k)

// rth element of nth row of pascal triangle is n-1Cr-1.
// for i=1 to n find ith element and return the row

int nCr(int n, int r) {
    long long res = 1;


    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {

    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

