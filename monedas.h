#ifndef MONEDAS_H
#define MONEDAS_H

#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

void monedas(const vector<int>& m, int d, vector<int>& s) {
    int n = m.size();
    // Inicializar el vector solución a 0
    s.assign(n, 0); 
    
    if (n == 0 || d <= 0) return;

    // Representación del valor "infinito"
    int inf_val = numeric_limits<int>::max();
    
    // Matriz de n filas por (d + 1) columnas
    vector<vector<int>> T(n, vector<int>(d + 1, inf_val));

    // Para la cantidad 0, se necesitan 0 monedas
    for (int i = 0; i < n; i++) {
        T[i][0] = 0;
    }

    // Cálculo de la primera fila
    for (int j = 1; j <= d; j++) {
        if (j >= m[0] && T[0][j - m[0]] != inf_val) {
            T[0][j] = 1 + T[0][j - m[0]];
        }
    }

    // Cálculo del resto de la tabla
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= d; j++) {
            if (j < m[i] || T[i][j - m[i]] == inf_val) {
                T[i][j] = T[i - 1][j];
            } else if (T[i - 1][j] != inf_val) {
                T[i][j] = min(T[i - 1][j], 1 + T[i][j - m[i]]);
            } else {
                T[i][j] = 1 + T[i][j - m[i]];
            }
        }
    }

    // Si el valor final sigue siendo infinito, no hay solución
    if (T[n - 1][d] == inf_val) return;

    // Recuperar la solución
    int i = n - 1;
    int j = d;
    while (j != 0) {
        if (i == 0 || T[i][j] != T[i - 1][j]) {
            s[i] = s[i] + 1;
            j = j - m[i];
        } else {
            i = i - 1;
        }
    }
}

#endif
