#include <iostream>
#include <map>
#include <vector>

int main() {
    std::freopen("art.in", "r", stdin);
    std::freopen("art.out", "w", stdout);

    int N;
    std::cin >> N;
//    int N{5};

    //  Store the min. coordinates for full rectangle (obtained from initially seen values).
    std::map<char, std::vector<std::vector<int>>> rectangles;

    std::vector<std::string> painting(N);
    for (int iter=0; iter<N; iter++) {
        int input;
        std::cin >> input;
        painting[iter] = std::to_string(input);
    }

    for (int num=1; num<10; num++) {
        int start_row = -1;
        int start_col = -1;

        int end_row = -1;
        int end_col = -1;

        for (int row=0; row<N; row++) {
            for (int col=0; col<N; col++) {
                if (painting[row][col] == static_cast<char>(std::to_string(num)[0])) {
                    if (start_row == -1 || row < start_row) {
                        start_row = row;
                    }
                    if (start_col == -1 || col < start_col) {
                        start_col = col;
                    }
                    if (end_row == -1 || row > end_row) {
                        end_row = row;
                    }
                    if (end_col == -1 || col > end_col) {
                        end_col = col;
                    }
                }
            }
        }

        // Skip over if the number doesn't exist.
        // Only possible if no values are seen (singular coordinate will be compared against all).
        if (start_row == -1) {
            continue;
        } else {
            rectangles[static_cast<char>(std::to_string(num)[0])] = {{start_row, start_col}, {end_row, end_col}};
        }
    }

    // See if any colors overlap the target rectangle ("key"), if it does, then it cannot be one of the first painted.
    std::map<char, bool> overlap_map;
    for (const auto& [key, value]: rectangles) {
        for (int row=value[0][0]; row<=value[1][0]; row++) {
            for (int col=value[0][1]; col<=value[1][1]; col++) {
                if (painting[row][col] != key) {
                    overlap_map[painting[row][col]] = true;
                }
            }
        }
    }

    int total = 0;
    // All rectangles that don't overlap others (boolean == false) could have been painted first.
    for (const auto& [key, value]: rectangles) {
        if (!overlap_map[key]) {
            total++;
        }
    }
    std::cout << total;
    return 1;
}
