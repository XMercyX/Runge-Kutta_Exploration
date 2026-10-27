#include <iostream>
#include <cmath>

// 2^x function
double real_function (double T) {
    // y0 = 1
    return pow(2,T);
}

double derivative(double tn) {
    double H = pow(10,-7);
    return (real_function(tn + H) - real_function(tn - H))/ (2 * H);
}

//Runge-Kutta Methods Exploration
int main(){ 
    /*
    dy/dt = f(t,y)
    y(t_0) = y_0

    "y" = a certain function (scalar or vector)
    "t" = time

    "h" = arbitrary step size > 0
    */
    double h; // Step size

    double t = 0;
    double y = 0;

    std::cout << "Define h << "; std::cin >> h;
    if (h <= 0){
        // if "h" is negative or zero, end the program.
        return 1;
    }

    double time_step = 0.00167;
    for (double i = 0; i < 100; i += time_step){
        y = y + (h/6)*(
            (derivative(t)) + 
            (2* (derivative(t))) + 
            (2*(derivative(t))) + 
            (derivative(t))
        );
        t = t + h;

        std::cout << "T: " << t << " / Y: " << y << '\n';
    }
    

    return 0;
}