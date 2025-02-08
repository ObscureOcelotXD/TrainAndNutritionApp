#include "TrainAndNutritionApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrainAndNutritionApp w;
    w.show();
    return a.exec();
}
