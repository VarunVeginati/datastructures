#include<bits/stdc++.h>
using namespace std;

// algorithm for course schedule 2.
class TopologicalSort{
private:
	vector<vector<int>> edges;
	vector<int> indegree;
	vector<int> order;
	queue<int> q;
	vector<int> visited;
	bool isPossible = true;

public:
	TopologicalSort(vector<vector<int>>& prerequisites, int n) {
		indegree = vector<int>(n, 0);
		visited = vector<int>(n,0);
		edges = vector<vector<int>>(n);
		for(int i=0; i<prerequisites.size(); i++) {
			edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
			indegree[prerequisites[i][0]]++;
		}
	}

	void buildOrder(int n) {
		for(int i=0; i<n; i++) {
			if(indegree[i]==0) q.push(i);
		}

		while(!q.empty() && isPossible) {
			int curr = q.front();
			q.pop();

			if(visited[curr]==1) continue;

			visited[curr]=1;
			order.push_back(curr);

			vector<int> adjacent_nodes = edges[curr];

			for(int i=0; i<adjacent_nodes.size(); i++) {
				if(visited[adjacent_nodes[i]]==1) continue;

				indegree[adjacent_nodes[i]]--;

				if(indegree[adjacent_nodes[i]]==0) q.push(adjacent_nodes[i]);

				if(indegree[adjacent_nodes[i]]<0) {
					isPossible = false;
					break;
				}
			}
		}
	}

	bool getIsPossible(int n) {
		for(int i=0; i<n; i++) {
			if(indegree[i]!=0) return false;
		}

		return isPossible;
	}

	vector<int> getOrder() {
		return order;
	}
};

int main() {
	vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};

	TopologicalSort tp = TopologicalSort(prerequisites, 4);

	tp.buildOrder(4);

	if(tp.getIsPossible(4)) {
		vector<int> order = tp.getOrder();

		for(int i=0; i<4; i++) {
			cout << order[i] << ",";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}