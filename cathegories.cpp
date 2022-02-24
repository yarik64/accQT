#include <QDir>
#include <QFileInfo>
#include <QString>


class app_cathegory {

	public:
		// принимает путь к папке с категориями

		app_cathegory() {
			QHash<QString, cathegories>  catHash;
			QHash<QString, applications> appHash;

			//applications
			QDir dir;
			dir.setPath(PATH_APPS);
			dir.setFilter(QDir::Files);
			QFileInfoList app_desktop_files = dir.entryInfoList();

			for (QFileInfo fileName : app_desktop_files) {
				QSettings settings(fileName.absoluteFilePath(), QSettings::IniFormat);
					settings.beginGroup("Desktop Entry");
					QString Name = settings.value("Name").toString();
					QString Icon = settings.value("Icon").toString();
					QString Cath = settings.value("Categories").toString();
				settings.endGroup();

				app *App = new application;
				App->Name = appName;
				App->Icon = appIcon;
				App->Cath = appCath;
				appHash.insert(Cath, *App);
			}

			//cathegories
			QDir dir;
			dir.setPath(PATH_CATHEGORIES);
			dir.setFilter(QDir::Files);
			QFileInfoList cath_desktop_files = dir.entryInfoList();

			for (QFileInfo fileName : cath_desktop_files) {
				QSettings settings(fileName.absoluteFilePath(), QSettings::IniFormat);
					settings.beginGroup("Desktop Entry");
					QString Name = settings.value("Name").toString();
					QString Icon = settings.value("Icon").toString();
					// QString Cath = settings.value("Categories").toString();
				settings.endGroup();

				cathegory *Ctg = new cathegory;
				Ctg->Name = Name;
				Ctg->Icon = Icon;
				catHash.insert(Name, *Ctg);
			}
			for(i : appHash.keys().reoveDuplicates()){}

			}

	private:

		struct application {
			QString Name;
			QString Icon;
			QString Cath;
		};

		struct cathegory {
			QString Name;
			QString Icon;
			QHash<QString, app> Apps;
		};

};
