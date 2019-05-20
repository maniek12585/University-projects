#pragma once
//Funkcja s³u¿¹ca do za³adowania mapy z pliku o odpowiednim formacie.W parametrach otrzymuje wskaŸnik
//na g³ówn¹ strukturê programu oraz nazwê pliku.Zwraca wartoœæ logiczn¹ która informuje o tym czy mapa zosta³a wczytana czy nie.
bool LoadMap(struct GameState *game, char *filename);

//Funkcja s³u¿¹ca do za³adowania kolejnego poziomu.W parametrach przesy³any jest wskaŸnik na g³ówn¹ strukturê programu oraz 
//zmienna przechowuj¹ca informacjê o obecnym poziomie.Funkcja zwraca wartoœæ logiczn¹która mówi o tym czy jest mo¿liwoœc za³adowania kolejnego poziomu.
bool LoadNextLevel(struct GameState *game, int current_level);
