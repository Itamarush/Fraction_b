#include "Fraction.hpp"

namespace ariel{

    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        int a = numerator;
        int b = denominator;
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        numerator /= a;
        denominator /= a;
        this->numerator = numerator;
        this->denominator = denominator;

        if (numerator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
    }



    Fraction::Fraction(float value)
    {
        // Reduce precision of the float to match maximum three digit numerator/denominator
        int factor = 1000; // 3 digits
        value = round(value * factor) / factor;
        
        // Convert the floating-point value to a fraction
        int n = static_cast<int>(value * factor);
        int d = factor;
        
        // Reduce the fraction
        int a = n;
        int b = d;
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        int gcd = a;
        numerator = n / gcd;
        denominator = d / gcd;
         
        if (numerator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
    }


    Fraction::Fraction()
    {
        this-> numerator = 0;
        this-> numerator = 1;
    }
    
    int Fraction::getNumerator() const
    {    
        int a = numerator;
        int b = denominator;
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return numerator / a;
    }

    int Fraction::getDenominator() const
    {
        int a = numerator;
        int b = denominator;
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return denominator / a;
    }


    bool operator>(const Fraction& frac1, float num) {
        return frac1.toFloat() > num;
    }

    bool operator<(const Fraction& frac1, float num) {
        return frac1.toFloat() < num;
    }

    bool operator>(const Fraction& frac1, const Fraction& frac2)
    {
        return frac1.toFloat() > frac2.toFloat();
    }    

    bool operator<(const Fraction& frac1, const Fraction& frac2)
    {
        return frac1.toFloat() < frac2.toFloat();
    }  

    bool operator==(const Fraction& frac1, const Fraction& frac2)
    {
        return frac1.numerator == frac2.numerator && frac1.denominator == frac2.denominator;
    }

    bool operator==(const Fraction& frac1, float num)
    {
        return frac1.toFloat() == num;
    }

    bool operator>=(const Fraction& frac1, const Fraction& frac2) {
        return frac1.toFloat() >= frac2.toFloat();
    }

    bool operator<=(const Fraction& frac1, const Fraction& frac2) {
        return frac1.toFloat() <= frac2.toFloat();
    }

    Fraction operator+(const Fraction& frac1, const Fraction& frac2) {
        int n = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
        int d = frac1.denominator * frac2.denominator;
        return Fraction(n, d);
    }

    Fraction operator+(const Fraction& frac1, float num) {
        return frac1 + Fraction(num);
    }

    Fraction operator-(const Fraction& frac1, const Fraction& frac2) {
        int n = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
        int d = frac1.denominator * frac2.denominator;
        return Fraction(n, d);
    }
    
    Fraction operator-(const Fraction& frac, float value)
    {
        Fraction newVal(value);
        int n = frac.numerator * newVal.denominator - newVal.numerator * frac.denominator;
        int d = frac.denominator * newVal.denominator;
        // Reduce the fraction
        int a = n;
        int b = d;
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        int gcd = a;
        n /= gcd;
        d /= gcd;
         
        if (n < 0)
        {
            n *= -1;
            d *= -1;
        }
        cout << n << endl;
        cout << d << endl;
        return Fraction(n, d);
    }


    Fraction operator*(const Fraction& fraction, float value) {
        float f = fraction.toFloat() * value;
        Fraction newFra(f);
        // Reduce the fraction
        int n = newFra.numerator;
        int d = newFra.denominator;
        int a = n;
        int b = d;
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        int gcd = a;
        n /= gcd;
        d /= gcd;
         
        if (n < 0)
        {
            n *= -1;
            d *= -1;
        }
        return Fraction(n,d);
    }

    Fraction operator*(float value, const Fraction& fraction) {
        float f = fraction.toFloat() * value;
        Fraction newFra(f);
        // Reduce the fraction
        int n = newFra.numerator;
        int d = newFra.denominator;
        int a = n;
        int b = d;
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        int gcd = a;
        n /= gcd;
        d /= gcd;
         
        if (n < 0)
        {
            n *= -1;
            d *= -1;
        }
        return Fraction(n,d);    }

    Fraction operator/(const Fraction& fraction, float value)
    {
        if(value == 0)
        {
            throw invalid_argument("cant divide by 0");
        }
        Fraction newVal(value);
        return Fraction(newVal.denominator * fraction.numerator, newVal.numerator *fraction.denominator);
    }

    Fraction operator/(float value, const Fraction& fraction)
    {
        if(fraction == 0)
        {
            throw invalid_argument("cant divide by 0");
        }
        int n = value * fraction.denominator;
        return Fraction(n, fraction.numerator);
    }

    Fraction Fraction::operator++()
    {
        numerator += denominator;
        return *this;
    };

    Fraction Fraction::operator++(int num)
    {
        Fraction old = *this;
        numerator += denominator;
        return old;
    };

    Fraction Fraction::operator--()
    {
        numerator -= denominator;
        return *this;
    };

    Fraction Fraction::operator--(int num)
    {
        Fraction old = *this;
        numerator -= denominator;
        return old;
    };

    Fraction Fraction::operator/(const Fraction& other) const
    {
        int n = numerator * other.denominator;
        int d = denominator * other.numerator;
        return Fraction(n, d);        
    };

    Fraction Fraction::operator*(const Fraction& other) const
    {
        int n = numerator * other.numerator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    };

    ostream& operator<<(ostream& output, const Fraction& f)
    {
        output << f.numerator << "/" << f.denominator;
        return output;
    }

    istream& operator>>(istream& input, Fraction& f)
    {
        int num = 0, den = 0;
        input >> num >> den;
        if(input.fail()) {
            throw runtime_error("Input is not good");
        }
        if(den == 0) {
            throw runtime_error("Denominator can't be zero");
        }
        f = Fraction(num, den);
        return input;
    }
}