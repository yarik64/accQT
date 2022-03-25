// module.h

#ifndef ACCQT_MODULE_H
#define ACCQT_MODULE_H

#include <QString>
#include <QSettings>


class Module {

	public:
		Module();
		void load(QString path);
		QString getName();
		QString getIcon();
		QString getCathegory();

	private:
		QString Name;
		QString Icon;
		QString Cathegory;

};
#endif // ACCQT_MODULE_H

