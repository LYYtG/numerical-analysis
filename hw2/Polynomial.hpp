/**
 * @file Polynomial.hpp
 * @author 李杨野 (1300096763@qq.com 3190103519@zju.edu.cn)
 * @brief define class Polynomial and some methods.
 * @version 0.1
 * @date 2021-10-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <random>
#include <vector>
#include <iostream>
using namespace std;
class Polynomial
{
    int degree;
    vector<double> Coefficient;
public:
    Polynomial();
    Polynomial(vector<double> _Coefficient);
    Polynomial(double _init);
    Polynomial derivation();
    Polynomial operator+(Polynomial &_poly) const;
    Polynomial operator-(Polynomial _poly) const;
    Polynomial operator*(Polynomial &_poly) const;
    Polynomial operator/(double _divider) const;
    friend ostream & operator<<(ostream &os,const Polynomial &_poly);
    double evaluation(double _x);
    Polynomial times_x_minus_a(double a);
};
/**
 * @brief Construct a new Polynomial:: Polynomial object
 * 
 * @param _Coefficient vector of coefficients.
 */
Polynomial::Polynomial(vector<double> _Coefficient)
{
    degree = _Coefficient.size()-1;
    Coefficient = vector<double>(degree+1);
    Coefficient = _Coefficient;
}
/**
 * @brief Construct a new Polynomial:: Polynomial object
 * 
 * @param _init initial number, as a_0.
 */
Polynomial::Polynomial(double _init)
{
    degree = 0;
    Coefficient = vector<double>(1);
    Coefficient[0] = _init;
}
/**
 * @brief Calculate the derivation of the polynomial.
 * 
 * @return Polynomial 
 */
Polynomial Polynomial::derivation()
{
    vector<double> Coeff_deriv(degree);
    int i;
    for(i = 0;i<degree;i++){
        Coeff_deriv[i] = (i+1)*Coefficient[i+1];
    }
    Polynomial ret = Polynomial(Coeff_deriv);
    return ret;
}
/**
 * @brief plus of polynomial.
 * 
 * @param _poly 
 * @return Polynomial 
 */
Polynomial Polynomial::operator+(Polynomial &_poly) const
{
    vector<double> coeff_plus;
    int max_degree,min_degree,i;
    if(_poly.degree > degree){
        max_degree = _poly.degree;
        min_degree = degree;
        coeff_plus = vector<double>(max_degree+1);
        for(i = 0;i<=max_degree;i++){
            if(i<=min_degree)
                coeff_plus[i] = _poly.Coefficient[i]+Coefficient[i];
            else
                coeff_plus[i] =  _poly.Coefficient[i];
        }
    }else{
        max_degree = degree;
        min_degree = _poly.degree;

        coeff_plus = vector<double>(max_degree+1);
        for(i = 0;i<=max_degree;i++){
            if(i<=min_degree)
                coeff_plus[i] = _poly.Coefficient[i]+Coefficient[i];
            else
                coeff_plus[i] =  Coefficient[i];
        }
    }
    Polynomial ret = Polynomial(coeff_plus);
    return ret;
}
/**
 * @brief minus of polynomial.
 * 
 * @param _poly 
 * @return Polynomial 
 */
Polynomial Polynomial::operator-(Polynomial _poly) const
{
    vector<double> coeff_minus;
    int max_degree,min_degree,i;
    if(_poly.degree > degree){
        max_degree = _poly.degree;
        min_degree = degree;
        coeff_minus = vector<double>(max_degree+1);
        for(i = 0;i<=max_degree;i++){
            if(i<=min_degree)
                coeff_minus[i] = -_poly.Coefficient[i]+Coefficient[i];
            else
                coeff_minus[i] =  -_poly.Coefficient[i];
        }
    }else{
        max_degree = degree;
        min_degree = _poly.degree;

        coeff_minus = vector<double>(max_degree+1);
        for(i = 0;i<=max_degree;i++){
            if(i<=min_degree)
                coeff_minus[i] = -_poly.Coefficient[i]+Coefficient[i];
            else
                coeff_minus[i] =  Coefficient[i];
        }
    }
    Polynomial ret = Polynomial(coeff_minus);
    return ret;
}
/**
 * @brief times of polynomial.
 * 
 * @param _poly 
 * @return Polynomial 
 */
Polynomial Polynomial::operator*(Polynomial &_poly) const
{
    vector<double> coeff_times(degree+_poly.degree+1);
    int i,j;
    for(i = 0;i<=degree;i++)
    {
        for(j = 0;j<=_poly.degree;j++){
            coeff_times[i+j] += Coefficient[i]*_poly.Coefficient[j];
        }
    }
    Polynomial ret = Polynomial(coeff_times);
    return ret;
}
/**
 * @brief divide by number of polynomial.
 * 
 * @param divider 
 * @return Polynomial 
 */
Polynomial Polynomial::operator/(double divider) const
{
    vector<double> coeff_divide(degree+1);
    int i,j;
    for(i = 0;i<=degree;i++)
    {
       coeff_divide[i] = Coefficient[i]/divider;
    }
    Polynomial ret = Polynomial(coeff_divide);
    return ret;
}
/**
 * @brief Reload of ostream.
 * 
 * @param os ostream
 * @param _poly 
 * @return ostream& 
 */
ostream & operator<<(ostream &os,const Polynomial &_poly)
{
    int i = 0;
    if(_poly.Coefficient[0]!=0||_poly.degree == 0)
        os << _poly.Coefficient[0];
    for(i = 1;i<=_poly.degree;i++)
    {
        if(fabs(_poly.Coefficient[i])>1e-15){
            if(_poly.Coefficient[i]>0){
                os << "+";
            }else if(_poly.Coefficient[i] == -1){
                os << "-";
            }
            if (abs(_poly.Coefficient[i])!=1){
                os << _poly.Coefficient[i];
                switch (i)
                {
                case 1:
                    os << "x";
                    break;
                default:
                    os << "x^{" << i << "}";
                    break;
                }
            }else{
                switch (i)
                {
                case 1:
                    os << "x";
                    break;
                default:
                    os << "x^{" << i << "}";
                    break;
                }
            }                
        }
    }
    os << endl;
    return os;
}
/**
 * @brief the evaluation of polynomial.
 * 
 * @param _x 
 * @return double 
 */
double Polynomial::evaluation(double _x)
{
    int i,j;
    double sum = 0;
    for(i = 0;i<=degree;i++)
    {
        double x_Multiply = 1;
        for(j = 1;j<=i;j++){
            x_Multiply*=_x; //x^n. Not using pow() because it's slow.
        }
        sum+=Coefficient[i]*x_Multiply;
    }
    return sum;
}
/**
 * @brief a simple function, used in NewtonInterp as a shortcut.
 * 
 * @param a 
 * @return Polynomial 
 */
Polynomial Polynomial::times_x_minus_a(double a)
{
    vector<double> ret(degree+2);
    int i;
    for(i = 0;i<ret.size();i++){
        if(i == 0){
            ret[i] = -a*Coefficient[0];
        }else if(i == ret.size()-1){
            ret[i] = Coefficient[degree];
        }else{
            ret[i] = Coefficient[i-1]-a*Coefficient[i];
        }
    }
    Polynomial retP = Polynomial(ret);
    return retP;
}
