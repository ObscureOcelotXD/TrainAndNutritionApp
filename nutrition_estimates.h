#pragma once



struct NutritionValues {
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
};

class NutritionInfo {
public:
    NutritionValues nutritionLogic(double weight);  // Function prototype
};

//void displayNutrition();

