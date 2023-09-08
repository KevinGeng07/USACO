#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::freopen("balancing.in", "r", stdin);
    std::freopen("balancing.out", "w", stdout);

    int num_cows{}, B{};
    std::cin >> num_cows >> B;

    std::vector<std::pair<int, int>> cow_pos(num_cows);
    std::vector<int> x_coords{};
    std::vector<int> y_coords{};

    for (int iter=0; iter < num_cows; iter++) {
        std::cin >> cow_pos[iter].first >> cow_pos[iter].second;

        int temp_X = cow_pos[iter].first + 1;
        int temp_Y = cow_pos[iter].second + 1;

        x_coords.push_back(temp_X);
        y_coords.push_back(temp_Y);
    }

    std::sort(cow_pos.begin(), cow_pos.end());
    std::sort(x_coords.begin(), x_coords.end());

    int M = 10001;

    for (int a: x_coords) {
        for (int b: y_coords) {
            std::vector<int> quads(4);

            for (std::pair<int, int> cur_cow: cow_pos) {
                if (cur_cow.first > a && cur_cow.second > b) {
                    quads[0]++;
                } else if (cur_cow.first > a && cur_cow.second < b) {
                    quads[1]++;
                } else if (cur_cow.first < a && cur_cow.second < b) {
                    quads[2]++;
                } else if (cur_cow.first < a && cur_cow.second > b) {
                    quads[3]++;
                }
            }

            std::sort(quads.begin(), quads.end());
            if (quads[3] < M) {
                M = quads[3];
            }
        }
    }

    std::cout << M;
}
