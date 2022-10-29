#include<bits/stdc++.h>
using namespace std;

class UnionFind {
private:
	vector<int> root;
	vector<int> rank;

public:
	UnionFind(int size) {
		root = vector<int>(size,0);
		rank = vector<int>(size,1);

		for(int i=0; i<size; i++)
			root[i] = i;
	}

	int find(int x) {
		while(x != root[x])
			x = root[x];

		return x;
	}

	void unionSet(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);

		if(rootX != rootY) {
			if(rank[rootX] > rank[rootY])
				root[rootY] = rootX;
			else if(rank[rootX] < rank[rootY])
				root[rootX] = rootY;
			else {
				root[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}

	int getRankByIndex(int x) {
		return rank[x];
	}

	int getRootByIndex(int x) {
		return root[x];
	}
};

int main()
{
	UnionFind uf(7);

	uf.unionSet(0,1);
	uf.unionSet(0,2);
	uf.unionSet(0,3);

	uf.unionSet(0,4);
	uf.unionSet(5,6);

	// for(int i=0; i<7; i++) {
	// 	cout << uf.getRankByIndex(i) << ",";
	// }

	// cout << endl;

	int x,y;

	cout << "enter x" << endl;
	cin>>x;
	cout << "enter y" << endl;
	cin>>y;

	cout << uf.connected(x,y) << endl;
}