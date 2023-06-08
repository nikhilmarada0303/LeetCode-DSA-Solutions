class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n = grid.size();
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
    distance[0][0] = 1;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == n - 1)
            return distance[x][y];

        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && distance[nx][ny] == INT_MAX) {
                q.push({nx, ny});
                distance[nx][ny] = distance[x][y] + 1;
            }
        }
    }

    return -1;

    }
};