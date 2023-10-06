#include <iostream>
#include <vector>


int main() {
    std::freopen("measurement.in", "r", stdin);
    std::freopen("measurement.out", "w", stdout);

    int numlines{};
    std::cin >> numlines;
    std::vector<int> bessie_milk{};
    std::vector<int> elsie_milk{};
    std::vector<int> mildred_milk{};


    int cur_bessie, cur_elsie, cur_mildred;
    cur_bessie = cur_elsie = cur_mildred = 7;


    for (int iter=0; iter < 0; iter++) {
        int day{};
        std::string cow{};
        std::string change{};
        std::cin >> day >> cow >> change;

        int i;
        if (change[0] == '+') {
            change.erase(0, 1);
            i = std::stoi(change);
        } else {
            change.erase(0, 1);
            i = -1 * std::stoi(change);
        }

        if (cow == "Bessie") {
            for (int iter=0; iter < day - bessie_milk.size() - 1; iter++) {
                bessie_milk.push_back(cur_bessie);
            }

            cur_bessie += i;
        } else if (cow == "Elsie") {
            for (int iter=0; iter < day - elsie_milk.size() - 1; iter++) {
                elsie_milk.push_back(cur_elsie);
            }

            cur_elsie += i;
        } else if (cow == "Mildred") {
            for (int iter=0; iter < day - mildred_milk.size() - 1; iter++) {
                mildred_milk.push_back(cur_mildred);
            }

            cur_mildred += i;
        }

    }

    int b_amt = 100 - bessie_milk.size();
    int e_amt = 100 - elsie_milk.size();
    int m_amt = 100 - mildred_milk.size();

    for (int iter=0; iter < b_amt; iter++) {
        bessie_milk.push_back(cur_bessie);
    }

    for (int iter=0; iter < e_amt; iter++) {
        elsie_milk.push_back(cur_elsie);
    }

    for (int iter=0; iter < m_amt; iter++) {
        mildred_milk.push_back(cur_mildred);
    }

    std::cout << bessie_milk.size() << ' ' << elsie_milk.size() << ' ' << mildred_milk.size();

    for (int amt: bessie_milk) {
        std::cout << amt << '\n';
    }

}
