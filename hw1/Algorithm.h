#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <random>
#include <vector>
using namespace std;
//template <class T>
/**
 * @brief base class.
 * 
 */
class EquationSolver
{
    public:
        EquationSolver(){};
        ~EquationSolver(){};
        virtual double Solve(void) = 0;
};
/**
 * @brief Derived class, using bisection method.
 * 
 */
class Bisection: public EquationSolver
{
    private:
        double a;
        double b;
        int M;
        double delta;
        double epsilon;
        double (*pf)(double x);
    public:
        Bisection(double _a,double _b,int _M,double _delta,double _epsilon,double (*_pf)(double x));
        virtual double Solve(void);
        int sgn(double x){
            if(x>0)
                return 1;
            else if(x=0)
                return 0;
            else
                return -1;
        }
};
/**
 * @brief Construct a new Bisection:: Bisection object
 * 
 * @param _a Left interval.
 * @param _b Right interval.
 * @param _M Maxium loop times.
 * @param _delta 
 * @param _epsilon 
 * @param _pf testing function.
 */
Bisection::Bisection(double _a,double _b,int _M,double _delta,double _epsilon,double (*_pf)(double x))
{
    a = _a;
    b = _b;
    M = _M;
    delta = _delta;
    epsilon = _epsilon;
    pf = _pf;
}
/**
 * @brief the bisection method to solve equations.
 * 
 * @return double 
 */
double Bisection::Solve(void)
{
    //cout << (*pf)(input) <<endl;
    int k;
    double h = b-a;
    double c,w;
    double u = (*pf)(a);
    for(k = 1;k<=M;k++)
    {
        h/=2;
        c = a+h;
        w = (*pf)(c);
        //cout << c << w << endl;
        if(fabs(h)<delta||fabs(w)<epsilon){
            break;
        }
        else if(sgn(w) == sgn(u)){
            a = c;
        }
    }
    return c;
}
/**
 * @brief Derived class.
 * 
 */
class Newton: public EquationSolver
{
    private:
        double x_0;
        int M;
        double epsilon;
        double (*pf)(double x);
        double (*pf_diff)(double x);
    public:
        Newton(double _x_0,int _M,double _epsilon,double (*_pf)(double x),double (*_pf_diff)(double x));
        virtual double Solve(void);
        //double Differential(double (*pf)(double x),double p);
};
/**
 * @brief Construct a new Newton:: Newton object
 * 
 * @param _x_0 initial point
 * @param _M maxium loop times
 * @param _epsilon 
 * @param _pf testing function
 * @param _pf_diff derivation of testing function
 */
Newton::Newton(double _x_0,int _M,double _epsilon,double (*_pf)(double x),double (*_pf_diff)(double x))
{
    x_0 = _x_0;
    M = _M;
    epsilon = _epsilon;
    pf = _pf;
    pf_diff = _pf_diff;
}
/**
 * @brief the Newton method to solve equations.
 * 
 * @return double 
 */
double Newton::Solve(void)
{
    double u,x;
    int k;
    x = x_0;
    for(k = 0;k<=M;k++){
        u = (*pf)(x);
        if(fabs(u)<epsilon){
            break;
        }
        x -= u/(*pf_diff)(x);
    }
    return x;
}
/**
 * @brief derived class.
 * 
 */
class Secant: public EquationSolver
{
    private:
        double x_0,x_1;
        int M;
        double delta;
        double epsilon;
        double (*pf)(double x);
    public:
        Secant(double _x_0,double _x_1,int _M,double _delta,double _epsilon,double (*_pf)(double x));
        virtual double Solve(void);
        //double Differential(double (*pf)(double x),double p);
};
/**
 * @brief Construct a new Secant:: Secant object
 * 
 * @param _x_0 initial testing point.
 * @param _x_1 initial testing point.
 * @param _M maxium loop times.
 * @param _delta 
 * @param _epsilon 
 * @param _pf testing function.
 */
Secant::Secant(double _x_0,double _x_1,int _M,double _delta,double _epsilon,double (*_pf)(double x))
{
    x_0 = _x_0;
    x_1 = _x_1;
    M = _M;
    delta = _delta;
    epsilon = _epsilon;
    pf = _pf;
}
/**
 * @brief the secant method to solve equations.
 * 
 * @return double 
 */
double Secant::Solve(void)
{
    double x_n = x_1;
    double x_p = x_0;
    double u = (*pf)(x_n),v = (*pf)(x_p);
    double temp,s;
    int k;
    for(k = 2;k<=M;k++){
        if(fabs(u)>fabs(v)){
            temp = x_n;
            x_n = x_p;
            x_p = temp;
            temp = u;
            u = v;
            v = temp;
            //switch x_p x_n
        }
        s = (x_n-x_p)/(u-v);
        x_p = x_n;
        v = u;
        x_n-=u*s;
        u = (*pf)(x_n);
        if(fabs(x_n-x_p)<delta||fabs(u)<epsilon){
            break;
        }
    }
    return x_n;
}

