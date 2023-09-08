#include <iostream>
//#include <array>
#include <vector>
#include <algorithm>

int singles = 0;
int doubles = 0;

std::vector<char> seen_single;
std::vector<std::vector<char>> seen_double;

bool checkSingle(const std::string& string) {
    if (std::count(string.begin(), string.end(), string[0]) == 3) {
        return true;
    }
    return false;
}

std::pair<bool, std::vector<char>> checkDouble(const std::string& string) {
    std::vector<char> check_double{};

    for (char letter: string) {
        if (std::find(check_double.begin(), check_double.end(), letter) == check_double.end()) {
            check_double.push_back(letter);
        }
    }

    if (check_double.size() == 2) {
        std::sort(check_double.begin(), check_double.end());

        return {true, check_double};
    }
    return {false, check_double};
}

void checks(std::string string) {
    if (checkSingle(string) && std::find(seen_single.begin(), seen_single.end(), string[0]) == seen_single.end()) {
        singles++;
        seen_single.push_back(string[0]);
    }

    auto double_result = checkDouble(string);
    if (double_result.first && std::find(seen_double.begin(), seen_double.end(), double_result.second) == seen_double.end()) {
        doubles++;
        seen_double.push_back(double_result.second);
    }
}

int main() {
    std::freopen("tttt.in", "r", stdin);
    std::freopen("tttt.out", "w", stdout);

    std::vector<std::string> input_array(3);

    for (int iter=0; iter < 3; iter++) {
        std::string input_string{};
        std::cin >> input_string;

        input_array[iter] = input_string;
    }

    for (int iter=0; iter < 3; iter++) {
//      Check horizontally.
        std::string vertical;
        vertical += input_array[iter][0];
        vertical += input_array[iter][1];
        vertical += input_array[iter][2];

        checks(vertical);

//      Check vertically.
        std::string horizontal;
        horizontal += input_array[0][iter];
        horizontal += input_array[1][iter];
        horizontal += input_array[2][iter];

        checks(horizontal);
    }

    std::string left_diag;
    left_diag += input_array[0][0];
    left_diag += input_array[1][1];
    left_diag += input_array[2][2];

    checks(left_diag);

    std::string right_diag;
    right_diag += input_array[0][2];
    right_diag += input_array[1][1];
    right_diag += input_array[2][0];

    checks(right_diag);

    std::cout << singles << '\n' << doubles;
}
