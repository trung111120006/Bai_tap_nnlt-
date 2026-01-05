#include <iostream>
#include <stdexcept>
#include <numeric>

class Rational {
public:
    using Integer = long long;
    
private:
    Integer num;
    Integer den;
    
    void simplify() {
        if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
        Integer g = std::gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }
    
public:
    Rational(Integer numerator = 0, Integer denominator = 1) 
        : num(numerator), den(denominator) {
        if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
        simplify();
    }
    
    Rational(const Rational& other) = default;
    Rational(Rational&& other) noexcept = default;
    Rational& operator=(const Rational& other) = default;
    Rational& operator=(Rational&& other) noexcept = default;
    ~Rational() = default;
    
    double toDouble() const {
        return static_cast<double>(num) / den;
    }
    
    Integer getNumerator() const { return num; }
    Integer getDenominator() const { return den; }
    
    Rational& operator+=(const Rational& rhs) {
        num = num * rhs.den + rhs.num * den;
        den = den * rhs.den;
        simplify();
        return *this;
    }
    
    Rational& operator-=(const Rational& rhs) {
        num = num * rhs.den - rhs.num * den;
        den = den * rhs.den;
        simplify();
        return *this;
    }
    
    Rational& operator*=(const Rational& rhs) {
        num *= rhs.num;
        den *= rhs.den;
        simplify();
        return *this;
    }
    
    Rational& operator/=(const Rational& rhs) {
        if (rhs.num == 0) throw std::domain_error("Division by zero");
        num *= rhs.den;
        den *= rhs.num;
        simplify();
        return *this;
    }
    
    bool operator==(const Rational& rhs) const {
        return num == rhs.num && den == rhs.den;
    }
    
    bool operator!=(const Rational& rhs) const {
        return !(*this == rhs);
    }
    
    bool operator<(const Rational& rhs) const {
        return num * rhs.den < rhs.num * den;
    }
    
    bool operator>(const Rational& rhs) const {
        return rhs < *this;
    }
    
    bool operator<=(const Rational& rhs) const {
        return !(rhs < *this);
    }
    
    bool operator>=(const Rational& rhs) const {
        return !(*this < rhs);
    }
    
    Rational operator-() const {
        return Rational(-num, den);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        if (r.den == 1) {
            os << r.num;
        } else {
            os << r.num << "/" << r.den;
        }
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Rational& r) {
        Integer n, d = 1;
        char slash;
        is >> n;
        if (is.peek() == '/') {
            is >> slash >> d;
        }
        r = Rational(n, d);
        return is;
    }
};

Rational operator+(Rational lhs, const Rational& rhs) { return lhs += rhs; }
Rational operator-(Rational lhs, const Rational& rhs) { return lhs -= rhs; }
Rational operator*(Rational lhs, const Rational& rhs) { return lhs *= rhs; }
Rational operator/(Rational lhs, const Rational& rhs) { return lhs /= rhs; }

int main() {
    try {
        Rational r1(1, 2);
        Rational r2(3, 4);
        
        std::cout << "r1: " << r1 << "\n";
        std::cout << "r2: " << r2 << "\n";
        
        Rational sum = r1 + r2;
        Rational sub = r1 - r2;
        Rational mul = r1 * r2;
        Rational div = r1 / r2;
        
        std::cout << "Sum: " << sum << " (" << sum.toDouble() << ")\n";
        std::cout << "Sub: " << sub << "\n";
        std::cout << "Mul: " << mul << "\n";
        std::cout << "Div: " << div << "\n";
        
        r1 *= r2;
        std::cout << "r1 after *= r2: " << r1 << "\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}