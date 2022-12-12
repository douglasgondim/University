import sqlite3
from models.subject import SubjectModel

class PreRequisiteModel:
    table_name = 'prerequisite'
    def __init__(self, prerequisite_code_pk, description,subject_fk, subject_requirement_fk):
        self.prerequisite_code_pk = prerequisite_code_pk
        self.description = description
        self.subject_fk = subject_fk
        self.subject_requirement_fk = subject_requirement_fk

    def __json__(self):
        subject = SubjectModel.findByCode(self.subject_fk)
        subject_requirement = SubjectModel.findByCode(self.subject_requirement_fk)

        return {"prerequisite_code_pk": self.prerequisite_code_pk,
                "description": self.description,
                "subject": subject.__json__(),
                "subject_requirement": subject_requirement.__json__(),
                "links": [
                    {
                        "href": f"/subject/{self.subject_fk}",
                        "rel": "subject",
                        "type": "GET"
                    },
                    {
                        "href": f"/subject/{self.subject_requirement_fk}",
                        "rel": "subject_requirement",
                        "type": "GET"
                    }
                ]
                }


    @classmethod
    def findByCode(cls, prerequisite_code_pk):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "SELECT * FROM {table} WHERE prerequisite_code_pk=?".format(table=cls.table_name)
        result = cursor.execute(query, (prerequisite_code_pk,))
        line = result.fetchone()
        if line:
            prerequisite = cls(*line)
        else:
            prerequisite = None
        connection.close()
        return prerequisite

    @classmethod
    def findBySubject(cls, subject_fk):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""SELECT * FROM {cls.table_name}
        WHERE subject_fk = {subject_fk} """

        result = cursor.execute(query)
   
        line = result.fetchone()
        if line:
            prerequisite = cls(*line)
        else:
            prerequisite = None
        connection.close()
        return prerequisite

        
    @classmethod
    def findBySubjectAndSubjectRequirement(cls, subject_fk, subject_requirement_fk):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""SELECT * FROM {cls.table_name}
        WHERE subject_fk = {subject_fk} AND subject_requirement_fk = {subject_requirement_fk}"""

        result = cursor.execute(query)
   
        line = result.fetchone()
        if line:
            prerequisite = cls(*line)
        else:
            prerequisite = None
        connection.close()
        return prerequisite


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

    @classmethod
    def fetchAllPostRequisitesBySubject(cls, subject_code):
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"SELECT * FROM {cls.table_name} where subject_requirement_fk = {subject_code}"
        result = cursor.execute(query).fetchall()

        if result != []:
            for i in range(len(result)):
                result[i] = cls(*result[i]).__json__()
        else:
            result = None
        connection.close()

        return result


    
