
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

//#include "..."  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Cajas {
    int tiempo, indice;
};
bool operator<(Cajas const &a, Cajas const& b) {
    return (a.tiempo > b.tiempo) || (a.tiempo == b.tiempo && a.indice > b.indice);
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C;
    cin >> N >> C;//N cajas, C clientes esperando.
    if (N == 0)
        return false;
    priority_queue<Cajas> q;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < N; i++) {
        q.push({ 0, i + 1 });
    }
    int cajasLibres = q.size(), tiempo = 0;
    for (int i = 0; i < C; i++) {
        if (cajasLibres > 0) {//si hay cajas libres, metemos un cliente a una caja
            Cajas c = q.top(); q.pop();
            cin >> c.tiempo;
            q.push(c);
            cajasLibres--;
        }
        else {//si no hay caja libre, sacamos al más prioritario le incrementamos el tiempo para que al insertarlo se vaya al final de la cola (si se queda en la cola, aunque haya sido atendido)
            Cajas c = q.top(); q.pop();
            cin >> tiempo;
            c.tiempo += tiempo;
            q.push(c);
        }
        tiempo++;
    }

    // escribir la solución
    cout << q.top().indice << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
