// app.h

#include <QString>
#include <QSettings>


class App {

	public:
		app();
		load(QString *path);

	private:
		QString Name;
		QString Icon;
		QString Cathegory;

}
