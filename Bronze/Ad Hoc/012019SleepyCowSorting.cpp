#include <iostream>
#include <vector>

int main() {
    std::freopen("sleepy.in", "r", stdin);
    std::freopen("sleepy.out", "w", stdout);

    int N;
    std::cin >> N;

    std::vector<int> cur_order(N);

    std::cin >> cur_order[0];

//   Find the number of sorted elements from the back for timesteps. (ie. 1 2 3 4 == 4 sorted (0 TS), 1 2 4 3 == 1 sorted (3 TS))
    int back_order = 1;
    for (int iter=1; iter<N; iter++) {
        std::cin >> cur_order[iter];

        if (cur_order[iter] < cur_order[iter - 1]) {
            back_order = 1;
        } else {
            back_order++;
        }
    }
    std::cout << N - back_order;

}
