#include <bits/stdc++.h> 
using namespace std;

class Rational {
    private:
    int numerator, denominator; 
    public:
    Rational() : numerator(0), denominator(1) {}
    Rational(int num, int denom) : numerator(num), denominator(denom) {}
    void copy (const Rational &r);
    void move (Rational &r);
    double toDouble();
    void operator= (const Rational &k){
       copy(k);
    };
};
void Rational::copy (const Rational &r){
    numerator = r.numerator;
    denominator = r.denominator;
}
void Rational::move (Rational &r){
    numerator = r.numerator;
    denominator = r.denominator;
    r.numerator = 0;
    r.denominator = 1;
}
double Rational::toDouble() {
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}
void Rational::operator += (const Rational &k){
    numerator = numerator * k.denominator + k.numerator * denominator;
    denominator = denominator * k.denominator;
}

void Rational::operator -= (const Rational &k){
    numerator = numerator * k.denominator - k.numerator * denominator;
    denominator = denominator * k.denominator;
}

void Rational::operator *= (const Rational &k){
    numerator = numerator * k.numerator;
    denominator = denominator * k.denominator;
}

void Rational::operator /= (const Rational &k){
    numerator = numerator * k.denominator;
    denominator = denominator * k.numerator;
}