#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::freopen("mowing.in", "r", stdin);
    std::freopen("mowing.out", "w", stdout);

    int num_steps{};
    std::cin >> num_steps;

    std::vector<std::pair<int, int>> past_positions{};

    std::pair<int, int> cur_position{0, 0};

    int smallest_frame = 0;
    for (int iter=0; iter < num_steps; iter++) {
        char direction{};
        int steps{};
        std::cin >> direction >> steps;

        int multiple_first = 1;
        int multiple_second = 1;
        if (direction == 'S') {
            multiple_second *= -1;
        } else if (direction == 'W') {
            multiple_first *= -1;
        }

        if (direction == 'N' || direction == 'S') {
            multiple_first = 0;
        } else if (direction == 'E' || direction == 'W') {
            multiple_second = 0;
        }

        for (int iter=0; iter < steps; iter++) {
            cur_position.first += multiple_first;
            cur_position.second += multiple_second;

//          MUST ALSO ACCOUNT FOR PLOTS LANDED >2 TIMES. FIND ALL OCCURENCES AND GET MOST RECENT ONE.
            auto found_it = std::find(past_positions.begin(), past_positions.end(), cur_position);

            while (std::find(found_it + 1, past_positions.end(), cur_position) != past_positions.end()) {
                found_it = std::find(found_it + 1, past_positions.end(), cur_position);
            }

            if (found_it != past_positions.end()) {
                int difference = past_positions.size() - (found_it - past_positions.begin());

                if (difference < smallest_frame || smallest_frame == 0) {
                    smallest_frame = difference;
                }
            }

            past_positions.push_back(cur_position);
        }
    }

    if (smallest_frame == 0) {
        std::cout << -1;
    } else {
        std::cout << smallest_frame;
    }
}
