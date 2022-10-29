#include<bits/stdc++.h>
using namespace std;

class UnionFind {
private:
	vector<int> root;

public:
	UnionFind(int size) {
		root = vector<int>(size, 0);
		for(int i=0; i<size; i++) {
			root[i] = i;
		}
	}

	int find(int x) {
		return root[x];
	}

	void unionSet(int x, int y) {
		int rootX = root[x];
		int rootY = root[y];

		if(rootX != rootY) {
			for(int i=0; i<root.size(); i++) {
				if(root[i]==rootY)
					root[i]=rootX;
			}
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
	uf.unionSet(1,3);
	uf.unionSet(1,4);

	uf.unionSet(2,5);
	uf.unionSet(2,6);

	int x,y;

	cout << "enter x" << endl;
	cin>>x;
	cout << "enter y" << endl;
	cin>>y;

	cout << uf.connected(x,y) << endl;
}