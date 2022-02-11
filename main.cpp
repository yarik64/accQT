#include <QMainWindow>
#include <QtGui>
#include <QApplication>
#include <QGridLayout>
#include <QRect>
#include <QDir>
#include <QRegExp>

#include <iostream>

#include "main.h"

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600
#define PATH_CATHEGORIES "/usr/share/alterator/desktop-directories/"
#define PATH_MODULES "/usr/share/alterator/applications/"

#define REX_NAME "(?:\s*Name\[ru\]=)(.*)"
#define REX_ICON "(?:\s*Icon=)(.*)"
#define REX_CATH "(?:\s*Categories=)(.*)"



class parseDestops {

    public:
virtual QHash parse(QString dt_addr) {
		QFile inputFile(dt_addr);
		inputFile.open(QIODevice::ReadOnly);

		QTextStream in(&inputFile);
		QRegExp rxName(REX_NAME);
		QRegExp rxIcon(REX_ICON);
		QRegExp rxCath(REX_CATH);

        rxName.setMinimal(true);
        rxIcon.setMinimal(true);
        rxCath.setMinimal(true);

        int pos = rxName.indexIn(in.readAll());
        int pos = rxIcon.indexIn(in.readAll());
        int pos = rxCath.indexIn(in.readAll());

        QHash result;
		result["Name"] = rxName.capturedTexts();
		result["Icon"] = rxIcon.capturedTexts();
		result["Cath"] = rxCath.capturedTexts();

		inputFile.close();
		return result;
	}
}




int main(int argc, char *argv[]) {

	QApplication app(argc, argv);
	QMainWindow w;

virtual QFileInfoList flists(QString path) {
	QDir dir;
	dir.setPath(path);
	dir.setFilter(QDir::Files);
    QFileInfoList result = dir.entryInfoList();
	return result;
}

	// получаем список названий desktop-файлов содержащих категории
	QFileInfoList listCathegories = flists(PATH_CATHEGORIES);

	// получаем список названий desktop-файлов содержащих имна модулей
	QFileInfoList listApp = flists(PATH_MODULES);

	// парсим *.desktop для извлечения нужной инфы
	parseDesktops();

	// анализируем списки для составления Grid

	for (int i = 0; i < listApp.size(); ++i) {
		QFileInfo fApp = listApp.at(i);

		QTextStream st(stdout) << fApp;
	}


	QGridLayout* grid = new QGridLayout;
	grid->setMargin(5);
	grid->setSpacing(15);


	w.resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	w.show();
	return app.exec();

}
