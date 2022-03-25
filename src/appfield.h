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
		AppField();
		~AppField();
		void loadCathegories(QList<Cathegorie> cath);
		void loadModules(QList<Module> module);

	private:

};
#endif // ACCQT_APPFIELD_H
