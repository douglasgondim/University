from django.db import models

class Book(models.Model):
    title = models.TextField()
    author = models.TextField()
    summary = models.TextField()
    numberOfExamplars = models.IntegerField()



