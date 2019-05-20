#pragma once

//Funkcja s�u��ca do inicjalizacji wszystkich element�w gry , ich wymiar�w , po�o�enia i wszystkich zmiennych logicznych
//Funkcja bez zwracania warto�ci.Parametrem jest wska�nik na g��wn� struktur� programu.
void InitializeGameState(struct GameState *game);

//Funkcja s�u��ca do wyznaczania miejsca aktualnie sprawdzanej skrzynki.Parametry przesy�ane do funkcji to obecne po�o�enie skrzyni oraz g�owa listy w kt�rej 
//przechowywane s� informacje o skrzyniach(wymiary itp.).Funkcja zwraca wska�nik typu struct Crate.
struct Crate *GetCrateIdx(int x, int y, struct Crate *head);

//G��wna funkcja obs�uguj�ca wszystkie eventy dla okna oraz klawiszy.W tej funkcji sprawdzana jest tak�e kolizja z otoczeniem czyli kolizja gracz - skrzynka, gracz - �ciana,
//skrzynia - �ciana, skrzynia - skrzynia.Funkcja zwraca warto�� logiczn� od kt�rej zale�y czy p�tla \lstinline!Game Loop!zako�czy dzia�anie.
//Parametry przesy�ane w funkcji to wska�nik na g��wn� strukture programu, wska�nik na struktur� GUIoraz zmienna logiczna *set obs�uguj�ca g��wn� p�tl� programu.
bool EventsMovementandCollisionDetection(struct GameState *game, struct GUI *window, bool *set); 

//Funkcja sprawdzaj�ca czy poziom zosta� uko�czony , czyli czy wszystkie skrzynki zosta�y ustawione na odpowiednim miejscu.
//Funkcja zwraca warto�� logiczn� od kt�rej zale�y czy program za�aduje kolejny poziom.W parametrach przesy�ana jest g�owa listy w 
//kt�rej znajduj� si� informacje o skrzyniach(po�o�enie, wymiary, itd.).
bool IsLevelComplete(struct Crate *head);

//Funkcja dodaj�ca element do listy jednokierunkowej czyli nowy asset(element pod�ogi, �ciany itp.).W parametrach przesy�ana jest g�owa Listy do kt�rej ma
//zosta� dodana nowy element na mapie, jego po�o�enie na mapie, oraz wymiary.
void AddAsset(struct Assets **head, int x, int  y, int w, int h);

////Funkcja dodaj�ca element do listy jednokierunkowej czyli now� skrzyni�.W parametrach przesy�ana jest g�owa Listy do kt�rej ma 
//zosta� dodana nowa skrzynia, jej po�o�enie na mapie, oraz wymiary.
void AddCrate(struct Crate **head, int x, int  y, int w, int h);

//Obie funkcje s�u�� do dealokacji pami�ci czyli usuni�cia list w kt�rych przechowywane s� informacje o elementach na mapie.
//Obie w parametrach otrzymuj� g�ow� listy jednokierunkowej.
void DestroyAsset(struct Assets **head);		
void DestroyCrate(struct Crate **cratehead);	