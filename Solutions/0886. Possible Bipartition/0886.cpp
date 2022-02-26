enum Color { WHITE, RED, GREEN };

class Solution {
 public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(N + 1);
    vector<Color> colors(N + 1, WHITE);

    for (const auto& d : dislikes) {
      const int u = d[0];
      const int v = d[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // reduce to 785. Is Graph Bipartite?
    for (int i = 1; i <= N; ++i)
      if (colors[i] == WHITE && !isValidColor(graph, i, colors, RED))
        return false;

    return true;
  }

 private:
  bool isValidColor(const vector<vector<int>>& graph, int u,
                    vector<Color>& colors, Color color) {
    // the painted color should be same as the `color`
    if (colors[u] != WHITE)
      return colors[u] == color;

    colors[u] = color;  // always paint w/ `color`

    // all children should have valid colors
    for (const int v : graph[u])
      if (!isValidColor(graph, v, colors, color == RED ? GREEN : RED))
        return false;

    return true;
  }
};
