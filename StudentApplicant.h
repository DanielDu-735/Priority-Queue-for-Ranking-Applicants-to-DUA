#ifndef STUDENTAPPLICANT_H
#define STUDENTAPPLICANT_H
#include <iostream>
#include <string>

struct Applicant {
    std::string name;
    std::string species;
    double height_cm;
    double weight_kg;
    double speed_kmh;

    Applicant(std::string n, std::string sp, double h, double w, double s)
        : name(n), species(sp), height_cm(h), weight_kg(w), speed_kmh(s) {}

    void display() const {
        std::cout << "Name: " << name
                  << " | Species: " << species
                  << " | Height: " << height_cm << " cm"
                  << " | Weight: " << weight_kg << " kg"
                  << " | Speed: " << speed_kmh << " km/h\n";
    }
};
#endif
