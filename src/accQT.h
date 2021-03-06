// accQT.h

#ifndef ACCQT_ACCQT_H
#define ACCQT_ACCQT_H

#include <QApplication>


// containers
#include <QList>
#include <QString>

// headers
#include "proto.h"


class AccQT : public QApplication {

	Q_OBJECT

	public:
		AccQT(int argc, char **argv);
		~AccQT();

		void loadUI();
		void loadModules();
		void loadCathegories();

		QList<Proto> getModules();
		QList<Proto> getCathegories();

	private:
	void load (QString *path, QList<Proto> *target);

		QList<Proto>   modules;
		QList<Proto>   cathegories;

		QStringList    fields;
		QStringList    filters;

		QString        PathToCathegories;
		QString        PathToModules;

};
#endif // ACCQT_ACCQT_H

