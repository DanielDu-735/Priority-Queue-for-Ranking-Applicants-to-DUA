#include <iostream>
#include <vector>
#include "StudentApplicant.h"
#include "Comparators.h"

int main() {
    std::vector<Applicant> applicants = create_animal_pool();
    int slots = 5;

    std::cout << "=== Du's University of Animals — Admissions Simulation ===\n";
    std::cout << "Total applicants: " << applicants.size() << "\n";
    std::cout << "Available slots: " << slots << "\n";

    // Default weights: 0.08 x Height - 0.003 x Weight + 1.5 x Speed
    process_admissions(applicants, AnimalComparator(), slots, "Default Weights");

    // Students can try their own weights by passing arguments:
    // AnimalComparator(height_weight, weight_weight, speed_weight)
    process_admissions(applicants, AnimalComparator(0.5, -0.001, 1.0), slots, "Height-Focused");
    process_admissions(applicants, AnimalComparator(0.01, -0.001, 3.0), slots, "Speed-Focused");

    std::cout << "\n=== Questions to Consider ===\n";
    std::cout << "1. Which weighting seems most fair? Why?\n";
    std::cout << "2. Which species benefit or suffer depending on the weights chosen?\n";
    std::cout << "3. Can any scoring formula be truly neutral?\n";
    std::cout << "4. What weights would YOU choose and why?\n";

    return 0;
}
