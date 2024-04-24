import connect

def makeDB():
    db= connect.dataBase()
    db.cursor.execute('''CREATE TABLE IF NOT EXISTS users(
            id INTEGER PRIMARY KEY AUTOINCREMENT, 
            login TEXT UNIQUE, 
            password TEXT, 
            category TEXT, 
            states TEXT)
    ''')
    db.cursor.execute('''
        CREATE TABLE IF NOT EXISTS tasks(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER,
            task TEXT,
            task_class TEXT, 
            description TEXT,
            status TEXT, 
            deadline TIMESTAMP,
            deadline_status TEXT, 
            FOREIGN KEY(user_id) REFERENCES users(id)
        )
    ''')
    db.database.commit()
    db.database.close()



makeDB()
print('makeDB done')