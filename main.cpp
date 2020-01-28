#include <iostream>
#include <cmath>

template<typename ValueType>
class Dual {
    ValueType visible, hidden;
public:
    Dual(ValueType v = 0, ValueType s = 0) : visible(v), hidden(s) {}

    ValueType GetVisible() const { return visible; } // vraca vrijednost f(a)

    ValueType GetHidden() const { return hidden; } // vraca vrijednost f'(a)

    Dual &operator+=(const Dual &d) {
        visible += d.visible;
        hidden += d.hidden;
        return *this;
    }

    Dual &operator-=(const Dual &d) {
        visible -= d.visible;
        hidden -= d.hidden;
        return *this;
    }

    Dual &operator*=(const Dual &d) {
        hidden = hidden * d.visible + visible * d.hidden;
        visible *= d.visible;
        return *this;
    }

    Dual &operator/=(const Dual &d) {
        hidden = hidden / d.visible - visible * d.hidden / (d.visible * d.visible);
        visible /= d.visible;
        return *this;
    }

    friend Dual operator+(Dual d1, const Dual &d2) {
        return d1 += d2;
    }

    friend Dual operator-(Dual d1, const Dual &d2) {
        return d1 -= d2;
    }

    friend Dual operator*(Dual d1, const Dual &d2) {
        return d1 *= d2;
    }

    friend Dual operator/(Dual d1, const Dual &d2) {
        return d1 /= d2;
    }

    friend Dual sin(const Dual &d) {
        return Dual(std::sin(d.visible), d.hidden * std::cos(d.visible));
    }

    friend Dual cos(const Dual &d) {
        return Dual(std::cos(d.visible), d.hidden * (-1) * std::sin(d.visible));
    }

    friend Dual tan(const Dual &d) {
        return Dual(std::tan(d.visible), d.hidden / (cos(d.visible) * cos(d.visible)));
    }

    friend Dual sinh(const Dual &d) {
        return Dual(std::sinh(d.visible), d.hidden * cosh(d.visible));
    }

    friend Dual cosh(const Dual &d) {
        return Dual(std::cosh(d.visible), d.hidden * sinh(d.visible));
    }

    friend Dual tanh(const Dual &d) {
        return Dual(std::tanh(d.visible), d.hidden / (cosh(d.visible) * cosh(d.visible)));
    }

    friend Dual asin(const Dual &d) {
        return Dual(std::asin(d.visible), d.hidden / sqrt(1 - d.visible * d.visible));
    }

    friend Dual acos(const Dual &d) {
        return Dual(std::acos(d.visible), d.hidden / sqrt(1 - d.visible * d.visible));
    }

    friend Dual atan(const Dual &d) {
        return Dual(std::atan(d.visible), d.hidden / (1 + d.visible * d.visible));
    }

    friend Dual asinh(const Dual &d) {
        return Dual(asin(d.visible), d.hidden / sqrt(1 + d.visible * d.visible));
    }

    friend Dual acosh(const Dual &d) {
        return Dual(acos(d.visible), d.hidden / sqrt(d.visible * d.visible - 1));
    }

    friend Dual atanh(const Dual &d) {
        return Dual(atan(d.visible), d.hidden / (1 - d.visible * d.visible));
    }

    friend Dual exp(const Dual &d) {
        return Dual(std::exp(d.visible), std::exp(d.visible) * d.hidden);
    }

    friend Dual log(const Dual &d) {
        return Dual(std::log(d.visible), d.hidden / d.visible);
    }

    friend Dual pow(const Dual &d, ValueType e) {
        return Dual(pow(d.visible, e), d.hidden * e * pow(d.visible, e + 1));
    }

    friend Dual pow(const Dual &d1, const Dual &d2) {
        return exp(d2 * log(d1));
    }

    friend Dual sqrt(const Dual &d) {
        return Dual(std::sqrt(d.visible), .5 * d.hidden / std::sqrt(d.visible));
    }
};

int main() {
    {
        // Test 1
        Dual<double> x(2, 1);
        Dual<double> d = x * log(x) - 3 / (sin(x * x + 1) - sqrt(x));
        std::cout << d.GetVisible() << " " << d.GetHidden() << std::endl;
    }
    {
        //test 2
        Dual<double> x(2.5, 1);
        Dual<double> d = (1 + sin(x)) / (log(x)  + cos(x));
        std::cout << d.GetVisible() << " " << d.GetHidden() << std::endl;
    }
    
    return 0;
}
