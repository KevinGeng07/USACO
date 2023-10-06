#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::freopen("citystate.in", "r", stdin);
    std::freopen("citystate.out", "w", stdout);

    int N;
    std::cin >> N;

    std::vector<std::pair<std::string, std::string>> city_state(N);
    std::map<std::string, int> citystate;
    for (int iter=0; iter < N; iter++) {
//       Convert from [CITY, STATE] to [CITYSTATE] (4 consecutive letters).
        std::string first;
        std::string second;

        std::cin >> first >> second;

        citystate[first.substr(0, 2) + second]++;
    }

    int special = 0;
    std::vector<std::string> seen_strings;
    for (auto comb: citystate) {
        std::string desired_str = comb.first.substr(2) + comb.first.substr(0, 2);

//        Third check to prevent same city/state from counting.
        if (comb.second > 0 && citystate[desired_str] > 0 && (comb.first != desired_str)) {
            special += comb.second * citystate[desired_str];
            seen_strings.push_back(comb.first);
        }
    }

    std::cout << special / 2;
}
