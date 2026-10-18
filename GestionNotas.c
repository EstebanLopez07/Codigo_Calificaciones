#include<stdio.h>

float notas[5][3];
float promedioEstudiante;
float promedioMateria;
int aprobados = 0;
int reprobados = 0;


float validacion(int estudiante, int asignatura){

    float nota;

    do{

        printf("Ingrese la nota del estudiante %d en la asignatura %d (0-10)\n", estudiante + 1, asignatura + 1);
        scanf("%f", &nota);

        if (nota < 0.0 || nota > 10.0)
        {
            printf("[error]: Solo se admiten notas entre 0 - 10\n");
        }

    }while (nota < 0.0 || nota > 10.0);

    return nota;
}

int main(){

    for (int i = 0; i < 5; i++)
    {
       for (int j = 0; j < 3; j++)
       {
            notas[i][j] = validacion(i, j);
       } 
    }

    for (int i = 0; i < 5; i++)
    {
        float sumaEstudiante = 0.0;
        float notaMaxima = 0.0;
        float notaMinima = notas[i][0];
        for (int j = 0; j < 3; j++)
        {
            sumaEstudiante += notas[i][j];

            if (notas[i][j] > notaMaxima)
            {
                notaMaxima = notas[i][j];
            }

            if (notas[i][j] < notaMinima)
            {
                notaMinima = notas[i][j];
            }
            
        }
        
        promedioEstudiante = sumaEstudiante/3;

        printf("Estudiante %d:\n", i + 1);
        printf("Promedio: %.2f\n", promedioEstudiante);
        printf("Nota Maxima: %.2f\n", notaMaxima);
        printf("Nota Minima: %.2f\n", notaMinima);

    }
    
    for (int j = 0; j < 3; j++)
    {
        float sumaMateria = 0.0;
        float materiaMaxima = 0.0;
        float materiaMinima = notas[0][j];
        int aprobados = 0;
        int reprobados = 0;
        for (int i = 0; i < 5; i++)
        {
            sumaMateria += notas[i][j];

            if (notas[i][j] > materiaMaxima)
            {
                materiaMaxima = notas[i][j];
            }
            
            if (notas[i][j] < materiaMinima)
            {
                materiaMinima = notas[i][j];
            }
            
            if (notas[i][j] >= 6)
            {
                aprobados++;
            }
            
            if (notas[i][j] < 6)
            {
                reprobados++;
            }
            
        }
        
        promedioMateria = sumaMateria/5;
        printf("Promedio materia %d: %.2f\n", j + 1,promedioMateria);
        printf("Nota Maxima de la Materia: %.2f\n", materiaMaxima);
        printf("Nota Minima de la Materia: %.2f\n", materiaMinima);
        printf("Aprobados: %d\n", aprobados);
        printf("Reprobados: %d\n", reprobados);
    }
    
    return 0;
}
