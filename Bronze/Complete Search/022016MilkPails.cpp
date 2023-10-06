#include <iostream>
#include <cmath>

int main() {
    std::freopen("pails.in", "r", stdin);
    std::freopen("pails.out", "w", stdout);

    int s{}, m{}, l{};
    std::cin >> s >> m >> l;

    int highest = 0;
    for (int iter=0; iter <= static_cast<int>(l / s); iter++) {
        int amount = s * iter;

        int temp = static_cast<int>((l - amount) / m) * m;
        amount += temp;

        if (amount > highest && amount <= l) {
            highest = amount;
        }
    }

    std::cout << highest;
}
