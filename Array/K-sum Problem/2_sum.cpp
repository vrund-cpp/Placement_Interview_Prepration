#include<bits/stdc++.h>
using namespace std;

// Link:- https://leetcode.com/problems/two-sum/

// brute-force:
// T.C - O(n^2) and S.C - O(1)
// for each num we find (target-num).

// better:
// T.C - O(n) and S.C - O(n)
// hashing (unordered_map)
// unordered_map : average O(n) and worst O(n^2)
// ordered_map : average and worst both O(nlogn)

// optimal:
// T.C - O(nlogn) and S.C - O(1)
// sorting and two pointer
// if we use merge sort then S.C - O(n)

// we want to check is there pair exist whose sum is target
class Solution {
public:
    bool twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size()-1;

        bool ans = false;
        while(s<e){
            if(nums[s] + nums[e] == target){
                ans = true;
                break;
            }
            else if(nums[s]+nums[e] > target){
                e--;
            }
            else{
                s++;
            }
        }

        return ans;
    }
};

// if we want to find unique pairs without set
// while(nums[s] == nums[s+1])s++; and while(nums[e] == nums[e-1])e--;
// then check sum is target or not
class Solution {
public:
    vector<pair<int,int>> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size()-1;

        vector<pair<int,int>>ans;
        while(s<e){
            
            if(nums[s] + nums[e] == target){
                while(s<e && nums[s] == nums[s+1])s++;
                while(s<e && nums[e] == nums[e-1])e--;
                ans.push_back({nums[s],nums[e]});
                s++;
                e--;
                
            }
            else if(nums[s]+nums[e] > target){
                e--;
            }
            else{
                s++;
            }

        }

        return ans;
    }
};

