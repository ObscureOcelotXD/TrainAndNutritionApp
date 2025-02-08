#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TrainAndNutritionApp.h"
#include "onerep_max.h"
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class TrainAndNutritionApp; }  
QT_END_NAMESPACE

class TrainAndNutritionApp : public QMainWindow
{
    Q_OBJECT

public:
    TrainAndNutritionApp(QWidget* parent = nullptr);
    ~TrainAndNutritionApp();


private slots:
    void on_button1_clicked();
    void on_button2_clicked();

private:
    Ui::TrainAndNutritionApp *ui;

};
