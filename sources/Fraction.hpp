#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cstring>
#include <climits>
#include <limits>
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

    Fraction& reduce();
    friend bool operator>(const Fraction& frac1, float num);
    friend bool operator>(const Fraction& frac1, const Fraction& frac2);    
    friend bool operator<(const Fraction& frac1, float num);
    friend bool operator<(const Fraction& frac1, const Fraction& frac2);  
    friend bool operator==(const Fraction& frac1, const Fraction& frac2); 
    friend bool operator==(const Fraction& frac1, float num);
    friend istream& operator>>(istream& input, Fraction& frac);
    friend ostream& operator<<(ostream& output, const Fraction& frac2);
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
    Fraction operator*(const Fraction& frac1) const;
    Fraction operator++();
    Fraction operator++(int num);
    Fraction operator--();
    Fraction operator--(int num);
    void check_add_overflow(int num1, int num2) const;
    void check_multiply_overflow(int num1, int num2) const;

    };

}
   
