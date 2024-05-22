#include <iostream>
#include <algorithm>
#include <string>

// Definimos el struct de Actividad
struct Actividad {
    std::string banda;
    int inicio;
    int fin;
};

// Comparador para ordenar las actividades por hora de finalización
bool comparador(const Actividad &a1, const Actividad &a2) {
    return a1.fin < a2.fin;
}

// Función para encontrar el conjunto máximo de actividades que no se solapan
void seleccionarActividades(Actividad actividades[], int n) {
    // Ordenamos las actividades por hora de finalización (https://www.geeksforgeeks.org/sort-c-stl/)
    std::sort(actividades, actividades + n, comparador);

    std::cout << "Actividades seleccionadas:\n";

    // La primera actividad siempre se selecciona
    int tiempoFinal = actividades[0].fin;
    std::cout << "Banda: " << actividades[0].banda << ", Inicio: " << actividades[0].inicio << ", Fin: " << actividades[0].fin << "\n";

    // Iteramos sobre las actividades ordenadas
    for (int i = 1; i < n; i++) {
        // Si la actividad no se solapa, la seleccionamos
        if (actividades[i].inicio >= tiempoFinal) {
            std::cout << "Banda: " << actividades[i].banda << ", Inicio: " << actividades[i].inicio << ", Fin: " << actividades[i].fin << "\n";
            tiempoFinal = actividades[i].fin;
        }
    }
}

int main() {
    // Definimos un array de actividades
    Actividad actividades[] = {
        {"Tony Velour", 1200, 1230},
        {"Redveil", 1230, 1315},
        {"Niko Rubio", 1250, 1330},
        {"Last Dinosaurs", 1315, 1400},
        {"Mills", 1300, 1340},
        {"Midwxst", 1350, 1430},
        {"Sam Fender", 1400, 1500},
        {"Petey", 1450, 1530},
        {"Willie Jones", 1410, 1450},
        {"Inhaler", 1500, 1600},
        {"Role Model", 1600, 1700},
        {"Zach Bryan", 1600, 1645},
        {"Giovannie and the Hired Guns", 1630, 1710},
        {"Tove Lo", 1700, 1800},
        {"100 Gecs", 1800, 1900},
        {"Remi Wolf", 1830, 1915},
        {"Maxo Kream", 1945, 2030},
        {"Lil Baby", 2045, 2200},
        {"Caroline Polachek", 2100, 2200},
        {"Jubilee", 1300, 1345},
        {"Bijou", 1400, 1500},
        {"Tsha", 1515, 1615},
        {"Chris Lorenzo", 1630, 1730},
        {"MK", 1745, 1845},
        {"Black Coffee", 1900, 2000},
        {"Zhu", 2030, 2145},
        {"Emmy Meli", 1200, 1245},
        {"Underscores", 1245, 1330},
        {"Sampa the Great", 1330, 1415},
        {"Maude Latour", 1415, 1515},
        {"Still Woozy", 1615, 1715},
        {"Manchester Orchestra", 1715, 1815},
        {"Billy Strings", 1815, 1915},
        {"Ashnikko", 1915, 2015},
        {"Metallica", 2015, 2230}
    };
    int n = sizeof(actividades) / sizeof(actividades[0]);

    // Seleccionamos las actividades que se pueden realizar
    seleccionarActividades(actividades, n);

    return 0;
}
