from socket import *
import os.path
from os import path


myHost = ''
portNumber = 50004
format = 'utf-8'
headerSize = 1024
socketObject = socket(AF_INET, SOCK_STREAM)

socketObject.bind((myHost, portNumber))

socketObject.listen(1)

while True:
    try:
        connection, address = socketObject.accept()
        print("Server Connected by ", address)

        data = connection.recv(headerSize)
        if not data: break
        fileURL = data.decode(format).split(" ")[1][1:]
        
        if(path.exists(fileURL)):
            f = open(fileURL, "r")  
            outputdata = f.read().splitlines()
            connection.send("HTTP/1.1 200 OK\r\n\r\n".encode(format))

            for i in outputdata:
                connection.send(f"<html><head></head><body><p>{i}</p></body></html>\r\n".encode(format))
            f.close()
        else:
            connection.send("HTTP/1.1 404 Not Found\r\n\r\n".encode(format))
            connection.send("<html><head></head><body><h1>404 Not Found</h1></body></html>\r\n".encode(format))
           
        connection.close()
    except:
        connection.close()
