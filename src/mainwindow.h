// mainwindow.h

#ifndef ACCQT_MAINWINDOW_H
#define ACCQT_MAINWINDOW_H


#include <QMainWindow>

// headers
#include "accQT.h"

class MainWindow : public QMainWindow {

	public:
		MainWindow();
		~MainWindow();
		void setUI(AccQT *app);

	private:

};
#endif // ACCQT_MAINWINDOW_H
