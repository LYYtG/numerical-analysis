/**
 * @file Value.hpp
 * @author 李杨野 (1300096763@qq.com 3190103519@zju.edu.cn)
 * @brief a subclass used in program.
 * @version 0.1
 * @date 2021-10-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>
using namespace std;
class value
{
public:
    double x;
    vector<double> fx;
    value(double _x,double _fx){
        x = _x;
        fx.push_back(_fx);
    }
};
