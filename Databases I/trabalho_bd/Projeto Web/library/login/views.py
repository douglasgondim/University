from django.shortcuts import render, HttpResponse
from django.db import connection
from django.contrib.auth import authenticate, login
from acervo.views import home_view
from django.shortcuts import redirect


def login_view(request, *args, **kargs):

    return render(request, "loginScreen.html", {})

# def auth2(request):
#     username = request.POST['username']
#     password = request.POST['password']
#     user = authenticate(request, username=username, password=password)
#     if user is not None:
#         login(request, user)
#         # Redirect to a success page.
#         ...
#     else:
#         # Return an 'invalid login' error message.
#         ...
  
def auth(request, *args, **kargs):
    if request.session.get('user_email'):
        request.session.flush()
        return redirect('/login/')
    else:
        # print(request.POST)
        email = request.POST.get('email')
        usuario = buscarUsuario(email)
        print(usuario)
        if usuario != [] and usuario[0].get('senha') == request.POST.get('password'):
            print("logged in")
            request.session['user_email'] =  email
            request.session['user_id'] =  usuario[0].get('pk_id')
            request.session.set_expiry(600)

            print(request.session.get_expiry_date())
            return redirect('/')
            
        else:
            return redirect('/login/')


def redefinir_senha_view(request, *args, **kargs):
    if request.method == 'POST':
       print(request.POST)
       cpf = request.POST.get("formData[1][value]")
       senha = request.POST.get("formData[3][value]")
       
       print(cpf)
       with connection.cursor() as cursor:
            cursor.execute("Select * from Usuario as u join Login as l on u.fk_email= l.pk_email where u.cpf = %s", [cpf])
            user_data = dictfetchall(cursor)
            print(user_data)
            # print(cursor)
            email_database = user_data[0].get("pk_email")
            rg = user_data[0].get("rg")
            print(rg, email_database)
       if request.POST.get("formData[2][value]") == rg and request.POST.get("formData[0][value]") == email_database:
            
            print("success")
            with connection.cursor() as cursor:
                cursor.execute("update Usuario as u join Login as l on u.fk_email= l.pk_email set l.senha = %s where u.cpf = %s", [senha, cpf])
            # return render(request, "redefinirSenhaScreen.html", {'cpf': cpf})
            # alert("Senha alterada com sucesso!")
            return HttpResponse()
       else:
            print("no")
            return redirect('/autenticar-user/')
    else:
        print("way")
        return redirect('/login/')


def autenticar_user_view(request, *args, **kargs):
    
   
    return render(request, "autenticarUserScreen.html", {})



def buscarUsuario(self):
    with connection.cursor() as cursor:
        # cursor.execute("UPDATE bar SET foo = 1 WHERE baz = %s", [self.baz])
        cursor.execute("Select * from Usuario as u join Login as l on u.fk_email= l.pk_email where l.pk_email = %s", [self])
        usuario = dictfetchall(cursor)
    return usuario

def dictfetchall(cursor):
    "Return all rows from a cursor as a dict"
    columns = [col[0] for col in cursor.description]
    return [
        dict(zip(columns, row))
        for row in cursor.fetchall()
    ]

