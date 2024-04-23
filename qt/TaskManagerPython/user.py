from data import connect
import os 
class user:
    def __init__(self, login, password):
        self.login = login
        self.password = password
        self.db = connect.dataBase()
        self.isLogged = False
    
    def addTask(self, task, description, status, deadline_status, task_class, deadline):
        db = connect.dataBase()
        db.execute('''INSERT INTO tasks(user_id, task, description, status, deadline_status, task_class, deadline) VALUES (?, ?, ?, ?, ?, ?, ?)''', 
                   self.login, task, description, status, deadline_status, task_class, deadline)
        pass
    
    def checkAuth(self):
        """
        Checks if the user's login and password are valid.
        Sets the 'isLogged' instance variable to True if successful.
        
        Returns:
            bool: True if login and password are valid, False otherwise.
        """
        # Check if the user's login and password are valid
        if self.db.checkUser(self.login, self.password):
            # If valid, set the 'isLogged' variable to True
            self.isLogged = True
            return True
        # If not valid, return False
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

        self.db.addUser(self.login, self.password)
        self.isLogged = True
        return "nope"


    def getTasks(self):
        pass
