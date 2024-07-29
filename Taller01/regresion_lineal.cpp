#include "regresion_lineal.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Datos* crearDatos(int n) {
    Datos* datos = new Datos;
    datos->x.resize(n);
    datos->y.resize(n);
    datos->n = n;
    return datos;
}

void liberarDatos(Datos* datos) {
    delete datos;
}

void calcularRegresion(Datos* datos, double& m, double& b, double alpha, int epochs) {
    ofstream mseFile("mse.txt");
    if (!mseFile.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir el MSE." << endl;
        return;
    }

    double db, dw, y_pred, error, mse;
    for (int epoch = 0; epoch < epochs; ++epoch) {
        db = 0;
        dw = 0;
        mse = 0;
        for (int i = 0; i < datos->n; ++i) {
            y_pred = b + m * datos->x[i];
            error = datos->y[i] - y_pred;
            db += error;
            dw += error * datos->x[i];
            mse += error * error;
        }
        mse /= datos->n;

        b += alpha * db / datos->n;
        m += alpha * dw / datos->n;

        // Imprimir la tabla en la consola
        cout << "Epoca: " << epoch + 1 << "\n";
        cout << left << setw(10) << "X" << setw(10) << "Y" << setw(10) << "Y_pred" << setw(15) << "Y - Y_pred" << setw(15) << "Error_Cuad" << endl;
        for (int i = 0; i < datos->n; ++i) {
            y_pred = b + m * datos->x[i];
            error = datos->y[i] - y_pred;
            cout << setw(10) << datos->x[i] << setw(10) << datos->y[i] << setw(10) << y_pred << setw(15) << error << setw(15) << error * error << endl;
        }
        cout << "MSE: " << mse << "\n" << endl;

        // Escribir el MSE en el archivo
        mseFile << mse << endl;
    }

    mseFile.close();
}
