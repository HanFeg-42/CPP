#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(2.0f, 2.0f);
    Point outside(10.0f, 10.0f);
    Point on_edge(5.0f, 0.0f);
    Point on_vertex(0.0f, 0.0f);

    std::cout << "Inside (expected 1): "
              << bsp(a, b, c, inside) << std::endl;

    std::cout << "Outside (expected 0): "
              << bsp(a, b, c, outside) << std::endl;

    std::cout << "On edge (expected 0): "
              << bsp(a, b, c, on_edge) << std::endl;

    std::cout << "On vertex (expected 0): "
              << bsp(a, b, c, on_vertex) << std::endl;

    return 0;
}
