class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]); // Since it's a bidirectional graph
        }
        
        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);
    }
    
private:
    bool dfs(const vector<unordered_set<int>>& graph, vector<bool>& visited, int curr, int destination) {
        if (curr == destination) return true;
        visited[curr] = true;
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor] && dfs(graph, visited, neighbor, destination)) {
                return true;
            }
        }
        return false;
    }
};