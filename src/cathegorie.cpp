// cathegorie.cpp

#include <QString>
#include <QSettings>

#include "cathegorie.h"

Cathegorie::Cathegorie(){ }

void Cathegorie::load(QString path){
	QSettings settings(path, QSettings::IniFormat);
	settings.beginGroup("Desktop Entry");
	this->Name = settings.value("Name").toString();
	this->Icon = settings.value("Icon").toString();
	this->Cathegory = settings.value("Categories").toString();
	settings.endGroup();
}

QString Cathegorie::getName() {
	return this->Name;
}

QString Cathegorie::getIcon() {
	return this->Icon;
}

QString Cathegorie::getCathegory() {
	return this->Cathegory;
}

