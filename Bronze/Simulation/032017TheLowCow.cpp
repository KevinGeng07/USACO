#include <iostream>
#include <cmath>

int main() {
    std::freopen("lostcow.in", "r", stdin);
    std::freopen("lostcow.out", "w", stdout);

    int x{}, y{};
    std::cin >> x >> y;


    int total = 0;

    int power = 0;
    int multiple = 1;

    while (true) {
        int new_pos = x + (multiple * std::pow(2, power));

        if ((new_pos <= y && x > y) || (new_pos >= y && y > x)) {
            total += std::abs(y - x);

            std::cout << total;
            return 0;
        }

        total += 2 * std::abs(new_pos - x);

        power++;
        multiple *= -1;
    }
}
