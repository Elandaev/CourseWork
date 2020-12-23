#include <include/SearchExtr.h>

double Trial::func(double a){
    return a * a;
}

std::ostream& operator<<(std::ostream &out, const Trial &v) {
        out << " x = " << v.x << "  y = " << v.y;
        return out;
}

double M(Trial a, Trial b) {
    double M = (b.y - a.y) / (b.x - a.x);
    if (M == 0.0) { return 1.0; }
    if (M < 0) { M = -M; }
    return 2.7 * M;
}

double R(Trial a, Trial b, double m) {
    double r = m * (b.x - a.x) + (((b.y - a.y) * (b.y - a.y)) / (m * (b.x - a.x))) - 2 * (b.y + a.y);
    return r;
}

double NX(Trial a, Trial b, double m) {
    double NX = (((b.x + a.x) / 2) - ((b.y - a.y) / m));
    return NX;
}

Trial CL(double a) {
    return Trial(a);
}

Trial SearchExtr(int a, int b){
    vector<double> ArM(100);
    ArM.clear();
    vector<double> ArR(100);
    ArR.clear();
    
    vector<Trial> A(2);
    A.clear();
    
    A.push_back(Trial(a));
    A.push_back(Trial(b));

    
    ArM.push_back(M(A[0], A[1]));
    ArR.push_back(R(A[0], A[1], ArM[0]));
    Trial c(NX(A[0], A[1], ArM[0]));
    A.insert(A.begin() + 1, c);
    int it = 0;
    double Epsilon = 2;
    while( it < 1000 && Epsilon > 0.02) {
        it++;
        int ArMsize = ArM.size();
        ArM.clear();


        for (int im = 0; im < ArMsize + 1; im++) {
            ArM.push_back(M(A[im], A[im + 1]));
        }
        double MaxM = ArM[0];
        int indexM = 0;
        for (int i = 1; i < ArM.size(); i++) {
            if (ArM[i] > MaxM) {
                MaxM = ArM[i];
                indexM = i;
            }
        }
        

        int ArRsize = ArR.size();
        ArR.clear();
        for (int ir = 0; ir < ArRsize + 1; ir++) {
            ArR.push_back(R(A[ir], A[ir + 1], MaxM));
        }
        
        double MaxR = ArR[0];
        int indexR = 0;
        for (int i = 1; i < ArR.size(); i++) {
            if (ArR[i] > MaxR) {
                MaxR = ArR[i];
                indexR = i;
            }
        }

        A.insert((A.begin() + (indexR+1)), CL(NX(A[indexR], A[indexR + 1], MaxM)));
        
        Epsilon = A[1].x - A[0].x;
        for (int i = 2; i < A.size(); i++) {
            if ((A[i].x - A[i - 1].x) < Epsilon)
                Epsilon = A[i].x - A[i - 1].x;
        }
    }
    Trial Best = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (A[i].y < Best.y) {
            Best = A[i];
        }
    }
    cout <<"it = " << it << '\n';
    return Best;
}
