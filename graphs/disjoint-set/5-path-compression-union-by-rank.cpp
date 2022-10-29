#include<bits/stdc++.h>
using namespace std;

class UnionFind {
private:
	vector<int> root;
	vector<int> rank;
	int count; // to find the number of components in the graph. 
			   // If all vertices are connected then the count will be 1.

public:
	UnionFind(int size) {
		count = size;
		for(int i=0; i<size; i++) {
			root.push_back(i);
			rank.push_back(1);
		}
	}

	int find(int x) {
		if(x==root[x]) return x;
		return root[x] = find(root[x]);
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
			count--;
		}
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};