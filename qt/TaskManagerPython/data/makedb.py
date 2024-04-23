import connect

def makeDB():
    db= connect.dataBase()
    db.cursor.execute('''CREATE TABLE IF NOT EXISTS users(id INTEGER PRIMARY KEY AUTOINCREMENT, login TEXT UNIQUE, password TEXT)''')
    db.cursor.execute('''
        CREATE TABLE IF NOT EXISTS tasks(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER,
            task TEXT,
            description TEXT,
            status TEXT, 
            deadline_status TEXT, 
            task_class TEXT, 
            deadline TIMESTAMP,
            FOREIGN KEY(user_id) REFERENCES users(id)
        )
    ''')
    db.database.commit()
    db.database.close()



makeDB()
print('makeDB done')