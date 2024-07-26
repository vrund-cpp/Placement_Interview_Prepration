#include<bits/stdc++.h>
using namespace std;

// brute-force
// T.C - O(n^2) and S.C - O(1)
// generating all continous subarray using 2 for loops
// check sum is k or not

// not use sorting because of order is important

// optimal
// T.C - O(n) and S.C - O(n)
// first we make prefix sum array
// use map to store sum is exist or not
// for each time we find prefixsum - target
// if it exist then target sum is also exist

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    map<int,int>mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; 
    for (int i = 0; i < n; i++) {

        preSum += arr[i];

        int remove = preSum - k;

        cnt += mpp[remove];

        mpp[preSum] += 1;
    }
    
    return cnt;
}