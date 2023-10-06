#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen("shell.in", "r", stdin);
    std::freopen("shell.out", "w", stdout);

    int num_swaps{};
    std::cin >> num_swaps;


    std::vector<int> stone_pos(num_swaps);

//   Populate the list.
    for (int index=0; index < num_swaps; index++) {
        stone_pos[index] = index + 1;
    }

    std::vector<int> correct_guesses(num_swaps);

    for (int swap=0; swap < num_swaps; swap++) {
        int swap_1{}, swap_2{}, guess{};
        std::cin >> swap_1 >> swap_2 >> guess;

        int temp = stone_pos[swap_1 - 1];
        stone_pos[swap_1 - 1] = stone_pos[swap_2 - 1];
        stone_pos[swap_2 - 1] = temp;

        correct_guesses[stone_pos[guess - 1] - 1]++;
    }

    int max_correct = 0;
    for (int guess: correct_guesses) {
        if (guess > max_correct) {
            max_correct = guess;
        }
    }

    std::cout << max_correct;
}
