### Taller 01: Implementación de Regresión Lineal con C++

#### Objetivo:
Implementar una regresión lineal simple utilizando estructuras (`structs`), vectores y apuntadores en C++. El objetivo es comprender y aplicar conceptos fundamentales de C++ para resolver problemas de análisis de datos y utilizar herramientas de control de versiones para colaborar en equipo.

#### Estructura del Proyecto:
El proyecto debe seguir la siguiente estructura:

```
Taller01/
├── main.cpp
├── regresion_lineal.h
└── regresion_lineal.cpp
```

#### Archivos Proporcionados:
Se proporciona el archivo de cabecera `regresion_lineal.h` que contiene las declaraciones de las estructuras y funciones necesarias para la implementación de la regresión lineal.

```cpp
// regresion_lineal.h
#ifndef REGRESION_LINEAL_H
#define REGRESION_LINEAL_H

#include <vector>
using namespace std;

struct Datos {
    vector<double> x;
    vector<double> y;
    int n;
};

Datos* crearDatos(int n);
void liberarDatos(Datos* datos);
void calcularRegresion(Datos* datos, double& m, double& b, double alpha, int epochs);

#endif // REGRESION_LINEAL_H
```

#### Tareas a Realizar:
1. **Implementar `regresion_lineal.cpp`:**
    - Definir las funciones declaradas en `regresion_lineal.h`.
    - Implementar las funciones para crear y liberar la estructura `Datos`.
    - Implementar la función `calcularRegresion` que realice el cálculo de la regresión lineal, imprima la tabla en consola y guarde los errores cuadráticos medios en un archivo de texto.

2. **Implementar `main.cpp`:**
    - Utilizar las funciones definidas en `regresion_lineal.cpp` para crear datos, calcular la regresión lineal y mostrar los resultados.

#### Descripción de las Funciones:
- **`crearDatos(int n)`:**
    - Crea una estructura `Datos` y asigna memoria para `n` puntos de datos.
    - Retorna un puntero a la estructura `Datos`.

- **`liberarDatos(Datos* datos)`:**
    - Libera la memoria asignada a la estructura `Datos`.

- **`calcularRegresion(Datos* datos, double& m, double& b, double alpha, int epochs)`:**
    - Calcula los parámetros de la regresión lineal utilizando el algoritmo de gradiente descendente.
    - Imprime una tabla en consola que muestra la época actual, los valores `X`, `Y`, `Y_pred`, `Y - Y_pred` y `Error_Cuad`.
    - Guarda el error cuadrático medio (MSE) en un archivo de texto (`mse.txt`) en cada época.

#### Ejemplo de Salida Esperada en Consola:

```
Epoca: 98
X         Y         Y_pred    Y - Y_pred     Error_Cuad
1         3.01      1.8587    1.1513         1.32549
2         5.11      3.30689   1.80311        3.25119
3         7.01      4.75509   2.25491        5.08463
4         8.95      6.20328   2.74672        7.54448
5         10.89     7.65147   3.23853        10.4881
MSE: 5.67096

Epoca: 99
X         Y         Y_pred    Y - Y_pred     Error_Cuad
1         3.01      1.86868   1.14132        1.30261
2         5.11      3.32461   1.78539        3.1876
3         7.01      4.78055   2.22945        4.97046
4         8.95      6.23648   2.71352        7.36319
5         10.89     7.69241   3.19759        10.2246
MSE: 5.53877

Epoca: 100
X         Y         Y_pred    Y - Y_pred     Error_Cuad
1         3.01      1.87854   1.13146        1.28019
2         5.11      3.34212   1.76788        3.12538
3         7.01      4.80571   2.20429        4.85891
4         8.95      6.26929   2.68071        7.18622
5         10.89     7.73287   3.15713        9.96748
MSE: 5.40969

Pendiente (m): 1.46358
Intersección (b): 0.414963

Process finished with exit code 0
```

#### Ejemplo de Contenido del Archivo `mse.txt`:

```
7.70906
7.52894
7.35305
7.18129
7.01358
6.84981
6.68989
6.53373
6.38125
6.23235
6.08695
5.94498
5.80634
5.67096
5.53877
5.40969
```

#### Colaboración y Control de Versiones:
- Trabajen en grupos y utilicen Git para colaborar en el desarrollo del proyecto.
- Cada miembro del grupo debe contribuir a la implementación de las funciones.
- Suban el proyecto a un repositorio de GitHub y asegúrense de que todos los miembros del grupo tengan acceso y contribuyan al repositorio.

#### Rúbrica de Evaluación:

| Criterio                                  | Excepcional (4) | Satisfactorio (3) | Necesita Mejorar (2) | Insuficiente (1) | Puntos |
|-------------------------------------------|-----------------|-------------------|----------------------|------------------|--------|
| **Definición de Estructuras de Datos**    | Claramente definidas y adecuadas | Correctamente definidas | Presentan errores | No están definidas o son incorrectas | 10%    |
| **Uso de Vectores**                       | Correctamente implementados y eficientes | Correctamente implementados | Presentan errores | No se utilizan o son incorrectos | 10%    |
| **Implementación de Apuntadores**         | Correctamente implementados y eficientes | Correctamente implementados | Presentan errores | No se utilizan o son incorrectos | 10%    |
| **Función de Regresión Lineal**           | Correctamente implementada y funcional | Correctamente implementada | Presenta errores | No funciona o está incorrectamente implementada | 15%    |
| **Actualización de la Tabla en Consola**  | Se actualiza correctamente y muestra toda la información | Se actualiza correctamente | Presenta errores o falta información | No se actualiza o está incorrecta | 10%    |
| **Registro de MSE en Archivo de Texto**   | Se actualiza correctamente | Se actualiza correctamente | Presenta errores | No se actualiza o está incorrecta | 10%    |
| **Eficiencia del Código**                 | Altamente eficiente | Eficiente | Presenta problemas de eficiencia | Ineficiente | 10%    |
| **Documentación y Comentarios**           | Bien documentado y con comentarios claros | Documentación y comentarios presentes | Documentación insuficiente | Sin documentación o comentarios | 10%    |
| **Uso de Git y Control de Versiones**     | Uso eficiente de Git, commits claros | Uso correcto de Git | Problemas en el uso de Git | No usa Git o su uso es incorrecto | 10%    |
| **Colaboración en Equipo**                | Muy colaborativo, tareas distribuidas equitativamente | Colaboración correcta | Problemas de colaboración | No colabora adecuadamente | 5%     |

### Total: 100%

#### Evaluación Final:
- **90-100:** Excelente
- **80-89:** Muy Bueno
- **70-79:** Bueno
- **60-69:** Satisfactorio
- **Menos de 60:** Insatisfactorio

Utilicen esta guía para organizar su trabajo y asegurarse de cubrir todos los aspectos necesarios para completar el taller con éxito. ¡Buena suerte!