// proto.cpp

#include <QString>
#include <QStringList>
#include <QSettings>

#include "proto.h"

Proto::Proto(){ }

void Proto::load(QString path, QStringList *fields ){
	QSettings settings(path, QSettings::IniFormat);
	settings.beginGroup("Desktop Entry");

	for (QString i : *fields) {
		Property.insert(i, settings.value(i).toString());
	}

	settings.endGroup();
}

QString Proto::getAttr(QString *attr) {
	return Property[*attr];
}

