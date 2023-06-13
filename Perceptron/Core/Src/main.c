#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int Ninput;
    double *weights;
    double threshold;
} Perceptron;

double guess(Perceptron p, double *input) {
    double res = 0.0;
    for (int i = 0; i < p.Ninput; i++) {
        res += p.weights[i] * input[i];
    }
    res += p.threshold;
    return (res >= 0) ? 1.0 : 0.0;
}

double result(Perceptron *p, double eta, double truevalue, double *input) {
    double prediction = guess(*p, input);
    double err = truevalue - prediction;
    for (int i = 0; i < p->Ninput; i++) {
        p->weights[i] += eta * err * input[i];
    }
    p->threshold += eta * err;
    return err;
}

void generatePerceptron(Perceptron *p, int size) {
    p->Ninput = size;
    p->weights = (double *)malloc(size * sizeof(double));
    p->threshold = ((float)(rand() % 100)) / 100;
    for (int i = 0; i < size; i++) {
        p->weights[i] = ((float)(rand() % 100)) / 100;
    }
}

int main(void) {
    srand(time(NULL));
    Perceptron A;
    generatePerceptron(&A, 2);

    while (1) {
        double array[2];
        for (int i = 0; i < 2; i++) {
            array[i] = rand() % 100;
        }
        double B = (array[0] != array[1]) ? 1 : 0;
        result(&A, 0.2, B, array);
    }

    return 0;
}
