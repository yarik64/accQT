#include <iostream>

#include "appfield.h"
#include "applications.h"
#include "mainwindow.h"


int main(int argc, char* argv[]){
	QApplication app(argc, argv);
	MainWindow w;

	w.show();
	return app.exec();
}
