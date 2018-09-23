ll h[100000];
const ll MAXN = 100000;
const ll MAXLOG = 17;
int par[MAXN][MAXLOG];

void dfs(ll s, ll p = -1){
	par[s][0] = p;
	if(p + 1)
		h[s] = h[p] + 1;
	for(int i = 1;i < MAXLOG;i ++)
		if(par[s][i-1] + 1)
			par[s][i] = par[par[s][i-1]][i-1];
	for(auto &e : tree[s]){
		if(e != p){
			dfs(e,s);
		}
	}
}

int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] + 1 && h[par[v][i]] >= h[u])
			v = par[v][i];
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}
