import sqlite3
from flask_restful import Resource, reqparse
from models.prerequisite import PreRequisiteModel
from models.topic import TopicModel
from flask_jwt import jwt_required, current_identity


class PreRequisite(Resource):
    table_name = 'prerequisite'

    parser = reqparse.RequestParser()

    parser.add_argument('description',
    type=str,
    required=True,
    help="A Prerequisite description is required!")


    @jwt_required()
    
    def post(self, subject_fk, subject_requirement_fk):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}
        data = PreRequisite.parser.parse_args()

        if PreRequisiteModel.findBySubjectAndSubjectRequirement(subject_fk, subject_requirement_fk):
            return {'message': 'This Prequisite already exists'}
        
        if PreRequisiteModel.findBySubjectAndSubjectRequirement(subject_requirement_fk, subject_fk):
            return {'message': 'Prerequisite violation. Not possible.'}
        
        
        
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "INSERT INTO {table} VALUES (Null, ?, ?, ?)".format(table=self.table_name)
        cursor.execute(query, (data['description'], subject_fk, subject_requirement_fk))

        connection.commit()
        connection.close()

        return {"message": "PreRequisite created successfully!"}

    @jwt_required()
    def get(self, subject_fk, subject_requirement_fk):
        prerequisite = PreRequisiteModel.findBySubjectAndSubjectRequirement(subject_fk, subject_requirement_fk)
        if prerequisite:
            return {"prerequisite": prerequisite.__json__()}
        return {"message": "PreRequisite not found"}

    @jwt_required()
    def put(self, subject_fk, subject_requirement_fk):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}

        data = PreRequisite.parser.parse_args()


        prerequisite = PreRequisiteModel.findBySubjectAndSubjectRequirement(subject_fk, subject_requirement_fk)
  
        if not prerequisite:
            return {"message": "Prerequisite not found"}


        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""UPDATE {self.table_name}
        SET 
        description = "{data['description']}"

        WHERE prerequisite_code_pk = {prerequisite.prerequisite_code_pk}
        """

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "Prerequisite updated successfully."}
    
    @jwt_required()
    def delete(self, subject_fk, subject_requirement_fk):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}
        prerequisite = PreRequisiteModel.findBySubjectAndSubjectRequirement(subject_fk, subject_requirement_fk)
        if not prerequisite:
            return {"message": "PreRequisite not found."}

        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")
        
        query = f"""DELETE from {self.table_name}
        WHERE prerequisite_code_pk= "{prerequisite.prerequisite_code_pk}" """

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "PreRequisite deleted succesffuly."}


class PreRequisiteList(Resource):
    table_name = 'prerequisite'

    @jwt_required()
    def get(self, subject_code):
        prerequisite_list = PreRequisiteModel.fetchAllBySubject(subject_code)
    
        if prerequisite_list:
            return prerequisite_list
        return {"message": "No prerequisites found."}

class PostRequisiteList(Resource):
    table_name = 'prerequisite'

    @jwt_required()
    def get(self, subject_code):
        post_requisite_list = PreRequisiteModel.fetchAllPostRequisitesBySubject(subject_code)
    
        if post_requisite_list:
            return post_requisite_list
        return {"message": "No post-requisites found."}




