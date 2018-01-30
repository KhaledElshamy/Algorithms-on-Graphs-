#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;

int n,m;
bool  visited[1001],check[1001];
bool flag=false;

int dfs(int x,vector< vector<int> >& v){
	visited[x]=1;
	check[x]=1;
	for(int j=0;j<(int)v[x].size();j++){
		int child=v[x][j];
		if(!visited[child]&&dfs(child,v))
			return 1;
		else if(check[child]) return 1;
	}
	check[x]=false;
	return 0;
}

int main() {
	cin>>n>>m;
	vector< vector<int> >v(n+1);
	while(m--){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!visited[i]){
			memset(visited,false,sizeof(visited));
			memset(check,false,sizeof(check));
			if(dfs(i,v)){
				cout<<"1"<<endl;
				return 0;
			}
		}
	cout<<"0"<<endl;
	return 0;
}
