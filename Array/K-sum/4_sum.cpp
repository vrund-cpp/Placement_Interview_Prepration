#include<bits/stdc++.h>
using namespace std;


// brute-force:
// T.C - O(n^4) and S.C - O(1)
// 4 loops check nums[i] + nums[j] + nums[k] + nums[l] == target

// better
// T.C - O(n^3logn) and S.C - O(1)
// for each 3 we find 4th element using binary search

// optimal
// T.C - O(n^3) and S.C - O(1)
// solve 4sum in terms of 2sum
// a + b + c + d = target every time we fix 2 element
// from remaining array using two sum we find c+d = target-a-b

// we want to check is there quadrate exist whose sum is target
class Solution {
public:
    bool threeSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        bool ans = false;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int temp_tar = target-nums[i]-nums[j];
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

            if(ans)break;

        }

        return ans;
    }
};


// if we want to find unique quadrates without set
// if(i!=0 && nums[i]==nums[i-1])continue
// if(j!=i+1 && nums[j] == nums[j-1])continue
// while(nums[s] == nums[s+1])s++; and while(nums[e] == nums[e-1])e--;
// then check sum == target or not 


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j!=(i+1) && nums[j] == nums[j-1])continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        while(k<l && nums[k] == nums[k+1])k++;
                        while(k<l && nums[l] == nums[l-1])l--;
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                    }
                    else if(sum < target)k++;
                    else l--;
                }
            }
        }
        return ans;
        
    }
};