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
        print("GET query: ",query, ", args:",args)
        self.cursor.execute(query, args)
        return self.cursor.fetchall()
    

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

    def getTasksByUser(self, user_id):
        return self.get('''SELECT * FROM tasks WHERE user_id=(?)''', (user_id))
    
    def getTask(self, task_id):
        return self.get('''SELECT * FROM tasks WHERE id=(?)''', (task_id))
    
    def updateCategory(self, user_id, category):
        self.execute('''UPDATE users SET category=(?) WHERE id=(?)''', category, user_id)
        
    def getCategory(self, user_id):
        return self.get('''SELECT category FROM users WHERE id=(?)''', (user_id))

    def __del__(self):
        self.database.close()

# db = dataBase()
# #print("making admin")
# #db.execute('''INSERT INTO users(login, password) VALUES (?, ?)''', 'admin', 'admin')
# print("validating admin")
# db.validateLogin('admin')

# #db.execute('''INSERT INTO tasks(user_id, task, description, status, deadline_status, task_class, deadline) VALUES (?, ?, ?, ?, ?, ?, ?)''', 1, 'test', 'test', 'test', 'test', 'test', 'test')
# db.execute('''UPDATE users SET password=(?) WHERE login=(?)''', 'hello', 'admin')
