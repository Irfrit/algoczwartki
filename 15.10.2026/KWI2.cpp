#include "iostream"
#include "vector"

using namespace std;

void dfs(int node, int rodzic, bool mial_kwiat,
         const vector<vector<int>> &sasiedzi,
         const vector<bool> &ma_kwiaciarnie, vector<bool> &mial_kwiaciarnie) {
  mial_kwiat = mial_kwiat || ma_kwiaciarnie[node];
  mial_kwiaciarnie[node] = mial_kwiat;

  for (int x : sasiedzi[node]) {
    if (x != rodzic) {
      dfs(x, node, mial_kwiat, sasiedzi, ma_kwiaciarnie, mial_kwiaciarnie);
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  if (!(cin >> n >> k))
    return 0;

  vector<bool> ma_kwiaciarnie(n + 1, false);

  for (int i = 0; i < k; ++i) {
    int s;
    cin >> s;
    ma_kwiaciarnie[s] = true;
  }

  vector<vector<int>> sasiedzi(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    int lsasiad, rsasiad;
    cin >> lsasiad >> rsasiad;
    sasiedzi[lsasiad].push_back(rsasiad);
    sasiedzi[rsasiad].push_back(lsasiad);
  }

  vector<bool> mial_kwiaciarnie(n + 1, false);

  dfs(1, 0, false, sasiedzi, ma_kwiaciarnie, mial_kwiaciarnie);
  bool first = true; // brak spacji na poczaktku
  for (int i = 1; i <= n; i++) {
    if (mial_kwiaciarnie[i]) {
      if (!first)
        cout << ' ';
      cout << i;
      first = false;
    }
  }
  return 0;
}
