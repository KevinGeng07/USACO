#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::freopen("cownomics.in", "r", stdin);
    std::freopen("cownomics.out", "w", stdout);

    int num_type{}, length{};
    std::cin >> num_type >> length;

    std::vector<std::string> spotty_cow(num_type);
    for (int iter=0; iter < num_type; iter++) {
        std::string input{};
        std::cin >> input;
        spotty_cow[iter] = input;
    }

    std::vector<std::string> plain_cow(num_type);
    for (int iter=0; iter < num_type; iter++) {
        std::string input{};
        std::cin >> input;
        plain_cow[iter] = input;
    }

    int total_positions = 0;
    for (int seq_index=0; seq_index < length; seq_index++) {
        std::vector<char> spotty_letters{};
        std::vector<char> plain_letters{};

        bool broken = false;

        for (int cow=0; cow < num_type; cow++) {
            char spotty_letter = spotty_cow[cow][seq_index];
            char plain_letter = plain_cow[cow][seq_index];

            spotty_letters.push_back(spotty_letter);
            plain_letters.push_back(plain_letter);

//           Check if letter already exists in opposite list.
            if (std::find(spotty_letters.begin(), spotty_letters.end(), plain_letter) != spotty_letters.end()) {
                broken = true;
                break;
            } else if (std::find(plain_letters.begin(), plain_letters.end(), spotty_letter) != plain_letters.end()) {
                broken = true;
                break;
            }
        }

        if (!broken) {
            total_positions++;
        }
    }

    std::cout << total_positions;
}
