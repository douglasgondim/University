# Generated by Django 2.2.1 on 2019-05-18 18:21

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('book', '0001_initial'),
    ]

    operations = [
        migrations.RenameField(
            model_name='book',
            old_name='numberOfExamplars',
            new_name='numberOfExamplar',
        ),
    ]
