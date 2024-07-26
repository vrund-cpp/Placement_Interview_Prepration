#include<bits/stdc++.h>
using namespace std;

// Link: https://leetcode.com/problems/majority-element/description/

// brute-force
// T.C - O(n^2) and S.C - O(1)
// for each element we find occurence in the array

// better
// T.C - O(n) and S.C - O(1)
// we use map to store occurece of each element
// ordered : T.C - O(nlogn) and unordered : T.C - O(n) 
// in worst case unordered : T.C - O(n^2)

// optimal
// T.C - O(n) and S.C - O(1)
// Moore’s Voting Algorithm

int majorityElement(vector<int> v) {


    int n = v.size();
    int cnt = 0; 
    int el; 

    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }


    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}