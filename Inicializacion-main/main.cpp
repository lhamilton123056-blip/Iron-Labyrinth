//   ########## PRUEBA BASE ##########


#include <raylib.h> // Libreria para desarrollo de videojuegos
#include <iostream>
#include <string>

struct Jugador{ // Creacion de estructura jugador
    Vector2 posicion;
    float velocidad;
};


//Inicializamos anchura y altura del jugador como constante para que no cambie
const auto JUGADOR_anchura = 32.0f;
const auto JUGADOR_altura = 32.0f;

int main(){
    //Dimensiones de la ventana
    auto ventana_anchura = 800;
    auto ventana_altura = 450;

    //Titulo de la ventana
    std::string titulo = "Ventana prueba";

    //Inicializar la ventana
    InitWindow(ventana_anchura, ventana_altura, titulo.c_str());
    
    //Usar 60 FPS 
    SetTargetFPS(60);

    //Creamos un objeto llamado jugador de tipo Jugador e 
    //inicializamos sus valores (posicion y su velocidad)
    Jugador jugador;
    jugador.posicion = { ventana_anchura / 2.0f, ventana_altura / 2.0f };
    jugador.velocidad = 200.0f;

    //Mientras que la ventana no se cierre 
    while (!WindowShouldClose()){
        float dt = GetFrameTime();

        //Si alguna tecla se presiona se mueve de coordenada(posicion)
        if (IsKeyDown(KEY_UP)) jugador.posicion.y -= jugador.velocidad * dt;
        if (IsKeyDown(KEY_DOWN)) jugador.posicion.y += jugador.velocidad * dt;
        if (IsKeyDown(KEY_LEFT)) jugador.posicion.x -= jugador.velocidad * dt;
        if (IsKeyDown(KEY_RIGHT)) jugador.posicion.x += jugador.velocidad * dt;

        //Inicializar el dibujo (siempre que se inicializa debe finalizarse también)
        BeginDrawing();

        //Limpia fondo a color negro
        ClearBackground(BLACK);

        //Imprimimos los FPS en la coordenada (10, 10)
        DrawFPS(10, 10);

        //Imprime en dónde se inicializa el jugador (coordenadas)
        DrawText("Empieza en:", 10, 40, 20, YELLOW);

        //Dibujamos el jugador con sus parametros
        DrawRectangleV(jugador.posicion, { JUGADOR_anchura, JUGADOR_altura }, RED);

        //Finalizamos el dibujo
        EndDrawing();
    }
    // Cerramos la ventana (por que ya no esta abierta del while)
    CloseWindow();
    return 0;
}
