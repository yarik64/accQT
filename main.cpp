#include "main.h"

#include <iostream>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600
#define PATH_CATHEGORIES "/usr/share/alterator/desktop-directories/"
#define PATH_MODULES "/usr/share/alterator/applications/"

class appbt: public QPushButton {
	public:
		appbt (QString Name, QString Icon, QString Cath) {
			appName = Name;
			appIcon = Icon;
			appCath = Cath;
		}

		void setName(QString val){appName = val;}
		void setIcon(QString val){appIcon = val;}
		void setCath(QString val){appCath = val;}

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
	QTextStream os(stdout);

	QList<appbt>   app_buttons;
	QList<QString> cathegories;

	// получаем список приложений
	QDir dir;
	dir.setPath(PATH_CATHEGORIES);
	dir.setFilter(QDir::Files);
	QFileInfoList app_desktop_files = dir.entryInfoList();


	// создаем массив кнопок QPushButton
	// забиваем их в QList 
	for (QFileInfo fileName : app_desktop_files) {

		QSettings settings(fileName.absoluteFilePath(), QSettings::IniFormat);
				settings.beginGroup("Desktop Entry");
				QString Name = settings.value("Name").toString();
				QString Icon = settings.value("Icon").toString();
				QString Cath = settings.value("Categories").toString();
		settings.endGroup();

		appbt *button = new appbt(Name, Icon, Cath);
		cathegories << button->getCath();
		os << button->getCath();
		// os << button->getName()
		// app_buttons->insert(button->getName(), *button);
	}

	// заливаем в grid копки
	/*
	int row=0;
	for (QString cath : cathegories) {
		int col=0;

		QLabel *lcath = new QLabel;
		lcath->setText(cath);
		grid->addItem(*lcath, row++, col, 1, 1);

		for (appbt *btn : app_buttons){
			if ( btn->getCath == cath) {
				grid->addItem(btn, row, col++);
			}
		}
	}
*/

	grid->setMargin(5);
	grid->setSpacing(15);

	w.resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	w.setLayout(grid);
	w.show();
	return app.exec();

}

