// proto.h

#ifndef ACCQT_CATHEGORIE_H
#define ACCQT_CATHEGORIE_H

#include <QString>
#include <QSettings>

 
class Proto {

	public:
		Proto();
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

