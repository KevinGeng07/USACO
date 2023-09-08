#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::freopen(   "censor.in", "r", stdin);
    std::freopen("censor.out", "w", stdout);

    std::string input_string{};
    std::cin >> input_string;

    std::string censor_string{};
    std::cin >> censor_string;
//    std::string input_string{ "whatthemomooofun" };
//    std::string censor_string{ "moo" };

    int size_input = input_string.size();
    int size_censor = censor_string.size();

    std::string result;
    for (int iter=0; iter < size_input; iter++) {
        result += input_string[iter];

        if (result.length() >= size_censor && result.substr(result.length() - size_censor) == censor_string) {
            result.erase(result.length() - size_censor, size_censor);
        }
    }
    std::cout << result;

//    int cur_index = 0;
//    while (true) {
//        char cur_letter = input_string[cur_index];
//
//        if (cur_letter == censor_string[0]) {
//            bool broken = false;
//
//            for (int index=1; index < censor_string.size(); index++) {
//                if (censor_string[index] != input_string[cur_index + index]) {
//                    cur_index += index;
//
//                    broken = true;
//                    break;
//                }
//            }
//
//            if (!broken) {
//                input_string.erase(cur_index, censor_string.size());
//                cur_index = 0;
//            }
//
//            continue;
//        }
//
//        if (cur_index == input_string.size() - 1) {
//            std::cout << input_string;
//            return 0;
//        }
//        cur_index++;
//    }
}

