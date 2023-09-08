#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::freopen("guess.in", "r", stdin);
    std::freopen("guess.out", "w", stdout);
    
    int num_cows{};
    std::cin >> num_cows;
    
    std::vector<std::pair<std::string, std::vector<std::string>>> cow_characteristics(num_cows);
    for (int iter=0; iter < num_cows; iter++) {
        std::string cow_name{};
        std::cin >> cow_name;

        int iters{};
        std::cin >> iters;

        std::vector<std::string> word_list(iters);
        for (int iter=0; iter < iters; iter++) {
            std::cin >> word_list[iter];
        }

        cow_characteristics[iter] = { cow_name, word_list };
    }

    int highest_max = 0;
//   Find which animals have the most words in common, then add 1 to it.
    for (int animal_1=0; animal_1 < num_cows; animal_1++) {
        std::vector<std::string> animal_words = cow_characteristics[animal_1].second;

        int cur_max = 0;

        for (int animal_2=animal_1 +1; animal_2 < num_cows; animal_2++) {
            int temp_similar = 0;
            std::vector<std::string> check_words = cow_characteristics[animal_2].second;

            for (std::string word: animal_words) {
                if (std::find(check_words.begin(), check_words.end(), word) != check_words.end()) {
                    temp_similar++;
                }
            }

            if (temp_similar > cur_max) {
                cur_max = temp_similar;
            }
        }

        if (cur_max > highest_max) {
            highest_max = cur_max;
        }
    }

    std::cout << highest_max + 1;
}
