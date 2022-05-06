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

#define PATH_APPS "/usr/share/alterator/applications/"
#define PATH_CATH "/usr/share/alterator/desktop-directories/"

AccQT::AccQT(int argc, char **argv): QApplication(argc, argv) {
	loadModules();
	loadCathegories();
	loadUI();
}


AccQT::~AccQT() {}


void AccQT::loadUI() {
	QString *pth = new QString(PATH_APPS);
	QList<Proto> *trg = new QList<Proto>;
	load(pth, trg);

	MainWindow *w = new MainWindow;
	w->setUI(this);
	w->show();
}


void AccQT::load (QString *path, QList<Proto> *target) {
	QDir dir(*path);
	QStringList filters = (QStringList() << "*.desktop" << "*.directory");
	dir.setNameFilters(filters);


	QStringList *fields = new QStringList(
			QStringList() << "Name" << "Icon" << "Categories" << "X-Alterator-Category"
			);

	QFileInfoList flist = dir.entryInfoList();


	for (QFileInfo i : flist) {
		Proto *cur_proto = new Proto;
		cur_proto->load(i.absoluteFilePath(), fields);
		*target << *cur_proto;
	}
}


void AccQT::loadModules() {
	load(new QString(PATH_APPS), &modules);
}


void AccQT::loadCathegories() {
	load(new QString(PATH_CATH), &cathegories);
}


QList<Proto> AccQT::getModules() {
	return modules;
}


QList<Proto> AccQT::getCathegories() {
	return cathegories;
}

