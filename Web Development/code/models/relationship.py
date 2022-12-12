import sqlite3
from models.subject import SubjectModel
from models.topic import TopicModel

class RelationshipModel:
    table_name = 'relationship'
    def __init__(self, relationship_code_pk,  description, subject_1_fk, topic_1_fk, subject_2_fk, topic_2_fk):
        self.relationship_code_pk = relationship_code_pk
        self.subject_1_fk = subject_1_fk
        self.topic_1_fk = topic_1_fk
        self.subject_2_fk = subject_2_fk
        self.topic_2_fk = topic_2_fk
        self.description = description

    def __json__(self):
        subject_1 = SubjectModel.findByCode(self.subject_1_fk)
        subject_2 = SubjectModel.findByCode(self.subject_2_fk)
        topic_1 = TopicModel.findByCode(self.topic_1_fk)
        topic_2 = TopicModel.findByCode(self.topic_2_fk)

        return {"relationship_code_pk": self.relationship_code_pk,
        "description": self.description,
        "subject_1": subject_1.__json__(),
        "topic_1": topic_1.__json__(),
        "subject_2": subject_2.__json__(),
        "topic_2": topic_2.__json__(),
        "links": [
            {
                "href": f"/subject/{self.subject_1_fk}",
                "rel": "subject_1",
                "type": "GET"
            },
            {
                "href": f"/subject/{self.subject_1_fk}/{self.topic_1_fk}",
                "rel": "topic_1",
                "type": "GET"
            },
            {
                "href": f"/subject/{self.subject_2_fk}",
                "rel": "subject_2",
                "type": "GET"
            },
            {
                "href": f"/subject/{self.subject_2_fk}/{self.topic_2_fk}",
                "rel": "topic_2",
                "type": "GET"
            }
        ]
        }


    @classmethod
    def findByCode(cls, relationship_code_pk):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "SELECT * FROM {table} WHERE relationship_code_pk=?".format(table=cls.table_name)
        result = cursor.execute(query, (relationship_code_pk,))
        line = result.fetchone()
        if line:
            topic = cls(*line)
        else:
            topic = None
        connection.close()
        return topic

    @classmethod
    def findByTopics(cls, topic_code_1,topic_code_2):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""SELECT * FROM {cls.table_name}
        WHERE (topic_1_fk = {topic_code_1} AND topic_2_fk = {topic_code_2})"""

        result = cursor.execute(query)
        
   
        line = result.fetchone()
        print(line)
        if line:
            topic = cls(*line)
        else:
            topic = None
        connection.close()
        return topic

    @classmethod
    def fetchAllForTopic(cls, topic_code):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""SELECT * FROM {cls.table_name}
        WHERE (topic_1_fk = {topic_code})"""

        result = cursor.execute(query).fetchall()
        

        if result != []:
            for i in range(len(result)):
                result[i] = cls(*result[i]).__json__()
        else:
            result = None
        connection.close()

        return result

    
    