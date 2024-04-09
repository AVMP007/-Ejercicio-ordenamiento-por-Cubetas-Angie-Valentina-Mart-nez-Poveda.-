#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generarNumerosAleatorios(int *numeros, int minimo, int maximo, int cantidad) {
    srand(time(0));
    for (int i = 0; i < cantidad; i++) {
        numeros[i] = minimo + rand() % (maximo - minimo + 1);
    }
}

void ordenarPorCubetas(int *numeros, int n, int tamanoCubeta) {
    int minimo = numeros[0];
    int maximo = numeros[0];
    
    // Encontrar el mínimo y el máximo
    for (int i = 1; i < n; i++) {
        if (numeros[i] < minimo) {
            minimo = numeros[i];
        }
        else if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
    }

    // Crear un vector de cubetas
    int cubetas[tamanoCubeta][n / tamanoCubeta + 1] = {0};

    // Distribuir los números en las cubetas
    for (int i = 0; i < n; i++) {
        int indice = (numeros[i] - minimo) / ((double)(maximo - minimo) / tamanoCubeta);
        cubetas[indice][cubetas[indice][0] + 1] = numeros[i];
        cubetas[indice][0]++;
    }

    // Ordenar los números en cada cubeta (usando cualquier algoritmo de ordenamiento)
    for (int i = 0; i < tamanoCubeta; i++) {
        for (int j = 1; j <= cubetas[i][0]; j++) {
            for (int k = j + 1; k <= cubetas[i][0]; k++) {
                if (cubetas[i][j] > cubetas[i][k]) {
                    swap(cubetas[i][j], cubetas[i][k]);
                }
            }
        }
    }

    // Fusionar las cubetas ordenadas de nuevo en el arreglo original
    int indice = 0;
    for (int i = 0; i < tamanoCubeta; i++) {
        for (int j = 1; j <= cubetas[i][0]; j++) {
            numeros[indice++] = cubetas[i][j];
        }
    }
}

void imprimirNumeros(int *numeros, int n) {
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 10;
    int numeros[n];
    const int minimo = 0;
    const int maximo = 100;
    const int tamanoCubeta = 5;

    generarNumerosAleatorios(numeros, minimo, maximo, n);
    cout << "Números originales: ";
    imprimirNumeros(numeros, n);

    ordenarPorCubetas(numeros, n, tamanoCubeta);
    cout << "Números ordenados: ";
    imprimirNumeros(numeros, n);

    return 0;
}
