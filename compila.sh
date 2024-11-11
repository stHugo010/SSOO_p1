# Generar archivo .o de libreria
gcc -c libreria.c -o libreria.o

#Generar libreria.a
ar -rv liblibreria.a libreria.o

#Generar ejecutable de test.c enlazado con la libreria
gcc -o test test.c -L. -llibreria

echo "Formato de uso: ./test [-head, -tail, -longLines] [N]"
