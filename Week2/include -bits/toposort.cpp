#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;

int n,m;
bool  visited[100001];
vector<vi>v(100001);
vi sorting(100001);

void dfs(int x,vector< vector<int> >& v, vector<int>& sorting){
	visited[x]=true;
	for(int j=0;j<(int)v[x].size();j++){
		int child=v[x][j];
		if(!visited[child])
			dfs(child,v,sorting);
	}
	sorting.insert(sorting.begin(),x);
}

int main() {
	cin>>n>>m;
	sorting.clear();
	memset(visited,false,sizeof(visited));
	while(m--){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i])
			dfs(i,v,sorting);
	}
	for(int i=0;i<(int)sorting.size();i++)cout<<sorting[i]<<" ";
	cout<<endl;
	return 0;
}
