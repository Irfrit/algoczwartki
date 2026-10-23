#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>
struct City {
public:
  long long x;
  long long y;
  std::uint64_t mask = 0;
};

struct Line {
  long long a, b, c;
};

int main() {
  int N;
  std::cin >> N;

  std::vector<City> cities;
  cities.reserve(N);

  for (int i = 0; i < N; ++i) {
    long long x, y;
    std::cin >> x >> y;
    cities.push_back({x, y});
  }
  int M;
  std::cin >> M;
  std::vector<Line> lines;
  lines.reserve(M);
  for (int i = 0; i < M; ++i) {
    long long a, b, c;
    std::cin >> a >> b >> c;
    lines.push_back({a, b, c});
  }

  // mask compute

  for (City &city : cities) {
    for (int i = 0; i < M; ++i) {
      const auto &[a, b, c] = lines[i];
      if (a * city.x + b * city.y + c > 0) {
        city.mask += (std::uint64_t{1} << i);
      }
    }
  }

  // unique mask
  std::unordered_set<std::uint64_t> uniqueMasks;

  for (City &city : cities) {
    uniqueMasks.insert(city.mask);
  }

  // at most 1 + (M(m+1)/2) regions so not bad

  // find next cheapest edge

  std::vector<std::uint64_t> masks(uniqueMasks.begin(), uniqueMasks.end());

  int l = masks.size();

  std::vector<bool> in_tree(l, false);
  std::vector<int> best_group(l, std::numeric_limits<int>::max());

  best_group[0] = 0;
  int total_cost = 0;
  for (int i = 0; i < l; ++i) {
    int u = -1; // current best candidate

    for (int j = 0; j < l; ++j) {
      if (!in_tree[j] && (u == -1 || best_group[j] < best_group[u])) {
        u = j;
      }
    }

    in_tree[u] = true;
    total_cost += best_group[u];

    for (int k = 0; k < l; ++k) {
      if (!in_tree[k]) {
        int cost = __builtin_popcountll(masks[u] ^ masks[k]);

        best_group[k] = std::min(best_group[k], cost);
      }
    }
  }
  std::cout << total_cost;
}
