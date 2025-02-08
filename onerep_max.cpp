#include <iostream>
#include <iomanip>
#include "onerep_max.h"

double numberOfReps = 0;
double oneRepMax = 0.0;

int formula = 0;
int calculationChoice = 0;

std::string formulaName = "";

double OneRepMax::oneRepMaxLogic(double weight,int numberOfReps,int formula) {

    switch (formula) {
    case 1:
        oneRepMax = weight * (36 / (37 - numberOfReps));
        formulaName = "Bryzcki Formula";
        break;
    case 2:
        oneRepMax = weight * (1 + (0.0333 * numberOfReps));
        formulaName = "Epley Formula";
        break;
    case 3:
        oneRepMax = weight * (pow(numberOfReps, 0.1));
        formulaName = "Lombardi Formula";
        break;
    case 4:
        oneRepMax = weight * (1 + (0.025 * numberOfReps));
        formulaName = "O'Conner Formula";
        break;
    }
    return oneRepMax;
}