#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
                              //TODO rename file
#include <TXLib.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

const double EPSIL = 0.000001;

const int    NMAS = 3;


int     ToCompare             (double a, double b);

int     SolveLin              (double b, double c, double* x1);

int     SolveSquare           (double a, double b, double c, double* x1, double* x2);

void    zapisChisl            (double* a, double* b, double* c, int* schprob, int schrazrad, double chsl);

void    OutputAns             (struct roots Ans);

void    InputCoefs            (struct coeffs* coef);

int     VerificationOfAnsvers (int num_tests);

roots   FullSolveQuad         (double a, double b, double c);

int     CountNumberOfTests    (char num);

struct coeffs {
        double a;
        double b;
        double c;
};

struct roots  {
        double x1;
        double x2;
        int    num_roots;
};

struct verif  {
        double a;
        double b;
        double c;
        double x1;
        double x2;
        int    n_Roots;
};


#endif // FUNCTIONS_H_INCLUDED
