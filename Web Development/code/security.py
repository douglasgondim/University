from werkzeug.security import safe_str_cmp
from models.user import UserModel

def authenticate(siape, password):
    user = UserModel.findBySiape(siape)
    if user and safe_str_cmp(user.password, password):
        return user

def identity(payload):
    user_id = payload['identity']
    return UserModel.findBySiape(user_id)
