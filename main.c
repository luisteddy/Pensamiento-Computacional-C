//Luis Edgar González Vargas  Seccion A
//Implementado en Replit
#include <stdio.h>
#include <string.h>

typedef struct Ensenanza_media{
  float PrimeroMedio;
  float SegundoMedio;
  float TerceroMedio;
  float CuartoMedio;
}Notas;

typedef struct Pruebas{
  int Matematicas;
  int Ciencias;
  int Historia;
  int Lenguaje;
  int promedio;
}PSU;

typedef struct Personas{
  char Nombre[100];
  int Rut;
  float Promedio_final;
  char Carrera[50];
  Notas Notas_media;
  PSU Psu_Pruebas;
  float Puntaje;
}Estudiantes;


//Registra los datos de cada estudiante ingresado en la estructura estudiantes.
void registro(Estudiantes* lista, char* _nombre, char* _carrera, int _rut, float _nota1, float _nota2, float _nota3, float _nota4, int _psu_mat, int _psu_len,int _psu_cie, int _psu_his, int* l, int* a, int* b){
  int i=0;
  float _promedio = 0;
  if (*l < 40){
    if (*a < 20 && (strcmp(_carrera, "Computacion"))==0){
    strcpy((lista+*l)->Nombre, _nombre);
    strcpy((lista+*l)->Carrera, _carrera);
    (lista+*l)->Rut = _rut;
    (lista+*l)->Notas_media.PrimeroMedio = _nota1;
    (lista+*l)->Notas_media.SegundoMedio = _nota2;
    (lista+*l)->Notas_media.TerceroMedio = _nota3;
    (lista+*l)->Notas_media.CuartoMedio = _nota4;
    _promedio = ((lista+*l)->Notas_media.PrimeroMedio + (lista+*l)->Notas_media.SegundoMedio + (lista+*l)->Notas_media.TerceroMedio + (lista+*l)->Notas_media.CuartoMedio)/4;
    (lista+*l)->Promedio_final = _promedio;
    (lista+*l)->Psu_Pruebas.Matematicas = _psu_mat;
    (lista+*l)->Psu_Pruebas.Lenguaje = _psu_len;
    (lista+*l)->Psu_Pruebas.Ciencias = _psu_cie;
    (lista+*l)->Psu_Pruebas.Historia = _psu_his;
    (lista+*l)->Psu_Pruebas.promedio = ((lista+*l)->Psu_Pruebas.Matematicas + (lista+*l)->Psu_Pruebas.Lenguaje + (lista+*l)->Psu_Pruebas.Ciencias + (lista+*l)->Psu_Pruebas.Historia)/4;
    (lista+*l)->Puntaje = ((lista+*l)->Promedio_final*125)*.20 + ((lista+*l)->Psu_Pruebas.promedio)*.80;
    *a = *a + 1;
    *l = *l + 1;
    }else{
      if (*l >= 40){
        printf("No se pueden registrar mas estudiantes\n");
      }
      else{
        if (*a > 19 && (strcmp(_carrera, "Computacion"))==0){
          printf("Lista de [Computacion] llena\n");
        }
      }
    }
    if (*b < 20 && (strcmp(_carrera, "Minas") == 0)){
    strcpy((lista+*l)->Nombre, _nombre);
    strcpy((lista+*l)->Carrera, _carrera);
    (lista+*l)->Rut = _rut;
    (lista+*l)->Notas_media.PrimeroMedio = _nota1;
    (lista+*l)->Notas_media.SegundoMedio = _nota2;
    (lista+*l)->Notas_media.TerceroMedio = _nota3;
    (lista+*l)->Notas_media.CuartoMedio = _nota4;
    _promedio = ((lista+*l)->Notas_media.PrimeroMedio + (lista+*l)->Notas_media.SegundoMedio + (lista+*l)->Notas_media.TerceroMedio + (lista+*l)->Notas_media.CuartoMedio)/4;
    (lista+*l)->Promedio_final = _promedio;
    (lista+*l)->Psu_Pruebas.Matematicas = _psu_mat;
    (lista+*l)->Psu_Pruebas.Lenguaje = _psu_len;
    (lista+*l)->Psu_Pruebas.Ciencias = _psu_cie;
    (lista+*l)->Psu_Pruebas.Historia = _psu_his;
    (lista+*l)->Psu_Pruebas.promedio = ((lista+*l)->Psu_Pruebas.Matematicas + (lista+*l)->Psu_Pruebas.Lenguaje + (lista+*l)->Psu_Pruebas.Ciencias + (lista+*l)->Psu_Pruebas.Historia)/4;
    (lista+*l)->Puntaje = ((lista+*l)->Promedio_final*125)*.20 + ((lista+*l)->Psu_Pruebas.promedio)*.80;
    *b = *b + 1;
    *l = *l + 1;
    }else{
      if (*l >= 40){
        printf("No se pueden registrar mas estudiantes\n");
      }
      else{
        if (*b >= 19 && (strcmp(_carrera, "Minas"))==0){
          printf("Lista de [Minas] llena\n");
        }
      }
    }
  }else{
    printf("Limite de estudiantes registrados superado\n");
  }
}



void imprime_fuera(Estudiantes* lista_est, int n){
  int i=0;
  printf("\n");
  printf("[Personas de Minas bajo puntaje de corte]\n\n");
  while (i < n){
    if ((strcmp(lista_est[i].Carrera, "Minas") == 0)){
      if (lista_est[i].Puntaje < 450){
        printf("%s\n",lista_est[i].Nombre);
      }
    }
    i++;
  }
}



//Imprime las diferentes listas, como lista de estudiantes, carreras y espera.
void imprime_registros(int* l,Estudiantes* lista_est, int opcion){
  if (opcion == 1){
    printf("\n\n[Lista de estudiantes]\n\n");
    for (int i=0; i < *l; i++){
      printf("Nombre: %s\n",lista_est[i].Nombre);
      printf("RUT   : %i\n",lista_est[i].Rut);
      printf("Notas :  [%.2f]  [%.2f]  [%.2f]  [%.2f]\n",lista_est[i].Notas_media.PrimeroMedio,lista_est[i].Notas_media.SegundoMedio,lista_est[i].Notas_media.TerceroMedio,lista_est[i].Notas_media.CuartoMedio);
      printf("Promedio Final: %.2f\n",lista_est[i].Promedio_final);
      printf("Notas PSU\n  Mat: %i\n  Len: %i\n  Cie: %i\n  His: %i\n",lista_est[i].Psu_Pruebas.Matematicas,lista_est[i].Psu_Pruebas.Lenguaje,lista_est[i].Psu_Pruebas.Ciencias,lista_est[i].Psu_Pruebas.Historia);
      printf("Puntaje: %.2f\n",lista_est[i].Puntaje);
      printf("Postulando a: %s\n",lista_est[i].Carrera);
      printf("\n");
    }
  }
  if (opcion == 2){
    printf("\n\n[Lista de carrera]\n\n");
    for (int i=0; i < *l; i++){
      printf("Nombre: %s\n",lista_est[i].Nombre);
      printf("Puntaje: %.2f\n",lista_est[i].Puntaje);
      printf("Postulando a: %s\n",lista_est[i].Carrera);
      printf("\n");
    }
  }
  if (opcion == 3){
    printf("\n\n[Lista de espera]\n\n");
    for (int i=0; i < *l; i++){
      if (lista_est[i].Puntaje >= 450){
        printf("Nombre: %s\n",lista_est[i].Nombre);
        printf("Puntaje: %.2f\n",lista_est[i].Puntaje);
        printf("Postulando a: %s\n",lista_est[i].Carrera);
        printf("\n");        
      }
    }
  }
}

//Ingresa los alumnos a las carreras, paga matricula y maneja la lista de espera
void ingreso_carrera(Estudiantes* lista_est, Estudiantes* carrera1, Estudiantes* carrera2, int* l, int* j, int* k, Estudiantes* lista_espera, int* x){
  int bandera=0;
  int i=0;
  int p = 0;
  char respuesta;
  printf("\n[Pago de matriculas]\n\n");
  while (i < *l){
    bandera = 0;
    if (((strcmp(lista_est[i].Carrera, "Computacion")) == 0) && (*j < 10)){
      if (lista_est[i].Puntaje >= 450){
        printf("%s [%s] pagas la matricula de $80000? (s/n)\n",lista_est[i].Nombre,lista_est[i].Carrera);
        scanf("%c",&respuesta);
        getchar();
        if (((strcmp(&respuesta, "s")) == 0)){
          carrera1[*j] = lista_est[i]; 
          *j = *j + 1;   
        }else{
          printf("No paga matricula.\n");
        }  
        bandera = 1;
      }
    }
    if (((strcmp(lista_est[i].Carrera, "Minas")) == 0) && (*k < 10)){
      if (lista_est[i].Puntaje >= 450){
        printf("%s [%s] pagas la matricula de $80000? (s/n)\n",lista_est[i].Nombre,lista_est[i].Carrera);
        scanf("%c",&respuesta);
        getchar();
        if (((strcmp(&respuesta, "s")) == 0)){
          carrera2[*k] = lista_est[i];
          *k = *k + 1;
        }else{
          printf("No paga matricula.\n");
        }
        bandera = 1;
      }
    }
    if (bandera == 0){
      lista_espera[p] = lista_est[i];
      p = p + 1;
      *x = *x + 1;
    }
    i++;
  }
  
}

//Ordena la lista de estudiantes por puntajes de mayor a menor.
void ordenar(Estudiantes* lista_est, int* x){
  int temp1=0,temp2=0,temp4=0;
  Estudiantes temp3;
  int i=0,j=0,k=0,p=0;
  while(k < *x){
    while(j < *x-1){
      temp1 = j;
      temp2= j+1;
      if (lista_est[temp1].Puntaje < lista_est[temp2].Puntaje){
        temp3 = lista_est[temp1];
        lista_est[temp1]= lista_est[temp2];
        lista_est[temp2] = temp3;
      }
      j++;
    }
    j=0;
    k++;
  }
}

//Muestra por pantalla los pagos al arancel. Meramente estetico...
void pagos(Estudiantes* Carrera1, Estudiantes* Carrera2, int j, int k){
  int i = 0;
  printf("\n[Pago de arancel]\n\n");
  while (i < j){
    printf("%s de '%s' se pago el arancel $4550000\n",Carrera1[i].Nombre,Carrera1[i].Carrera);
    i++;
  }
  i=0;
  while (i < k){
    printf("%s de '%s' se pago el arancel $4250000\n",Carrera2[i].Nombre,Carrera2[i].Carrera);
    i++;
  }
}

//Funcion para precargar datos
void ingreso_datos(Estudiantes* Estud, int* l, int* a, int* b){
  registro(Estud, "Carlos", "Computacion", 203992316, 6.5, 6.5, 6.3, 6.5, 600, 600, 590, 500, l, a, b);
  registro(Estud, "Annie", "Minas", 203842327, 6.1, 6.7, 6.2, 6.0, 700, 650, 660, 501, l, a, b);
  registro(Estud, "Juan", "Computacion", 100020000, 6.0, 5.5, 5.3, 6.5, 600, 520, 512, 505, l, a, b);
  registro(Estud, "Zoe", "Computacion", 113117567, 6.6, 5.1, 5.3, 6.8, 590, 550, 600, 505, l, a, b);
  registro(Estud, "Alvaro", "Computacion", 202312338, 6.0, 6.2, 6.3, 6.4, 650, 620, 632, 540, l, a, b);
  registro(Estud, "Pablo", "Computacion", 203934238, 6.5, 6.5, 6.3, 6.5, 600, 590, 610, 505, l, a, b);
  registro(Estud, "Edgar", "Computacion", 189307365, 6.5, 6.5, 6.3, 6.5, 600, 590, 610, 505, l, a, b);
  registro(Estud, "Carlos", "Minas", 220301366, 6.1, 5.0, 5.3, 6.5, 400, 590, 160, 105, l, a, b);
  registro(Estud, "Luis", "Computacion", 110002001, 6.5, 6.5, 6.3, 6.5, 600, 600, 590, 500, l, a, b);
  registro(Estud, "Mariza", "Computacion", 103842321, 6.1, 6.7, 6.2, 6.0, 700, 650, 660, 501, l, a, b);
  registro(Estud, "Alfredo", "Computacion", 200020022, 6.0, 5.5, 5.3, 6.5, 600, 520, 512, 505, l, a, b);
  registro(Estud, "Miguel", "Computacion", 313117563, 6.6, 5.1, 5.3, 6.8, 590, 550, 600, 505, l, a, b);
  registro(Estud, "Angel", "Computacion", 402312334, 6.7, 6.2, 6.3, 6.4, 650, 620, 632, 540, l, a, b);
  registro(Estud, "Zurita", "Computacion", 503934235, 6.0, 6.6, 5.3, 5.4, 300, 625, 632, 540, l, a, b);
  registro(Estud, "Oscar", "Computacion", 689307366, 6.6, 6.2, 5.3, 5.4, 500, 610, 620, 540, l, a, b);  
  registro(Estud, "Pedro", "Computacion", 900002001, 6.0, 6.2, 5.0, 6.4, 450, 620, 632, 540, l, a, b);
  registro(Estud, "Anays", "Computacion", 900042321, 6.0, 6.2, 6.3, 6.4, 550, 660, 690, 540, l, a, b);
  registro(Estud, "Margarita", "Computacion", 900020022, 6.0, 6.9, 5.3, 5.9, 200, 620, 632, 570, l, a, b);
  registro(Estud, "Matias", "Computacion", 900017563, 6.0, 6.2, 6.3, 6.9, 200, 620, 632, 590, l, a, b);
  registro(Estud, "Sebastian", "Computacion", 901012334, 5.0, 5.2, 5.3, 6.4, 620, 620, 632, 800, l, a, b);
  registro(Estud, "Tomas", "Computacion", 901004235, 6.4, 5.2, 5.7, 6.4, 700, 620, 632, 540, l, a, b);
  registro(Estud, "Bastian", "Minas", 100307099, 6.1, 6.2, 6.7, 6.6, 700, 790, 710, 805, l, a, b);  
  registro(Estud, "Maria", "Minas", 230307366, 6.1, 6.5, 6.5, 6.5, 800, 890, 810, 805, l, a, b);
    registro(Estud, "Juana", "Minas", 220301366, 6.5, 5.0, 5.3, 6.5, 400, 590, 160, 105, l, a, b);
}

int main(void) {
  Estudiantes Estud[40]; //Totalidad de estudiantes, maximo 40
  Estudiantes Carrera1[10]; //1ra carrera, maximo 10 estudiantes
  Estudiantes Carrera2[10]; //2da carrera, maximo 10 estudiantes
  Estudiantes Lista_espera[20]; // esta es la lista de espera donde seran ingresados y elegidos en caso de. maximo 20 personas
  int a=0,b=0; //representan la cantidad de estudiantes de cada carrera
  int l=0; // variable utilizada como contador de estudiantes registrados
  int j=0,k=0; // representa la cantidad de registros en las carreras
  int x=0; // representa la cantidad de estudiantes en la lista de espera
  ingreso_datos(Estud, &l, &a, &b);
  ordenar(Estud, &l);
  imprime_registros(&l, Estud,1);
  ingreso_carrera(Estud, Carrera1, Carrera2, &l, &j, &k, Lista_espera, &x);
  imprime_registros(&j, Carrera1,2);
  imprime_registros(&k, Carrera2,2);
  pagos(Carrera1, Carrera2, j, k);
  imprime_registros(&x, Lista_espera,3);
  imprime_fuera(Estud, l);
  
  return 0;
}