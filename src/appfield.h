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

	private:

};
#endif // ACCQT_APPFIELD_H
