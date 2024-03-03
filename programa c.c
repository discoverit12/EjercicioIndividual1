//dado que en la hoja solo habia espacio para 3 consultas y somos 4 en el grupo esta consulta no esta en la hoja. Vamos a consultar la contraseña de un jugador sabiendo su nombre
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiï¿³n: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexin
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "Bd",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	char jugador[20];
	// Pregunto el nombre del jugador a consultar
	printf ("Dame el nombre de un jugador\n"); 
	scanf ("%s", jugador);
	
	char consulta [80];
	strcpy (consulta,"SELECT Jugador.contraseña FROM Jugador,Puntos,Partida WHERE Jugador.nombre = '");
	strcat (consulta, jugador);
	
	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recogemos el resultado de la consulta. El resultado de la
	//consulta se devuelve en una variable del tipo puntero a
	//MYSQL_RES tal y como hemos declarado anteriormente.
	//Se trata de una tabla virtual en memoria que es la copia
	//de la tabla real en disco.
	resultado = mysql_store_result (conn);
	// El resultado es una estructura matricial en memoria
	// en la que cada fila contiene los datos de una persona.
	
	// Ahora obtenemos la primera fila que se almacena en una
	// variable de tipo MYSQL_ROW
	row = mysql_fetch_row (resultado);
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			// la columna 0 contiene el nombre del jugador
			printf ("%s\n", row[0]);
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
	}
	
	mysql_close (conn);
	exit(0);
}
