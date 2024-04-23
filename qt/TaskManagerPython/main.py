from PyQt6.QtWidgets import QApplication

from mainwindow import UI


if __name__ == '__main__':
    import sys
    app = QApplication(sys.argv)
    ui = UI()
    sys.exit(app.exec())




