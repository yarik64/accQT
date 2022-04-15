// appfield.h

#ifndef ACCQT_APPFIELD_H
#define ACCQT_APPFIELD_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QList>

//headers
#include "module.h"
#include "cathegorie.h"

class AppField : public QTreeWidget {

	public:
		AppField(QWidget *parent );
		~AppField();
		void loadCathegories(QList<Cathegorie> cath, QList<Module> modules);
		void loadModules(QList<Module> module);

	private:

};
#endif // ACCQT_APPFIELD_H
