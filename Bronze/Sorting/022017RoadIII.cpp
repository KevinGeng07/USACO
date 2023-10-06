#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::freopen("cowqueue.in", "r", stdin);
    std::freopen("cowqueue.out", "w", stdout);

    int N{};
    std::cin >> N;

    std::vector<std::pair<int, int>> cow_info(N);

    for (int iter=0; iter < N; iter++) {
        std::cin >> cow_info[iter].first >> cow_info[iter].second;
    }

    std::sort(cow_info.begin(), cow_info.end());

    int cur_time = 0;
    for (std::pair<int, int> cur_pair: cow_info) {
        if (cur_pair.first > cur_time) {
            cur_time = cur_pair.first;
        }

        cur_time += cur_pair.second;
    }

    std::cout << cur_time;

}
