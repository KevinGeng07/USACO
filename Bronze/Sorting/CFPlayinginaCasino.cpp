#include <iostream>
#include <vector>

int main() {
    int num_cases{};
    std::cin >> num_cases;

    for (int iter=0; iter < num_cases; iter++) {
        int n{}, m{};
        std::cin >> n >> m;

        std::vector<std::vector<int>> cards_info(n);
        for (int iter1=0; iter1 < n; iter1++) {
            std::vector<int> player_cards(m);

            for (int iter2=0; iter2 < m; iter2++) {
                std::cin >> player_cards[iter2];
            }

            cards_info[iter1] = player_cards;
        }

        long long maximum = 0;
        for (int index1=0; index1 < n; index1++) {

            for (int index2=index1+1; index2 < n; index2++) {

                for (int index3=0; index3 < m; index3++) {
                    maximum += std::abs(cards_info[index1][index3] - cards_info[index2][index3]);
                }
            }
        }

        std::cout << maximum << '\n';

    }
}
