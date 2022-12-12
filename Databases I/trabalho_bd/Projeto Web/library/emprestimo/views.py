from django.shortcuts import render, HttpResponse
from django.db import connection
from django.shortcuts import redirect
from datetime import date, timedelta



def meus_emprestimos_view(request, *args, **kargs):
    user_id = request.session.get('user_id')
    if request.method == 'POST':
        print(request.POST)
        # cod_livro = request.POST.get("formData[0][value]")
        qtd_exemplares_disp = request.POST.get("formData[1][value]")
        cod_emprestimo = request.POST.get("formData[1][value]")
        print(cod_emprestimo)
        renovarEmprestimo(cod_emprestimo)
        # print(cod_livro, qtd_exemplares_disp)
        return HttpResponse()
    else:
        if request.session.get('user_email'):
            emprestimos = buscarTodosOsEmprestimos(user_id)
            # for i in emprestimos:
            #     print(i)
            context = {
                "emprestimo": "true",
                "emprestimos": emprestimos,
            }
            # for i in emprestimos:
            #     print(i)
            return render(request, "meusEmprestimosScreen.html", context)
        else:
            return redirect('/login/')


def dictfetchall(cursor):
    "Return all rows from a cursor as a dict"
    columns = [col[0] for col in cursor.description]
    return [
        dict(zip(columns, row))
        for row in cursor.fetchall()
    ]


def buscarTodosOsEmprestimos(user_id):
    with connection.cursor() as cursor:
        cursor.execute("Select *, date_format(e.data_limite_devolucao, '%%d/%%m/%%Y') as data_limite_devolucao, a.nome as nome_autor, e.pk_codigo as codigo_emprestimo \
             from ((((Usuario as u join Emprestimo as e on u.pk_id = e.fk_id_usuario)\
        join Exemplar as ex on e.fk_cod_exemp = ex.pk_cod_exemp) join\
             Livro as l on ex.fk_cod_livro = l.pk_cod_livro) join Autor as a on l.fk_id_autor = a.pk_id_autor) where u.pk_id = %s", [user_id])
        lista_emprestimos = dictfetchall(cursor)
        # print("hey")
        # print("%s", [user_id])
    return lista_emprestimos

def renovarEmprestimo(cod_emprestimo):
    today = date.today()
    data_limite_devolucao = (today + timedelta(days=30)).strftime("%Y/%m/%d")
    print(data_limite_devolucao)
    with connection.cursor() as cursor:
        cursor.execute("update Emprestimo as e set data_limite_devolucao = %s where e.pk_codigo = %s", [data_limite_devolucao, cod_emprestimo])


