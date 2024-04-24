from data import connect
import os 
class user:
    def __init__(self, login, password):
        self.login = login
        self.password = password
        self.db = connect.dataBase()
        self.states = "#".join(["ToDo", "Doing", "Done"])
        self.category = "#".join(["Work", "Personal", "Home"])
        self.isLogged = False
    
    def addTask(self, task, task_class, description, status, deadline, deadline_status):
        db = connect.dataBase()
        db.execute('''INSERT INTO tasks(user_id, task, task_class, description, status, deadline, deadline_status) VALUES (?, ?, ?, ?, ?, ?, ?)''', 
                self.login, task, task_class, description, status, deadline, deadline_status)
        print("Added task: ", task)
        pass
    
    def checkAuth(self):
        if self.db.checkUser(self.login, self.password):
            self.isLogged = True
            self.category = self.db.getCategory(self.login)
            self.states = self.db.getStates(self.login)
            print("Logged in as: {},{}".format(self.login, self.category))
            return True

        return False

    def validate(self,password2):
        #validateLogin():
        if self.login == '':
            return "Error: Login can't be empty!"
        bad_chars = "`~!@#$%^&*()_+-=[]{}|;':\",./<>?\'\\"
        invalid_chars = ''.join(ch for ch in self.login if ch in bad_chars)
        if invalid_chars:
            return f"Error: Login contains invalid characters: {invalid_chars}"
        if not self.db.validateLogin(self.login):
            return "Error: Login already exists!" 
        
        #validatePassword():
        if self.password == '':
            return "Error: Password can't be empty!"
        if self.password != password2:
            return "Error: Passwords don't match!"

        self.db.addUser(self.login, self.password, self.states, self.category)
        self.isLogged = True
        return "nope"

    def updateCategory(self, category):
        self.category = category
        self.db.updateCategory(self.login, self.category)
        
    def updateStates(self, states):
        self.states = states
        self.db.updateStates(self.login, self.states)

    def getTasks(self):
        return self.db.getTasksByUser(self.login)
    
    def updateTaskStatus(self, taskList):
        self.db.updateTasksStates(self.login, taskList)