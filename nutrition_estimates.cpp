#include <iostream>
#include <iomanip>
#include "nutrition_estimates.h"

static double weight = 0;

double protienGainLow = 0;
double protienGainHigh = 0;
double protienFatLossLow = 0;
double protienFatLossHigh = 0;
double protienMaintenenceLow = 0;
double protienMaintenenceHigh = 0;

double carbsGainLow = 0;
double carbsGainHigh = 0;
double carbsFatLossLow = 0;
double carbsFatLossHigh = 0;
double carbsMaintenenceLow = 0;
double carbsMaintenenceHigh = 0;

double fatsGainLow = 0;
double fatsGainHigh = 0;
double fatsFatLossLow = 0;
double fatsFatLossHigh = 0;
double fatsMaintenenceLow = 0;
double fatsMaintenenceHigh = 0;

double caloriesGainLow = 0;
double caloriesGainHigh = 0;
double caloriesFatLossLow = 0;
double caloriesFatLossHigh = 0;
double caloriesMaintainLow = 0;
double caloriesMaintainHigh = 0;

void nutritionLogic() {

    std::cout << "Enter Weight in lb \n";
    std::cin >> weight;

    protienGainLow = weight * (0.7);
    protienGainHigh = weight * (1.0);

    protienFatLossLow = weight * (0.9);
    protienFatLossHigh = weight * (1.4);

    protienMaintenenceLow = weight * (0.5);
    protienMaintenenceHigh = weight * (0.7);

    //bulking
    carbsGainLow = weight * (1.8);
    carbsGainHigh = weight * (2.7);

    //lean out
    carbsFatLossLow = weight * (0.9);
    carbsFatLossHigh = weight * (1.8);

    //maintain
    carbsMaintenenceLow = weight * (1.4);
    carbsMaintenenceHigh = weight * (2.3);


    //bulking
    fatsGainLow = weight * (0.35);
    fatsGainHigh = weight * (0.55);

    //lean out
    fatsFatLossLow = weight * (0.25);
    fatsFatLossHigh = weight * (0.45);

    //maintain
    fatsMaintenenceLow = weight * (0.35);
    fatsMaintenenceHigh = weight * (0.45);

    //bulking
    caloriesGainLow = (protienGainLow * 4) + (carbsGainLow * 4) + (fatsGainLow * 9);
    caloriesGainHigh = (protienGainHigh * 4) + (carbsGainHigh * 4) + (fatsGainHigh * 9);

    //leanout
    caloriesFatLossLow = (protienFatLossLow * 4) + (carbsFatLossLow * 4) + (fatsFatLossLow * 9);
    caloriesFatLossHigh = (protienFatLossHigh * 4) + (carbsFatLossHigh * 4) + (fatsFatLossHigh * 9);

    //maintain
    caloriesMaintainLow = (protienMaintenenceLow * 4) + (carbsMaintenenceLow * 4) + (fatsMaintenenceLow * 9);
    caloriesMaintainHigh = (protienMaintenenceHigh * 4) + (carbsMaintenenceHigh * 4) + (fatsMaintenenceHigh * 9);

    std::cout << "To gain muscle (Bulking) you should consume between: " << protienGainLow << " and " << protienGainHigh << " grams of protien. \n";
    std::cout << "To gain muscle (Bulking) you should consume between: " << carbsGainLow << " and " << carbsGainHigh << " grams of carbs. \n";
    std::cout << "To gain muscle (Bulking) you should consume between: " << fatsGainLow << " and " << fatsGainHigh << " grams of fats. \n";
    std::cout << "To gain muscle (Bulking) calories should be between: " << caloriesGainLow << " - " << caloriesGainHigh << " kcal. \n\n";

    std::cout << "To achive fat loss and maintain (Lean Out) you should consume between: " << protienFatLossLow << " and " << protienFatLossHigh << " grams of protien. \n";
    std::cout << "To achive fat loss and maintain (Lean Out) you should consume between: " << carbsFatLossLow << " and " << carbsFatLossHigh << " grams of carbs. \n";
    std::cout << "To achive fat loss and maintain (Lean Out) you should consume between: " << fatsFatLossLow << " and " << fatsFatLossHigh << " grams of fats. \n";
    std::cout << "To achive fat loss and maintain (Lean Out) calories should be between: " << caloriesFatLossLow << " - " << caloriesFatLossHigh << " kcal. \n\n";

    std::cout << "To maintain muscle you should consume between: " << protienMaintenenceLow << " and " << protienMaintenenceHigh << " grams of protien. \n";
    std::cout << "To maintain muscle you should consume between: " << carbsMaintenenceLow << " and " << carbsMaintenenceHigh << " grams of carbs. \n";
    std::cout << "To maintain muscle you should consume between: " << fatsMaintenenceLow << " and " << fatsMaintenenceHigh << " grams of fats. \n";
    std::cout << "To maintain muscle calories should be between: " << caloriesMaintainLow << " - " << caloriesMaintainHigh << " kcal. \n\n";

    displayNutrition();

}

void displayNutrition() {

    std::cout << "\nNutrition Table for " << weight << " lbs\n";
    std::cout << std::left
        << std::setw(15) << "Goal"
        << std::setw(15) << "Protein (g)"
        << std::setw(15) << "Carbs (g)"
        << std::setw(15) << "Fats (g)"
        << std::setw(20) << "Calories (kcal)"
        << std::endl;

    std::cout << std::string(80, '-') << std::endl;

    std::cout << std::left
        << std::setw(15) << "Muscle Gain"
        << std::setw(3) << protienGainLow << std::setw(1) << "-" << std::setw(11) << protienGainHigh
        << carbsGainLow << std::setw(1) << "-" << std::setw(5) << std::setw(11) << carbsGainHigh
        << fatsGainLow << std::setw(1) << "-" << std::setw(12) << fatsGainHigh
        << caloriesGainLow << "-" << caloriesGainHigh
        << std::endl;

    std::cout << std::left
        << std::setw(15) << "Lean Out"
        << std::setw(3) << protienFatLossLow << std::setw(1) << "-" << std::setw(11) << protienFatLossHigh
        << carbsFatLossLow << std::setw(1) << "-" << std::setw(5) << std::setw(11) << carbsFatLossHigh
        << fatsFatLossLow << std::setw(1) << "-" << std::setw(12) << fatsFatLossHigh
        << caloriesFatLossLow << "-" << caloriesFatLossHigh
        << std::endl;

    std::cout << std::left
        << std::setw(15) << "Maintain"
        << std::setw(3) << protienMaintenenceLow << std::setw(1) << "-" << std::setw(11) << protienMaintenenceHigh
        << carbsMaintenenceLow << std::setw(1) << "-" << std::setw(5) << std::setw(11) << carbsMaintenenceHigh
        << fatsMaintenenceLow << std::setw(1) << "-" << std::setw(12) << fatsMaintenenceHigh
        << caloriesMaintainLow << "-" << caloriesMaintainHigh
        << std::endl;

}
