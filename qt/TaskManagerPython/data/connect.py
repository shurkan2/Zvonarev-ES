import os
import sqlite3

class dataBase():

    def __init__(self):
        current_directory = os.path.dirname(os.path.abspath(__file__))
        self.database_path = os.path.join(current_directory, 'TaskManager.sqlite')
        self.database = sqlite3.connect(self.database_path)
        self.cursor = self.database.cursor()

    def execute(self, query, *args):
        print("EXECUTE query: ",query, ", args:",args)
        self.cursor.execute(query, args)
        self.database.commit()
    
    def addUser(self, login, password, states, category):
        self.execute('''INSERT INTO users(login, password, states, category) VALUES (?, ?, ?, ?)''',
                     login, password, states, category)
        
    
    def get(self, query, *args):  
        self.cursor.execute(query, args)
        tmp = self.cursor.fetchall()
        print("GET query: ",query, ", args:",args, ",\n\t result:",tmp)
        return tmp
    

    def close(self):
        self.database.commit()
        self.database.close()
    
    def validateLogin(self, login):
        result = self.get('''SELECT * FROM users WHERE login=(?)''', (login))
        print(result)
        return len(result) == 0
    
    def updatePassword(self, login, password):
        self.execute('''UPDATE users SET password=(?) WHERE login=(?)''', password, login)

    def checkUser(self, login, password):
        result = self.get('''SELECT * FROM users WHERE login=(?) AND password=(?)''', login, password)
        return len(result) > 0

    def getTasksByUser(self, login):
        return self.get('''SELECT * FROM tasks WHERE login=(?)''', (login))
    
    def updateCategory(self, login, category):
        self.execute('''UPDATE users SET category=(?) WHERE login=(?)''', category, login)
        
    def getCategory(self, login):
        res =  self.get('''SELECT category FROM users WHERE login=(?)''', (login))
        return res[0][0]
    
    def getStates(self, login):
        res =  self.get('''SELECT states FROM users WHERE login=(?)''', (login))
        return res[0][0]
    
    
    def updateStates(self, login, states):
        self.execute('''UPDATE users SET states=(?) WHERE login=(?)''', states, login)

    def __del__(self):
        self.database.close()

# db = dataBase()
# #print("making admin")
# #db.execute('''INSERT INTO users(login, password) VALUES (?, ?)''', 'admin', 'admin')
# print("validating admin")
# db.validateLogin('admin')

# #db.execute('''INSERT INTO tasks(user_id, task, description, status, deadline_status, task_class, deadline) VALUES (?, ?, ?, ?, ?, ?, ?)''', 1, 'test', 'test', 'test', 'test', 'test', 'test')
# db.execute('''UPDATE users SET password=(?) WHERE login=(?)''', 'hello', 'admin')
