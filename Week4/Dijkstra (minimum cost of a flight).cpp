#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;

vector<vector< pair<int,int> > > adjlist;

bool visited[100001],flag=false;
int node1,node2;
int INF=1000000;

void dfs(int node){
	visited[node]=true;
	for(int i=0;i<(int)adjlist[node].size();i++){
		ii child=adjlist[node][i];
		if(child.first==node2)flag=true;
		if(!visited[child.first])dfs(child.first);
	}
}

int main() {
	int n,m,x,y,d;
	cin>>n>>m;
	memset(visited,false,sizeof(visited));
	adjlist.assign(n+1,vector< pair<int,int> >());
	while(m--){
		cin>>x>>y>>d;
		adjlist[x].push_back(ii(y,d));
	}
	cin>>node1>>node2;
	dfs(node1);
	if(!flag){
		cout<<"-1"<<endl;
		return 0;
	}
	vi distance(n+1,INF);
	priority_queue<ii>pq;
	distance[node1]=0;
	pq.push(ii(0,node1));

	while(!pq.empty()){
		ii front =pq.top();pq.pop();
		int d=front.first,parent=front.second;
		if(d>distance[parent])continue;
		for(int i=0;i<(int)adjlist[parent].size();i++){
			ii path=adjlist[parent][i];
			if(distance[parent]+path.second<distance[path.first]){
				distance[path.first]=distance[parent]+path.second;
				pq.push(ii(distance[path.first],path.first));
			}
		}
	}
	cout<<distance[node2]<<endl;

	return 0;
}
