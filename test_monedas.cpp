#include <iostream>
#include <vector>
#include "monedas.h"

using namespace std;

int main() {
    // Ejemplo del PDF: Valores V={1, 4, 6} y cantidad M=8
    vector<int> m = {1, 4, 6};
    int d = 8;
    vector<int> s;

    monedas(m, d, s);

    cout << "Para devolver " << d << " u.v. con monedas de {";
    for (size_t i = 0; i < m.size(); i++) {
        cout << m[i] << (i < m.size() - 1 ? ", " : "");
    }
    cout << "} se necesitan:\n";

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] > 0) {
            cout << "- " << s[i] << " moneda(s) de " << m[i] << "\n";
        }
    }

    return 0;
}

