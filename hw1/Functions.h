double B1(double x)
{
    return (1.0/x)-tan(x);
}
double B2(double x)
{
    return 1.0/x-pow(2,x);
}
double B3(double x)
{
    return pow(2,-x)+exp(x)+2*cos(x)-6;
}
double B4(double x)
{
    return (x*x*x+4*x*x+3*x+5)/(2*x*x*x-9*x*x+18*x-2);
}
double C(double x)
{
    return x-tan(x);
}
double C_diff(double x)
{
    return 1-1/(cos(x)*cos(x));
}
double D1(double x)
{
    return sin(x/2)-1;
}
double D2(double x)
{
    return exp(x)-tan(x);
}
double D3(double x)
{
    return x*x*x-12*x*x+3*x+1;
}
double E(double x)
{
    return 12.4-10*(0.5*M_PI-asin(x)-x*sqrt(1-x*x));
}
double E_diff(double x)
{
    return 20*sqrt(1-x*x);
}
double Fa(double x)
{
    double beta = 11.5/180*M_PI;
    double l = 89;
    double h = 49;
    double D = 55;
    double part1 = l*sin(beta)*sin(x)*cos(x)+l*cos(beta)*sin(x)*sin(x);
    double part2 = ((h+0.5*D)*sin(beta)-0.5*D*tan(beta))*cos(x);
    double part3 = ((h+0.5*D)*cos(beta)-0.5*D)*sin(x);
    return part1-part2-part3;
}
double Fa_diff(double x)
{
    double beta = 11.5/360*2*M_PI;
    double l = 89;
    double h = 49;
    double D = 55;
    double part1 = l*sin(beta)*cos(2*x)+l*cos(beta)*sin(2*x);
    double part2 = ((h+0.5*D)*sin(beta)-0.5*D*tan(beta))*-sin(x);
    double part3 = ((h+0.5*D)*cos(beta)-0.5*D)*cos(x);
    return part1-part2-part3;
}
double Fb(double x)
{
    double beta = 11.5/360*2*M_PI;
    double l = 89;
    double h = 49;
    double D = 30;
    double part1 = l*sin(beta)*sin(x)*cos(x)+l*cos(beta)*sin(x)*sin(x);
    double part2 = ((h+0.5*D)*sin(beta)-0.5*D*tan(beta))*cos(x);
    double part3 = ((h+0.5*D)*cos(beta)-0.5*D)*sin(x);
    return part1-part2-part3;
}
double Fb_diff(double x)
{
    double beta = 11.5/360*2*M_PI;
    double l = 89;
    double h = 49;
    double D = 30;
    double part1 = l*sin(beta)*cos(2*x)+l*cos(beta)*sin(2*x);
    double part2 = ((h+0.5*D)*sin(beta)-0.5*D*tan(beta))*-sin(x);
    double part3 = ((h+0.5*D)*cos(beta)-0.5*D)*cos(x);
    return part1-part2-part3;
}