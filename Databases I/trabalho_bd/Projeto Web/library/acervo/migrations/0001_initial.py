# Generated by Django 2.2.1 on 2019-05-19 19:15

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Livro',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('titulo', models.TextField()),
                ('autor', models.TextField()),
                ('capa', models.TextField()),
                ('sumario', models.TextField()),
                ('numeroExemplares', models.IntegerField()),
            ],
        ),
    ]
