#pragma once
//Funkcja s�u��ca do za�adowania mapy z pliku o odpowiednim formacie.W parametrach otrzymuje wska�nik
//na g��wn� struktur� programu oraz nazw� pliku.Zwraca warto�� logiczn� kt�ra informuje o tym czy mapa zosta�a wczytana czy nie.
bool LoadMap(struct GameState *game, char *filename);

//Funkcja s�u��ca do za�adowania kolejnego poziomu.W parametrach przesy�any jest wska�nik na g��wn� struktur� programu oraz 
//zmienna przechowuj�ca informacj� o obecnym poziomie.Funkcja zwraca warto�� logiczn�kt�ra m�wi o tym czy jest mo�liwo�c za�adowania kolejnego poziomu.
bool LoadNextLevel(struct GameState *game, int current_level);
