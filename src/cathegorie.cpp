// cathegorie.cpp

#include <QString>
#include <QSettings>

#include "cathegorie.h"

Cathegorie::Cathegorie(){ }

void Cathegorie::load(QString path){
	QSettings settings(path, QSettings::IniFormat);
	settings.beginGroup("Desktop Entry");
	Name = settings.value("Name").toString();
	Icon = settings.value("Icon").toString();
	Cathegory = settings.value("X-Alterator-Category").toString();
	settings.endGroup();
}

QString Cathegorie::getName() {
	return Name;
}

QString Cathegorie::getIcon() {
	return Icon;
}

QString Cathegorie::getCathegory() {
	return Cathegory;
}

