#pragma once

//Funkcja s³u¿¹ca do inicjalizacji wszystkich elementów gry , ich wymiarów , po³o¿enia i wszystkich zmiennych logicznych
//Funkcja bez zwracania wartoœci.Parametrem jest wskaŸnik na g³ówn¹ strukturê programu.
void InitializeGameState(struct GameState *game);

//Funkcja s³u¿¹ca do wyznaczania miejsca aktualnie sprawdzanej skrzynki.Parametry przesy³ane do funkcji to obecne po³o¿enie skrzyni oraz g³owa listy w której 
//przechowywane s¹ informacje o skrzyniach(wymiary itp.).Funkcja zwraca wskaŸnik typu struct Crate.
struct Crate *GetCrateIdx(int x, int y, struct Crate *head);

//G³ówna funkcja obs³uguj¹ca wszystkie eventy dla okna oraz klawiszy.W tej funkcji sprawdzana jest tak¿e kolizja z otoczeniem czyli kolizja gracz - skrzynka, gracz - œciana,
//skrzynia - œciana, skrzynia - skrzynia.Funkcja zwraca wartoœæ logiczn¹ od której zale¿y czy pêtla \lstinline!Game Loop!zakoñczy dzia³anie.
//Parametry przesy³ane w funkcji to wskaŸnik na g³ówn¹ strukture programu, wskaŸnik na strukturê GUIoraz zmienna logiczna *set obs³uguj¹ca g³ówn¹ pêtlê programu.
bool EventsMovementandCollisionDetection(struct GameState *game, struct GUI *window, bool *set); 

//Funkcja sprawdzaj¹ca czy poziom zosta³ ukoñczony , czyli czy wszystkie skrzynki zosta³y ustawione na odpowiednim miejscu.
//Funkcja zwraca wartoœæ logiczn¹ od której zale¿y czy program za³aduje kolejny poziom.W parametrach przesy³ana jest g³owa listy w 
//której znajduj¹ siê informacje o skrzyniach(po³o¿enie, wymiary, itd.).
bool IsLevelComplete(struct Crate *head);

//Funkcja dodaj¹ca element do listy jednokierunkowej czyli nowy asset(element pod³ogi, œciany itp.).W parametrach przesy³ana jest g³owa Listy do której ma
//zostaæ dodana nowy element na mapie, jego po³o¿enie na mapie, oraz wymiary.
void AddAsset(struct Assets **head, int x, int  y, int w, int h);

////Funkcja dodaj¹ca element do listy jednokierunkowej czyli now¹ skrzyniê.W parametrach przesy³ana jest g³owa Listy do której ma 
//zostaæ dodana nowa skrzynia, jej po³o¿enie na mapie, oraz wymiary.
void AddCrate(struct Crate **head, int x, int  y, int w, int h);

//Obie funkcje s³u¿¹ do dealokacji pamiêci czyli usuniêcia list w których przechowywane s¹ informacje o elementach na mapie.
//Obie w parametrach otrzymuj¹ g³owê listy jednokierunkowej.
void DestroyAsset(struct Assets **head);		
void DestroyCrate(struct Crate **cratehead);	