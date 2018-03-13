#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;

int weight(int x1,int y1, int x2, int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

class UnionFind {
	private: vi parent, rank;
	public:
	UnionFind(int N) {
		rank.assign(N, 0);
		parent.assign(N, 0);
		for (int i = 0; i < N; i++) parent[i] = i;
	}
	
	int findSet(int i) { return (parent[i] == i) ? i : (parent[i] = findSet(parent[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) parent[y] = x;
			else {
				parent[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
} } };

int main() {
	int n;
	cin>>n;
	vector< pair<int, ii> > EdgeList;
	vector<int>u(n),v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &u[i], &v[i]);
	}

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			EdgeList.push_back(make_pair(weight(u[i],v[i],u[j],v[j]), ii(i,j)));

	sort(EdgeList.begin(), EdgeList.end());
	int mst_cost = 0;
	UnionFind UF(n);

	for (int i = 0; i < n; i++) {
		pair<int, ii> front = EdgeList[i];
		if (!UF.isSameSet(front.second.first, front.second.second)) {
			mst_cost += front.first;
			UF.unionSet(front.second.first, front.second.second);
		}
	}
	printf("MST cost = %d (Kruskal’s)\n", mst_cost);
	return 0;
}
