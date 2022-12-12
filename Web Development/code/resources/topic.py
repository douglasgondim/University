import sqlite3
from flask_restful import Resource, reqparse
from models.topic import TopicModel
from flask_jwt import jwt_required, current_identity

class TopicCreate(Resource):
    table_name = 'topic'

    parser = reqparse.RequestParser()

    parser.add_argument('name',
    type=str,
    required=True,
    help="A name is required!")

    parser.add_argument('description',
    type=str,
    required=True,
    help="A subject description is required!")

    @jwt_required()
    def post(self, subject_code):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}

        data = TopicCreate.parser.parse_args()
        topic = TopicModel.findByName(data['name'])

        if topic and topic.subject_fk == int(subject_code):
            return {'message': 'This topic has already been registered.'}
        
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = "INSERT INTO {table} VALUES (Null, ?, ?, ?)".format(table=self.table_name)
        cursor.execute(query, (data['name'], data['description'], 
        subject_code))

        connection.commit()
        connection.close()

        return {"message": "Topic created successfully!"}


class Topic(Resource):
    table_name = 'topic'

    parser = reqparse.RequestParser()

    parser.add_argument('name',
    type=str,
    required=True,
    help="A name is required!")

    parser.add_argument('description',
    type=str,
    required=True,
    help="A subject description is required!")

    @jwt_required()
    def get(self, subject_code, topic_code):
        topic = TopicModel.findByCode(topic_code)
        if topic and topic.subject_fk == int(subject_code):
            return {"topic": topic.__json__()}
        return {"message": "Topic not found"}

    @jwt_required()
    def put(self, subject_code, topic_code):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}

        data = Topic.parser.parse_args()
        topic = TopicModel.findByCode(topic_code)
        if not topic or topic.subject_fk != int(subject_code):
            return {"message": "Topic not found."}

        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""UPDATE {self.table_name}
        SET 
        name = "{data['name']}",
        description = "{data['description']}",
        subject_fk = {subject_code}

        WHERE topic_code_pk = "{topic.topic_code_pk}"
        """ 

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "Topic updated successfully."}
    
    @jwt_required()
    def delete(self, subject_code, topic_code):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted"}

        topic = TopicModel.findByCode(topic_code)
        if not topic or topic.subject_fk != int(subject_code):
            return {"message": "Topic not found."}

        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")
        
        query = f"""DELETE from {self.table_name}
        WHERE topic_code_pk = "{topic.topic_code_pk}" """

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "Topic deleted succesffuly."}

class TopicList(Resource):
    table_name = 'topic'

    @jwt_required()
    def get(self, subject_code):
        topic_list = TopicModel.fetchAllBySubject(subject_code)
       
        if topic_list:
            return topic_list
        return {"message": "No topics found."}




