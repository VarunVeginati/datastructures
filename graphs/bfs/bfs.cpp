#include<bits/stdc++.h>
using namespace std;

class BFS {
private:
	vector<vector<char> > edges_map;
	vector<int> visited;
	vector<string> paths;

public:
	BFS(vector<vector<char> > edges, int size) {
		edges_map = vector<vector<char> >(size);
		visited = vector<int>(size, 0);

		for(int i=0; i<edges.size(); i++) {
			edges_map[edges[i][0]-'A'].push_back(edges[i][1]);
			edges_map[edges[i][1]-'A'].push_back(edges[i][0]);
		}
	}


	void calculateAllPaths(string source, char destination) {
		queue<string> q;
		q.push(source);

		while(!q.empty()) {
			int size = q.size();

			for(int i=0; i<size; i++) {
				string currentPath = q.front();
				q.pop();

				if(currentPath.back() == destination)
					paths.push_back(currentPath);

				vector<char> adjacentNodes = edges_map[currentPath.back()-'A'];

				for(int j=0; j<adjacentNodes.size(); j++) {
					if(visited[adjacentNodes[j]-'A'] == 0) {
						q.push(currentPath+adjacentNodes[j]);
					}
				}

				visited[currentPath.back()-'A'] = 1;
			}
		}
	}

	void printAllPaths() {
		for(int i=0; i<edges_map.size(); i++) {
			for(int j=0; j<edges_map[i].size(); j++) {
				cout << edges_map[i][j] << ", ";
			}
			cout << endl;
		}
		// for(int i=0; i<paths.size(); i++) {
		// 	cout << paths[i] << endl;
		// }
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

	BFS bfs(edges, 6);
	
	bfs.calculateAllPaths("A", 'F');

	bfs.printAllPaths();
}