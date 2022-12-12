# Generated by Django 2.2.1 on 2019-05-25 14:43

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Login',
            fields=[
                ('pk_email', models.CharField(max_length=40, primary_key=True, serialize=False)),
                ('senha', models.CharField(blank=True, max_length=30, null=True)),
                ('nivel', models.IntegerField(blank=True, null=True)),
            ],
            options={
                'db_table': 'Login',
                'managed': False,
            },
        ),
    ]