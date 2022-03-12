// app.cpp

#include <QString>
#include <QSettings>


App::app(QString *p){
app:load(*p);
}

app::load(QString *path){
	QSettings settings(path, QSettings::IniFormat);
	settings.beginGroup("Desktop Entry");
	this->Name = settings.value("Name").toString();
	this->Icon = settings.value("Icon").toString();
	this->Cath = settings.value("Categories").toString();
	settings.endGroup();
}
