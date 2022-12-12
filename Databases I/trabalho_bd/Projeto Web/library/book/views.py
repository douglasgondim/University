from django.http import HttpResponse
from django.shortcuts import render


def home_view(request, *args, **kargs):
    # return HttpResponse("<h1>Hey</h1>")
    return render(request, "home.html", {})