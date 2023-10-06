#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::freopen("angry.in", "r", stdin);
    std::freopen("angry.out", "w", stdout);

    int num_bales{};
    std::cin >> num_bales;

    std::vector<int> positions(num_bales);
    for (int iter=0; iter < num_bales; iter++) {
        std::cin >> positions[iter];

//    int num_bales{6};
//
//    std::vector<int> positions{8, 5, 6, 13, 3, 4};

    std::sort(positions.begin(), positions.end());

    int max_cows = 0;

    for (int iter=0; iter < num_bales; iter++) {

        int radius = 1;
        int num_cows = 1;
        int last_pos = iter;
        int last_neg = iter;

        bool neg_broken = false;
        bool pos_broken = false;

        while (true) {
            int cur_pos = last_pos;

            int cur_neg = last_neg;

            for (int iter1=0; iter1 < radius; iter1++) {
                if (last_pos + iter1 + 1 == positions.size()) {
                    pos_broken = true;
                }

                if (last_neg - iter1 - 1 == -1) {
                    neg_broken = true;
                }


                int pos_1 = positions[last_pos + iter1 + 1];
                int pos_2 = positions[last_pos];

                if (!pos_broken && positions[last_pos + iter1 + 1] - positions[last_pos] <= radius) {

                    num_cows++;
                    cur_pos++;

                } else if (iter1 == 0) {
                    pos_broken = true;
                }

                if (!neg_broken && positions[last_neg] - positions[last_neg - iter1 - 1] <= radius) {

                    num_cows++;
                    cur_neg--;

                } else if (iter1 == 0) {
                    neg_broken = true;
                }
            }

            if (pos_broken && neg_broken) {
                if (num_cows > max_cows) {
                    max_cows = num_cows;
                }

                break;
            }
            radius++;
            last_pos = cur_pos;
            last_neg = cur_neg;
        }

//        int radius = 1;
//        int num_cows = 1;
//        int last_pos = iter;
//
//        while (true) {
//            bool broken = false;
//            int cur_pos = last_pos;
//
//            for (int iter1=0; iter1 < radius; iter1++) {
//                if (last_pos - iter1 - 1 == -1) {
//                    broken = true;
//                    break;
//                }
//
//                int pos_1 = positions[last_pos - iter1 - 1];
//                int pos_2 = positions[last_pos];
//
//                if (!broken &&  positions[last_pos] - positions[last_pos + iter1 + 1] <= radius) {
//                    num_cows++;
//                    cur_pos--;
//
//                } else if (iter1 == 0) {
//                    broken = true;
//                    break;
//                }
//            }
//
//            if (broken) {
//                std::cout << num_cows << '\n';
//                break;
//            }
//            radius++;
//            last_pos = cur_pos;
//        }


//        int neg_dir = 0;
//        int prev_neg = iter;
//        for (int iter2=iter; iter2 >= 0; iter2--) {
//            int cur_pos = prev_neg;
//
//            for (int iter2_1=1; iter2_1 < pos_dir + 1; iter2_1++) {
//                if (std::abs(positions[iter2 + iter2_1] - positions[cur_pos]) <= pos_dir + 1) {
//                    neg_dir++;
//                    prev_neg = iter2_1;
//                } else {
//                    break;
//                }
//            }
//        }

//        int neg_dir = 0;
//        int prev_neg = launched_posit;
//        for (int iter2=iter; iter2 >= 0; iter2--) {
//            if (std::abs(positions[iter2] - prev_neg) <= pos_dir + 1) {
//                neg_dir++;
//                prev_neg = positions[iter2];
//            } else {
//                break;
//            }
//        }
//
//        if (pos_dir + neg_dir > max_bales) {
//            max_bales = pos_dir + neg_dir;;
//        }
    }
//    std::cout << max_bales;

    std::cout << max_cows;

}
