#include<bits/stdc++.h>
using namespace std;

class DIJKASTRAS {
private:
	// data structure to store the connected edges.
	// 1->2->10, 1->3->5 will be stores as [[[2,10], [3,5]], [[]], ..].
	vector<vector<vector<int> > > edges;

	// data structure to keep track of which nodes are visited.
	vector<int> visited;

	// to keep track of visited nodes count.
	int visited_count;

	// to store total number of nodes.
	int total_nodes;

	// data structure to store dijkstras algorithm table.
	vector<pair<int,int> > table;

	// min heap data structure to process the next min cost node.
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

public:
	DIJKASTRAS(vector<vector<int> > graph, int n) {
		visited = vector<int>(n+1, 0);
		total_nodes = n;
		visited_count = 0;

		edges = vector<vector<vector<int> > >(n+1);
		table = vector<pair<int,int> >(n+1);

		for(int i=1; i<=n; i++) {
			table[i] = make_pair(INT_MAX,INT_MAX);
		}

		for(int i=0; i<graph.size(); i++) {
			edges[graph[i][0]].push_back({graph[i][1], graph[i][2]});
		}
	}

	void generate_table(int starting_node) {
		table[starting_node] = make_pair(0, INT_MAX);

		for(int i=0; i<edges[starting_node].size(); i++) {
			pq.push(make_pair(edges[starting_node][i][1], edges[starting_node][i][0]));
			table[edges[starting_node][i][0]] = make_pair(edges[starting_node][i][1], starting_node);
		}

		visited_count++;
		visited[starting_node] = 1;

		while(pq.size() > 0 && visited_count < total_nodes) {
			int top_node = pq.top().second;
			pq.pop();

			if(visited[top_node] == 1) continue;

			vector<vector<int> > adjacentNodes = edges[top_node];

			for(int i=0; i<adjacentNodes.size(); i++) {
				int cost = table[top_node].first+adjacentNodes[i][1];
				if(visited[adjacentNodes[i][0]] == 1) continue;
				else if(cost < table[adjacentNodes[i][0]].first) {
					table[adjacentNodes[i][0]] = make_pair(cost, top_node);
					pq.push(make_pair(cost, adjacentNodes[i][0]));
				}
			}

			visited_count++;
			visited[top_node] = 1;
		}
	}


	void print_table() {
		for(int i=1; i<=total_nodes; i++) {
			cout << i << ", " << table[i].first << ", " << table[i].second << endl;
		}
	}

	void print_edges() {
		for(int i=1; i<=total_nodes; i++) {
			vector<vector<int> > adjacentNodes = edges[i];

			cout << i << " -> ";

			for(int j=0; j<adjacentNodes.size(); j++) {
				cout << "[" << adjacentNodes[j][0] << "," << adjacentNodes[j][1] << "], ";
			}

			cout << endl;
		}
	}

};

int main() {
	vector<vector<int> > graph = {{1,2,1},{1,4,3},{1,3,1},{2,4,2},{3,4,1},{2,5,1},{4,5,2},};

	DIJKASTRAS dj(graph, 5);

	dj.generate_table(1);

	dj.print_table();
}