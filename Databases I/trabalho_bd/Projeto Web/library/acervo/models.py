from django.db import models


class Editora(models.Model):
    pk_codigo = models.AutoField(primary_key=True)
    nome = models.CharField(max_length=30, blank=True, null=True)
    contato = models.IntegerField(blank=True, null=True)
    cnpj = models.CharField(max_length=15, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Editora'

class Autor(models.Model):
    nome = models.CharField(max_length=40, blank=True, null=True)
    pk_id_autor = models.AutoField(primary_key=True)
    biografia = models.CharField(max_length=300, blank=True, null=True)
    foto = models.CharField(max_length=30, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Autor'



class Livro(models.Model):
    pk_cod_livro = models.AutoField(primary_key=True)
    titulo = models.CharField(max_length=50, blank=True, null=True)
    fk_id_autor = models.ForeignKey(Autor, models.DO_NOTHING, db_column='fk_id_autor', blank=True, null=True)
    fk_id_editora = models.ForeignKey(Editora, models.DO_NOTHING, db_column='fk_id_editora', blank=True, null=True)
    genero = models.CharField(max_length=30, blank=True, null=True)
    capa = models.CharField(max_length=30, blank=True, null=True)
    sumario = models.CharField(max_length=500, blank=True, null=True)
    num_pags = models.IntegerField(blank=True, null=True)
    pais = models.CharField(max_length=30, blank=True, null=True)
    data_publicacao = models.DateField(blank=True, null=True)
    qtd_exemp = models.IntegerField(blank=True, null=True)
    palavras_chave = models.CharField(max_length=50, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Livro'

class Exemplar(models.Model):
    pk_cod_exemp = models.AutoField(primary_key=True)
    fk_cod_livro = models.ForeignKey('Livro', models.DO_NOTHING, db_column='fk_cod_livro', blank=True, null=True)
    edicao = models.IntegerField(blank=True, null=True)
    ano = models.IntegerField(blank=True, null=True)
    estado = models.CharField(max_length=50, blank=True, null=True)
    disp = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Exemplar'





