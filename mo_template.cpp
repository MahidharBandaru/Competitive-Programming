inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
bool comp(const pair<pll,ll> &a,const pair<pll,ll> &b){
	return gilbertOrder(a.f.f,a.f.s,21,0) < gilbertOrder(b.f.f,b.f.s,21,0);
}


void add(ll o, ll t){
	if(o < t){
		for(ll i = o+1 ; i <= t ; i++){
			ans+=(1 + 2*g[arr[i]])*arr[i];
			g[arr[i]]++;
		}
	}
	else if(o > t){
		for(ll i = o-1 ; i >= t ; i--){
			ans+=(1 + 2*g[arr[i]])*arr[i];
			g[arr[i]]++;
		}
	}
}


void rem(ll o, ll t){
	if(o < t){
		for(ll i = o ; i < t ; i++){
			ans+=(1 - 2*g[arr[i]])*arr[i];
			g[arr[i]]--;
		}
	}
	else if(o > t){
		for(ll i = o ; i > t ; i--){
			ans+=(1 - 2*g[arr[i]])*arr[i];
			g[arr[i]]--;
		}
	}
}
