# Generated by Django 2.2.1 on 2019-05-18 18:22

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('book', '0002_auto_20190518_1821'),
    ]

    operations = [
        migrations.RenameField(
            model_name='book',
            old_name='numberOfExamplar',
            new_name='numberOfExamplars',
        ),
    ]
