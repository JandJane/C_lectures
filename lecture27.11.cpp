#include <iostream>
#include <cmath>

class Complex {
private:
    double x, y;
public:
    Complex(double a = 0.0, double b = 0.0) : x(a), y(b)
    {
    }

    double Re() const {  // const - this func does not modify the object
        return x;
    }

    double Im() const {
        return y;
    }

    double Abs() const {
        return sqrt(x * x + y * y);
    }

    Complex& operator += (const Complex& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
};


Complex operator + (const Complex& u, const Complex& v) {
    return {u.Re() + v.Re(), u.Im() + v.Im()};
}

/* void Complex::foo()  // Also Complex class function
{
}
*/

std::ostream& operator << (std::ostream& out, const Complex& z) {
    out << z.Re() << "+" << z.Im() << "i";
    return out;
}


int main() {
    Complex z(2.0, 3.0);
    std::cout << z.Re() << " " << z.Im() << "\n";
    std::cout << z << " " << (z + z) << "\n";
}
