import sqlite3
from flask_restful import Resource, reqparse
from models.relationship import RelationshipModel
from models.topic import TopicModel
from flask_jwt import jwt_required, current_identity


class Relationship(Resource):
    table_name = 'relationship'

    parser = reqparse.RequestParser()

    parser.add_argument('description',
    type=str,
    required=True,
    help="A relationship description is required!")

    @jwt_required()
    def post(self, subject_code_1, topic_code_1, subject_code_2, topic_code_2):
        data = Relationship.parser.parse_args()

        if RelationshipModel.findByTopics(topic_code_1, topic_code_2):
            return {'message': 'This stopic already exists'}
        
        if topic_code_1 == topic_code_2:
            return {"message": "Cannot create relationship between the same topic"}
        
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "INSERT INTO {table} VALUES (Null, ?, ?, ?, ?, ?)".format(table=self.table_name)
       
        cursor.execute(query, (data['description'], subject_code_1, topic_code_1, 
        subject_code_2, topic_code_2
        ))

        cursor.execute(query, (data['description'], subject_code_2, topic_code_2, 
        subject_code_1, topic_code_1
        ))

        connection.commit()
        connection.close()

        return {"message": "Relationship created successfully!"}

    @jwt_required()
    def get(self, subject_code_1, topic_code_1, subject_code_2, topic_code_2):
        print(topic_code_1, topic_code_2)
        relationship = RelationshipModel.findByTopics(topic_code_1, topic_code_2)
        print(relationship)
        if relationship and TopicModel.findByCode(topic_code_1).subject_fk == int(subject_code_1) and TopicModel.findByCode(topic_code_2).subject_fk == int(subject_code_2) :
            return {"relationship": relationship.__json__()}
        return {"message": "Relationship not found"}

    @jwt_required()
    def put(self, subject_code_1, topic_code_1, subject_code_2, topic_code_2):
        data = Relationship.parser.parse_args()
        relationship = RelationshipModel.findByTopics(topic_code_1, topic_code_2)
        relationship_revert = RelationshipModel.findByTopics(topic_code_2, topic_code_1)
        if not relationship and not relationship_revert:
            return {"message": "Relationship not found."}

        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""UPDATE {self.table_name}
        SET 
        description = "{data['description']}",
        subject_1_fk = "{subject_code_1}",
        topic_1_fk = "{topic_code_1}",
        subject_2_fk = "{subject_code_2}",
        topic_2_fk = "{topic_code_2}"

        WHERE relationship_code_pk = "{relationship.relationship_code_pk}"
        """ 

        cursor.execute(query)

        query = f"""UPDATE {self.table_name}
        SET 
        description = "{data['description']}",
        subject_1_fk = "{subject_code_2}",
        topic_1_fk = "{topic_code_2}",
        subject_2_fk = "{subject_code_1}",
        topic_2_fk = "{topic_code_1}"

        WHERE relationship_code_pk = "{relationship_revert.relationship_code_pk}"
        """ 

        cursor.execute(query)


        connection.commit()
        connection.close()

        return {"message": "Relationship updated successfully."}
    
    @jwt_required()
    def delete(self, subject_code_1, topic_code_1, subject_code_2, topic_code_2):
        relationship = RelationshipModel.findByTopics(topic_code_1, topic_code_2)
        relationship_revert = RelationshipModel.findByTopics(topic_code_2, topic_code_1)
        if not relationship and not relationship_revert:
            return {"message": "Relationship not found."}

        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")
        
        query = f"""DELETE from {self.table_name}
        WHERE relationship_code_pk= "{relationship.relationship_code_pk}" """

        cursor.execute(query)

        query = f"""DELETE from {self.table_name}
        WHERE relationship_code_pk= "{relationship_revert.relationship_code_pk}" """

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "Relationship deleted succesffuly."}

class RelationshipList(Resource):
    def get(self, subject_code, topic_code):
        relationship_list = RelationshipModel.fetchAllForTopic(topic_code)

        if relationship_list and TopicModel.findByCode(topic_code).subject_fk == int(subject_code):
                return relationship_list
        return {"message": "No relationships found."}



