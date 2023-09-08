#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num_cows{};
    std::cin >> num_cows;

    std::vector<std::pair<int, char>> info(num_cows);
    for (int iter=0; iter<num_cows; iter++) {
        std::cin >> info[iter].second >> info[iter].first;
    }
    std::sort(info.begin(), info.end());

    int least_liars = 1001;
    for (int start_index=0; start_index < num_cows; start_index++) {

        int temp_liars = 0;
        for (int other_index=0; other_index < num_cows; other_index++) {
            if (other_index < start_index && info[other_index].second == 'L') {
                temp_liars++;
            } else if (other_index > start_index && info[other_index].second == 'G') {
                temp_liars++;
            }
        }

        if (temp_liars < least_liars) {
            least_liars = temp_liars;
        }
    }

    std::cout << least_liars;
}
