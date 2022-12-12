from django.shortcuts import render, HttpResponse
from django.db import connection
from django.shortcuts import redirect
from datetime import date, timedelta


def minhas_reservas_view(request, *args, **kargs):
    user_id = request.session.get('user_id')

    if request.method == 'POST':
        print(request.POST)
        if request.POST.get("formData[2][value]") == "reservar":
            print(request.POST)
            print("reserving")
            cod_livro = request.POST.get("formData[0][value]")
            qtd_exemplares_disp = request.POST.get("formData[1][value]")
            data_limite = ""
            disponibilidade = 0

            if int(qtd_exemplares_disp) > 0:
                disponibilidade = 1
                today = date.today()
                data_limite = (today + timedelta(days=2)).strftime("%Y/%m/%d")
                print(data_limite)
          
            realizarReserva(user_id, cod_livro, data_limite, disponibilidade)
          

          
            return HttpResponse()
        elif request.POST.get("formData[0][value]") == 'cancelar_reserva':
            print(request.POST)
            cod_reserva = request.POST.get("formData[1][value]")
            print("deleting")
            print(cod_reserva)
            cancelarReserva(cod_reserva)
            return HttpResponse()
            
    else:
        print("its get")
        if request.session.get('user_email'):
            print("its logged in")
            reservas = buscarTodasAsReservas(user_id)   
            context = {
                "reserva": "true",
                "reservas": reservas,
            } 
            return render(request, "minhasReservasScreen.html", context)
        else:
            return redirect('/login/')
    


def dictfetchall(cursor):
    "Return all rows from a cursor as a dict"
    columns = [col[0] for col in cursor.description]
    return [
        dict(zip(columns, row))
        for row in cursor.fetchall()
    ]

def buscarTodasAsReservas(user_id):
    with connection.cursor() as cursor:
        cursor.execute("Select *, date_format(r.data_limite, '%%d/%%m/%%Y') as data_limite_reserva, a.nome as nome_autor, r.pk_codigo as codigo_reserva \
             from ((Usuario as u join Reserva as r on u.pk_id = r.fk_id_usuario)\
        join Livro as l on r.fk_cod_livro = l.pk_cod_livro) join Autor as a on l.fk_id_autor = a.pk_id_autor where u.pk_id = %s", [user_id])
        lista_reservas = dictfetchall(cursor)
        for i in lista_reservas:
            if(i.get('disponivel') == 1):
                i.update(disponivel = 'Sim')
            elif(i.get('disponivel') == 0):
                i.update(disponivel = 'Não')
    # print(lista_reservas)

    return lista_reservas

def realizarReserva(user_id, cod_livro, data_limite, disponibilidade):


    with connection.cursor() as cursor:
        cursor.execute("Insert into Reserva (fk_id_usuario, fk_cod_livro, data_limite, disponivel) values (""%s"", ""%s"", ""%s"", ""%s"")", [user_id, cod_livro, data_limite, disponibilidade])
    #     lista_reservas = dictfetchall(cursor)
    #     for i in lista_reservas:
    #         if(i.get('disponivel') == 1):
    #             i.update(disponivel = 'Sim')
    #         else: 
    #             i.update(disponivel = 'Não')

    # return lista_reservas

def cancelarReserva(cod_reserva):
    with connection.cursor() as cursor:
        print("Code reservation ")
        print(cod_reserva)
        cursor.execute("Delete from Reserva as r where r.pk_codigo = %s", [cod_reserva])
