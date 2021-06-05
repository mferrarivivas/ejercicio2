#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<mpi.h>

void main(int argc, char **argv){

int node, numtasks;
char mensaje[23]="";
char aux[23]="";
MPI_Status status;

MPI_Init(&argc, &argv);

MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

MPI_Comm_rank(MPI_COMM_WORLD, &node);

if(argc!=2) {
  printf("Falta especificar el numero de vueltas.\n"); 
  exit(1);
} 

int i=0;

while (i < atoi(argv[1])){
  /*strcpy(mensaje,"hey desde ");
  sprintf(aux,"%d",node);
  strcat(mensaje,aux);*/
  
  if ( node == (numtasks - 1) ){
    MPI_Send(mensaje, 23, MPI_CHAR, 0, 0, MPI_COMM_WORLD); 
    printf("Vuelta Numero: %d. El proceso %d envia M%d con el dato 'A'al proceso 0:\n", i+1,node, node);
  
  }
      
  else{
      MPI_Send(mensaje, 23, MPI_CHAR, node + 1, 0, MPI_COMM_WORLD);
  
      printf("Vuelta Numero: %d. El proceso %d envia M%d con el dato 'A'al proceso %d:\n",i+1, node, node, node+1);
  
  }
     


  if (node == 0)
     MPI_Recv(mensaje, 23, MPI_CHAR, numtasks - 1, 0, MPI_COMM_WORLD, &status);
  else
     MPI_Recv(mensaje, 23, MPI_CHAR, node - 1, 0, MPI_COMM_WORLD, &status);
  MPI_Barrier(MPI_COMM_WORLD);
  //printf("Hola soy el proceso %d, es la vuelta número %d y recibo %s:\n", node, i+1,mensaje);
  i++;
}

MPI_Finalize();

}

