#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::freopen("lifeguards.in", "r", stdin);
    std::freopen("lifeguards.out", "w", stdout);

    int lifeguards{};
    std::cin >> lifeguards;

    std::vector<std::pair<int, int>> lifeguard_info{};
    for (int iter=0; iter < lifeguards; iter++) {
        int start{}, end{};
        std::cin >> start >> end;

        lifeguard_info.push_back({start, end});
    }

    int max_time = 0;
    for (int index_1=0; index_1 < lifeguards; index_1++) {
//       "index_1" represents the fired lifeguard.
        std::vector<int> filled(1000);

        for (int index_2=0; index_2 < lifeguards; index_2++) {
            if (index_1 == index_2) {
                continue;
            }

            for (int start=lifeguard_info[index_2].first; start < lifeguard_info[index_2].second; start++) {
                filled[start] = 1;
            }
        }

        int total_ones = std::accumulate(filled.begin(), filled.end(), 0);
        if (total_ones > max_time) {
            max_time = total_ones;
        }
    }

    std::cout << max_time;
}
