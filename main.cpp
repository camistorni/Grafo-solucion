#include "Grafo.h"
#include "string.h"

int main() {
    Grafo grafo;
    /*grafo.agregarVertice("A");
    grafo.agregarVertice("B");
    grafo.agregarVertice("C");
    grafo.agregarVertice("D");
    grafo.agregarVertice("E");
    grafo.agregarVertice("F");


    grafo.agregarCamino("A", "C", 8);
    grafo.agregarCamino("C", "B", 7);
    grafo.agregarCamino("C", "D", 5);
    grafo.agregarCamino("D", "B", 1);
    grafo.agregarCamino("E", "A", 1);
    grafo.agregarCamino("E", "D", 5);


    grafo.mostrarGrafo();

    grafo.usarFloyd();
    grafo.caminoMinimo("A", "B");
    grafo.caminoMinimo("A", "F");
    grafo.caminoMinimo("D", "C");
    grafo.caminoMinimo("F", "F");

    grafo.usarDijkstra();
    grafo.caminoMinimo("A", "B");
    grafo.caminoMinimo("A", "F");
    grafo.caminoMinimo("D", "C");
    grafo.caminoMinimo("F", "F");
	*/
	
void Juego::crearVertices(){
	
	int filas = this->obtenerMapa()->obtenerCantidadFilas();
	int columnas = this->obtenerMapa()->obtenerCantidadColumnas();
	//agrega todos los vertices (todas las coordenadas)
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			string coordX = to_string(j);
			string coordY = to_string(i);
			string coordActual = coordX + coordY;
			grafo.agregarVertice(coordActual);
		}
	}
}


//crear caminos entre cada coordenada
void Juego::crearCaminos(){	

	int filas = this->obtenerMapa()->obtenerCantidadFilas();
	int columnas = this->obtenerMapa()->obtenerCantidadColumnas();
	
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columans; j++){
			string coordX = to_string(j);
			string coordY = to_string(i);
			string coordActual = coordX + coordY;
			
			string coordXAnterior = to_string(j - 1) + coordY;
			string coordYAnterior = coordX + to_string(i - 1);
			string coordXSiguiente = to_string(j + 1) + coordY;
			string coordYSiguiente = coordX + to_string(i + 1);
			
			esquinas(i, j);
			bordes(i, j);
			
			grafo.agregarCamino(coordActual, coordXAnterior, valoresCaminos(j-1, i));
			grafo.agregarCamino(coordActual, coordXSiguiente, valoresCaminos(j+1, i));
			grafo.agregarCamino(coordActual, coordYAnterior, valoresCaminos(j, i-1));
			grafo.agregarCamino(coordActual, coordYSiguiente, valoresCaminos(j, i+1));
		}
	}
}


void Juego::esquinas(i, j){

	string coordX = to_string(j);
	string coordY = to_string(i);
	string coordActual = coordX + coordY;
	
	string coordXAnterior = to_string(j - 1) + coordY;
	string coordYAnterior = coordX + to_string(i - 1);
	string coordXSiguiente = to_string(j + 1) + coordY;
	string coordYSiguiente = coordX + to_string(i + 1);
	
	//caso esquina superior izquierda del mapa
	if(i == 0 && j == 0){
		grafo.agregarCamino(coordActual, coordXSiguiente, valoresCaminos(j+1, i));
		grafo.agregarCamino(coordActual, coordYSiguiente, valoresCaminos(j, i+1));
	}
	//caso esquina superior derecha del mapa
	if(i == 0 && j == columnas - 1){
		grafo.agregarCamino(coordActual, coordXAnterior, valoresCaminos(j-1, i));
		grafo.agregarCamino(coordActual, coordYSiguiente, valoresCaminos(j, i+1));
	}
	//caso esquina inferior izquierda
	if(i == filas - 1 && j == 0){
		grafo.agregarCamino(coordActual, coordXSiguiente, valoresCaminos(j+1, i));
		grafo.agregarCamino(coordActual, coordYAnterior, valoresCaminos(j, i-1));
	}
	//caso esquina inferior derecha
	if(i == filas - 1 && j == columnas - 1){
		grafo.agregarCamino(coordActual, coordXAnterior, valoresCaminos(j-1, i));
		grafo.agregarCamino(coordActual, coordYAnterior, valoresCaminos(j, i-1));
	}
}


void Juego::bordes(i, j){
	string coordX = to_string(j);
	string coordY = to_string(i);
	string coordActual = coordX + coordY;
	
	string coordXAnterior = to_string(j - 1) + coordY;
	string coordYAnterior = coordX + to_string(i - 1);
	string coordXSiguiente = to_string(j + 1) + coordY;
	string coordYSiguiente = coordX + to_string(i + 1);
			
	//caso borde inferior
	if((i == filas - 1 && j != 0) || (i == filas - 1 && j != columnas - 1)){
		grafo.agregarCamino(coordActual, coordXAnterior, valoresCaminos(j-1, i));
		grafo.agregarCamino(coordActual, coordXSiguiente, valoresCaminos(j+1, i));
		grafo.agregarCamino(coordActual, coordYAnterior, valoresCaminos(j, i-1));
	}
	//caso borde superior
	if((i == 0 && j != 0) || (i == 0 && j != columnas - 1){
		grafo.agregarCamino(coordActual, coordXAnterior, valoresCaminos(j-1, i));
		grafo.agregarCamino(coordActual, coordXSiguiente, valoresCaminos(j+1, i));
		grafo.agregarCamino(coordActual, coordYSiguiente, valoresCaminos(j, i+1));
	}
	//caso borde izquierdo
	if((i != 0 && j == 0) || (i != filas - 1 && j == 0)){
		grafo.agregarCamino(coordActual, coordXSiguiente, valoresCaminos(j+1, i));
		grafo.agregarCamino(coordActual, coordYAnterior, valoresCaminos(j, i-1));
		grafo.agregarCamino(coordActual, coordYSiguiente, valoresCaminos(j, i+1));
	}
	//caso borde derecho
	if((i != 0 && j == columnas - 1) || (i != filas - 1 && j == columnas - 1)){
		grafo.agregarCamino(coordActual, coordXAnterior, valoresCaminos(j-1, i));
		grafo.agregarCamino(coordActual, coordYAnterior, valoresCaminos(j, i-1));
		grafo.agregarCamino(coordActual, coordYSiguiente, valoresCaminos(j, i+1));
	}
}

int Juego::valoresCaminos(int x, int y){
	
	char casillero = this->obtenerMapa()->obtenerCasillero(x, y)->obtenerCaracter();
 
	if(casillero == "C")
		return 4;
	
	if(casillero == "B")
		return 0;
		
	if((casillero == "L" && obtenerJugadorActivo() == 0) || (casillero == "M" && obtenerJugadorActivo() == 1))
		return 2;
	
	if((casillero == "L" && obtenerJugadorActivo() == 1) || (casillero == "M" && obtenerJugadorActivo() == 0))
		return 5;	
	
	if(casillero == "T")
		return 25;
}
	
	
	/*
	grafo.agregarCamino("B", "C", 4);
    grafo.agregarCamino("B", "L", 2);
    grafo.agregarCamino("B", "M", 5);
    grafo.agregarCamino("B", "T", 25);
    grafo.agregarCamino("C", "B", 0);
    grafo.agregarCamino("C", "L", 2);
    grafo.agregarCamino("C", "M", 5);
    grafo.agregarCamino("C", "T", 25);
    grafo.agregarCamino("L", "B", 0);
    grafo.agregarCamino("L", "C", 4);
    grafo.agregarCamino("L", "M", 5);
    grafo.agregarCamino("L", "T", 25);
    grafo.agregarCamino("M", "B", 0);
    grafo.agregarCamino("M", "L", 2);
    grafo.agregarCamino("M", "C", 4);
    grafo.agregarCamino("M", "T", 25);
    grafo.agregarCamino("T", "B", 0);
    grafo.agregarCamino("T", "L", 2);
    grafo.agregarCamino("T", "M", 5);
    grafo.agregarCamino("T", "C", 4);*/


    grafo.mostrarGrafo();
    
    
	grafo.usarFloyd();
    grafo.caminoMinimo("01", "13");


    grafo.usarDijkstra();
    grafo.caminoMinimo("01", "13");

    return 0;
}
