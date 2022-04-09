// mainwindow.cpp

#include <QWidget>
#include <QString>

#include "mainwindow.h"
#include "appfield.h"

#define WIDTH 800
#define HEIGHT 600


MainWindow::MainWindow() { }

MainWindow::~MainWindow() {
	delete this;
}

void MainWindow::setUI(AccQT *app) {
    AppField *field =  new AppField(this);

/*
    field->loadCathegories(
            app->getCathegories()
            );
    field->loadModules(
            app->getModules()
            );
*/
    this->setCentralWidget(field);
    this->resize(WIDTH, HEIGHT);

}
