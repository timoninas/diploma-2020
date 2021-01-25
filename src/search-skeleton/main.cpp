#include <iostream>

double angle(double x1, double y1, double x2, double y2) {
    double t = (x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2));
    if (t < -1) t = -1;
    if (t > 1) t = 1;
    return acos(t);
}

struct Node {
    double angle;
    double x_pos;
    double y_pos;
};

// Определение углов разным квадрантам
// Тк сейчас все значения с положительным знаком
int main(int argc, const char * argv[]) {
    double x1 = 20;
    double y1 = -2;
    double x2 = 5;
    double y2 = 3;
    std::cout << angle(1, 0, x2 - x1, y2 - y1) * 180 / 3.14 << std::endl;
    std::cout << angle(1, 0, -1, 1) * 180 / 3.14 << std::endl;
    return 0;
}
