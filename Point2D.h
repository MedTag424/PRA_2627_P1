#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D {
public:
    // Coordenadas del punto
    double x;
    double y;

    // Constructor: por defecto, el punto es (0, 0)
    Point2D(double x = 0.0, double y = 0.0);

    // Calcula la distancia entre dos puntos
    static double distance(const Point2D &a, const Point2D &b);

    // Comprueba si dos puntos son iguales
    bool operator==(const Point2D &other);

    // Comprueba si dos puntos son diferentes
    bool operator!=(const Point2D &other);

    // Permite imprimir un punto por pantalla
    friend std::ostream& operator<<(std::ostream &out,
                                    const Point2D &p);
};

#endif
