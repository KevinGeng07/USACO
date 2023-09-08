#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::freopen("paint.in", "r", stdin);
    std::freopen("paint.out", "w", stdout);

    int A{}, B{}, C{}, D{};
    std::cin >> A >> B >> C >> D;
//    int A{7}, B{10}, C{4}, D{8};

    int total = (B - A) + (D - C);
    int intersection = (std::min(B, D) - std::max(C, A));

    total -= std::max(intersection, 0);

    std::cout << total;
}
