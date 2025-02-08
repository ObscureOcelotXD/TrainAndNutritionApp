#include "TrainAndNutritionApp.h"
#include "ui_TrainAndNutritionApp.h"
#include "onerep_max.h"
#include "nutrition_estimates.h"
#include <QInputDialog>  
#include <QMessageBox>

TrainAndNutritionApp::TrainAndNutritionApp(QWidget *parent)
    : QMainWindow(parent), ui (new Ui::TrainAndNutritionApp)

{
    ui->setupUi(this);

    //connect(ui->button1, &QPushButton::clicked, this, &TrainAndNutritionApp::on_button1_clicked);
    //connect(ui->button2, &QPushButton::clicked, this, &TrainAndNutritionApp::on_button2_clicked);
}

TrainAndNutritionApp::~TrainAndNutritionApp()
{
    delete ui;
}

void TrainAndNutritionApp::on_button1_clicked()
{
    OneRepMax oneRepMax;

    // Step 1: Get user input
    bool ok;
    double weight = QInputDialog::getDouble(
        this,
        "Input",
        "Enter weight (lb):",
        0.0,  // Default value
        0.0,  // Minimum value
        1000.0, // Maximum value
        2,    // Decimal places
        &ok
    );

    if (!ok) {
        // User pressed "Cancel"
        return;
    }


    // Get SECOND input (e.g., reps)
    bool ok2;
    int reps = QInputDialog::getInt(
        this,
        "Input",
        "Enter number of reps:",
        1,  // Default value
        1,  // Min value
        20, // Max value
        1,  // Step
        &ok2
    );
    if (!ok2) return;  // User canceled


    // Get Exercise Type (1-4)
    bool okFormula;
    int formula = QInputDialog::getInt(
        this, "Select Calculation Method:",
        "Select Calculation Method: (1-4):\n"
        "1: Bryzcki Formula\n"
        "2: Epley Formula\n"
        "3: Lombardi Formula\n"
        "4: O'Conner Formula",
        1,  // Default value
        1,  // Minimum
        4,  // Maximum
        1,  // Step
        &okFormula
    );
    if (!okFormula) return;


    double oneRepMaxValue = oneRepMax.oneRepMaxLogic(weight,reps,formula);

    // Display Result
    QMessageBox::information(
        this, "Result",
        QString("Weight: %1 Lb\nReps: %2\n Formula: %3\nOne-Rep Max: %4 Lb")
        .arg(weight, 0, 'f', 2)
        .arg(reps)
        .arg(formula)
        .arg(oneRepMaxValue, 0, 'f', 2)
    );
}

void TrainAndNutritionApp::on_button2_clicked()
{

    NutritionInfo nutritionInfo;

    // Step 1: Get user input
    bool ok;
    double weight = QInputDialog::getDouble(
        this,
        "Input",
        "Enter Your weight (lb):",
        0.0,  // Default value
        0.0,  // Minimum value
        1000.0, // Maximum value
        2,    // Decimal places
        &ok
    );

    if (!ok) {
        // User pressed "Cancel"
        return;
    }

    NutritionValues values = nutritionInfo.nutritionLogic(weight);

    // Initialize table
    QTableWidget* table = ui->nutritionTable;
    table->clear();

    // Configure table
    table->setRowCount(4);
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({ "Protein (g)", "Carbs (g)", "Fats (g)", "Calories" });
    table->setVerticalHeaderLabels({ "", "Bulking", "Leaning Out", "Maintain" });

    // Style headers
    table->horizontalHeader()->setStyleSheet("QHeaderView::section { font-weight: bold; }");
    table->verticalHeader()->setStyleSheet("QHeaderView::section { font-weight: bold; }");

    table->setItem(1, 0, new QTableWidgetItem(QString("%1 - %2").arg(values.protienGainLow).arg(values.protienGainHigh)));
    table->setItem(1, 1, new QTableWidgetItem(QString("%1 - %2").arg(values.carbsGainLow).arg(values.carbsGainHigh)));
    table->setItem(1, 2, new QTableWidgetItem(QString("%1 - %2").arg(values.fatsGainLow).arg(values.fatsGainHigh)));
    table->setItem(1, 3, new QTableWidgetItem(QString("%1 - %2").arg(values.caloriesGainLow).arg(values.caloriesGainHigh)));

    table->setItem(2, 0, new QTableWidgetItem(QString("%1 - %2").arg(values.protienFatLossLow).arg(values.protienFatLossHigh)));
    table->setItem(2, 1, new QTableWidgetItem(QString("%1 - %2").arg(values.carbsFatLossLow).arg(values.carbsFatLossHigh)));
    table->setItem(2, 2, new QTableWidgetItem(QString("%1 - %2").arg(values.fatsFatLossLow).arg(values.fatsFatLossHigh)));
    table->setItem(2, 3, new QTableWidgetItem(QString("%1 - %2").arg(values.caloriesFatLossLow).arg(values.caloriesFatLossHigh)));

    table->setItem(3, 0, new QTableWidgetItem(QString("%1 - %2").arg(values.protienMaintenenceLow).arg(values.protienMaintenenceHigh)));
    table->setItem(3, 1, new QTableWidgetItem(QString("%1 - %2").arg(values.carbsMaintenenceLow).arg(values.carbsMaintenenceHigh)));
    table->setItem(3, 2, new QTableWidgetItem(QString("%1 - %2").arg(values.fatsMaintenenceLow).arg(values.fatsMaintenenceHigh)));
    table->setItem(3, 3, new QTableWidgetItem(QString("%1 - %2").arg(values.caloriesMaintainLow).arg(values.caloriesMaintainHigh)));

    table->resizeColumnsToContents();
}