#pragma once
void GUIWindowClose(SDL_Window *window, bool *set, bool *done); 
void GUIQuit(bool *set, bool *done);						
//Obie funkcje s�u�a do obs�ugi zdarze� dla GUI czyli w tym przypadku zamykanie okna.W parametrach otrzymuj� wska�niki na zmienne logiczne obs�uguj�ce g��wne p�tle programu,
//decyduj�ce o zako�czenia tych p�tli. W pierwszej funkcji w parametrach przesy�any jest te� wska�nik na zmienn� window u�ywan� przy tworzeniu okna gry.