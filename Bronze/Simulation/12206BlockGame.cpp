#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::freopen("blocks.in", "r", stdin);
    std::freopen("blocks.out", "w", stdout);

    int num_cards{};
    std::cin >> num_cards;

//  Store the map containing the minimum amount of each letter required.
    std::map<char, int> min_letters;
    for (char first='a'; first <= 'z'; first++) {
        min_letters.insert({ first, 0 });
    }

    for (int iter=0; iter < num_cards; iter++) {
        std::string input_1{}, input_2{};
        std::cin >> input_1 >> input_2;

        std::vector<char> seen_chars{};

        for (char letter: input_1) {
            if (std::find(seen_chars.begin(), seen_chars.end(), letter) != seen_chars.end()) {
                continue;
            }

            int first_amt{ static_cast<int>(std::count(input_1.begin(), input_1.end(), letter)) },
                    second_amt{ static_cast<int>(std::count(input_2.begin(), input_2.end(), letter)) };

            min_letters[letter] += (first_amt > second_amt) ? first_amt: second_amt;
            seen_chars.push_back(letter);
        }

//      Check unseen letters in second word.
        for (char letter: input_2) {
            if (std::find(seen_chars.begin(), seen_chars.end(), letter) != seen_chars.end()) {
                continue;
            }

            int first_amt{ static_cast<int>(std::count(input_1.begin(), input_1.end(), letter)) },
                    second_amt{ static_cast<int>(std::count(input_2.begin(), input_2.end(), letter)) };

            if (first_amt == 0 && second_amt > 0) {
                min_letters[letter] += second_amt;

                seen_chars.push_back(letter);
            }
        }
    }

    for (auto const& [key, val] : min_letters) {
        std::cout << val << '\n';
    }

    return 0;
}
