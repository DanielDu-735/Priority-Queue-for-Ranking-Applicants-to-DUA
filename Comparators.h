#ifndef COMPARATORS_H
#define COMPARATORS_H
#include "StudentApplicant.h"
#include <queue>
#include <vector>
#include <iostream>
#include <string>

struct AnimalComparator {
    double height_weight;
    double weight_weight;
    double speed_weight;

    AnimalComparator(double h_w = 0.08, double w_w = -0.003, double s_w = 1.5)
        : height_weight(h_w), weight_weight(w_w), speed_weight(s_w) {}

    double calculate_score(const Applicant& app) const {
        return height_weight * app.height_cm
             + weight_weight * app.weight_kg
             + speed_weight  * app.speed_kmh;
    }

    bool operator()(const Applicant& a, const Applicant& b) const {
        return calculate_score(a) < calculate_score(b); // max heap
    }
};

void process_admissions(std::vector<Applicant>& applicants,
                        AnimalComparator comp,
                        int slots,
                        const std::string& method_name) {
    std::priority_queue<Applicant, std::vector<Applicant>, AnimalComparator> pq(comp);

    for (const auto& app : applicants)
        pq.push(app);

    std::cout << "\n========== " << method_name << " ==========\n";
    std::cout << "Weights used — Height: " << comp.height_weight
              << "  Weight: " << comp.weight_weight
              << "  Speed: "  << comp.speed_weight << "\n";
    std::cout << "Admitting top " << slots << " students:\n\n";

    int admitted = 0;
    while (!pq.empty() && admitted < slots) {
        Applicant top = pq.top();
        pq.pop();
        std::cout << ++admitted << ". ";
        top.display();
        std::cout << "   Score: " << comp.calculate_score(top) << "\n";
    }
}

std::vector<Applicant> create_animal_pool() {
    return {
        {"Duke D.0236",   "Dog",      66.3,  6.4,    36.4},
        {"Binx C.0347",   "Cat",      30.2,  4.5,    36.8},
        {"R.0622",        "Rabbit",   30.2,  4.1,    53.9},
        {"Cosmo C.0328",  "Cat",      37.8,  3.5,    35.6},
        {"Oliver C.0437", "Cat",      43.3,  6.4,    45.4},
        {"Nutmeg R.0636", "Rabbit",   34.0,  3.7,    23.8},
        {"Sadie D.0087",  "Dog",      59.1,  14.8,   39.9},
        {"Dolly C.0722",  "Cow",      136.3, 426.3,  9.5 },
        {"Dotty P.0905",  "Pig",      81.3,  53.3,   9.8 },
        {"Rocky D.0083",  "Dog",      64.9,  11.7,   42.0},
        {"Rasher P.0798", "Pig",      79.1,  70.5,   8.4 },
        {"Storm C.0355",  "Cat",      34.9,  4.9,    48.3},
        {"Stella D.0047", "Dog",      54.4,  18.9,   41.8},
        {"Queenie C.0658","Cow",      148.9, 460.5,  10.0},
        {"Peanut E.0970", "Elephant", 242.8, 3631.5, 5.5 },
        {"Clover R.0624", "Rabbit",   38.1,  1.1,    45.0},
        {"Atlas E.0973",  "Elephant", 258.2, 4893.6, 8.7 },
        {"Jasper C.0442", "Cat",      42.0,  4.7,    43.9},
        {"R.0497",        "Rabbit",   32.2,  3.0,    50.6},
        {"Binky R.0566",  "Rabbit",   35.6,  2.1,    50.7},
    };
}
#endif
