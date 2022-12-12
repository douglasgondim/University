"""biblioteca URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from acervo.views import home_view, livro_view, pesquisar_view
from cadastro.views import cadastro_view
from reserva.views import minhas_reservas_view
from emprestimo.views import meus_emprestimos_view
from login.views import login_view, redefinir_senha_view, autenticar_user_view, auth


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', home_view, name='homepage'),
    path('login/', login_view, name='login'),
    path('cadastro/', cadastro_view, name='cadastro'),
    # path('livro/', livro_view, name='livro'),
    path('reservas/', minhas_reservas_view, name='reservas'),
    path('emprestimos/', meus_emprestimos_view, name='emprestimos'),
    path('redefinir-senha/', redefinir_senha_view, name='redefinir-senha'),
    path('autenticar-user/', autenticar_user_view, name='autenticar-user'),
    path('auth/', auth, name='auth'),
    path('pesquisar/', pesquisar_view, name='pesquisar'),

]
