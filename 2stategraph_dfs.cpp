#include <bits/stdc++.h>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define pb(x) push_back(x)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define fi first
    #define se second
    using namespace std;
    vll adj[400000+2];
    int v[400000+2];
    ll dp[400000+2];
    ll ans[200000];
    ll a[200000];
    ll n;
    int win;
    void dfs(ll s){
        v[s] = 1;
        for(auto e: adj[s]){
            if(v[e] == 0){
                dfs(e);
                if(win == -1){
                    v[s] = -1;

                }
                else if(win == 2){
                    v[s] = 2;
                    dp[s] = dp[e] + a[s/2];
                }
            }
            else if(v[e] == 1){
                win = -1;
                v[s] = -1;
                return;
            }
            else if(v[e] == 2){
                win = 2;
                v[s] = 2;
                dp[s] = dp[e] + a[s/2];
                return;
            }
        }
    }
    void dfs1(){
        for(ll i = 1 ; i < n ; i++){
            if(v[2*i+1] == 0){
                vll temp;
                win = 0;
                dfs(2*i+1);
                
                if(win == -1){
                    ans[i] = -1;
                }
                else if(win == 2){
                    ans[i] = dp[2*i + 1] + i;
                }

            }
            else if(v[2*i+1] == 2)
                ans[i] = dp[2*i+1] + i;
            else if(v[2*i+1] == -1)
                ans[i] = -1;
        }
    }
    int main()
    {   
        std::ios::sync_with_stdio(false);

        cin >> n;
        v[2*n] = 2;
        v[2*n+1] = 2;
        v[0] = -1;
        v[1] = -1;
        dp[2*n] = 0;
        dp[2*n+1] = 0;
        for(ll i = 0 ; i < n-1 ; i++)
            cin >> a[i+1];
        for(ll i = 1 ; i < n ; i++){
            if(i+a[i] < n){
                adj[2*i].pb(2*(i+a[i]) + 1);
            }
            else{
                adj[2*i].pb(2*n+1);
            }
            if(i-a[i] >= 0){
                adj[2*i+1].pb(2*(i-a[i]));
            }
            else{
                adj[2*i+1].pb(2*n);
            }
        }
        dfs1();
        for(ll i = 1 ; i < n ; i++)
            if(ans[i] == 0)
                cout << -1 << endl;
            else
                cout << ans[i] << endl;
        return 0;
        
    }
