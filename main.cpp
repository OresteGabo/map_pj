/*#include <QApplication>
#include <QPushButton>
//#include <QMapControl/mapcontrol.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}*/

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include "Widget.h"
#include<iostream>
#include<vector>
using std::vector;
int main(int argc, char *argv[]) {
    QApplication qApplication(argc, argv);  // Create the QApplication instance





    auto app= App();
    Widget w(app);
    w.show();

    return qApplication.exec();  // Start the application event loop

}