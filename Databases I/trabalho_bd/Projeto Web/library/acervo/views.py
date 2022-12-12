from django.shortcuts import render
from . models import Livro
from . models import Editora
from usuario.models import Usuario, Contato
from django.db import connection
from django.shortcuts import redirect
from django.contrib import messages

def home_view(request, *args, **kargs):
   
    if request.session.get('user_email'):

        # usuario = buscarUsuario()
        # acervo = Livro.objects.raw('Select * from Livro as l join Editora as e on l.id_editora = e.codigo where e.nome="Net"')
        acervo = buscarTodosOsLivros()


        # print(usuario.get('nome'))
        # editora = Editora.objects.raw('Select * from Editora')
        # acervo = Livro.objects.raw('Select *, a.nome from Livro as l join Autor as a on l.fk_id_autor = a.pk_id_autor ')
        # user_email = Usuario.objects.raw('Select * from Login as l join Usuario as u on u.fk_email = l.pk-email ')
        
        # print(user_email.pk_email)
        # print(request.POST)
        # print(request.POST.get('password'))
        # for l in acervo:
        #     print(l)
        # print(todosOsLivros())
        
        context = {
            "acervo": acervo,
            # 'editora': editora
            # "test2": "search" 
        }
        
        return render(request, "homepageScreen.html", context)
    else:
        # print("Flop")
        # print(request.session.get('email'))
        return redirect('/login/')



def livro_view(request, *args, **kargs):
    return render(request, "livro.html", {})

def dictfetchall(cursor):
    "Return all rows from a cursor as a dict"
    columns = [col[0] for col in cursor.description]
    return [
        dict(zip(columns, row))
        for row in cursor.fetchall()
    ]

def buscarTodosOsLivros():
    with connection.cursor() as cursor:
        # cursor.execute("UPDATE bar SET foo = 1 WHERE baz = %s", [self.baz])
        cursor.execute("Select *, a.nome as nome_autor from Livro as l join Autor as a on l.fk_id_autor = a.pk_id_autor")
        lista = dictfetchall(cursor)
        # print(lista)
    return lista

def pesquisar_view(request, *args, **kargs):
    # print(request.POST)
    pesquisa = request.POST.get('pesquisa')

    resultado_pesquisa = pesquisarLivro(pesquisa)
  
    context = {
        "resultado_pesquisa": resultado_pesquisa,
        "ultimo_titulo_procurado": pesquisa,
    
    }
    
    return render(request, "pesquisarScreen.html", context)


def pesquisarLivro(pesquisa):
  
    with connection.cursor() as cursor:
        cursor.execute('Select *, a.nome as nome_autor from Livro as l join Autor as a on l.fk_id_autor = a.pk_id_autor where (l.titulo like "%%%s%%") or (l.palavras_chave like "%%%s%%") or (a.nome like "%%%s%%");' % (pesquisa, pesquisa, pesquisa))
        resultado_pesquisa = dictfetchall(cursor)
        print(resultado_pesquisa)
 
    return resultado_pesquisa