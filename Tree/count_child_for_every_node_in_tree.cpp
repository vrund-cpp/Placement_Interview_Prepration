// problem link - https://cses.fi/problemset/task/1674
// platfort - CSES 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll fun(ll i,vector<ll>&ans,vector<ll>Adj[]){
    
    if(Adj[i].empty()){
        ans[i] = 0; // leaf has no child
        return ans[i]+1;
    }
 
    ll cnt = 0;
    for(auto it:Adj[i]){
        cnt += fun(it,ans,Adj); // sum of all cnt of child
    }

    ans[i] = cnt;
    return ans[i]+1; 
}
 
int main(){
    ll n;
    cin >> n;
    vector<ll>Adj[n+1];
    for(ll i=0;i<n-1;i++){
        ll te;
        cin >> te;
        Adj[te].push_back(i+2);
    }
 
    vector<ll>ans(n+1,0);
    ll temp = fun(1,ans,Adj);

    for(ll i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
 
    return 0;
}