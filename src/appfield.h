// appfield.h

#ifndef ACCQT_APPFIELD_H
#define ACCQT_APPFIELD_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QList>

//headers
#include "proto.h"

class AppField : public QTreeWidget {

	public:
		AppField(QWidget *parent );
		~AppField();

		void loadCathegories(
				QList<Proto> cathegories,
				QList<Proto> modules
				);

		void loadModules(QList<Proto> module);

	public slots:
		void startModule(QTreeWidgetItem *sender, int col);

	signals:
		// void itemDoubleClicked(QTreeWidgetItem *item, int column)

	private:
		QString CathegoryNameInCathegory;
		QString CathegoryNameInModule;
		QString AttrName;

};
#endif // ACCQT_APPFIELD_H
