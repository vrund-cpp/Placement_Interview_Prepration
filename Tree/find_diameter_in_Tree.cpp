// Problem link: https://cses.fi/problemset/task/1131/
// Platform - CSES

// at every node there may be more than 2 child
// that's why we use max and second max
// in binary at max 2 child so just we add left + child

#include<bits/stdc++.h>
using namespace std;

 
int fun(int i,vector<int>Adj[],int &ans,vector<int>&vis){
    vis[i] = 1;
 
    if(Adj[i].empty())return 1;
 
    int maxi = 0;
    int second_maxi = 0;
 
    for(auto it:Adj[i]){
        if(!vis[it]){
            int temp =  fun(it,Adj,ans,vis);
            if(temp>=maxi){
                second_maxi = maxi;
                maxi = temp;
            }
            else if(temp>second_maxi){
                second_maxi = temp;
            }          
        }
    }
 
    ans = max(ans,maxi+second_maxi);
    
    return maxi+1;
}
 
int main(){
 
    int n;
    cin >> n;
    vector<int>Adj[n+1];
    vector<int>vis(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int ans = 0;
    int vb = fun(1,Adj,ans,vis);

    cout << ans << endl;
 
    return 0;
}