// accQT.cpp

// headers
#include "accQT.h"
#include "mainwindow.h"
#include "proto.h"

// Qt widgets
#include <QMainWindow>

// conrainers
#include <QList>

// Qt classes
#include <QDir>
#include <QString>
#include <QFileInfoList>
#include <QDebug>

#include <QTextStream>

// #define PATH_APPS "/usr/share/alterator/applications/"
// #define PATH_CATH "/usr/share/alterator/desktop-directories/"

AccQT::AccQT(int argc, char **argv): QApplication(argc, argv) {
	PathToCathegories	= "/usr/share/alterator/applications/";         //PATH_CATH;
	PathToModules		= "/usr/share/alterator/desktop-directories/";  //PATH_APPS;
	fields				<< "Name" << "Icon" << "Categories" << "X-Alterator-Category";
	filters				<< "*.desktop" << "*.directory";

	loadModules();
	loadCathegories();
	loadUI();
}


AccQT::~AccQT() {}


void AccQT::loadUI() {
	QList<Proto> *trg = new QList<Proto>;
	load(&PathToModules, trg);

	MainWindow *w = new MainWindow;
	w->setUI(this);
	w->show();
}


void AccQT::load (QString *path, QList<Proto> *target) {
	QDir dir(*path);
	dir.setNameFilters(filters);

	for (QFileInfo i : dir.entryInfoList()) {
		Proto *cur_proto = new Proto;
		cur_proto->load(i.absoluteFilePath(), &fields);
		*target << *cur_proto;
	}
}


void AccQT::loadModules() {
	load(&PathToModules, &modules);
}


void AccQT::loadCathegories() {
	load(&PathToCathegories, &cathegories);
}


QList<Proto> AccQT::getModules() {
	return modules;
}


QList<Proto> AccQT::getCathegories() {
	return cathegories;
}

