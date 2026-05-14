#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Integral approximation using trapezoidal rule
double approxIntegral(const double a, const double b, const int nbIter , double(*f)(double) )
{
    const double delta = (b - a) / nbIter;

    double sum = 0.0;

        //f(a + i * delta) est une expression qui calcule la valeur de la fonction f à un point spécifique dans l'intervalle [a, b] == f(xi)

    for (int i = 1; i < nbIter; i++)
    {
        sum += f(a + i * delta);
    }

    return delta * (f(a) + 2.0 * sum + f(b)) / 2.0;
}

int main()
{
    const double a = 0;
    const double b = 1;
    const int nbIter = 10;
    printf("Integral approximation of sqrt between %f and %f (%d iterations):\n", a, b, nbIter);
    printf("%f\n", approxIntegral(a, b, nbIter,sqrt));

    return EXIT_SUCCESS;
}