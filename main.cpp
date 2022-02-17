#include <QMainWindow>
#include <QtGui>
#include <QApplication>
#include <QGridLayout>
#include <QDir>
#include <QLabel>

#include <iostream>

#include "main.h"

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600
#define PATH_CATHEGORIES "/usr/share/alterator/desktop-directories/"
#define PATH_MODULES "/usr/share/alterator/applications/"

class AppButton: public QPushButton {
	public:
		/*
		AppButton(QString *path_to_desktop) {
			for (QFileInfoList fileName : res){
			}
		}
		*/
		void setName(QString a){appName = a;}
		void setIcon(QString a){appIcon = a;}
		void setCath(QString a){appCath = a;}

		QString getName(){return appName;}
		QString getIcon(){return appIcon;}
		QString getCath(){return appCath;}

	private:
		QString appName;
		QString appIcon;
		QString appCath;
};



int main(int argc, char *argv[]) {

	// объявляем элементы
	QApplication app(argc, argv);
	QMainWindow w;
	QGridLayout* grid = new QGridLayout;

	// получаем список приложений
	QDir dir;
	dir.setPath(PATH_CATHEGORIES);
	dir.setFilter(QDir::Files);
	QFileInfoList app_desktop_files = dir.entryInfoList();

	QList<AppButton>* app_buttons;
	QList<QString> cathedories;

	// создаем массив кнопок QPushButton
	// забиваем их в QList 
	for (QFileInfo fileName : app_desktop_files) {
		AppButton *button = new AppButton;

		QSettings settings(fileName.absoluteFilePath(), QSettings::IniFormat);
				settings.beginGroup("Desktop Entry");
				button->setName (settings.value("Name").toString());
				button->setIcon (settings.value("Icon").toString());
				button->setCath (settings.value("Categories").toString());
		settings.endGroup();

		cathedories << button->getCath();
		app_buttons->insert(button->getName, *button);

	}

	// заливаем в grid копки
	int row=0;
	for (QString cath : cathedories) {
		int col=0;

		QLabel *lcath = new QLabel;
		lcath->setText(cath);
		grid->addItem(*lcath, row++, col, 1, 1);

		for (AppButton *btn : app_buttons){
			if (btn->getCath==cath) {
				grid->addItem(btn, row, col++);
			}
		}
	}


	grid->setMargin(5);
	grid->setSpacing(15);
	w.resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	w.setLayout(grid);
	w.show();
	return app.exec();

}

