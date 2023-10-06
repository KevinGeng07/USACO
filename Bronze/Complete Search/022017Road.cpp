#include <iostream>
#include <map>

int main() {
    std::freopen("circlecross.in", "r", stdin);
    std::freopen("circlecross.out", "w", stdout);

    std::string input_string{};
    std::cin >> input_string;

    std::map<char, int> num_seen{};
    for (char start='A'; start <= 'Z'; start++) {
        num_seen[start] = 0;
    }

    int intersect = 0;
    for (int index_1=0; index_1 < 52; index_1++) {
        char letter_1 = input_string[index_1];
        num_seen[letter_1] += 2;

        std::map<char, int> temp{};

        for (int index_2=index_1+1; index_2 < 52; index_2++) {
            char letter_2 = input_string[index_2];

            if (letter_1 == letter_2) {
                break;
            }
            temp[letter_2] += 1;
        }

        for (const auto &key_value: temp) {
            if (num_seen[key_value.first] != 2 && key_value.second == 1) {
                intersect += 1;
            }
        }
    }

    std::cout << intersect;
}
