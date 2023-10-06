#include <iostream>
#include <bits/stdc++.h>
#include <tuple>
#include <map>

int main() {
//    int num_cows{};
//    std::cin >> num_cows;
    int num_cows{6};


//    std::vector<std::tuple<char, int, int>> cows_directions_vector{};
//    for (int iter=0; iter < num_cows; iter++) {
//        char direction{};
//        std::cin >> direction;
//        int start_X{}, start_Y{};
//        std::cin >> start_X >> start_Y;
//    }
    std::vector<std::tuple<char, int, int>> cows_directions_vector{ {'E', 3, 5}, {'N', 5, 3}, {'E', 4, 6}, {'E', 10, 4}, {'N', 11, 2}, {'N', 8, 1}};

    std::vector<int> stopped_cells(num_cows);

    for (int start_cow_iter=0; start_cow_iter < num_cows; start_cow_iter++) {
        std::tuple<char, int, int> cur_tuple = cows_directions_vector[start_cow_iter];

        int least_intersect = 1000000001;

        for (int remaining_cow_iter=0; remaining_cow_iter < num_cows; remaining_cow_iter++) {
            if (remaining_cow_iter == start_cow_iter) {
                continue;
            }

            std::tuple<char, int, int> temp_tuple = cows_directions_vector[remaining_cow_iter];

            char cur_direction = std::get<0>(cur_tuple);
            char desired_direction = std::get<0>(temp_tuple);

            if (cur_direction == 'N' && desired_direction == 'E') {
//               Calculate the time it takes to get to intersection.

                if (std::get<1>(temp_tuple) < std::get<1>(cur_tuple) && std::get<2>(temp_tuple) > std::get<2>(cur_tuple)) {
                    int intersect_time = std::abs(std::get<2>(cur_tuple) - std::get<2>(temp_tuple)) - std::abs(std::get<1>(cur_tuple) - std::get<1>(temp_tuple));
                    int north_dist = std::abs(std::get<2>(cur_tuple) - std::get<2>(temp_tuple));
                    int east_dist = std::abs(std::get<1>(cur_tuple) - std::get<1>(temp_tuple));

                    if (intersect_time > 0) {
                        if (std::abs(std::get<2>(cur_tuple) - std::get<2>(temp_tuple)) < least_intersect) {
                            least_intersect = std::abs(std::get<2>(cur_tuple) - std::get<2>(temp_tuple));
                        }
                    }
                }
            } else if (cur_direction == 'E' && desired_direction == 'N') {
                if (std::get<1>(temp_tuple) < std::get<1>(cur_tuple) && std::get<2>(temp_tuple) > std::get<2>(cur_tuple)) {
                    int intersect_time = std::abs(std::get<1>(cur_tuple) - std::get<1>(temp_tuple)) - std::abs(std::get<2>(cur_tuple) - std::get<2>(temp_tuple));

                    // Intersection doesn't exist if the supporting cow stopped before intersecting.
                    if (intersect_time > 0) {
                        if (std::abs(std::get<1>(cur_tuple) - std::get<1>(temp_tuple)) < least_intersect) {
                            least_intersect = std::abs(std::get<1>(cur_tuple) - std::get<1>(temp_tuple));
                        }
                    }
                }

            }
        }

        stopped_cells[start_cow_iter] = least_intersect;
    }

    for (int iter: stopped_cells) {
        if (iter == 1000000001) {
            std::cout << "Infinity" << '\n';
        } else {
            std::cout << iter << '\n';
        }
    }

}


// Extra storage:
/*  LN 55: && std::abs(std::get<1>(cur_tuple) - std::get<1>(temp_tuple)) < stopped_cells[remaining_cow_iter]
 *  LN 44: && std::abs(std::get<2>(cur_tuple) - std::get<2>(temp_tuple)) < stopped_cells[remaining_cow_iter]
 * */
