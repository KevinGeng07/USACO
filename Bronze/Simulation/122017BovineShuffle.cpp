#include <iostream>
#include <vector>
#include <map>

int main() {
    std::freopen("shuffle.in", "r", stdin);
    std::freopen("shuffle.out", "w", stdout);

    int num_input{};
    std::cin >> num_input;

    std::map<int, int> index_swap{};
    for (int iter=0; iter < num_input; iter++) {
        int new_index{};
        std::cin >> new_index;

        index_swap.insert({new_index - 1, iter});
    }

    std::vector<int> cur_pos(num_input);
    for (int iter=0; iter < num_input; iter++) {
        int input_num{};
        std::cin >> input_num;

        cur_pos[iter] = input_num;
    }

    for (int swap=0; swap < 3; swap++) {
        std::vector<int> temp_vector(num_input);

        for (int iter=0; iter < num_input; iter++) {
            temp_vector[index_swap[iter]] = cur_pos[iter];
        }

        cur_pos = temp_vector;
    }

    for (int number: cur_pos) {
        std::cout << number << '\n';
    }

}
