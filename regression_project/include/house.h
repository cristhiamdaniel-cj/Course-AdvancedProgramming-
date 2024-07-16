#ifndef HOUSE_H
#define HOUSE_H

#include <vector>

struct House {
    double area; // Área en metros cuadrados
    double price; // Precio en dólares
};

void printHouses(const std::vector<House>& houses);
void linearRegression(const std::vector<House>& houses, double& beta0, double& beta1);
double calculateR2(const std::vector<House>& houses, double beta0, double beta1);
double calculateMSE(const std::vector<House>& houses, double beta0, double beta1);

#endif // HOUSE_H
