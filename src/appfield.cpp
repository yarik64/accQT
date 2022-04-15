// appfield.cpp

#include <QList>


// headers
#include "appfield.h"
#include "module.h"
#include "cathegorie.h"

AppField::AppField(QWidget *parent ) : QTreeWidget( parent ) { }

void AppField::loadCathegories(QList<Cathegorie> cath, QList<Module> modules) {

	for (Cathegorie i : cath) {
		int row = 0;
		QTreeWidgetItem *newItem = new QTreeWidgetItem;

		for (Module j : modules) {
			int row2 = 0;
			QTreeWidgetItem *newItemChild = new QTreeWidgetItem;

			int cmp = QString::compare(i.getCathegory(), j.getCathegory(), Qt::CaseInsensitive);
			if (cmp == 0) {
			newItemChild->setText(row, j.getName());
			newItem->insertChild(row, newItemChild);
			}
			row2++;
		}

		newItem->setText(row, i.getName());
		this->insertTopLevelItem(row, newItem);
		row++;
	}

}

void AppField::loadModules(QList<Module> module) { }


AppField::~AppField() { }
