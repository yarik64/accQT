#include "AppButton.h"
#include <QString>

class AppButton: public QPushButton {
	public:
		AppButton (QString Name, QString Icon, QString Cath) {
			appName = Name;
			appIcon = Icon;
			appCath = Cath;
		}

		void setName(QString val){appName = val;}
		void setIcon(QString val){appIcon = val;}
		void setCath(QString val){appCath = val;}

		QString getName(){return appName;}
		QString getIcon(){return appIcon;}
		QString getCath(){return appCath;}

	private:
		QString appName;
		QString appIcon;
		QString appCath;
};
