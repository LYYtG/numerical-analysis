/**
 * @file InterpConditions.hpp
 * @author 李杨野 (1300096763@qq.com 3190103519@zju.edu.cn)
 * @brief record the data, etc.
 * @version 0.1
 * @date 2021-10-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Value.hpp"
#include <cmath>
class InterpConditions
{
public:
    vector<value> D_value;
    vector<value> E_value_sp1;
    vector<value> E_value_sp2;
    InterpConditions();
    vector<value> B_construct(int n);
    vector<value> C_construct(int n);
};
/**
 * @brief Construct a new Interp Conditions:: Interp Conditions object
 * 
 */
InterpConditions::InterpConditions()
{
    int i = 0;
    D_value.clear();
    E_value_sp1.clear();
    E_value_sp2.clear();
    vector<double> D_time = {0,3,5,8,13};
    vector<double> D_distance = {0,225,383,623,993};
    vector<double> D_speed = {75,77,80,74,72};
    vector<double> E_day = {0,6,10,13,17,20,28};
    vector<double> E_sp1 = {6.67,17.3,42.7,37.3,30.1,29.3,28.7};
    vector<double> E_sp2 = {6.67,16.1,18.9,15.0,10.6,9.44,8.89};
    for(i = 0;i<D_time.size();i++){
        value temp(D_time[i],D_distance[i]);
        temp.fx.push_back(D_speed[i]);
        D_value.push_back(temp);
    }
    
    for(i = 0;i<E_day.size();i++){
        value temp(E_day[i],E_sp1[i]);
        E_value_sp1.push_back(temp);
    }
    
    for(i = 0;i<E_day.size();i++){
        value temp(E_day[i],E_sp2[i]);
        E_value_sp2.push_back(temp);
    }
    
}
/**
 * @brief construct B from different integers.
 * 
 * @param n 
 * @return vector<value> 
 */
vector<value> InterpConditions::B_construct(int n)
{
    vector<value> B_value;
    int i = 0;
    double x_i,fx_i;
    for(i = 0;i<=n;i++){
        x_i = -5+10.0*i/n;
        fx_i = 1.0/(1+x_i*x_i);
        value temp(x_i,fx_i);
        B_value.push_back(temp);
    }
    return B_value;
}
/**
 * @brief construct C from different integers.
 * 
 * @param n 
 * @return vector<value> 
 */
vector<value> InterpConditions::C_construct(int n)
{
    vector<value> C_value;
    C_value.clear();
    double k;
    double x_k,fx_k;
    for(k = 1.0;k<=n;k++){
        x_k = cos((2*k-1)*180/2*n);
        fx_k = 1.0/(1+25*x_k*x_k);
        value temp(x_k,fx_k);
        C_value.push_back(temp);
    }
    return C_value;
}