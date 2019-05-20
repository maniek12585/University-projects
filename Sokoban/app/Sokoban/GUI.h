#pragma once
void GUIWindowClose(SDL_Window *window, bool *set, bool *done); 
void GUIQuit(bool *set, bool *done);						
//Obie funkcje s³u¿a do obs³ugi zdarzeñ dla GUI czyli w tym przypadku zamykanie okna.W parametrach otrzymuj¹ wskaŸniki na zmienne logiczne obs³uguj¹ce g³ówne pêtle programu,
//decyduj¹ce o zakoñczenia tych pêtli. W pierwszej funkcji w parametrach przesy³any jest te¿ wskaŸnik na zmienn¹ window u¿ywan¹ przy tworzeniu okna gry.