// mainwindow.cpp

#include <QWidget>
#include <QString>
#include <QTextStream>

#include "mainwindow.h"
#include "appfield.h"

#define WIDTH 800
#define HEIGHT 600


MainWindow::MainWindow() {}

MainWindow::~MainWindow() {}

void MainWindow::setUI(AccQT *app) {
	AppField *field =  new AppField(this);

	field->loadCathegories(
			app->getCathegories(),
			app->getModules()
			);

	setCentralWidget(field);
	resize(WIDTH, HEIGHT);

}
