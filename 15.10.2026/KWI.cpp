#include "iostream"
#include "vector"

using namespace std;

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

  vector<bool> odwiedzone(n + 1, false);
  vector<bool> mial_kwiaciarnie(n + 1, false);

  vector<int> q;
  q.reserve(n);

  q.push_back(1);
  odwiedzone[1] = true;
  mial_kwiaciarnie[1] = ma_kwiaciarnie[1];

  int poczatek = 0;
  while (poczatek < q.size()) {
    int u = q[poczatek++];

    for (int x : sasiedzi[u]) {
      if (!odwiedzone[x]) {
        odwiedzone[x] = true;
        mial_kwiaciarnie[x] = mial_kwiaciarnie[u] || ma_kwiaciarnie[x];
        q.push_back(x);
      }
    }
  }
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
