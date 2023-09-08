//#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_tests{};
    cin >> num_tests;

    vector<int> results(num_tests);

    for (int i = 0; i < num_tests; i++) {
        int num_elems{};
        cin >> num_elems;

        int total = 0;

        vector<int> test_case(num_elems);
        for (int j = 0; j < num_elems; j++) {
            cin >> test_case[j];

            total += test_case[j];
        }

        int modifications = -1;

        for (int factor = total; factor >= 0; factor--) {
            if (total % factor == 0) {
                int cur_mods = 0;

                int desired = total / factor;
                int cur = 0;
                bool broken = false;

                for (int item: test_case) {
                    cur += item;
                    cur_mods++;

                    if (cur == desired) {
                        cur = 0;
                    } else if (cur > desired) {
                        broken = true;
                        break;
                    }
                }
//
                if (!broken) {
                    if (cur_mods < modifications || modifications == -1) {
                        modifications = cur_mods;
                    }
                }
            }
//
//

        }

        cout << modifications << '\n';
    }
}
