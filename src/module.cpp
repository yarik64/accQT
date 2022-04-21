// module.cpp

#include <QString>
#include <QSettings>

#include "module.h"

Module::Module(){ }

void Module::load(QString path){
	QSettings settings(path, QSettings::IniFormat);
	settings.beginGroup("Desktop Entry");
	Name = settings.value("Name").toString();
	Icon = settings.value("Icon").toString();
	Cathegory = settings.value("Categories").toString();
	settings.endGroup();
}

QString Module::getName() {
	return Name;
}

QString Module::getIcon() {
	return Icon;
}

QString Module::getCathegory() {
	return Cathegory;
}

