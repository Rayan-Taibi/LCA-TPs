#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Integral approximation using trapezoidal rule
float approxIntegral(const float a, const float b, const int nbIter)
{
    const float delta = (b - a) / nbIter;

    float sum = 0.f;

    for (int i = 1; i < nbIter; i++)
    {
        sum += sqrt(a + i * delta);
    }

    return delta * (sum + (sqrt(a) + sqrt(b)) * 0.5f);
}

int main()
{
    const int a = 0;
    const int b = 1;
    const int nbIter = 10;
    printf("Integral approximation of sqrt between %d and %d (%d iterations):\n", a, b, nbIter);
    printf("%f\n", approxIntegral(a, b, nbIter));

    return EXIT_SUCCESS;
}