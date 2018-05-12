
    #include <bits/stdc++.h>
    typedef long long ll;
    using namespace std;
    set<ll> adj[200000];
    ll n,m;
    set<ll> vis;
    multiset<ll> ans;
    void dfs1util(ll s, ll &siz){
        vis.erase(s);
        siz++;
        ll cur = 0;
        while (1) {
            auto it = vis.upper_bound(cur);
            if (it == vis.end()) break;
            cur = *it;
            if (adj[s].find(*it) == adj[s].end()) 
                dfs1util(*it, siz);
        }
    }
    void dfs1(){
        while (!vis.empty()) {
            ll siz = 0;
            dfs1util(*(vis.begin()), siz);
            ans.insert(siz);
        }
    }
    int main()
    {
        std::ios::sync_with_stdio(false);


        cin >> n >> m;
        for(ll i = 0 ; i < m ; i++){
            ll u,v;
            cin >> u >> v;
            u--;v--;
            adj[u].insert(v);
            adj[v].insert(u);

        }
        for(ll i = 0 ; i < n ; i++)
            vis.insert(i);
        dfs1();
        cout << ans.size() << endl;
        for(auto &e : ans)
            cout << e << " ";
        return 0;
        
    }
    
    // Note: This idea was used in http://codeforces.com/problemset/problem/920/E
    // This code is the solution for  ^ problem
