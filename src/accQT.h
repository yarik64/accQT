// accQT.h

#ifndef ACCQT_ACCQT_H
#define ACCQT_ACCQT_H

#include <QApplication>


// containers
#include <QList>
#include <QString>

// headers
#include "module.h"
#include "cathegorie.h"


class AccQT : public QApplication {

	public:
        AccQT(int argc, char *argv[]);
		~AccQT();
		void loadUI();
		void loadModules();
		void loadCathegories();

		QList<Module>     getModules();
		QList<Cathegorie> getCathegories();

	private:
		QList<Module>     modules;
		QList<Cathegorie> cathegories;

};
#endif // ACCQT_ACCQT_H

