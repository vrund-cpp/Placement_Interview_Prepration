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

int findLargestSubarraySumK(vector<int>&v,int target){
    int n = v.size();
    int prefsum = 0;
    int ans = 0;
    map<int,int>mp;

    mp[0] = -1;

    for(int i=0;i<n;i++){
        prefsum += v[i];

        if(mp.count(prefsum-target)){
            ans = max(ans,i-mp[prefsum-target]);
        }
        else if(!mp.count(prefsum)){
            mp[prefsum] = i;
        }

    }

    return ans;
}