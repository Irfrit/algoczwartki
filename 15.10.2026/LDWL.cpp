#include "iostream"
#include "vector"

using namespace std;

void dfs(int node, int rodzic, const vector<vector<int>> &neighbourgh,
         vector<bool> &visited) {
  visited[node] = true;
  for (int x : neighbourgh[node]) {
    if (!visited[x]) {
      dfs(x, node, neighbourgh, visited);
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  if (!(cin >> N >> M))
    return 0;

  vector<bool> visited(N + 1, false);

  vector<vector<int>> neighbourgh(N + 1);

  for (int i = 0; i < M; ++i) {
    int lsasiad, rsasiad;
    cin >> lsasiad >> rsasiad;
    neighbourgh[lsasiad].push_back(rsasiad);
    neighbourgh[rsasiad].push_back(lsasiad);
  }

  int result = 0;

  for (int i = 1; i <= N; ++i) {
    if (visited[i]) {
      continue;
    }
    ++result;
    dfs(i, 0, neighbourgh, visited);
  }

  cout << result;
}
