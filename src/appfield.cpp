// appfield.cpp

#include <QList>


// headers
#include "appfield.h"
#include "module.h"
#include "cathegorie.h"

// AppField::AppField() { }


void AppField::loadCathegories(QList<Cathegorie> cath) {
	for (Cathegorie i : cath) {
		int row = 0;
		QTreeWidgetItem *newItem = new QTreeWidgetItem;

		QString itemText = i.getName();
		newItem->setText(row, itemText);
		this->insertTopLevelItem(row, newItem);
		row++;
	}
}

void AppField::loadModules(QList<Module> module) {
}


AppField::~AppField() {
	delete this;
}
