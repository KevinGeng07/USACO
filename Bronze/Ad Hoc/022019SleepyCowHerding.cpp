#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::freopen("herding.in", "r", stdin);
    std::freopen("herding.out", "w", stdout);

    std::vector<int> BEM(3);
    for (int iter=0; iter<3; iter++) {
        std::cin >> BEM[iter];
    }
    std::sort(BEM.begin(), BEM.end());
    std::vector<int> first_second{ BEM[1]-BEM[0], BEM[2]-BEM[1] };
    std::sort(first_second.begin(), first_second.end());

    if (BEM[2] - BEM[0] == 2) {
        std::cout << 0;
    } else if (first_second[0] == 2) {
        std::cout << 1;
    } else {
        std::cout << 2;
    }

    // The max number of switches is the greatest difference - 1.
    std::cout << '\n' << first_second[1] - 1;


}