// proto.h

#ifndef ACCQT_PROTO_H
#define ACCQT_PROTO_H

#include <QString>
#include <QSettings>

 
class Proto {

	public:
		Proto();
		void load(QString path, QStringList *fields );
		QString getAttr(QString *attr);

	private:
		QHash<QString, QString> Property;

};
#endif // ACCQT_PROTO_H

