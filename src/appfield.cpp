// appfield.cpp

#include <QList>
#include <QDebug>
#include <QTextStream>


// headers
#include "appfield.h"
#include "module.h"
#include "cathegorie.h"
#include "proto.h"

AppField::AppField(QWidget *parent ) : QTreeWidget( parent ) { }


AppField::~AppField() {}

void AppField::loadCathegories(QList<Proto> cath, QList<Proto> modules) {
	QTextStream out(stdout);

	for (Proto i : cath) {
		int row = 0;
		QTreeWidgetItem *newItem = new QTreeWidgetItem;

		for (Proto j : modules) {
			int row2 = 0;
			QTreeWidgetItem *newItemChild = new QTreeWidgetItem;
					out << "i:= "<< i.getAttr(new QString("Categories"));
					out << "j:= "<< j.getAttr(new QString("Categories"));
					out << "\n";

			int cmp = QString::compare(
					i.getAttr(new QString("Categories")),
					j.getAttr(new QString("Categories")),
					Qt::CaseInsensitive
					);

			if (cmp == 0) {
			newItemChild->setText(row, j.getAttr(new QString("Name")));
			newItem->insertChild(row, newItemChild);
			}
			row2++;

		}

		newItem->setText(row, i.getAttr(new QString("Name")));
		insertTopLevelItem(row, newItem);
		row++;
	}

}

void AppField::loadModules(QList<Proto> module) { }


