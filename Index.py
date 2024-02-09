import os

comando = "g++ Setup.c++ -o Setup -lsfml-graphics -lsfml-window -lsfml-system"
comando2 = "./Setup"

os.system(comando)
os.system(comando2)