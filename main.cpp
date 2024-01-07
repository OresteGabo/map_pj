

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