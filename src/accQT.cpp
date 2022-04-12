// accQT.cpp

// headers
#include "accQT.h"
#include "mainwindow.h"

#include <QMainWindow>

// conrainers
#include <QList>

// libs
#include <QDir>
#include <QString>
#include <QFileInfoList>
#include <QDebug>

#define PATH_APPS "/usr/share/alterator/applications/"
#define PATH_CATH "/usr/share/alterator/desktop-directories/"


AccQT::AccQT(int argc, char **argv): QApplication(argc, argv) {
	loadModules();
	loadCathegories();
	loadUI();
}


AccQT::~AccQT() {
}


void AccQT::loadUI() {
	MainWindow *w = new MainWindow;
	w->setUI(this);
	w->show();
}


void AccQT::loadModules() {
	QDir dir(PATH_APPS);
	QFileInfoList flist = dir.entryInfoList();

	for (QFileInfo i : flist) {
		Module *current_mod = new Module;
		QString ipath = i.absoluteFilePath();
		current_mod->load(ipath);
		this->modules << *current_mod;
	}
}


void AccQT::loadCathegories() {
	QDir dir(PATH_CATH);
	QFileInfoList flist = dir.entryInfoList();

	for (QFileInfo i : flist) {
		Cathegorie *current_cath = new Cathegorie;
		QString ipath = i.absoluteFilePath();
		current_cath->load(ipath);
		this->cathegories << *current_cath;
	}
}


QList<Module> AccQT::getModules() {
	return this->modules;
}


QList<Cathegorie> AccQT::getCathegories() {
	return this->cathegories;
}

