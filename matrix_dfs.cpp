int vis[N][N];
int dx[8]={-1, -1, -1, 0, 0, +1, +1, +1};
int dy[8]={+1, 0, -1, +1, -1, +1, 0, -1};


void dfs(int x, int y)
{
	if(x<1 || y<1 || x>n || y>n)
		return;
	if(vis[x][y])
		return;
	if(attack(x, y))
		return;
	vis[x][y]=1;
	for(int k=0;k<8;k++)
	{
		dfs(x+dx[k], y+dy[k]);
	}
}
