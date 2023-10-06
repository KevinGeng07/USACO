#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::freopen("notlast.in", "r", stdin);
    std::freopen("notlast.out", "w", stdout);

    int N;
    std::cin >> N;

    std::map<std::string, int> production_map;
    for (int iter=0; iter<N; iter++) {
        std::string name;
        int amount;
        std::cin >> name >> amount;

        production_map[name] += amount;
    }

    std::vector<int> milk_values;

    for (auto &info: production_map) {
        if (std::find(milk_values.begin(), milk_values.end(), info.second) == milk_values.end()) {
            milk_values.push_back(info.second);
        }
    }

//   Checks if 6 or less cows are present.
    if (production_map.size() < 7) {
        milk_values.push_back(0);
    }
    std::sort(milk_values.begin(), milk_values.end());

    if (milk_values.size() == 1) {
        std::cout << "Tie";
        return 1;
    } else {
        // Add check to see if cows missing.
        int desired_value = milk_values[1];

        std::vector<std::string> result_names;
        for (auto &info: production_map) {
            if (info.second == desired_value) {
                result_names.push_back(info.first);
            }
        }

        if (result_names.size() > 1) {
            std::cout << "Tie\n";
            return 1;
        } else {
            std::cout << result_names[0];
            return 1;
        }
    }

}
