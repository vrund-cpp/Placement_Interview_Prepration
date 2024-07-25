#include<bits/stdc++.h>
using namespace std;

// Link: https://leetcode.com/problems/3sum/

// brute-force:
// T.C - O(n^3) and S.C - O(1)
// 3 loops check nums[i] + nums[j] + nums[k] == target

// better
// T.C - O(n^2logn) and S.C - O(1)
// for each 2 we find 3rd element using binary search

// optimal
// T.C - O(n^2) and S.C - O(1)
// solve 3sum in terms of 2sum
// a + b + c = target every time we fix one element
// from remaining array using two sum we find b+c = target-a


// we want to check is there triplet exist whose sum is target
class Solution {
public:
    bool threeSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        bool ans = false;
        for(int i=0;i<nums.size();i++){
            int temp_tar = target-nums[i];
            int s=i+1;
            int e=nums.size()-1;

            while(s<e){
                if(nums[s]+nums[e] == temp_tar){
                    ans = true;
                    break;
                }
                else if(nums[s]+nums[e] > temp_tar){
                    e--;
                }
                else{
                    s++;
                }
            }

            if(ans)break;
        }

        return ans;
    }
};


// if we want to find unique triplets without set
// if(i!=0 && nums[i]==nums[i-1])continue
// while(nums[s] == nums[s+1])s++; and while(nums[e] == nums[e-1])e--;
// then check sum == target or not 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int i=0;i<nums.size();i++){

            if(i!=0 && nums[i] == nums[i-1])continue;

            int temp_target = target-nums[i];
            int s = i+1;
            int e = nums.size()-1;

            while(s<e){
                
                if(nums[s] + nums[e] == temp_target){

                    while(s<e && nums[s] == nums[s+1])s++;
                    while(s<e && nums[e] == nums[e-1])e--;

                    vector<int>temp_ans;
                    temp_ans.push_back(nums[i]);
                    temp_ans.push_back(nums[s]);
                    temp_ans.push_back(nums[e]);
                    ans.push_back(temp_ans);

                    s++;
                    e--;
                }
                else if(nums[s]+nums[e] > temp_target){
                    e--;
                }
                else{
                    s++;
                }

            }
        
        }

        return ans;
    }
};