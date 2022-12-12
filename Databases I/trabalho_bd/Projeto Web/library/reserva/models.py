from django.db import models
from acervo.models import Livro
from usuario.models import Usuario

class Reserva(models.Model):
    pk_codigo = models.AutoField(primary_key=True)
    fk_id_usuario = models.ForeignKey(Usuario, models.DO_NOTHING, db_column='fk_id_usuario', blank=True, null=True)
    fk_cod_livro = models.ForeignKey(Livro, models.DO_NOTHING, db_column='fk_cod_livro', blank=True, null=True)
    data_limite = models.DateField(blank=True, null=True)
    disponivel = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Reserva'