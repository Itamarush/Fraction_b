#pragma once
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel
{
    class Fraction{

    public:
    int numerator;
    int denominator;

    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(float num);
    float toFloat() const
    {
        return (float)numerator / (float)denominator;
    }

    int getNumerator() const;
    int getDenominator() const;

    int gcd(int a, int b) const;
    int lcm(int a, int b) const;
    friend bool operator>(const Fraction& frac1, float num);
    friend bool operator>(const Fraction& frac1, const Fraction& frac2);    
    friend bool operator<(const Fraction& frac1, float num);
    friend bool operator<(const Fraction& frac1, const Fraction& frac2);  
    friend bool operator==(const Fraction& frac1, const Fraction& frac2); 
    friend bool operator==(const Fraction& frac1, float num);
    friend istream& operator>>(istream& input, Fraction& f);
    friend ostream& operator<<(ostream& output, const Fraction& f);
    friend bool operator>=(const Fraction& frac1,const Fraction& frac2);
    friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
    friend Fraction operator+(const Fraction &frac1, float num);
    friend Fraction operator-(const Fraction& frac1 , const Fraction& frac2);
    friend Fraction operator-(const Fraction& frac1 , float num);
    friend Fraction operator*(const Fraction& fraction, float value);
    friend Fraction operator*(float value, const Fraction& fraction);
    friend Fraction operator/(const Fraction& fraction, float value);
    friend Fraction operator/(float value, const Fraction& fraction);
    Fraction operator/(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator++();
    Fraction operator++(int num);
    Fraction operator--();
    Fraction operator--(int num);

    };

}
   
