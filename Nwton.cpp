#include "header.h"



using namespace std;



double NewtonRaphsonStudent::NewtonRaphson(func Function, func Derivative, double start, double accu)

{

    double h=Function(start)/Derivative(start);

    while(abs(h)>=accu)

    {

        h=Function(start)/Derivative(start);

        start=start-h;

    }

    return start;



}


