#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Structure représentant un drone dans l'espace 3D*/
typedef struct {
    int id;
    float x;
    float y;
    float z;
} Drone;
/*Fonction calculant la distance euclidienne entre deux drones*/
float distance(Drone *a, Drone *b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    float dz = a->z - b->z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main()
{
    int n = 10000;
    /*Allocation dynamique de mémoirepour stocker tous les drones*/
    Drone *essaim;
    essaim = (Drone*) malloc(n * sizeof(Drone));
    /* Vérification de l'allocation mémoire */
    if(essaim == NULL)
    {
        printf("Erreur mémoire\n");
        return 1;
    }
    /*Initialisation des drones avec des coordonnées aléatoires*/
    Drone *p = essaim;
    for(int i = 0; i < n; i++, p++)
    {
        p->id = i;
        p->x = rand() % 100;
        p->y = rand() % 100;
        p->z = rand() % 100;
    }
    /*Variables pour stocker la distance minimale trouvée*/
    float min = 999999;

    Drone *bestA = NULL;
    Drone *bestB = NULL;

    /*Recherche des deux drones les plus proches*/
    Drone *iPtr = essaim;

    for(int i = 0; i < n; i++, iPtr++)
    {
        /* Le second pointeur commence après le premier drone */
        Drone *jPtr = iPtr + 1;

        for(int j = i + 1; j < n; j++, jPtr++)
        { 
            /* Calcul de distance */
            float d = distance(iPtr, jPtr);
            /* Vérification de la distance minimale */
            if(d < min)
            {
                min = d;
                bestA = iPtr;
                bestB = jPtr;
            }
        }
    }
    /*Affichage des résultats*/
    printf("Distance minimale : %f\n", min);
    printf("Drone 1 : %d\n", bestA->id);
    printf("Drone 2 : %d\n", bestB->id);
    /*Libération de la mémoire*/
    free(essaim);

    return 0;
}