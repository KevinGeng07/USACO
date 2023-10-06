#include <iostream>
#include <vector>
#include <array>

int main() {
    std::freopen("speeding.in", "r", stdin);
    std::freopen("speeding.out", "w", stdout);

    int road_segments{}, bessie_segments{};
    std::cin >> road_segments >> bessie_segments;

    std::array<int, 100> segment_limit{};
    int total_recorded_miles = 0;
    for (int iter=0; iter < road_segments; iter++) {
        int miles{}, speed_limit{};
        std::cin >> miles >> speed_limit;


        for (int iter2=0; iter2 < miles; iter2++) {
            segment_limit[total_recorded_miles] = speed_limit;
            total_recorded_miles++;
        }
    }

    int max_over = 0;
    int bessie_miles = 0;
    for (int iter=0; iter < bessie_segments; iter++) {
        int miles{}, bessie_speed{};
        std::cin >> miles >> bessie_speed;

        for (int iter2=0; iter2 < miles; iter2++) {
            int diff = bessie_speed - segment_limit[bessie_miles];

            if (diff > max_over) {
                max_over = diff;
            }

            bessie_miles++;
        }
    }

    std::cout << max_over;
}

