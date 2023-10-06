#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int main() {
    std::freopen("blist.in", "r", stdin);
    std::freopen("blist.out", "w", stdout);

    int num_cows{};
    std::cin >> num_cows;
//    int num_cows{3};

    std::vector<std::array<int, 4>> cows_info(num_cows);
    for (int cow=0; cow < num_cows; cow++) {
        int start{}, end{}, buckets{};
        std::cin >> start >> end >> buckets;

        cows_info[cow] = {start, end, buckets, 0};
    }
//    std::vector<std::array<int, 4>> cows_info{ {4, 10, 1, 0}, {8, 13, 3, 0}, {2, 6, 2, 0} };


    std::sort(cows_info.begin(), cows_info.end());

    int total_buckets = 0;
    int free_buckets = 0;

    for (int index=0; index < num_cows; index++) {
//       Loop through previous cows to find if any milk buckets have been freed up.
        for (int index2=0; index2 < index; index2++) {
//           Checks if any cows have already finished before the current cow started.
            if (cows_info[index][0] >= cows_info[index2][1] && cows_info[index2][3] == 0) {
                free_buckets += cows_info[index2][2];
                cows_info[index2][3] = 1;
            }
        }

        if (free_buckets >= cows_info[index][2]) {
            free_buckets -= cows_info[index][2];
        } else {
            total_buckets += cows_info[index][2] - free_buckets;
            free_buckets = 0;
        }
    }

    std::cout << total_buckets;

}
