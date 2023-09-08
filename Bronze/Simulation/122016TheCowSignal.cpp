#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen("cowsignal.in", "r", stdin);
    std::freopen("cowsignal.out", "w", stdout);

    int rows{}, cols{}, multiple{};
    std::cin >> rows >> cols >> multiple;

    std::vector<std::string> input_map{};
    for (int iter=0; iter < rows; iter++) {
        std::string input{};
        std::cin >> input;

        std::string output{};
        for (char character: input) {
            for (int iter2=0; iter2 < multiple; iter2++) {
                output += character;
            }
        }

        for (int iter3=0; iter3 < multiple; iter3++) {
            std::cout << output << '\n';
        }

    }
}
