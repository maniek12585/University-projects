#pragma once
//Funkcja s�u��ca do dealokacji pami�ci, czyli w tym przypadku zniszczenia tekstur za�adowanych do programu.W parametrach orzymuje wska�nik na g��wn� struktur� programu.
void DestroyTextures(struct GameState *game);

//Funkcja s�u��ca do za�adowania tekstur do programu.W parametrach orzymuje wska�nik na g��wn� struktur� programu
void LoadTextures(struct GameState *game);

//Funkcja s�u��ca do rysowania element�w mapy na ekranie.W parametrach otrzymuje wska�nik na g��wn� struktur� programu.
void doRender(struct GameState *game);

//Funkcja s�u��ca do rysowania napisu Game Over po uko�czeniu wszystkich poziom�w.W parametrach otrzymuje wska�nik na zmienn� renderer u�ywan� przy rysowaniu element�w
//na mapie oraz wska�nik na tablic� textures[] przchowuj�c� za�adowane do programu tekstury.
void DrawGameOver(struct SDL_Renderer *renderer, struct SDL_Texture *textures[]);