#include "house.h"
#include <iostream>
#include <cmath>

using namespace std;

void printHouses(const vector<House>& houses) {
    for (const auto& house : houses) {
        cout << "Area: " << house.area << " sqm, Price: $" << house.price << endl;
    }
}

void linearRegression(const vector<House>& houses, double& beta0, double& beta1) {
    int n = houses.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;

    for (const auto& house : houses) {
        sumX += house.area;
        sumY += house.price;
        sumXY += house.area * house.price;
        sumXX += house.area * house.area;
    }

    beta1 = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    beta0 = (sumY - beta1 * sumX) / n;
}

double calculateR2(const vector<House>& houses, double beta0, double beta1) {
    double sumY = 0, sumYY = 0, sumResiduals = 0;
    for (const auto& house : houses) {
        sumY += house.price;
    }
    double meanY = sumY / houses.size();
    for (const auto& house : houses) {
        sumYY += pow(house.price - meanY, 2);
        sumResiduals += pow(house.price - (beta0 + beta1 * house.area), 2);
    }
    return 1 - (sumResiduals / sumYY);
}

double calculateMSE(const vector<House>& houses, double beta0, double beta1) {
    double mse = 0;
    for (const auto& house : houses) {
        mse += pow(house.price - (beta0 + beta1 * house.area), 2);
    }
    return mse / houses.size();
}
