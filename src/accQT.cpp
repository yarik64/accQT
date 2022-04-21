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
	QTextStream out(stdout);
	QString *pth = new QString(PATH_APPS);
	
	QList<Proto> *trg = new QList<Proto>;
	load(pth, trg);

	// for (Proto i : *trg) { out << i.getAttr(new QString("Name")); }

	MainWindow *w = new MainWindow;
	w->setUI(this);
	w->show();
}


void AccQT::load (QString *path, QList<Proto> *target) {
	QDir dir(*path);
	QFileInfoList flist = dir.entryInfoList();
	QStringList *fields = new QStringList();
	*fields << "Name" << "Icon" << "Categories";

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


/*
void AccQT::loadModules() {
	QDir dir(PATH_APPS);
	QFileInfoList flist = dir.entryInfoList();

	for (QFileInfo i : flist) {
		Module *current_mod = new Module;
		current_mod->load(i.absoluteFilePath());
		modules << *current_mod;
	}
}


void AccQT::loadCathegories() {
	QDir dir(PATH_CATH);
	QFileInfoList flist = dir.entryInfoList();

	for (QFileInfo i : flist) {
		Cathegorie *current_cath = new Cathegorie;
		current_cath->load(i.absoluteFilePath());
		cathegories << *current_cath;
	}
}
*/

QList<Proto> AccQT::getModules() {
	return modules;
}


QList<Proto> AccQT::getCathegories() {
	return cathegories;
}

