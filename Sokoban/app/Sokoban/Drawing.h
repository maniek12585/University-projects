#pragma once
//Funkcja s³u¿¹ca do dealokacji pamiêci, czyli w tym przypadku zniszczenia tekstur za³adowanych do programu.W parametrach orzymuje wskaŸnik na g³ówn¹ strukturê programu.
void DestroyTextures(struct GameState *game);

//Funkcja s³u¿¹ca do za³adowania tekstur do programu.W parametrach orzymuje wskaŸnik na g³ówn¹ strukturê programu
void LoadTextures(struct GameState *game);

//Funkcja s³u¿¹ca do rysowania elementów mapy na ekranie.W parametrach otrzymuje wskaŸnik na g³ówn¹ strukturê programu.
void doRender(struct GameState *game);

//Funkcja s³u¿¹ca do rysowania napisu Game Over po ukoñczeniu wszystkich poziomów.W parametrach otrzymuje wskaŸnik na zmienn¹ renderer u¿ywan¹ przy rysowaniu elementów
//na mapie oraz wskaŸnik na tablicê textures[] przchowuj¹c¹ za³adowane do programu tekstury.
void DrawGameOver(struct SDL_Renderer *renderer, struct SDL_Texture *textures[]);