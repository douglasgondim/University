from django.db import models



class Login(models.Model):
    pk_email = models.CharField(primary_key=True, max_length=40)
    senha = models.CharField(max_length=30, blank=True, null=True)
    nivel = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Login'



