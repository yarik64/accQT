// mainwindow.h

#ifndef ACCQT_MAINWINDOW_H
#define ACCQT_MAINWINDOW_H


#include <QMainWindow>

// headers
#include "accQT.h"

class MainWindow : public QMainWindow {

	Q_OBJECT

	public:
		MainWindow();
		~MainWindow();
		void setUI(AccQT *app);

	private:
		QString MenuStyle;

};
#endif // ACCQT_MAINWINDOW_H
