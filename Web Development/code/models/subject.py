import sqlite3

class SubjectModel:
    table_name = 'subject'
    def __init__(self, subject_code_pk, name, semester, workload, description):
        self.subject_code_pk = subject_code_pk
        self.name = name
        self.semester = semester
        self.workload = workload
        self.description = description

    def __json__(self):
        return {"subject_code_pk": self.subject_code_pk,
        "name": self.name,
        "semester": self.semester,
        "workload": self.workload,
        "description": self.description}

    @classmethod
    def findByName(cls, name):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "SELECT * FROM {table} WHERE name=?".format(table=cls.table_name)
        result = cursor.execute(query, (name,))
        line = result.fetchone()
        if line:
            subject = cls(*line)
        else:
            subject = None
        connection.close()
        return subject

    @classmethod
    def findByCode(cls, subject_code_pk):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "SELECT * FROM {table} WHERE subject_code_pk=?".format(table=cls.table_name)
        result = cursor.execute(query, (subject_code_pk,))
        line = result.fetchone()
        if line:
            subject = cls(*line)
        else:
            subject = None
        connection.close()
        return subject

    @classmethod
    def fetchAll(cls):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"SELECT * FROM {cls.table_name}"
        result = cursor.execute(query).fetchall()



        if result != []:
            for i in range(len(result)):
                result[i] = cls(*result[i]).__json__()
        else:
            result = None
        connection.close()

        return result

    

    