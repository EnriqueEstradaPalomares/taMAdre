#include <iostream>
using namespace::std;


 const int Tamano_Alto = 20; //TAMANO PISO
 const int Tamano_Ancho = 60;
 int x = 1; //SE INICIA CON LA TORTUGA UBICADA EN (0,0)
 int y = 1;
 void Imprime_Comandos();
 void Avanza( int[][Tamano_Alto + 1], int, int, int, char, char);
 void Imprime( int[][Tamano_Alto +1], int, int);



////////////////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////////////

 int main()

 {
 cout <<"\nEste programa emula el lenguaje logo."<<endl;

 Imprime_Comandos();

 int Piso[Tamano_Ancho + 1][Tamano_Alto + 1] = {{0}, {0,0}};
 int comando = 1; //SE RECIBEN LOS COMANDOS.
 int pluma1 = -1; //LA PLUMA SE INICIA HACIA ABAJO.
 char direccion = 'h'; //LA DIRECCION HACIA LA QUE VE LA TORTUGA ES HORIZONTAL
 char avanza_o_retrocede = 'a';

 while ( 0 != comando )

 { // ABRE WHILE
 cout <<"\nIntroduzca comando (0 para terminar, 7 para imprimir los comandos): " <<endl;
 cin >> comando;

 switch (comando)

 { //ABRE SWITCH

 case 1:
 pluma1 = 1;
 cout <<"\nLa pluma esta hacia arriba. " <<endl;
 break;

 case 2:
 pluma1 = -1;
 cout << "\nLa pluma esta hacia abajo. " << endl;
 break;

 case 3:

 if( 'v' == direccion )

 {

 if ( 'a' == avanza_o_retrocede )

 {

 direccion = 'h';
 avanza_o_retrocede = 'r';

 }

 else

 {

 direccion = 'h';
 avanza_o_retrocede = 'a';

 }

 }

 else

 {
 if('a' == avanza_o_retrocede)

 {

 direccion = 'v';
 avanza_o_retrocede = 'a';

 }

 else

 {
 direccion = 'v';
 avanza_o_retrocede = 'r';

 }

 }

 cout <<"\nSe gira a la derecha." <<endl;

 break;
 cout << "\nSe gira hacia la derecha. " <<endl;
 break;

 case 4:

 direccion == 'v'?

 ( avanza_o_retrocede == 'a'?
 ({ direccion = 'h'; avanza_o_retrocede = 'a';}):
 ({direccion = 'h'; avanza_o_retrocede = 'r';})):

 (avanza_o_retrocede == 'a'?
 ({ direccion = 'v'; avanza_o_retrocede = 'r';}):
 ( { direccion = 'v'; avanza_o_retrocede = 'a';}));


 cout <<"\nSe gira hacia la izquierda. " <<endl;
 break;

 case 5:
 cout <<"\nAvanza hacia adelante. " <<endl;
 Avanza(Piso, Tamano_Ancho, Tamano_Alto, pluma1, direccion, avanza_o_retrocede);
 break;

 case 6:
 cout <<"\nEste es el recorrido de la tortuga: " << endl;
 Imprime( Piso, Tamano_Ancho, Tamano_Alto);
 break;

 case 7:
 Imprime_Comandos();
 break;

 case 8:
 cout <<"\nLa tortuga esta en la posicion (" << x << "," << y << ") y";
 cout << ( 'a' == avanza_o_retrocede ? " avanza ": "retrocede");
 cout <<" en la direccion ";
 cout << ( 'h' == direccion ? "x": "y" ) <<endl;

 default:
 break;

 } //CIERRA SWITCH

 } //CIERRA WHILE

 return 0;

 } //CIERRA MAIN


 //************************************************************************
 // SE DEFINE LA FUNCION IMPRIME COMANDOS
 //************************************************************************

void Imprime_Comandos()

 { // ABRE IMPRIME PARAMETROS

 cout <<"\nLos comandos para mover a la tortuga son: " <<endl;
 cout <<"1 La pluma esta hacia arriba. " <<endl;
 cout <<"2 pluma hacia abajo" << endl;
 cout <<"3 vuelta a la derecha" << endl;
 cout <<"4 vuelta a la izquierda" <<endl;
 cout <<"5 avanza hacia adelante" << endl;
 cout <<"6 despliega el piso de " << Tamano_Ancho <<" por " <<Tamano_Alto <<endl;
 cout <<"7 imprime los comandos" << endl;
 cout <<"8 imprime la posicion y direccion actual de la tortuga " <<endl;

 } // CIERRA IMPRIME PARAMETROS


 //************************************************************************
 // DEFINICION DE LA FUNCION AVANZA
 //************************************************************************


 void Avanza( int A[][Tamano_Alto + 1], int Ancho, int Alto, int pluma, char horizontal_o_vertical, char al_frente_o_atras)


 { //ABRE AVANZA

 int cuadros_avanza;
 char variable_a_mover;
 int i;
 int temporal;

 cout <<endl<<"Cuantos cuadros avanzara la tortuga? " << endl;
 cin >> cuadros_avanza;


 ('h' == horizontal_o_vertical) ?
 ({ variable_a_mover = 'x'; temporal = x;}):
 ({ variable_a_mover = 'y'; temporal = y;});


 for ( i = variable_a_mover == 'x'? x : y;
 (al_frente_o_atras == 'a') ?
 i <= (temporal + cuadros_avanza - 1):
 i >= (temporal - cuadros_avanza + 1);
 (al_frente_o_atras == 'a') ? i++ : i--)



 { //ABRE FOR

 if ( variable_a_mover == 'x' )

 { //ABRE IF variable_a_mover

 if (i <= Ancho && i > 0 )

 { //ABRE EL IF DE FOR

 A[i][y] = pluma == -1? 1: 0;
 cout << "(" << i <<"," << y<< ")" << endl;
 x = al_frente_o_atras == 'a'? (x + 1): (x - 1);

 } //CIERRA EL IF DE FOR


 else

 {

 if ( i > Ancho )

 { // ABRE IF

 A[Ancho][y] = pluma == -1? 1: 0;
 x = Ancho;

 } //CIERRA IF

 else

 { // ABRE ELSE DE IF

 A[1][y] = pluma == -1? 1: 0;
 x = 1;

 } // CIERRA ELSE DE IF
 } // CIERRA IF
 } //CIERRA IF variable_a_mover

 else

 { //ABRE ELSE variable_a_mover

 if (i <= Alto && i > 0) //ABRE IF

 {
 A[x ][i] = pluma == -1? 1: 0;
 cout << "(" << x << "," << i << ")" <<endl;
 y = al_frente_o_atras == 'a'? ( y + 1): (y -1);
 } //CIERRA IF

 else

 { //ABRE ELSE

 if ( Alto < i )
 {

 A[x ][Alto] = pluma == -1? 1: 0;

 y = Alto;

 }



 else

 { //ABRE ELSE INTERNO
 A[x ][1] = pluma == -1? 1: 0;
 y = 1;
 } //CIERRA ELSE INTERNO

 } //CIERRA ELSE

 } //CIERRA ELSE variable_a_mover

 } //CIERRA FOR


 return;

 } //CIERRA AVANZA


 //************************************************************************
 //FUNCION IMPRIME
 //************************************************************************

 void Imprime (int tablero[][Tamano_Alto + 1], int ancho, int alto)

 {

 int n, m;

 for ( n = 1; n <= alto; n++)

 { // ABRE FOR

 for ( m = 1; m <= ancho; m++)

 { //ABRE FOR ANIDADO

 if ( 1 == tablero[m][n])
 cout << "*";

 else
 cout << " ";

 } //CIERRA FOR ANIDADO

 cout << endl;

 } //CIERRA FOR

 return;

 }
