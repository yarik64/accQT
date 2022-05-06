// appfield.cpp

#include <QList>
#include <QDebug>
#include <QTextStream>


// headers
#include "appfield.h"
#include "proto.h"

AppField::AppField(QWidget *parent ) : QTreeWidget( parent ) { }


AppField::~AppField() {}

void AppField::loadCathegories(QList<Proto> cathegories, QList<Proto> modules) {
	for (Proto i : cathegories) {
		QTreeWidgetItem *newItem = new QTreeWidgetItem;
		for (Proto j : modules) {
			QTreeWidgetItem *newItemChild = new QTreeWidgetItem;
			int cmp = QString::compare(
					i.getAttr(new QString("X-Alterator-Category")),
					j.getAttr(new QString("Categories")),
					Qt::CaseInsensitive
					);

			if (cmp == 0) {
			newItemChild->setText(0, j.getAttr(new QString("Name")));
			newItem->insertChild(0, newItemChild);
			}
		}

		newItem->setText(0, i.getAttr(new QString("Name")));
		insertTopLevelItem(0, newItem);
	}

}

void AppField::loadModules(QList<Proto> module) { }


