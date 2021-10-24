/**
 * @file NewtonInterp.hpp
 * @author 李杨野 (1300096763@qq.com 3190103519@zju.edu.cn)
 * @brief the main algorithmatic part of program.
 * @version 0.1
 * @date 2021-10-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "Polynomial.hpp"
class NewtonInterp{
private:
    Polynomial interpoly_ = Polynomial(0);
    vector<value> xArray_;
    vector<vector<double>> tableOfDivideDiff_;
    int r;
public:
    NewtonInterp(){
        xArray_.clear();
        tableOfDivideDiff_.clear();
    };
    Polynomial solve(vector<value> _value);
    Polynomial solve(double _x,double _fx);
    Polynomial Neville_Aitken(vector<value> _value);
    void showTable();
};
/**
 * @brief Hermite Interpolation. A certain arrangement of _value is required.
 * 
 * @param _value 
 * @return Polynomial 
 */
Polynomial NewtonInterp::solve(vector<value> _value)
{
    
    int n = _value.size()-1;
    int r = 0;//size of first row,0~r-1
    int i,j,k;
    vector<double> temp1;
    for(i = 0;i<n+1;i++){
        for(j = 0;j<_value[i].fx.size();j++){
            xArray_.push_back(_value[i]);
            temp1.push_back(_value[i].fx[0]);
            r++;
        }
    }
    tableOfDivideDiff_.push_back(temp1);
    for(i = 1;i<r;i++)
    {
        vector<double> tableRow(r-i);
        tableOfDivideDiff_.push_back(tableRow);
        for(j = 0;j<r-i;j++){
            if(xArray_[i+j].x == xArray_[j].x){
                tableOfDivideDiff_[i][j] = xArray_[j].fx[i];
            }else{
                tableOfDivideDiff_[i][j] = (tableOfDivideDiff_[i-1][j+1]-tableOfDivideDiff_[i-1][j])/(xArray_[i+j].x-xArray_[j].x);
            }
        }
    }
    Polynomial ret(0);
    for(i = 0;i<r;i++){
        Polynomial tpoly = Polynomial(tableOfDivideDiff_[i][0]);
        for(j = 0;j<i;j++){
            tpoly = tpoly.times_x_minus_a(xArray_[j].x);
        }
        ret = ret+tpoly;
    }
    interpoly_ = ret;
    return ret;
}
/**
 * @brief Newton Interpolation from previous polynomial.
 * 
 * @param _x the new node
 * @param _fx the new node
 * @return Polynomial 
 */
Polynomial NewtonInterp::solve(double _x,double _fx)
{
    int i,j,k;
    value newNode = value(_x,_fx);
    xArray_.push_back(newNode);
    tableOfDivideDiff_[0].push_back(_fx);
    int r = tableOfDivideDiff_[0].size();
    for(i = 1;i<r-1;i++){
        j = r-1-i;
        tableOfDivideDiff_[i].push_back((tableOfDivideDiff_[i-1][j+1]-tableOfDivideDiff_[i-1][j])/(xArray_[i+j].x-xArray_[j].x));
    }
    i = r-1;
    j = 0;
    vector<double> newRow = {(tableOfDivideDiff_[i-1][j+1]-tableOfDivideDiff_[i-1][j])/(xArray_[i+j].x-xArray_[j].x)};
    tableOfDivideDiff_.push_back(newRow);
    Polynomial tpoly = Polynomial(tableOfDivideDiff_[i][0]);
    for(j = 0;j<i;j++){
        tpoly = tpoly.times_x_minus_a(xArray_[j].x);
    }
    interpoly_ = interpoly_ + tpoly;
    return interpoly_;
}
/**
 * @brief print the current tableOfDivideDiff_ after interpolation.
 * 
 */
void NewtonInterp::showTable()
{
    int r = tableOfDivideDiff_.size();
    int i,j;
    for(i = 0;i<r;i++){
        cout << xArray_[i].x << " ";
    }
    cout << endl;
    for(i = 0;i<r;i++){
        for(j = 0;j<r-i;j++){
            cout << tableOfDivideDiff_[i][j] << " ";
        }
        cout << endl;
    }
}
/**
 * @brief N-A algorithm. Generally will get the same answer with method 'solve'.
 * 
 * @param _value 
 * @return Polynomial 
 */
Polynomial NewtonInterp::Neville_Aitken(vector<value> _value)
{
    vector<Polynomial> p;
    int n = _value.size()-1;
    int i,j,k;
    for(i = 0;i<_value.size();i++){
        if(_value[i].fx.size()>1){
            cerr << "N-A algorithm can't handle derivatives!";
            break;
        }
        xArray_.push_back(_value[i]);
        p.push_back(Polynomial(_value[i].fx[0]));
    }
    for(k = 0;k<n;k++)
    {
        for(i = 0;i<=n-k-1;i++){
                p[i] = (p[i+1].times_x_minus_a(xArray_[i].x)-p[i].times_x_minus_a(xArray_[i+k+1].x))/(xArray_[i+k+1].x-xArray_[i].x);
        }
    }
    return p[0];
}