from flask import Flask, jsonify, request
from flask_restful import Resource, Api, reqparse
from flask_jwt import JWT
from flask_cors import CORS

from resources.user import UserRegister, User
from resources.subject import SubjectCreate, Subject, SubjectList
from resources.topic import TopicCreate, Topic, TopicList
from resources.relationship import Relationship, RelationshipList
from resources.prerequisite import PreRequisite, PreRequisiteList, PostRequisiteList

from security import authenticate, identity

from datetime import timedelta



app = Flask(__name__)
CORS(app)
app.secret_key = 'secret'
api = Api(app)



app.config['JWT_AUTH_USERNAME_KEY'] = 'siape'
app.config['JWT_EXPIRATION_DELTA'] = timedelta(seconds=3600)

jwt = JWT(app, authenticate, identity)

api.add_resource(UserRegister, '/register')
api.add_resource(User, '/user/<int:siape_pk>')

api.add_resource(SubjectCreate, '/subject')
api.add_resource(Subject, '/subject/<string:subject_code>')
api.add_resource(SubjectList, '/subject')

api.add_resource(TopicCreate, '/subject/<string:subject_code>')
api.add_resource(Topic, '/subject/<string:subject_code>/<string:topic_code>')
api.add_resource(TopicList, '/subject/<int:subject_code>/topics')

api.add_resource(Relationship, """/subject/relationship/<string:subject_code_1>/<string:topic_code_1>/<string:subject_code_2>/<string:topic_code_2>""")
api.add_resource(RelationshipList, "/subject/relationships/<int:subject_code>/<int:topic_code>")

api.add_resource(PreRequisite, "/subject/prerequisite/<int:subject_fk>/<int:subject_requirement_fk>")
api.add_resource(PreRequisiteList, "/subject/<int:subject_code>/prerequisites")
api.add_resource(PostRequisiteList, "/subject/<int:subject_code>/postrequisites")
