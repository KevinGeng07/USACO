#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::freopen("milkorder.in", "r", stdin);
    std::freopen("milkorder.out", "w", stdout);

    int N, M, K;
    std::cin >> N >> M >> K;

    std::map<int, int> hierarchy;
    for (int iter=0; iter < M; iter++) {
        int value;
        std::cin >> value;
        hierarchy[value] = iter;
    }

    std::vector<int> sim(N);
    for (int iter=0; iter < K; iter++) {
        int value, position;
        std::cin >> value >> position;

        sim[position - 1] = value;
    }

    // Inspired by Greedy Algorithm- looking for first available case.
    int prev_hierarchy = 0;

    int prev_iter = 0;
    int prev_value = sim[0];
    for (int iter=1; iter<N; iter++) {
        if (sim[iter] != 0) {
            int cur_value = sim[iter];

            if (hierarchy[cur_value] && hierarchy[prev_value]) {
                if (hierarchy[cur_value] - hierarchy[prev_value] - 1 <= iter - prev_iter) {
                    std::cout << prev_value + 1;
                    return 1;
                }
            } else if (hierarchy[cur_value] && !hierarchy[prev_value]) {
                if (cur_value - prev_value - 1 == hierarchy[cur_value] - hierarchy[prev_hierarchy] - 1) {

                }
            }
        }
    }

    if (K == 1) {
        if (value_pos[0] == 1) {
            std::cout << 1;
        } else {
            std::cout << 2;
        }
        return 1;
    }

    std::sort(positions.begin(), positions.end(), std::greater<int>());



    for (int d_p: positions) {
        if (std::find(hierarchy.begin(), hierarchy.end(), value_pos[d_p]) != hierarchy.end()) {
            past_pos = d_p;
            num_fwd =
        }
    }
}
