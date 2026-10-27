#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square();
    Square(std::string color, Point2D* vertices);

    void set_vertices(Point2D* vertices) override;
    void print() override;

    friend std::ostream& operator<<(std::ostream &out, const Square &square);

private:
    static bool check(Point2D* vertices);
};

#endif
