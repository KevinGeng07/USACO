#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::freopen("gymnastics.in", "r", stdin);
    std::freopen("gymnastics.out", "w", stdout);

    int matches{}, num_cows{};
    std::cin >> matches >> num_cows;
    std::vector<std::map<int, int>> matches_info(matches);
    for (int match=0; match < matches; match++) {
        std::map<int, int> info{};
        for (int cow=0; cow < num_cows; cow++) {
            int temp{};
            std::cin >> temp;
            info.insert({temp - 1, cow});
        }

        matches_info[match] = info;
    }

    int consistent_pairs = 0;
    for (int number_1=0; number_1 < num_cows; number_1++) {
        for (int number_2=number_1 + 1; number_2 < num_cows; number_2++) {
            std::vector<bool> vector_values(matches);

            for (int match=0; match < matches; match++) {
                vector_values[match] = matches_info[match][number_1] < matches_info[match][number_2];
            }

            if (std::count(vector_values.begin(), vector_values.end(), true) == matches || std::count(vector_values.begin(), vector_values.end(), false) == matches) {
                consistent_pairs++;
            }
        }
    }

    std::cout << consistent_pairs;
}
