#include <iostream>
#include "InterpConditions.hpp"
#include "NewtonInterp.hpp"
int main(){
    cout << "Test for public methods. It's NOT the main program." << endl;
    cout << "Polynomials:"<<endl;
    vector<double> v1 = {-1,2};
    vector<double> v2 = {1,-2,3};
    Polynomial p1 = Polynomial(v1);
    Polynomial p2 = Polynomial(v2);
    cout << "\tp1: "<< p1 << endl << "\tp2: "<< p2 << endl;
    cout << "\tp1+p2: " << p1+p2 <<endl;
    cout << "\tp1-p2: " << p1-p2<<endl;
    cout << "\tp1*p2: " << p1*p2<<endl;
    cout << "\tp1/2: " << p1/2<<endl;
    cout << "\tp1': " << p1.derivation() <<endl;
    cout << "\tp1 at 0: " << p1.evaluation(0) << endl<<endl;
    cout << "\tp1*(x-1): " << p1.times_x_minus_a(1) << endl; 
    cout << "NewtonInterp:"<<endl;
    cout << "\tGiven the inital data: x = [0,1], f(x) = [1,0]."<< endl;
    cout << "\tThe corresponding polynomial of Newton(Hermite) Interpolation: ";
    vector<value> data;
    data.push_back(value(0,1));
    data.push_back(value(1,0));
    NewtonInterp solver;
    cout << solver.solve(data) << endl << "\tShow the table of divided difference functions: "<<endl;
    solver.showTable();
    cout << "\tGive another pair [2,3],and the recalculated polynomial: ";
    cout << solver.solve(2,3);
    solver.showTable();
    cout << "\tFinally, use Neville-Aitken algorithm: ";
    data.push_back(value(2,3));
    cout << solver.Neville_Aitken(data);
    return 0;
}