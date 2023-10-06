#include <iostream>
#include <vector>

int main() {
    std::freopen("cbarn.in", "r", stdin);
    std::freopen("cbarn.out", "w", stdout);

    int total_cows{};
    std::cin >> total_cows;
//    int total_cows{5};

    std::vector<int> cows_pos{};
//    std::vector<int> cows_pos{ 4, 7, 8, 6, 4 };

    for (int iter=0; iter < total_cows; iter++) {
        int input_size{};
        std::cin >> input_size;

        cows_pos.push_back(input_size);
    }

    int max{};
    for (int start_ind=0; start_ind < total_cows; start_ind++) {
        int cur_max{};

        for (int next_ind=0; next_ind < total_cows; next_ind++) {
            int cur_ind = (start_ind + next_ind) % total_cows;

            cur_max += cows_pos[cur_ind] * next_ind;
        }

        if (cur_max < max || max == 0) {
            max = cur_max;
        }
    }

    std::cout << max;
}
