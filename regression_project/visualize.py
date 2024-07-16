import sys
import matplotlib.pyplot as plt

def visualize(area, price, price_pred):
    plt.scatter(area, price, color='blue', label='Actual Prices')
    plt.plot(area, price_pred, color='red', label='Predicted Prices')

    # Añadir líneas punteadas verticales para mostrar el error de cada predicción
    errors = []
    for a, p, pp in zip(area, price, price_pred):
        plt.plot([a, a], [p, pp], 'k--', lw=1)
        error = p - pp
        errors.append(error)
        # print(f'Area: {a}, Actual Price: {p}, Predicted Price: {pp}, Error: {error}')

    plt.xlabel('Area (sqm)')
    plt.ylabel('Price ($)')
    plt.title('Linear Regression')
    plt.legend()
    plt.grid(True)  # Añadir la grilla
    plt.savefig('linear_regression_plot.png')  # Guarda la gráfica como un archivo PNG

if __name__ == "__main__":
    area = [float(x) for x in sys.argv[1].split(',')]
    price = [float(x) for x in sys.argv[2].split(',')]
    price_pred = [float(x) for x in sys.argv[3].split(',')]
    visualize(area, price, price_pred)
