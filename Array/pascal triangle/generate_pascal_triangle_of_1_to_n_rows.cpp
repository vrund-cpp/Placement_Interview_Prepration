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
// T.C - O(n^2) and S.C - O(1)
// find i = 1 to nth row using nCr approach

// in here answer array is not considered in space complexity

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); 


    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}