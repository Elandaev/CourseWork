#include "math.h"
#include "iostream"
#include <vector>
using namespace std;

class Trial{
public:
    double x;
    double y;
    Trial() :x(0.0), y(0.0){}
    Trial(double a) {
        x = a;
        y = func(a);
    }
    Trial(double a, double b, int c) :x(a), y(b) {}
    Trial(const Trial &v) {
        x = v.x;
        y = v.y;
    }
    Trial& operator=(const Trial& v) {
        if (this == &v) {
            return *this;
        }
        x = v.x;
        y = v.y;
        return *this;
    }
    double func(double a);
    friend ostream& operator<<(ostream &out, const Trial &v);
};

double M(Trial a, Trial b);

double R(Trial a, Trial b, double m);

double NX(Trial a, Trial b, double m);

Trial CL(double a);

Trial SearchExtr(int a, int b);
