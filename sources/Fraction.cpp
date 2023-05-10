#include "Fraction.hpp"
using namespace std; 
namespace ariel
{

    Fraction::Fraction(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }

        this->numerator = numerator;
        this->denominator = denominator;

        if (numerator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
        this->reduce();
    }



    Fraction::Fraction(float value)
    {
        this->numerator = int(value * 1000);
        this->denominator = 1000;
        this->reduce();
    }

    Fraction& Fraction::reduce()
    {
        int a = numerator;
        int b = denominator;
        int temp;
        if (a < 0) {
            a = -a;
        }
        while (b != 0) {
            temp = a % b;
            a = b;
            b = temp;
        }
        numerator /= a;
        denominator /= a;
        if (denominator < 0 || (numerator == 0 && denominator < 0))
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        return *this;
    }


    Fraction::Fraction()
    {
        this-> numerator = 0;
        this-> numerator = 1;
        this->reduce();
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

    Fraction operator+(const Fraction& frac1, const Fraction& frac2)
    {
        frac1.check_add_overflow(frac1.getNumerator() * frac2.getDenominator(),
                                (frac2.getNumerator() * frac1.getDenominator()));
        frac1.check_multiply_overflow(frac1.getNumerator() , (frac2.getDenominator()));
        frac1.check_multiply_overflow(frac2.getNumerator() , (frac1.getDenominator()));
        frac1.check_multiply_overflow(frac2.getDenominator() , (frac1.getDenominator()));
        int n = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
        int d = frac1.denominator * frac2.denominator;
        return Fraction(n, d);
    }

    Fraction operator+(const Fraction& frac1, float num) {
        return frac1 + Fraction(num);
    }

    Fraction operator-(const Fraction& frac1, const Fraction& frac2)
    {
        frac1.check_add_overflow(frac2.getNumerator(), 1);
        frac1.check_multiply_overflow(frac1.getNumerator(), frac2.getDenominator());
        frac1.check_multiply_overflow(frac2.getNumerator(), frac1.getDenominator());
        frac1.check_multiply_overflow(frac2.getDenominator(), frac1.getDenominator());

        long long n = static_cast<long long>(frac1.numerator) * frac2.denominator - static_cast<long long>(frac2.numerator) * frac1.denominator;
        long long d = static_cast<long long>(frac1.denominator) * frac2.denominator;

        if (n < INT_MIN || n > INT_MAX || d < INT_MIN || d > INT_MAX) {
            throw std::overflow_error("Overflow error");
        }

        return Fraction(n, d);
    }

    
    Fraction operator-(const Fraction& frac, float value)
    {
        Fraction newVal(value);
        int n = frac.numerator * newVal.denominator - newVal.numerator * frac.denominator;
        int d = frac.denominator * newVal.denominator;

        return Fraction(n, d);
    }


    Fraction operator*(const Fraction& fraction, float value)
    {    
        Fraction fvalue(value);
        return fvalue * fraction;
    }

    Fraction operator*(float value, const Fraction& fraction)
    {    
        Fraction fvalue(value);
        return fvalue * fraction;
    }

    Fraction operator/(const Fraction& fraction, float value)
    {
        if(value == 0)
        {
            
            throw std::runtime_error("cant divide by 0");
        }
        Fraction fvalue(value);
        return fraction / fvalue;
    }

    Fraction operator/(float value, const Fraction& fraction)
    {
        if(fraction == 0)
        {
            throw std::runtime_error("cant divide by 0");
        }
        Fraction fvalue(value);
        return fvalue / fraction;
    }

    Fraction Fraction::operator++()
    {
        *this = *this + 1;
        this->reduce();
        return *this;
    };

    Fraction Fraction::operator++(int num)
    {
        Fraction old = *this;
        *this = *this + 1;
        this->reduce();
        return old;
    };

    Fraction Fraction::operator--()
    {
        *this = *this - 1;
        this->reduce();
        return *this;
    };

    Fraction Fraction::operator--(int num)
    {
        Fraction old = *this;
        *this = *this - 1;
        this->reduce();
        return old;
    };

    Fraction Fraction::operator/(const Fraction& other) const
    {
        if(other == 0)
        {
            throw std::runtime_error("cant divide by 0");
        }
        this->check_multiply_overflow(this->getDenominator(), other.getNumerator());
        this->check_multiply_overflow(other.getDenominator(), this->getNumerator());
        int n = numerator * other.denominator;
        int d = denominator * other.numerator;
        return Fraction(n, d);        
    };

    Fraction Fraction::operator*(const Fraction& other) const
    {
        this->check_multiply_overflow(this->getDenominator(), other.getDenominator());
        this->check_multiply_overflow(this->getNumerator(), other.getNumerator());
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
            throw std::runtime_error("Denominator can't be zero");
        }
        f = Fraction(num, den);
        return input;
    }

void Fraction::check_add_overflow(int num1, int num2) const
{
    if (num1 > 0 && num2 > 0 && num1 > INT_MAX - num2)
    {
        throw std::overflow_error("Overflow error");
    }
    else if (num1 < 0 && num2 < 0 && num1 < INT_MIN - num2)
    {
        throw std::overflow_error("Overflow error");
    }
}

void Fraction::check_multiply_overflow(int num1, int num2) const
{
    bool overflow = false;
    if (num1 > 0)
    {
        if (num2 > 0 && num1 > INT_MAX / num2)
        {
            overflow = true;
        }
        else if (num2 < 0 && num2 < INT_MIN / num1)
        {
            overflow = true;
        }
    }
    else if (num1 < 0)
    {
        if (num2 > 0 && num1 < INT_MIN / num2)
        {
            overflow = true;
        }
        else if (num2 < 0 && (num1 < INT_MAX / num2 || num2 < INT_MAX / num1))
        {
            overflow = true;
        }
    }
    if (overflow)
    {
        throw std::overflow_error("Overflow error");
    }
}

}