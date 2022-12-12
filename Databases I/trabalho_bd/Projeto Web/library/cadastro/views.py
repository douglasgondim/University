from django.shortcuts import render

def cadastro_view(request, *args, **kargs):
    return render(request, "cadastroScreen.html", {})