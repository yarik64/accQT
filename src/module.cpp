// module.cpp

#include <QString>
#include <QSettings>

#include "module.h"

Module::Module(){ }

void Module::load(QString path){
	QSettings settings(path, QSettings::IniFormat);
	settings.beginGroup("Desktop Entry");
	this->Name = settings.value("Name").toString();
	this->Icon = settings.value("Icon").toString();
	this->Cathegory = settings.value("Categories").toString();
	settings.endGroup();
}
