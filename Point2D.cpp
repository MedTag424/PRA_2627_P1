#include <ostream>
#include <cmath>
#include "Point2D.h"

// Inicializa las coordenadas del punto
Point2D::Point2D(double x, double y) : x(x), y(y) {
}

// Calcula la distancia euclidiana entre dos puntos
double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(
        std::pow(a.x - b.x, 2) +
        std::pow(a.y - b.y, 2)
    );
}

// Comprueba si las dos coordenadas son iguales
bool Point2D::operator==(const Point2D &other) {
    return x == other.x && y == other.y;
}

// Comprueba si las dos coordenadas son diferentes
bool Point2D::operator!=(const Point2D &other) {
    return !(*this == other);
}

// Imprime el punto con el formato (x,y)
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
