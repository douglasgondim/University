import sqlite3
from models.subject import SubjectModel

class TopicModel:
    table_name = 'topic'
    def __init__(self, topic_code_pk, name, description, subject_fk):
        self.topic_code_pk = topic_code_pk
        self.name = name
        self.description = description
        self.subject_fk = subject_fk

    def __json__(self):
        subject = SubjectModel.findByCode(self.subject_fk)

        return {"topic_code_pk": self.topic_code_pk,
        "name": self.name,
        "description": self.description,
        "subject": subject.__json__(),
        "links": [
            {
                "href": f"/subject/{self.subject_fk}",
                "rel": "subject",
                "type": "GET"
            }
        ]}

    

    @classmethod
    def findByName(cls, name):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "SELECT * FROM {table} WHERE name=?".format(table=cls.table_name)
        result = cursor.execute(query, (name,))
        line = result.fetchone()
        if line:
            topic = cls(*line)
        else:
            topic = None
        connection.close()
        return topic
    

    @classmethod
    def findByCode(cls, topic_code_pk):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "SELECT * FROM {table} WHERE topic_code_pk=?".format(table=cls.table_name)
        result = cursor.execute(query, (topic_code_pk,))
        line = result.fetchone()
        if line:
            topic = cls(*line)
        else:
            topic = None
        connection.close()
        return topic

    @classmethod
    def fetchAllBySubject(cls, subject_code):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"SELECT * FROM {cls.table_name} where subject_fk = {subject_code}"
        result = cursor.execute(query).fetchall()

        if result != []:
            for i in range(len(result)):
                result[i] = cls(*result[i]).__json__()
        else:
            result = None
        connection.close()

        return result