# PySide2 tutorial 5


import sys
from datetime import datetime
from PySide2 import QtCore, QtGui, QtWidgets


class MyWidget(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)

        quit = QtWidgets.QPushButton("Quit")
        quit.setFont(QtGui.QFont("Times", 18, QtGui.QFont.Bold))

        self.counter = 11
        
        self.lcd = QtWidgets.QLCDNumber(2)
        self.lcd.display(5);
        self.slider = QtWidgets.QSlider(QtCore.Qt.Horizontal)
        self.slider.setRange(0, 99)
        self.slider.setValue(0)

        self.connect(quit, QtCore.SIGNAL("clicked()"),
                     QtWidgets.qApp, QtCore.SLOT("quit()"))
        self.connect(self.slider, QtCore.SIGNAL("valueChanged(int)"),
                     self.lcd, QtCore.SLOT("display(int)"))

        self.timer = QtCore.QTimer(self)
        self.connect(self.timer, QtCore.SIGNAL("timeout()"), self.setValue)
        self.timer.start(1000)
        
        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(quit);
        layout.addWidget(self.lcd);
        layout.addWidget(self.slider);
        self.setLayout(layout);

    @QtCore.Slot()    
    def setValue(self):
        self.counter -= 1
        self.lcd.display(self.counter)


app = QtWidgets.QApplication(sys.argv)
widget = MyWidget()
widget.show()
sys.exit(app.exec_())
