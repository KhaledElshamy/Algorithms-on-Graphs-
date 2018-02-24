#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;

vector<vi> v;
vi vis,c;
int cnt=0,f=1;
void isBipartite(int x){
	vis[x]=1;
	for (int i = 0; i < v[x].size(); ++i) {
		if(c[v[x][i]]==-1)
			c[v[x][i]]=1-c[x];
		else if(c[v[x][i]]== c[x])f=0;
		if(!vis[v[x][i]])
			isBipartite(v[x][i]);
	}
}

int main() {
//	freopen("A-small-practice.in", "r", stdin);
//	freopen("Output.out", "w", stdout);
	int n,m,x,y;
		cin>>n>>m;
		v.assign(n+1,vi()),vis.assign(n+1,0),c.assign(n+1,-1);
		while(m--){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			c[i]=1;
			if(!vis[i])isBipartite(i);
		}
		cout<<f<<endl;
	return 0;
}
