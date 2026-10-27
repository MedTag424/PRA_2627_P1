#include "Square.h"
#include <stdexcept>

Square::Square()
    : Rectangle("red", new Point2D[4]{
        Point2D(-1, 1),
        Point2D(1, 1),
        Point2D(1, -1),
        Point2D(-1, -1)
    }) {
}

Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid square vertices");
    }
}

bool Square::check(Point2D* vertices) {
    if (vertices == nullptr) {
        return false;
    }

    double side = Point2D::distance(vertices[0], vertices[1]);

    return side == Point2D::distance(vertices[1], vertices[2])
        && side == Point2D::distance(vertices[2], vertices[3])
        && side == Point2D::distance(vertices[3], vertices[0]);
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid square vertices");
    }

    Rectangle::set_vertices(vertices);
}

void Square::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.get_color() << "; vertices = ";

    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << square[i];
    }

    out << "]";
    return out;
}
