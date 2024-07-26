#include<bits/stdc++.h>
using namespace std;

// Link: https://leetcode.com/problems/majority-element-ii

// at max only 2 element present in array who occurs more than n/3 time

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
// extended Moore’s Voting Algorithm

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); 

    int cnt1 = 0, cnt2 = 0; 
    int el1 = INT_MIN; 
    int el2 = INT_MIN; 


    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; 

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    return ls;
}

