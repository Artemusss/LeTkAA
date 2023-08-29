#ifndef DEFAULT_H_INCLUDED
#define DEFAULT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

const double EPSIL = 0.000001;

const int    NMAS = 3;

int     ToCompare             (double a, double b);

int     SolveLin              (double b, double c, double* x1);

int     SolveSquare           (double a, double b, double c, double* x1, double* x2 );

void    zapisChisl            (double* a, double* b, double* c, int* schprob, int schrazrad, double chsl);

void    OutputAns             (struct roots Ans);

void    InputCoefs            (struct coeffs* coef);

int     VerificationOfAnsvers (int num_tests);

struct roots FullSolveQuad(double a, double b, double c);

struct coeffs {
        double a;
        double b;
        double c;
};

struct roots {
        double x1;
        double x2;
        int    num_roots;
};

struct verif {
        double a;
        double b;
        double c;
        double x1;
        double x2;
        int    n_Roots;
};


#endif // DEFAULT_H_INCLUDED
