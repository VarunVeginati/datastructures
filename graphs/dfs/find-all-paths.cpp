#include<bits/stdc++.h>
using namespace std;

class DFS {
private:
	vector<string> paths;
	map<char, vector<char> > edges_map;
	set<char> visited;

public:
	DFS(vector<vector<char> > edges) {
		for(int i=0; i<edges.size(); i++) {
			edges_map[edges[i][0]].push_back(edges[i][1]);
			edges_map[edges[i][1]].push_back(edges[i][0]);
		}
	}

	void calculateAllPaths(char currentVertex, char targetVertex, string path) {
		path += currentVertex;
		if(currentVertex == targetVertex) {
			paths.push_back(path);
			return;
		}

		vector<char> connectedNodes = edges_map[currentVertex];
		visited.insert(currentVertex);

		for(int i=0; i<connectedNodes.size(); i++) {
			if(visited.find(connectedNodes[i]) == visited.end()) {
				calculateAllPaths(connectedNodes[i], targetVertex, path);
			}
		}

		visited.erase(currentVertex);
	}

	void printAllPaths() {
		for(int i=0; i<paths.size(); i++)
			cout << paths[i] << endl;
	}

};

int main()
{
	vector<vector<char> > edges(8, vector<char>(2));

	edges[0][0]='A';
	edges[0][1]='B';

	edges[1][0]='A';
	edges[1][1]='D';

	edges[2][0]='A';
	edges[2][1]='C';

	edges[3][0]='B';
	edges[3][1]='E';

	edges[4][0]='D';
	edges[4][1]='E';

	edges[5][0]='C';
	edges[5][1]='E';

	edges[6][0]='B';
	edges[6][1]='F';

	edges[7][0]='E';
	edges[7][1]='F';

	DFS dfs(edges);

	dfs.calculateAllPaths('A','B',"");

	dfs.printAllPaths();
}