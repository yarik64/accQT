// appfield.cpp

#include <QList>
#include <QDebug>
#include <QTextStream>
#include <QQmlApplicationEngine>


// headers
#include "appfield.h"
#include "proto.h"

AppField::AppField(QWidget *parent ) : QTreeWidget(parent) {
	CathegoryNameInCathegory = "X-Alterator-Category";
	CathegoryNameInModule    = "Categories";
	AttrName                 = "Name";
}

AppField::~AppField() {}


void AppField::loadCathegories(QList<Proto> cathegories, QList<Proto> modules) {
	for (Proto i : cathegories) {
		QTreeWidgetItem *newItem = new QTreeWidgetItem;
		for (Proto j : modules) {
			QTreeWidgetItem *newItemChild = new QTreeWidgetItem;

			int cmp = QString::compare(
					i.getAttr(&CathegoryNameInCathegory),
					j.getAttr(&CathegoryNameInModule),
					Qt::CaseInsensitive
					);

			if (cmp == 0) {
				newItemChild->setText(0, j.getAttr(&AttrName));
				newItem->insertChild(0, newItemChild);
			}
		}

		newItem->setText(0, i.getAttr(&AttrName));
		insertTopLevelItem(0, newItem);
	}

	QObject::connect(
			this, &AppField::itemDoubleClicked,
			this, &AppField::startModule
			);
}

void AppField::loadModules(QList<Proto> module) { }

void AppField::startModule(QTreeWidgetItem *sender, int col) {
	QQmlApplicationEngine engine(sender->text(0) + ".qml");
	QTextStream os(stdout);
	os << "SENDER:= " << sender->text(0) << "\n";
}

