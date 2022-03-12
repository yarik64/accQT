// mainwindow.cpp

#include <QWidget>

#define WIDTH 800
#define HEIGHT 600


MainWindow::MainWindow(){
	AppField *field =  new AppField;
	this->setLaout(field);
	this->resize(WIDTH, HEIGHT);
}

MainWindow::MainWindow() {
	delete this;
}
