#!/usr/bin/env python3

import PyQt5.QtWidgets as wg
import sys, os
import ConfigParser

def d(a):
    print(str(a))

def initparser(app_dir):


class accQTmain(wg.QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()


    def initUI(self):
        APP_DIR = '/usr/share/alterator/applications/'

        appFiles = os.listdir(APP_DIR)
        apps = {}

        for i in appFiles:
            cfg = config.parser()
            cfg.read(APP_DIR + i)

            Name = cfg['Desktop Entry']['Name']
            Icon = cfg['Desktop Entry']['Icon']
            Cath = cfg['Desktop Entry']['Cath']

            apps[i] = {
                    'Name': Name,
                    'Icon': Icon,
                    'Cath': Cath
                        }


        grid = wg.QGridLayout()
        for i in apps:
            app_button = QPushButton(i[Name])
            grid.addWidget()


        self.setLayout(grid)
        
 

        #l1 = wg.QLabel ('NEW LABEL!!!')
        #grid.addWidget(l1, 0,0)
        self.setWindowTitle('TEST WINDOW')
        self.resize(800, 600)
        self.show()


if __name__ == '__main__':
    app = wg.QApplication(sys.argv)
    ex = accQTmain()
    sys.exit(app.exec_())
