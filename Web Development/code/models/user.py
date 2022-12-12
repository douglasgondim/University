import sqlite3

class UserModel:
    table_name = 'user'
    def __init__(self, name, siape_pk, password, level):
        self.id = siape_pk
        self.name = name
        self.siape_pk = siape_pk
        self.password = password
        self.level = level

    def __json__(self):
        return {
            "name": self.name,
            "siape_pk": self.siape_pk,
            "level": self.level

        }
    

    @classmethod
    def findBySiape(cls, siape_pk):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "SELECT * FROM {table} WHERE siape_pk=?".format(table=cls.table_name)
        result = cursor.execute(query, (siape_pk,))
        line = result.fetchone()
        if line:
            user = cls(*line)
        else:
            user = None
        connection.close()
        return user

        