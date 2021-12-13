#include <include/SearchExtr.h>

double SearchExtrFinally(const double x1, const double x2, double (*fcnPtr)(double),
                                    double epsilon, double r) {
    if (x1 == x2)
        throw "The intervals should be different";

    // Step 1
    std::vector<double> X;
    X.push_back(x1);
    X.push_back(x2);

    while (1) {
        // Step 2
        std::sort(X.begin(), X.end());

        // Step 3
        double maxlk;
        double Lk;
        double templk;
        for (int i = 0; i < static_cast<int>(X.size()) - 1; ++i) {
            templk = (std::abs(fcnPtr(X.at(i + 1)) - fcnPtr(X.at(i)))) / (X.at(i + 1) - X.at(i));
            if (i == 0)
                maxlk = templk;
            else
                maxlk = maxlk < templk ? templk : maxlk;
        }
        Lk = maxlk == 0 ? 1.0 : r * maxlk;

        // Step 4
        int Rt = 0;
        double minRi;
        double tempRi;
        for (int i = 0; i < static_cast<int>(X.size()) - 1; ++i) {
            tempRi = ((fcnPtr(X.at(i)) + fcnPtr(X.at(i + 1))) / 2) -
                            ((1 + pow((((fcnPtr(X.at(i + 1)) - fcnPtr(X.at(i))) / (X.at(i + 1) -
                                    X.at(i))) / Lk), 2)) / 2) * Lk * ((X.at(i + 1) - X.at(i)) / 2);
            if (i == 0) {
                minRi = tempRi;
            } else {
                if (minRi > tempRi) {
                    minRi = tempRi;
                    Rt = i;
                }
            }
        }

        // Step 5
        if (X.at(Rt + 1) - X.at(Rt) <= epsilon) {
            return X.at(Rt + 1);
        }

        // Step 6
        X.push_back((X.at(Rt) + X.at(Rt + 1)) / 2 - (fcnPtr(X.at(Rt + 1)) - fcnPtr(X.at(Rt))) / (2 * Lk));
    }
}
