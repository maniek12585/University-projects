#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>


typedef int bool;  //
#define true 1	   // zdefiniowany typ logiczny 'bool'	
#define false 0	   //

#define WindowWidth 816		// sta³e u¿ywane do tworzenia okna : wysokoœæ i szerokoœæ okna
#define WindowHeight 612	//

#define TexturesWidthAndHeight 51 // podstawowe wymiary wszystkich textur wczytywanych do programu

#define LogicInnerLoopCount 16	//
#define LogicOuterLoopCount 12	// Sta³e u¿ywane w pêtlach do inicjalizacji zmiennych oraz do rysowania mapy w oknie
#define RenderingLoopCount  192	//


// struktura opisuj¹ca Gracza : jego pozycja x i y ,jego przesuniêcie podczas ruchu dx i dy oraz jego wymiary h - wysokoœæ i w - szerokoœæ
typedef struct Player
{	
	int x, y, w, h, dx, dy;
};


//Struktura w postaci listy jednokierunkowej opisuj¹ca wszystkie statyczne elementy na mapie czyli pod³ogi ,œciany , i miejsca docelowe dla skrzynek. 
//Struktura posiada podstawowe parametry takich elementów czyli pozycja x i y oraz wymiary w i h.  
typedef struct Assets 
{
	int x, y, w, h;
	struct Assets *next;
	
};

// struktura opisuj¹ca skrzynie któr¹ przesuwa gracz , oprócz podstawowych parametrów,
//posiada zmienn¹ bool on_dot dziêki której sprawdzamy czy szkrzynia jest umieszczona na odpowidenim miejscu
typedef struct Crate {
	int x, y, w, h;
	bool on_dot;
	struct Crate *next;
};

//zdefiniowany typ wyliczeniowy , pomocny przy wczytywaniu i pos³ugiwaniu sie teksturami oraz odwo³aniem do elementów na mapie np podczas sprawdzania kolizji
enum Textures
{
	TEX_WALL = 0,
	TEX_FLOOR = 1,
	TEX_FLOOR_DOT = 2,
	TEX_CRATE = 3,
	TEX_PLAYER_IDLE = 4,
	TEX_PLAYER_RIGHT = 5,
	TEX_PLAYER_LEFT = 6,
	TEX_PLAYER_TOP = 7,
	TEX_PLAYER_BOT = 8,
	TEX_GAME_OVER = 9,
	TEX_CRATE_ONDOT = 10,

	MAP_NONE = -1,
	MAP_WALL = TEX_WALL,
	MAP_FLOOR = TEX_FLOOR,
	MAP_FLOOR_DOT = TEX_FLOOR_DOT,
	MAP_CRATE = TEX_CRATE,

};

//G³ówna struktura programu w której zdefiniowane mamy wskaŸniki do wszystkich obiektów i elementów gry.
typedef struct GameState
{
	struct Assets *Wall, *Floor, *Floor_with_dot; // Zdefiniowane wskaŸniki na elementy mapy
	struct Crate *Crate;						  //



	struct Player player;

	int map[12][16]; //tablica do której wczytywana, jest z pliku, mapa 

	SDL_Texture *textures[32]; //tablica przechowuj¹ca tekstury u¿yte do wyœwietlania obrazu
	SDL_Renderer *renderer;    

	bool move_left, move_right, move_up, move_down, idle;  //zmienne logiczne u¿ywane przy rysowaniu mapy 

	int current_level; // zmienna przechowuj¹ca inforamacje o aktualnym levelu 

}; 
typedef struct GUI // struktura przechowuj¹ca wskaŸnik u¿yty do tworzenia okna 
{
	SDL_Window *window; 
};
