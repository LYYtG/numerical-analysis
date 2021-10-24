/**
 * @file main.cpp
 * @author 李杨野 (1300096763@qq.com 3190103519@zju.edu.cn)
 * @brief main program.
 * @version 0.1
 * @date 2021-10-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "InterpConditions.hpp"
#include "NewtonInterp.hpp"
int main()
{
    int n;
    InterpConditions IC;
    cout << "B:" << endl;
    for(n = 2;n<=8;n = n+2){
        NewtonInterp solver_B;
        cout << solver_B.solve(IC.B_construct(n));
    }
    cout << "C:" << endl;
    for(n = 5;n<=20;n = n+5){
        NewtonInterp solver_C;
        cout << solver_C.solve(IC.C_construct(n));
    }
    cout << "D:" << endl;
    NewtonInterp solver_D;
    Polynomial D_ans = solver_D.solve(IC.D_value);
    cout <<"Poly: "<<D_ans;
    cout <<"t = 10s: "<< D_ans.evaluation(10)<<endl;;
    cout <<"Deriv: "<<D_ans.derivation();
    cout << "E:" << endl;
    NewtonInterp solver_E1;
    NewtonInterp solver_E2;
    cout << "sp1: " <<  solver_E1.solve(IC.E_value_sp1);
    cout << "sp2: " <<  solver_E2.solve(IC.E_value_sp2);    
    return 0;
}