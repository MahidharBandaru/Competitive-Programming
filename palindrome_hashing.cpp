#include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
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
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define fi first
    #define se second
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pb(x) push_back(x)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

    using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
    
   ll hash1[5000001]; 
   ll po[5000001];
   ll hash2[5000001];
   string s;
   string s1;
   ll si;
   ll p = 73;
   // ll p2 = 41;
    ll m = 1000000009;
    // ll m2 = 1000000009;
   ll sub_hash(ll i, ll j){
    ll thash;
    if(i <= j)
        thash = (hash1[i]+m - ((hash1[j+1])*po[j+1-i])%m)%m;
    else
        thash = (hash1[i] + sub_hash(0,j)*po[si-i])%m;
    return thash;
   }

   ll sub_hash2(ll i,ll j){
    ll thash;
    if(i <= j)
        thash = (hash2[i]+m - ((hash2[j+1])*po[j+1-i])%m)%m;
    else
        thash = (hash2[i] + sub_hash2(0,j)*po[si-i])%m;
    return thash;
   }

   bool isPalin(ll i, ll j){
        ll id = si-i-1;
        ll jd = si-j-1;
        if(sub_hash(i,j) == sub_hash2(jd,id))
            return 1;
        return 0;
   }
    int main()
    {_

        // cin >> si;
        cin >> s;
        si = s.size();
        reverse(s.begin(), s.end());
        s1 = s;
        reverse(s.begin(), s.end());
        for(ll i = 0 ; i < si ; i++){
            if(i == 0){
                po[i] = 1;
            }
            else{
                po[i] = (po[i-1]*p)%m;

            }
        }
        hash1[si] = 0;
        hash2[si] = 0;
        for(ll i = si-1 ; i >= 0 ; i--){
            if(i == si-1){
                hash1[i] = s[i] - 'a' + 1;
                hash2[i] = s1[i] - 'a' + 1;

            }
            else{
                hash1[i] = (s[i] - 'a' + 1 + hash1[i+1]*p)%m;
                hash2[i] = (s1[i] - 'a' + 1 + hash2[i+1]*p)%m;

            }
        }
        
        cout << isPalin(0,si-1);




            
        return 0;
   }
