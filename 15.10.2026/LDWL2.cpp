#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  std::cout << N - M;
}
