### Fundamentos del Gradiente Descendente

El **gradiente descendente** es un algoritmo de optimización iterativo utilizado para minimizar una función de coste. En el contexto de la regresión lineal, la función de coste es el Error Cuadrático Medio (MSE) entre los valores observados y los valores predichos.

#### Conceptos Clave

1. **Función de Coste:**
   La función de coste utilizada en la regresión lineal es el Error Cuadrático Medio (MSE):
   \[
   J(b, w) = \frac{1}{n} \sum_{i=1}^{n} \left( y_i - (b + w \cdot x_i) \right)^2
   \]
   Donde:
    - \( y_i \) es el valor observado.
    - \( b + w \cdot x_i \) es el valor predicho.
    - \( n \) es el número de puntos de datos.

2. **Gradientes:**
   Para minimizar \( J \), necesitamos calcular las derivadas parciales de \( J \) respecto a \( b \) y \( w \):

   \[
   \frac{\partial J}{\partial b} = -\frac{2}{n} \sum_{i=1}^{n} \left( y_i - (b + w \cdot x_i) \right)
   \]

   \[
   \frac{\partial J}{\partial w} = -\frac{2}{n} \sum_{i=1}^{n} \left( y_i - (b + w \cdot x_i) \right) \cdot x_i
   \]

3. **Actualización de Parámetros:**
   Los parámetros se actualizan en la dirección opuesta a los gradientes:
   \[
   b_{\text{nuevo}} = b_{\text{anterior}} + \alpha \frac{\partial J}{\partial b}
   \]

   \[
   w_{\text{nuevo}} = w_{\text{anterior}} + \alpha \frac{\partial J}{\partial w}
   \]

   Donde \( \alpha \) es la tasa de aprendizaje.

### Implementación en Excel con Macros

#### Estructura de la Hoja de Cálculo

La hoja de cálculo contiene las siguientes columnas y parámetros:

- **Columnas:**
    - **A:** `X` - Valores de la variable independiente.
    - **B:** `Y` - Valores observados de la variable dependiente.
    - **C:** `aux` - Diferencia entre `Y` y `Y_pred`.
    - **D:** `db` - Gradiente de \( b \).
    - **E:** `dw` - Gradiente de \( w \).
    - **F:** `Y_pred` - Valores predichos por el modelo.
    - **G:** `Y - Y_pred` - Residuo.
    - **H:** `error_cuad` - Error cuadrático de cada punto.

- **Parámetros:**
    - **H10:** \( b \)
    - **H11:** \( w \)
    - **H12:** Número de épocas (`epochs`)
    - **H13:** Tasa de aprendizaje (`alpha`)
    - **H16:** Número de la época actual
    - **H17:** Promedio de `db`
    - **H18:** Promedio de `dw`
    - **H19:** \( b \) actualizado
    - **H20:** \( w \) actualizado
    - **H21:** Error Cuadrático Medio (MSE)

#### Descripción del Proceso:

1. **Inicialización de Parámetros:**
   Se inicializan los valores de \( b \), \( w \), \(\alpha\) (tasa de aprendizaje) y el número de épocas (`epochs`). Estos parámetros controlan cómo el modelo ajusta los datos y durante cuántas iteraciones.

2. **Cálculo de Predicciones y Errores:**
   Para cada punto de datos \( (x_i, y_i) \), se calcula la predicción (\( y_{\text{pred}} = b + w \cdot x_i \)) y el error (\( y_i - y_{\text{pred}} \)). Se guarda el error cuadrático (\((y_i - y_{\text{pred}})^2\)) para calcular el MSE al final de cada iteración.

3. **Cálculo de Gradientes:**
   Se calculan las sumas de los gradientes de \( b \) y \( w \) para todos los puntos de datos. Estas sumas se dividen por el número de puntos de datos \( n \) para obtener los gradientes promedio.

4. **Actualización de Parámetros:**
   Los parámetros \( b \) y \( w \) se actualizan utilizando las fórmulas de gradiente descendente:
   \[
   b = b + \alpha \cdot \frac{1}{n} \sum_{i=1}^{n} \left( y_i - (b + w \cdot x_i) \right)
   \]
   \[
   w = w + \alpha \cdot \frac{1}{n} \sum_{i=1}^{n} \left( y_i - (b + w \cdot x_i) \right) \cdot x_i
   \]

5. **Registro y Visualización:**
    - Se actualizan los valores de \( b \) y \( w \) en la hoja de cálculo.
    - Se muestra la tabla en la consola con los valores de cada época, las predicciones, los errores y el MSE.
    - Se actualiza el gráfico en cada iteración para visualizar cómo la línea de regresión se ajusta a los datos.

6. **Pausa y Actualización de la Pantalla:**
   Se inserta una pausa de 0.25 segundos en cada iteración para observar visualmente cómo los parámetros se ajustan en tiempo real y cómo el MSE converge.

### Conclusión

El gradiente descendente es una herramienta poderosa en el aprendizaje automático y la optimización, utilizada para ajustar modelos de manera eficiente. La implementación en Excel, junto con las macros, proporciona una visualización clara y una comprensión práctica de cómo los parámetros se actualizan iterativamente para minimizar la función de coste. Este enfoque práctico ayuda a los estudiantes a entender tanto la teoría como la aplicación del gradiente descendente en problemas de regresión lineal.