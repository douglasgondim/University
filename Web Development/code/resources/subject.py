import sqlite3
from flask_restful import Resource, reqparse
from flask_jwt import jwt_required, current_identity
from models.subject import SubjectModel

class SubjectCreate(Resource):
    table_name = 'subject'

    parser = reqparse.RequestParser()

    parser.add_argument('name',
    type=str,
    required=True,
    help="A name is required!")

    parser.add_argument('semester',
    type=int,
    required=True,
    help="A semester is required!")

    parser.add_argument('workload',
    type=int,
    required=True,
    help="A workload value is required!")

    parser.add_argument('description',
    type=str,
    required=True,
    help="A subject description is required!")

    @jwt_required()
    def post(self):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}
        data = SubjectCreate.parser.parse_args()

        if SubjectModel.findByName(data['name']):
            return {'message': 'This subject has already been registered..'}
        
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "INSERT INTO {table} VALUES (Null, ?, ?, ?, ?)".format(table=self.table_name)
        cursor.execute(query, (data['name'], data['semester'], 
        data['workload'], data['description']))

        connection.commit()
        connection.close()

        return {"message": "Subject created successfully!"}


class Subject(Resource):
    table_name = 'subject'

    parser = reqparse.RequestParser()

    parser.add_argument('name',
    type=str,
    required=True,
    help="A name is required!")

    parser.add_argument('semester',
    type=int,
    required=True,
    help="A semester is required!")

    parser.add_argument('workload',
    type=int,
    required=True,
    help="A workload value is required!")

    parser.add_argument('description',
    type=str,
    required=True,
    help="A subject description is required!")

    @jwt_required()
    def get(self, subject_code):
        subject = SubjectModel.findByCode(subject_code)
        if subject:
            return {"subject": subject.__json__()}
        return {"message": "Subject not found"}

    @jwt_required()
    def put(self, subject_code):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}

        data = Subject.parser.parse_args()
        subject = SubjectModel.findByCode(subject_code)
        if not subject:
            return {"message": "Subject not found."}

        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""UPDATE {self.table_name}
        SET 
        name = "{data['name']}",
        semester = {data['semester']},
        workload = "{data['workload']}",
        description = "{data['description']}"

        WHERE subject_code_pk = "{subject.subject_code_pk}"
        """ 

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "Subject updated successfully."}
    
    @jwt_required()
    def delete(self, subject_code):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}
        
        subject = SubjectModel.findByCode(subject_code)
        if not subject:
            return {"message": "Subject not found."}

        connection = sqlite3.connect('database/data.db')
        
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")
        query = f"""DELETE from {self.table_name}
        WHERE subject_code_pk= "{subject.subject_code_pk}" """

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "Subject deleted succesffuly."}



class SubjectList(Resource):
    @jwt_required()
    def get(self):
        subjectList = SubjectModel.fetchAll()
        
        if subjectList:
            return subjectList
        return {"message": "No subjects found."}

