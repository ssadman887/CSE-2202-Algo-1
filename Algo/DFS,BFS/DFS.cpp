#include <iostream>
#include <vector>

using namespace std;


void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " "; // Print the visited node
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}



int main() {
    int n; // Number of nodes in the graph
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n); // Adjacency list representing the graph
    vector<bool> visited(n, false); // Array to mark visited nodes
    
    int m; // Number of edges in the graph
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < m; i++) {
        int u, v; // Edge from node u to node v
        cin >> u >> v;
        graph[u].push_back(v);
    graph[v].push_back(u); // Add the edge to the graph
    }

    int src; // Source node for DFS
    cout << "Enter the source node for DFS: ";
    cin >> src;

    cout << "DFS traversal starting from node " << src << ": ";
    dfs(src, graph, visited);

    return 0;
}
