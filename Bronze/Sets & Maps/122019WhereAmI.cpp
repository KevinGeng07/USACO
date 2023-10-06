#include <iostream>
#include <algorithm>
#include <map>

int main() {
//    Simulation; loop through every possible value.
    std::freopen("whereami.in", "r", stdin);
    std::freopen("whereami.out", "w", stdout);

    int letters{};
    std::cin >> letters;

//    std::vector<char> input(letters);

    std::string input;

    for (int iter=0; iter < letters; iter++) {
        char letter;

        std::cin >> letter;
        input += letter;
    }

    for (int plate_len=1; plate_len < letters; plate_len++) {
        bool broken = false;

        std::map<std::string, int> items_map{};
        for (int start_ind=0; start_ind < letters - plate_len + 1; start_ind++) {
            std::string substring = input.substr(start_ind, plate_len);

            items_map[substring]++;

            if (items_map[substring] > 1) {
                broken = true;
                break;
            }
        }

        if (!broken) {
            std::cout << plate_len;
            break;
        }
    }

//    std::vector<char> min_string{ input[0] };
//
//    for (int added_letters=0; added_letters < letters; added_letters++) {
//        bool broken = false;
//
//        for (int second_start=min_string.size(); second_start < letters - min_string.size(); second_start++) {
//            for (int letter=0; letter < min_string.size(); letter++) {
//                if (min_string[letter] == )
//            }
//        }
//    }

}
