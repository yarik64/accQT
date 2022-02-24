#include "main.h"
#include "mainwindow.h"

#include <QString>
#include <QSettings>
#include <QTextStream>

#include <iostream>


#define PATH_CATHEGORIES "/usr/share/alterator/desktop-directories/"
#define PATH_MODULES "/usr/share/alterator/applications/"



int main(int argc, char *argv[]) {

	// объявляем элементы
	QApplication app(argc, argv);
	MainWindow w;
	QTextStream os(stdout);

	QGridLayout *grid = new QGridLayout;
	grid->setMargin(5);
	grid->setSpacing(15);


	int row=0;
	for (QString cath : cathegories) {
		int col=0;

		QLabel *lcath = new QLabel;
		lcath->setText(cath);
		grid->addItem(*lcath, row++, col, 1, 1);

		for (AppButton *btn : app_buttons){
			if ( btn->getCath == cath ) {
				grid->addItem(btn, row, col++);
			}
		}
	}

	w.resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	w.setLayout(grid);
	w.show();
	return app.exec();

}

