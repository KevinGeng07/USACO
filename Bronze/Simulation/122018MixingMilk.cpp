#include <iostream>
#include <array>

int main() {
    std::freopen("mixmilk.in", "r", stdin);
    std::freopen("mixmilk.out", "w", stdout);

    std::array<int, 3> total_capacity{};
    std::array<int, 3> current_amount{};
    std::cin >> total_capacity[0] >> current_amount[0] >> total_capacity[1] >> current_amount[1] >> total_capacity[2] >> current_amount[2];

    for (int iter=0; iter < 100; iter++) {
        int first_bucket{ iter % 3 };
        int second_bucket{ (iter + 1) % 3 };

        if (total_capacity[second_bucket] >= current_amount[first_bucket] + current_amount[second_bucket]) {
            current_amount[second_bucket] += current_amount[first_bucket];
            current_amount[first_bucket] = 0;
        } else {
            if (current_amount[first_bucket] >= total_capacity[second_bucket] - current_amount[second_bucket]) {
                current_amount[first_bucket] -= total_capacity[second_bucket] - current_amount[second_bucket];
                current_amount[second_bucket] = total_capacity[second_bucket];

            } else {
                current_amount[second_bucket] += current_amount[first_bucket];
                current_amount[first_bucket] = 0;

            }
        }
    }

    std::cout << current_amount[0] << '\n' << current_amount[1] << '\n' << current_amount[2] << '\n';

}
