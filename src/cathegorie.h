// cathegorie.h

#ifndef ACCQT_CATHEGORIE_H
#define ACCQT_CATHEGORIE_H

#include <QString>
#include <QSettings>

 
class Cathegorie {

	public:
		Cathegorie();
		void load(QString path);
		QString getName();
		QString getIcon();
		QString getCathegory();

	private:
		QString Name;
		QString Icon;
		QString Cathegory;

};
#endif // ACCQT_CATHEGORIE_H

