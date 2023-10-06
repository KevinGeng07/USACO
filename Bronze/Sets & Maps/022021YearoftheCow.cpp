#include <iostream>
#include <map>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, int> zodiac_map = {{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4},
                                             {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8},
                                             {"Dog", 9}, {"Pig", 10}, {"Rat", 11} };

    std::map<std::string, std::vector<std::string>> animal_info;

    for (int iter=0; iter < N; iter++) {
        std::string name;
        std::vector<std::string> info(3);

        std::string arb;
        std::cin >> name >> arb >> arb >> info[0] >> info[1] >> arb >> info[2];

        animal_info[name] = info;
    }

    std::vector<std::string> name_order{ "Elsie" };
    std::cout << name_order[0];

    // "name_order" established to only include needed cows.
    while (name_order[name_order.size() - 1] != "Bessie") {
        name_order.push_back(animal_info[name_order[name_order.size() - 1]][2]);
//        std::cout << name_order[name_order.size() - 1] << '\n';
    }

    int age_diff = 0;
    std::string prev_zod = animal_info["Elsie"][1];
    std::string prev_sign = animal_info["Elsie"][0];

    for (int iter=1; iter < name_order.size() - 1; iter++) {

        std::string cur_zod = animal_info[name_order[iter]][1];
        std::string cur_sign = animal_info[name_order[iter]][0];


        if (prev_sign == "next") {
            if (zodiac_map[cur_zod] > zodiac_map[prev_zod]) {
                age_diff += zodiac_map[prev_zod] + (12 - zodiac_map[cur_zod]);
            } else {
                age_diff += zodiac_map[prev_zod] - zodiac_map[cur_zod];
            }

        } else if (prev_sign == "previous") {
            if (zodiac_map[cur_zod] > zodiac_map[prev_zod]) {
                age_diff -= zodiac_map[cur_zod] - zodiac_map[prev_zod];
            } else {
                age_diff -= zodiac_map[cur_zod] + (12 - zodiac_map[prev_zod]);
            }
        }

        prev_zod = cur_zod;
        prev_sign = cur_sign;

    }

    if (prev_sign == "next") {
        age_diff += zodiac_map[prev_zod];
    } else if (prev_sign == "previous") {
        age_diff -= 12 - zodiac_map[prev_zod];
    }

    std::cout << std::abs(age_diff);
}
