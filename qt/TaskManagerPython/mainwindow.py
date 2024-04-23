from PyQt6 import uic
from PyQt6.QtWidgets import *
from PyQt6.QtCore import *
from PyQt6.QtSql import *
import os

from user import user


class UI(QMainWindow):
    def __init__(self):
        super(UI,self).__init__()  
        uic.loadUi(self.pathOfFile("mainwindow.ui"), self)

        #define our control widgets
        self.gbMainLogged = self.findChild(QGroupBox, 'gbMainLogged')
        self.logOut = self.gbMainLogged.findChild(QPushButton, 'logOutBtn')
        self.quit1Btn = self.gbMainLogged.findChild(QPushButton, 'quit1Btn')
        self.newTaskBtn = self.gbMainLogged.findChild(QPushButton, 'newTaskBtn')
        self.personNameLbl = self.gbMainLogged.findChild(QLabel, 'personNameLbl')
        
        self.gbMainUnLogged = self.findChild(QGroupBox, 'gbMainUnLogged')
        self.authBtn = self.gbMainUnLogged.findChild(QPushButton, 'authBtn')
        self.registerBtn = self.gbMainUnLogged.findChild(QPushButton, 'registerBtn')
        self.quit2Btn = self.gbMainUnLogged.findChild(QPushButton, 'quit2Btn')
    
        #define our control connections
        self.logOut.clicked.connect(self.logoutButtonClicked)
        self.authBtn.clicked.connect(self.authButtonClicked)
        self.registerBtn.clicked.connect(self.registerButtonClicked)
        self.quit1Btn.clicked.connect(self.close)
        self.quit2Btn.clicked.connect(self.close)
        self.newTaskBtn.clicked.connect(self.newTaskButtonClicked)
        
        #define our task lists
        self.taskFrame = self.findChild(QFrame, 'taskFrame') 
        self.gbToDo = self.taskFrame.findChild(QGroupBox, 'gbToDo')
        self.gbDoing = self.taskFrame.findChild(QGroupBox, 'gbDoing')
        self.gbDone = self.taskFrame.findChild(QGroupBox, 'gbDone')
        
        
        #init user
        self.user = user('', '')
        
        # other need functions
        self.loggedOut() # To hide logoutBtn
        self.show()

    def registerButtonClicked(self):
    
        
        def regWindowAccepted():
            regWindow.setEnabled(False)
            login = regWindow.findChild(QLineEdit, 'lineLogin').text()
            password = regWindow.findChild(QLineEdit, 'linePass1').text()
            password2 = regWindow.findChild(QLineEdit, 'linePass2').text()
            self.user = user(login, password)
            err = self.user.validate(password2)
            if err != 'nope': 
                QMessageBox.critical(regWindow, "Error", err)
                return
            
            QMessageBox.information(regWindow, "Success", "You have successfully registered!")
            self.authorized()
            regWindow.close()   

        regWindow = QDialog()
        uic.loadUi(self.pathOfFile('registration.ui'), regWindow)
        regWindow.accepted.connect(regWindowAccepted)
        regWindow.exec()
        
        self.setEnabled(True)
        pass


    def authButtonClicked(self):
        def authWindowAccepted():
            authWindow.setEnabled(False)
            login = authWindow.findChild(QLineEdit, 'lineLogin').text()
            password = authWindow.findChild(QLineEdit, 'linePass').text()
            self.user = user(login, password)
            if not self.user.checkAuth():
                QMessageBox.critical(authWindow, "Error", "Wrong login or password!")
                return

            self.authorized()
            authWindow.close()
            QMessageBox.information(authWindow, "Success", "You have successfully logged in!")

        authWindow = QDialog()
        uic.loadUi(self.pathOfFile('auth.ui'), authWindow)
        authWindow.accepted.connect(authWindowAccepted)
        authWindow.exec()
        pass

    def logoutButtonClicked(self):
        self.user = user('', '')
        self.loggedOut()
        pass
    
    def authorized(self):  #hide registration buttons
        self.gbMainLogged.setVisible(True)
        self.gbMainUnLogged.setVisible(False)
        self.personNameLbl.setText("Hi, " + self.user.login)
        self.taskFrame.setVisible(True)
        
    def loggedOut(self): #show registration buttons
        self.gbMainUnLogged.setVisible(True)
        self.gbMainLogged.setVisible(False)
        self.taskFrame.setVisible(False)
        
    def showTasks(self):
        taskBox = QToolBox(self.taskFrame)
        taskBox.setObjectName("taskBox")

        tasks = self.user.getTasks()

        for i, task in enumerate(tasks):
            page = QWidget()
            descriptionLabel = QLabel(task['description'], page)
            descriptionLabel.setWordWrap(True)
            #iconLabel = QLabel(page)
            #iconLabel.setPixmap(QPixmap(":/icons/task/" + task['task_class'] + ".png"))
            #layout.addWidget(iconLabel)
            exceptionTimeLabel = QLabel(task['deadline_status'], page)

            layout = QVBoxLayout(page)
            layout.addWidget(descriptionLabel)
            
            layout.addWidget(exceptionTimeLabel)

            page.setLayout(layout)
            taskBox.addItem(page, task['task'])

        self.taskFrame.layout().addWidget(taskBox)

        pass


    def newTaskButtonClicked(self):
        pass
    
    @staticmethod
    def pathOfFile(filename):
        ui_file_path = os.path.join(os.path.dirname(__file__), "UI", filename)
        if not os.path.isfile(ui_file_path):
            raise RuntimeError(f"No such file: {ui_file_path}")
        return os.path.join(os.path.dirname(__file__), "UI", filename)



