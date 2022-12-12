import sqlite3
from flask_restful import Resource, reqparse
from flask_jwt import jwt_required, current_identity
from models.user import UserModel

class UserRegister(Resource):
    table_name = 'user'

    parser = reqparse.RequestParser()

    parser.add_argument('name',
    type=str,
    required=True,
    help="A name is required!")

    parser.add_argument('siape',
    type=int,
    required=True,
    help="A Siape is required!")

    parser.add_argument('password',
    type=str,
    required=True,
    help="A password is required!")

    parser.add_argument('level',
    type=str,
    required=True,
    help="A user level is required!")

    def post(self):
        data = UserRegister.parser.parse_args()

        if UserModel.findBySiape(data['siape']):
            return {'message': 'This SIAPE has already been registered.'}
        
        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"INSERT INTO {self.table_name} VALUES (?, ?, ?, ?)"
        cursor.execute(query, (data['name'], data['siape'], 
        data['password'], data['level']))

        connection.commit()
        connection.close()

        return {"message": "User created successfully!"}


class User(Resource):
    table_name = 'user'

    parser = reqparse.RequestParser()

    parser.add_argument('name',
    type=str,
    required=True,
    help="A name is required!")

    parser.add_argument('siape',
    type=int,
    required=True,
    help="A SIAPE is required!")

    parser.add_argument('password',
    type=str,
    required=True,
    help="A password is required!")

    parser.add_argument('level',
    type=str,
    required=True,
    help="A user level is required!")

    @jwt_required()
    def get(self, siape_pk):
        current_user = current_identity
        if(current_user.level != "admin"): return {"message": "Access not granted."}
        user = UserModel.findBySiape(siape_pk)
        if user:
            return {"user": user.__json__()}
        return {"message": "User not found"}

    @jwt_required()
    def put(self, siape_pk):
        data = User.parser.parse_args()
        user = UserModel.findBySiape(siape_pk)
        if not user:
            return {"message": "User not found."}

        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")

        query = f"""UPDATE {self.table_name}
        SET 
        name = "{data['name']}",
        siape_pk = "{data['siape']}",
        password = "{data['password']}",
        level = "{data['level']}"

        WHERE siape_pk = "{siape_pk}"
        """ 

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "User updated successfully."}
    
    @jwt_required()
    def delete(self, siape_pk):
        user = UserModel.findBySiape(siape_pk)
        if not user:
            return {"message": "User not found."}

        connection = sqlite3.connect('database/data.db')
        cursor = connection.cursor()
        cursor.execute("PRAGMA foreign_keys = ON")
        
        query = f"""DELETE from {self.table_name}
        WHERE siape_pk= "{siape_pk}" """

        cursor.execute(query)
        connection.commit()
        connection.close()

        return {"message": "User deleted succesffuly."}




