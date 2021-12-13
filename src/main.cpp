#include <include/SearchExtr.h>
using namespace std;

double Function (double x) {
    return (x*x);
}

double Function2 (double x) {
    return sin(x);
}

double Function3 (double x) {
    return sin(x) * cos(x);
}

double Function4 (double x) {
    return 3*pow(2.7182818, -2*x) * (cos(x) + sin(x));
}

int main(){
    //func1 y = x^2
    double (*fcnPtr)(double) = Function;
    double Result = SearchExtrFinally(-5, 2, Function, 1e-3, 2);
    cout << "expected: x = 0, y = 0" << '\n';
    cout << "x: " << Result << '\n' << "y: " << Function(Result) << '\n' << endl;
    
    //func2: y = sin(x)
    double (*fcnPtr2)(double) = Function2;
    cout << "expected: x = -1.54, y = -0.99" << '\n';
    double Result2 = SearchExtrFinally(-8, 4, Function2, 1e-3, 2);
    cout << "x: " << Result2 << '\n' << "y: " << Function2(Result2) << '\n' << endl;
    
    //func3: y = sin(x) * cos(x)
    double (*fcnPtr3)(double) = Function3;
    cout << "expected: x = 8.62, y = -0.4999" << '\n';
    double Result3 = SearchExtrFinally(3, 11, Function3, 1e-3, 2);
    cout << "x: " << Result3 << '\n' << "y: " << Function3(Result3) << '\n' << endl;
    
    //func4: Damping sine wave
    double (*fcnPtr4)(double) = Function4;
    cout << "expected: x = -3.464288, y = -1934.233" << '\n';
    double Result4 = SearchExtrFinally(-4, 2, Function4, 1e-3, 2);
    cout << "x: " << Result4 << '\n' << "y: " << Function4(Result4) << '\n' << endl;
    
    return 0;

}
