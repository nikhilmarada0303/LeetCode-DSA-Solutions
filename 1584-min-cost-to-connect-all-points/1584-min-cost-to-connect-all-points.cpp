class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<pair<int, int>>> adj(n);  // Adjacency list
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].emplace_back(j, dist);
                adj[j].emplace_back(i, dist);
            }
        }
        
        vector<int> minDist(n, INT_MAX);  // Stores the minimum distance to each point
        vector<bool> vis(n, false);       // Marks visited points
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Min-heap
        pq.push({0, 0});  // Initial point to the priority queue
        int totalCost = 0;
        
        while (!pq.empty()) {
            int curDist = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            
            if (vis[curNode]) {
                continue;
            }
            vis[curNode] = true;
            totalCost += curDist;
            
            // Update minimum distances for neighboring points using adjacency list
            for (const auto& neighbor : adj[curNode]) {
                int nextNode = neighbor.first;
                int newDist = neighbor.second;
                if (!vis[nextNode] && newDist < minDist[nextNode]) {
                    minDist[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }
        
        return totalCost;
    }
};
