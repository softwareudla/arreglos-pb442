#include <stdio.h>

#define MAX_ALUMNOS 5
#define MAX_ASIGNATURAS 3
#define NOMBRE_LEN 50

int main(int argc, char *argv[]) {
    float notas[MAX_ALUMNOS][MAX_ASIGNATURAS], promedioEstudiante, maximaNota, minimaNota;
    int totalAprobados, totalReprobados;
    char nombresAlumnos[MAX_ALUMNOS][NOMBRE_LEN];
    char nombresAsignaturas[MAX_ASIGNATURAS][NOMBRE_LEN];

    for (int i = 0; i < MAX_ALUMNOS; i++) {
        printf("Ingrese el nombre del alumno %d: ", i + 1);
        scanf("%s", nombresAlumnos[i]);
    }

    for (int j = 0; j < MAX_ASIGNATURAS; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j + 1);
        scanf("%s", nombresAsignaturas[j]);
    }

    for (int estudiante = 0; estudiante < MAX_ALUMNOS; estudiante++) {
        printf("\nIngrese las calificaciones de %s\n", nombresAlumnos[estudiante]);

        for (int asignatura = 0; asignatura < MAX_ASIGNATURAS; asignatura++) {
            do {
                printf("Ingrese la calificacion de %s: ", nombresAsignaturas[asignatura]);
                scanf("%f", &notas[estudiante][asignatura]);

                if (notas[estudiante][asignatura] < 0 || notas[estudiante][asignatura] > 10) {
                    printf("La calificacion ingresada no es valida, intente de nuevo.\n");
                }
            } while (notas[estudiante][asignatura] < 0 || notas[estudiante][asignatura] > 10);
        }
    }

    for (int estudiante = 0; estudiante < MAX_ALUMNOS; estudiante++) {
        promedioEstudiante = 0;
        maximaNota = notas[estudiante][0];
        minimaNota = notas[estudiante][0];

        for (int asignatura = 0; asignatura < MAX_ASIGNATURAS; asignatura++) {
            promedioEstudiante += notas[estudiante][asignatura];

            if (notas[estudiante][asignatura] > maximaNota) {
                maximaNota = notas[estudiante][asignatura];
            }

            if (notas[estudiante][asignatura] < minimaNota) {
                minimaNota = notas[estudiante][asignatura];
            }
        }

        promedioEstudiante /= MAX_ASIGNATURAS;
        printf("El promedio de %s es %.2f\n", nombresAlumnos[estudiante], promedioEstudiante);
        printf("Nota maxima de %s: %.2f\n", nombresAlumnos[estudiante], maximaNota);
        printf("Nota minima de %s: %.2f\n\n", nombresAlumnos[estudiante], minimaNota);
    }

    for (int asignatura = 0; asignatura < MAX_ASIGNATURAS; asignatura++) {
        promedioEstudiante = 0;
        maximaNota = notas[0][asignatura];
        minimaNota = notas[0][asignatura];
        totalAprobados = 0;
        totalReprobados = 0;

        for (int estudiante = 0; estudiante < MAX_ALUMNOS; estudiante++) {
            promedioEstudiante += notas[estudiante][asignatura];

            if (notas[estudiante][asignatura] > maximaNota) {
                maximaNota = notas[estudiante][asignatura];
            }

            if (notas[estudiante][asignatura] < minimaNota) {
                minimaNota = notas[estudiante][asignatura];
            }

            if (notas[estudiante][asignatura] >= 6) {
                totalAprobados++;
            } else {
                totalReprobados++;
            }
        }

        promedioEstudiante /= MAX_ALUMNOS;
        printf("El promedio de %s es %.2f\n", nombresAsignaturas[asignatura], promedioEstudiante);
        printf("Nota maxima de %s: %.2f\n", nombresAsignaturas[asignatura], maximaNota);
        printf("Nota minima de %s: %.2f\n", nombresAsignaturas[asignatura], minimaNota);
        printf("Aprobados de %s: %d\n", nombresAsignaturas[asignatura], totalAprobados);
        printf("Reprobados de %s: %d\n\n", nombresAsignaturas[asignatura], totalReprobados);
    }

    return 0;
}
