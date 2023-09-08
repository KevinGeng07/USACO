#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::freopen("triangles.in", "r", stdin);
    std::freopen("triangles.out", "w", stdout);

    int num_points{};
    std::cin >> num_points;

    std::vector<std::pair<int, int>> points(num_points);
    for (int iter=0; iter < num_points; iter++) {
        std::cin >> points[iter].first >> points[iter].second;
    }

    long long max_area = 0;
    for (int index_1=0; index_1<num_points; index_1++) {
        for (int index_2=0; index_2<num_points; index_2++) {
            for (int index_3=0; index_3<num_points; index_3++) {
                std::pair<int, int> point_1 = points[index_1];
                std::pair<int, int> point_2 = points[index_2];
                std::pair<int, int> point_3 = points[index_3];

                if (point_1.second == point_2.second && point_2.first == point_3.first) {
                    long long temp = std::abs(point_1.first - point_2.first) * std::abs(point_2.second - point_3.second);

                    max_area = std::max(max_area, temp);
                }
            }
        }
    }

    std::cout << max_area;
}
