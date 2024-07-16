#include <iostream>
#include <vector>
#include <sstream>
#include "house.h"
#include <cstdlib>

using namespace std;

int main() {
    vector<House> houses = {
        {1500, 300000},
        {1700, 340000},
        {2000, 360000},
        {2300, 380000},
        {2500, 400000}
    };

    // Imprimir datos de las casas
    cout << "Datos de las casas:" << endl;
    printHouses(houses);

    // Calcular coeficientes de regresión lineal
    double beta0, beta1;
    linearRegression(houses, beta0, beta1);
    cout << "\nCoeficientes de regresión lineal:" << endl;
    cout << "beta0: " << beta0 << endl;
    cout << "beta1: " << beta1 << endl;

    // Evaluar el modelo
    double r2 = calculateR2(houses, beta0, beta1);
    double mse = calculateMSE(houses, beta0, beta1);
    cout << "\nEvaluación del modelo:" << endl;
    cout << "Coeficiente de determinación (R^2): " << r2 << endl;
    cout << "Error cuadrático medio (MSE): " << mse << endl;

    // Datos para visualización
    vector<double> area, price, price_pred, errors;
    for (const auto& house : houses) {
        area.push_back(house.area);
        price.push_back(house.price);
        double predicted = beta0 + beta1 * house.area;
        price_pred.push_back(predicted);
        errors.push_back(house.price - predicted);
    }

    // Convertir datos a strings
    ostringstream area_stream, price_stream, price_pred_stream, errors_stream;
    for (size_t i = 0; i < area.size(); ++i) {
        if (i != 0) {
            area_stream << ",";
            price_stream << ",";
            price_pred_stream << ",";
            errors_stream << ",";
        }
        area_stream << area[i];
        price_stream << price[i];
        price_pred_stream << price_pred[i];
        errors_stream << errors[i];
    }

    // Imprimir errores en la consola
    cout << "\nErrores de predicción:" << endl;
    for (size_t i = 0; i < errors.size(); ++i) {
        cout << "Area: " << area[i] << ", Error: " << errors[i] << endl;
    }

    // Llamar al script shell para activar el entorno virtual y ejecutar el script Python
    string command = "/home/cristhiamdaniel/CLionProjects/ProgramacionAvanzada/regression_project/run_visualize.sh " + area_stream.str() + " " + price_stream.str() + " " + price_pred_stream.str();
    system(command.c_str());

    // Abrir la imagen generada
    system("xdg-open linear_regression_plot.png");

    return 0;
}
