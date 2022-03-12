// AccQT.h

#include <QDir>
#include <QString>

// headers
#include "app.h"

class AccQT {

	public:
		AccQT();
		~AccQT();
		loadApps();

	private:
		QList<app> applications;

};
