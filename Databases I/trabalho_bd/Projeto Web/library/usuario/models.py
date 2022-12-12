from django.db import models
from login.models import Login

class Contato(models.Model):
    pk_contato = models.AutoField(primary_key=True)
    telefone = models.IntegerField(blank=True, null=True)
    endereco = models.CharField(max_length=40, blank=True, null=True)
    cidade = models.CharField(max_length=40, blank=True, null=True)
    estado = models.CharField(max_length=3, blank=True, null=True)
    cep = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Contato'

class Usuario(models.Model):
    pk_id = models.AutoField(primary_key=True)
    nome = models.CharField(max_length=40, blank=True, null=True)
    cpf = models.CharField(max_length=15, blank=True, null=True)
    rg = models.CharField(max_length=15, blank=True, null=True)
    fk_email = models.ForeignKey(Login, models.DO_NOTHING, db_column='fk_email', blank=True, null=True)
    fk_contato = models.ForeignKey(Contato, models.DO_NOTHING, db_column='fk_contato', blank=True, null=True)
    foto = models.CharField(max_length=30, blank=True, null=True)
    limite_livro = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Usuario'

