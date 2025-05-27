//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//// Function to integrate: f(x) = e^(-x^2) * sin(x) + ln(x + 2)
//double complexFunction(double x) {
//    return exp(-x * x) * sin(x) + log(x + 2);
//}
//
//// Simpson’s Rule for numerical integration
//double simpsonsRule(double a, double b, int n) {
//    if (n % 2 != 0) {
//        cerr << "Number of intervals must be even for Simpson's Rule." << endl;
//        return NAN;
//    }
//
//    double h = (b - a) / n;
//    double result = complexFunction(a) + complexFunction(b);
//
//    for (int i = 1; i < n; ++i) {
//        double x = a + i * h;
//        result += (i % 2 == 0 ? 2 : 4) * complexFunction(x);
//    }
//
//    result *= h / 3.0;
//    return result;
//}
//
//int main() {
//    double a = 0.0;
//    double b = 5.0;
//    int n = 1000000; // large number of subintervals for complexity
//
//    cout << "Integrating f(x) = e^(-x^2) * sin(x) + ln(x+2) from " << a << " to " << b << "..." << endl;
//
//    double result = simpsonsRule(a, b, n);
//
//    cout.precision(10);
//    cout << "Result of integration: " << result << endl;
//
//    return 0;
//}
