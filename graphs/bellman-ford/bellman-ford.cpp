#include<bits/stdc++.h>
using namespace std;


// this algorithm deals the cheapest flight leetcode question. 
// But this can be used for common Bellman Ford algorithm.
class BellmanFord{
private:
	vector<vector<int>> dp;
	vector<vector<vector<int>>> edges;

public:
	BellmanFord(int k, int n, vector<vector<int>> graph) {
		dp = vector<vector<int>>(k+1, vector<int>(n, INT_MAX));
		edges = vector<vector<vector<int>>>(n);

		for(int i=0; i<graph.size(); i++) {
			edges[graph[i][1]].push_back({graph[i][0], graph[i][2]});
		}
	}

	int findMinCost(int source, int destination, int k, int n) {
		dp[0][source] = 0;

		for(int i=1; i<=k; i++) {
			for(int j=0; j<n; j++) {
				if(j==source) dp[i][j] = 0;
				else {
					vector<vector<int>> incomingEdges = edges[j];
					for(int k=0; k<incomingEdges.size(); k++) {
						int prev = dp[i-1][incomingEdges[k][0]];
						prev = prev == INT_MAX ? INT_MAX : prev+incomingEdges[k][1];
						dp[i][j] = min(dp[i][j], prev);
					}
				} 
			}
		}

		return dp[k][destination];
	}
};


int main() {
	vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}};

	BellmanFord bfa = BellmanFord(2, 4, flights);

	cout << bfa.findMinCost(0,3,2,4) << endl;
}