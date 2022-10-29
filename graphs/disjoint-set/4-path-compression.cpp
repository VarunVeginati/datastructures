#include<bits/stdc++.h>
using namespace std;

class UnionFind {
private:
	vector<int> root;

public:
	UnionFind(int size) {
		for(int i=0; i<size; i++)
			root.push_back(i);
	}

	int find(int x) {
		if(x==root[x])
			return x;
		return root[x] = find(root[x]);
	}

	void unionSet(int x, int y) {
		int rootX = root[x];
		int rootY = root[y];

		if(rootX != rootY) {
			root[rootY] = rootX;
		}
	}

	bool connected(int x, int y) {
		return find(x)==find(y);
	}
};

int main()
{
	UnionFind uf(7);

	uf.unionSet(0,1);
	uf.unionSet(1,2);
	uf.unionSet(1,3);

	uf.unionSet(4,5);
	uf.unionSet(4,6);

	int x,y;

	cout << "enter x" << endl;
	cin>>x;
	cout << "enter y" << endl;
	cin>>y;

	cout << uf.connected(x,y) << endl;
}