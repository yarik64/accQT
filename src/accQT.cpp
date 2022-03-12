// accQT.cpp

#include <QDir>
#include <QString>

// headers
#include "app.h"

#define PATH_DESKTOP 


AccQT::AccQT() {
	/usr/share/alterator/applications/
}

AccQT::loadApps() {
	QDir dir = new QDir(PATH_DESKTOP);
	QFileInfoList flist = dir.entryInfoList();

	for (QString i : flist){
		App *current_app = new App(i);
		this->applications << *current_app;
	}

}

AccQT::~AccQT() {
	delete this;
}
