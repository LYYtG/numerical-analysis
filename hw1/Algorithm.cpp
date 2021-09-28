#include <iostream>
#include "Algorithm.h"
#include "Functions.h"
#define PI 3.14159265
int main()
{
    //using 1e-13 as epsilon and 1e-6 as delta.
    Bisection B_1(0,M_PI/2,100,1e-6,1e-13,B1);
    Bisection B_2(0,1,100,1e-6,1e-13,B2);
    Bisection B_3(1,3,100,1e-6,1e-13,B3);
    Bisection B_4(0,4,100,1e-6,1e-13,B4);
    //
    Newton C_1(4.5,100,1e-13,C,C_diff);
    Newton C_2(7.7,100,1e-13,C,C_diff);
    //
    Secant D_1(0,M_PI/2,100,1e-6,1e-13,D1);
    Secant D_2(1,1.4,100,1e-6,1e-13,D2);
    Secant D_3(10,20,100,1e-6,1e-13,D3);
    //
    Bisection E_1(0,1,100,1e-6,1e-13,E);
    Newton E_2(0.5,100,1e-13,E,E_diff);
    Secant E_3(0,1,100,1e-6,1e-13,E);
    //
    Newton F_1(33.0/360*2*M_PI,100,1e-13,Fa,Fa_diff);
    Newton F_2(33.0/360*2*M_PI,100,1e-13,Fb,Fb_diff);
    Secant F_3(33.0/360*2*M_PI,100*M_PI,100,1e-6,1e-13,Fb);
    //
    cout <<"Solution of B_1: "<< B_1.Solve() << endl;
    cout <<"Solution of B_2: "<< B_2.Solve() << endl;
    cout <<"Solution of B_3: "<< B_3.Solve() << endl;
    cout <<"Solution of B_4: "<< B_4.Solve() << endl;
    //
    cout <<"Solution of C_1: "<< C_1.Solve() << endl;
    cout <<"Solution of C_2: "<< C_2.Solve() << endl;
    //
    cout <<"Solution of D_1: "<< D_1.Solve() << endl;
    cout <<"Solution of D_2: "<< D_2.Solve() << endl;
    cout <<"Solution of D_3: "<< D_3.Solve() << endl;
    //
    cout <<"Solution of E_1: "<< E_1.Solve() << endl;
    cout <<"Solution of E_2: "<< E_2.Solve() << endl;
    cout <<"Solution of E_3: "<< E_3.Solve() << endl;
    //
    cout <<"Solution of F_1: "<< F_1.Solve()/(M_PI/180) << "degree" << endl;
    cout <<"Solution of F_2: "<< F_2.Solve()/(M_PI/180) << "degree" << endl;
    cout <<"Solution of F_3: "<< F_3.Solve()/(M_PI/180) << "degree" << endl;
    return 0;
}