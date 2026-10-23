#include <iostream>
void solve() {
  long long a, b;
  std::cin >> a >> b;

  int res = 0;

  while (a != b) {
    if (a > b) {
      a = a / 2;
    } else {
      b = b / 2;
    }
    res++;
  }
  std::cout << res << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int q;
  std::cin >> q;
  while (q--) {
    solve();
  }

  return 0;
}
