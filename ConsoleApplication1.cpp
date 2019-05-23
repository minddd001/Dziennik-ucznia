// praca_zaliczeniowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "stdio.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	string dane_studentow[] = { "Kajetan Kulinski", "Adrian Marciniak", "Mateusz Kwasniak", "Lukasz Wizental", "Wiktor Przygocki" };
	string dane_prowadzacych[] = { "Karolina Kowalska","Szymon Stankiewicz","Kacper Wojciechowski","Maciej Chojnacki","Tymon Makowski" };
	string nazwy_przedmiotow[] = { "Matematyka", "Polski", "Historia", "WOS", "WF" };

	int oceny_matematyka[5][10] = {
		{ 5, 4, 4, 3, 4, 5, 3 ,4 ,3 ,3 },
		{ 5, 4, 3, 4, 3, 5, 3 ,3 ,4 ,5 },
		{ 3, 4, 4, 2, 4, 3, 4 ,4 ,2 ,3 },
		{ 5, 1, 3, 4, 5, 4, 3 ,4 ,4 ,4 },
		{ 2, 3, 5, 3, 5, 5, 4 ,4 ,3 ,4 },
	};
	int oceny_polski[5][10] = {
		{ 1, 2, 5, 2, 2, 1, 2 ,2 ,3 ,3 },
		{ 3, 1, 2, 2, 4, 3, 2 ,3 ,2 ,1 },
		{ 2, 2, 3, 1, 2, 1, 1 ,4 ,2 ,1 },
		{ 3, 2, 1, 2, 1, 4, 5 ,2 ,4 ,1 },
		{ 3, 1, 4, 2, 1, 1, 3 ,2 ,2 ,3 },
	};
	int oceny_historia[5][10] = {
		{ 3, 4, 2, 4, 3, 3, 5 ,5 ,4 ,3 },
		{ 5, 3, 5, 4, 2, 5, 4 ,5 ,3 ,3 },
		{ 1, 2, 1, 3, 2, 2, 1 ,2 ,1 ,4 },
		{ 2, 2, 1, 2, 2, 1, 2 ,4 ,3 ,2 },
		{ 5, 2, 3, 5, 3, 4, 5 ,2 ,3 ,5 },
	};
	int oceny_wos[5][10] = {
		{ 4, 5, 5, 3, 4, 3, 2 ,5 ,4 ,4 },
		{ 3, 5, 5, 5, 5, 4, 4 ,5 ,3 ,4 },
		{ 3, 5, 5, 4, 3, 5, 5 ,3 ,4 ,3 },
		{ 4, 4, 5, 3, 4, 4, 4 ,5 ,5 ,5 },
		{ 5, 4, 4, 5, 3, 4, 5 ,4 ,3 ,4 },
	};
	int oceny_wf[5][10] = {
		{ 4, 2, 3, 1, 3, 4, 1 ,3 ,5 ,5 },
		{ 3, 1, 2, 3, 5, 3, 4 ,2 ,2 ,2 },
		{ 1, 3, 5, 4, 3, 4, 3 ,3 ,3 ,4 },
		{ 3, 4, 1, 5, 2, 1, 2 ,2 ,4 ,1 },
		{ 4, 5, 2, 2, 1, 4, 5 ,1 ,1 ,2 },
	};

	bool skip_login = false;
	int blad = 0;
	int wybor_menu_startowe = 0;
	char flaga = 'u';

	do
	{
		string login, haslo;
		if (skip_login == false)
		{
			do {
				cout << "Wprowadz login (user/admin): ";
				cin >> login;
				if (login != "admin" && login != "user") cout << "\nWprowadz poprawna nazwe uzytkownika.\n\n";
			} while (login != "admin" && login != "user");
			if (login == "admin")
			{
				do {
					cout << "Haslo: ";
					cin >> haslo;
					if (haslo != "admin") cout << "\nWprowadz poprawne haslo.\n\n";
				} while (haslo != "admin");
			}
			if (login == "admin") flaga = 'a';
			if (login == "user") flaga = 'u';
		}

		cout << "\nKarta ocen studenta\n\n";
		if (flaga == 'u') cout << "1. Przegladaj oceny.\n2. Policz srednia.\n3. Wyswietl liste studentow.\n8. Zmien uzytkownika.\n9. Wyjdz.\n\n";
		if (flaga == 'a') cout << "1. Przegladaj oceny.\n2. Policz srednia.\n3. Wyswietl liste studentow.\n4. Edytuj oceny.\n8. Zmien uzytkownika.\n9. Wyjdz.\n\n";
		if (flaga == 'u')
		{
			do
			{
				cout << "Wybor pozycji z menu: ";
				cin >> wybor_menu_startowe;
				cout << "\n";
			} while (wybor_menu_startowe != 1 && wybor_menu_startowe != 2 && wybor_menu_startowe != 3 && wybor_menu_startowe != 8 && wybor_menu_startowe != 9);
		}
		if (flaga == 'a')
		{
			do
			{
				cout << "Wybor pozycji z menu: ";
				cin >> wybor_menu_startowe;
				cout << "\n";
			} while (wybor_menu_startowe != 1 && wybor_menu_startowe != 2 && wybor_menu_startowe != 3 && wybor_menu_startowe != 4 && wybor_menu_startowe != 8 && wybor_menu_startowe != 9);
		}
		switch (wybor_menu_startowe)
		{
		case 1: {
			int powrot = 0;
			do {
				int numer_studenta;
				do {
					cout << "Podaj numer studenta (1-5): ";
					cin >> numer_studenta;
				} while (numer_studenta != 1 && numer_studenta != 2 && numer_studenta != 3 && numer_studenta != 4 && numer_studenta != 5);
				float ocena_koncowa;
				cout << "\nOceny studenta: " << dane_studentow[numer_studenta - 1] << "\n\n";
				cout << "Matematyka\t |\t Prowadzacy - " << dane_prowadzacych[0] << "\n";
				for (int i = 0; i < 10; i++) cout << oceny_matematyka[numer_studenta - 1][i] << "\t";
				float ocena_koncowa_suma = 0;
				for (int j = 0; j < 10; j++) ocena_koncowa_suma = ocena_koncowa_suma + oceny_matematyka[numer_studenta - 1][j];
				ocena_koncowa = ocena_koncowa_suma / 10;
				if (ocena_koncowa < 1.8) ocena_koncowa = 1;
				if (ocena_koncowa < 2.6 && ocena_koncowa > 1.8) ocena_koncowa = 2;
				if (ocena_koncowa < 3.6 && ocena_koncowa > 2.6) ocena_koncowa = 3;
				if (ocena_koncowa < 4.6 && ocena_koncowa > 3.6) ocena_koncowa = 4;
				if (ocena_koncowa > 4.6) ocena_koncowa = 5;
				cout << "\nOcena koncowa: " << ocena_koncowa << "\n";

				cout << "\nPolski\t\t |\t Prowadzacy - " << dane_prowadzacych[1] << "\n";
				for (int i = 0; i < 10; i++) cout << oceny_polski[numer_studenta - 1][i] << "\t";
				ocena_koncowa_suma = 0;
				for (int j = 0; j < 10; j++) ocena_koncowa_suma = ocena_koncowa_suma + oceny_polski[numer_studenta - 1][j];
				ocena_koncowa = ocena_koncowa_suma / 10;
				if (ocena_koncowa < 1.8) ocena_koncowa = 1;
				if (ocena_koncowa < 2.6 && ocena_koncowa > 1.8) ocena_koncowa = 2;
				if (ocena_koncowa < 3.6 && ocena_koncowa > 2.6) ocena_koncowa = 3;
				if (ocena_koncowa < 4.6 && ocena_koncowa > 3.6) ocena_koncowa = 4;
				if (ocena_koncowa > 4.6) ocena_koncowa = 5;
				cout << "\nOcena koncowa: " << ocena_koncowa << "\n";


				cout << "\nHistoria\t |\t Prowadzacy - " << dane_prowadzacych[2] << "\n";
				for (int i = 0; i < 10; i++) cout << oceny_historia[numer_studenta - 1][i] << "\t";
				ocena_koncowa_suma = 0;
				for (int j = 0; j < 10; j++) ocena_koncowa_suma = ocena_koncowa_suma + oceny_historia[numer_studenta - 1][j];
				ocena_koncowa = ocena_koncowa_suma / 10;
				if (ocena_koncowa < 1.8) ocena_koncowa = 1;
				if (ocena_koncowa < 2.6 && ocena_koncowa > 1.8) ocena_koncowa = 2;
				if (ocena_koncowa < 3.6 && ocena_koncowa > 2.6) ocena_koncowa = 3;
				if (ocena_koncowa < 4.6 && ocena_koncowa > 3.6) ocena_koncowa = 4;
				if (ocena_koncowa > 4.6) ocena_koncowa = 5;
				cout << "\nOcena koncowa: " << ocena_koncowa << "\n";


				cout << "\nWOS\t\t |\t Prowadzacy - " << dane_prowadzacych[3] << "\n";
				for (int i = 0; i < 10; i++) cout << oceny_wos[numer_studenta - 1][i] << "\t";
				ocena_koncowa_suma = 0;
				for (int j = 0; j < 10; j++) ocena_koncowa_suma = ocena_koncowa_suma + oceny_wos[numer_studenta - 1][j];
				ocena_koncowa = ocena_koncowa_suma / 10;
				if (ocena_koncowa < 1.8) ocena_koncowa = 1;
				if (ocena_koncowa < 2.6 && ocena_koncowa > 1.8) ocena_koncowa = 2;
				if (ocena_koncowa < 3.6 && ocena_koncowa > 2.6) ocena_koncowa = 3;
				if (ocena_koncowa < 4.6 && ocena_koncowa > 3.6) ocena_koncowa = 4;
				if (ocena_koncowa > 4.6) ocena_koncowa = 5;
				cout << "\nOcena koncowa: " << ocena_koncowa << "\n";


				cout << "\nWF\t\t |\t Prowadzacy - " << dane_prowadzacych[4] << "\n";
				for (int i = 0; i < 10; i++) cout << oceny_wf[numer_studenta - 1][i] << "\t";
				ocena_koncowa_suma = 0;
				for (int j = 0; j < 10; j++) ocena_koncowa_suma = ocena_koncowa_suma + oceny_wf[numer_studenta - 1][j];
				ocena_koncowa = ocena_koncowa_suma / 10;
				if (ocena_koncowa < 1.8) ocena_koncowa = 1;
				if (ocena_koncowa < 2.6 && ocena_koncowa > 1.8) ocena_koncowa = 2;
				if (ocena_koncowa < 3.6 && ocena_koncowa > 2.6) ocena_koncowa = 3;
				if (ocena_koncowa < 4.6 && ocena_koncowa > 3.6) ocena_koncowa = 4;
				if (ocena_koncowa > 4.6) ocena_koncowa = 5;
				cout << "\nOcena koncowa: " << ocena_koncowa << "\n";

				do {
					cout << "\n\nCzy chcesz sprawdzic oceny innego studenta?\n\n0 - Nie, powrot do glownego menu\n1 - Tak\n\n";
					cin >> powrot;
					skip_login = true;
				} while (powrot != 0 && powrot != 1);
			} while (powrot != 0);
			break;
		}
		case 2: {
			int powrot;
			int wybor_dla_czego_liczyc_srednia;
			do {
				cout << "Dla czego chcesz liczyc srednia?\n\n1. Przedmiot\n2. Student\n3. Wszystkie przedmioty\n\n";
				cin >> wybor_dla_czego_liczyc_srednia;
				cout << "\n";
			} while (wybor_dla_czego_liczyc_srednia != 1 && wybor_dla_czego_liczyc_srednia != 2 && wybor_dla_czego_liczyc_srednia != 3);
			if (wybor_dla_czego_liczyc_srednia == 1) {
				do {
					float suma_sredniej = 0;
					float srednia;
					int numer_przedmiotu;
					do {
						cout << "Wybierz przedmiot:\n1. Matematyka\n2. Polski\n3. Historia\n4. WOS\n5. WF\n\n";
						cin >> numer_przedmiotu;
					} while (numer_przedmiotu != 1 && numer_przedmiotu != 2 && numer_przedmiotu != 3 && numer_przedmiotu != 4 && numer_przedmiotu != 5);
					if (numer_przedmiotu == 1)
					{
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								suma_sredniej = suma_sredniej + oceny_matematyka[i][j];
							}
						}
						srednia = suma_sredniej / 50;
						cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[numer_przedmiotu - 1] << " wynosi: " << srednia << "\n";
					}
					if (numer_przedmiotu == 2)
					{
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								suma_sredniej = suma_sredniej + oceny_polski[i][j];
							}
						}
						srednia = suma_sredniej / 50;
						cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[numer_przedmiotu - 1] << " wynosi: " << srednia << "\n";
					}
					if (numer_przedmiotu == 3)
					{
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								suma_sredniej = suma_sredniej + oceny_historia[i][j];
							}
						}
						srednia = suma_sredniej / 50;
						cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[numer_przedmiotu - 1] << " wynosi: " << srednia << "\n";
					}
					if (numer_przedmiotu == 4)
					{
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								suma_sredniej = suma_sredniej + oceny_wos[i][j];
							}
						}
						srednia = suma_sredniej / 50;
						cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[numer_przedmiotu - 1] << " wynosi: " << srednia << "\n";
					}
					if (numer_przedmiotu == 5)
					{
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								suma_sredniej = suma_sredniej + oceny_wf[i][j];
							}
						}
						srednia = suma_sredniej / 50;
						cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[numer_przedmiotu - 1] << " wynosi: " << srednia << "\n";
					}
					do {
						cout << "\n\nCzy chcesz sprawdzic srednia innego przedmiotu?\n\n0 - Nie, powrot do glownego menu\n1 - Tak\n\n";
						cin >> powrot;
						skip_login = true;
					} while (powrot != 0 && powrot != 1);
				} while (powrot != 0);
			}
			if (wybor_dla_czego_liczyc_srednia == 2) {
				do {
					int numer_studenta;
					do {
						cout << "Podaj numer studenta (1-5): ";
						cin >> numer_studenta;
					} while (numer_studenta != 1 && numer_studenta != 2 && numer_studenta != 3 && numer_studenta != 4 && numer_studenta != 5);
					float suma_matematyka = 0, suma_polski = 0, suma_historia = 0, suma_wos = 0, suma_wf = 0;
					for (int j = 0; j < 10; j++)
					{
						suma_matematyka = suma_matematyka + oceny_matematyka[numer_studenta - 1][j];
						suma_polski = suma_polski + oceny_polski[numer_studenta - 1][j];
						suma_historia = suma_historia + oceny_historia[numer_studenta - 1][j];
						suma_wos = suma_wos + oceny_wos[numer_studenta - 1][j];
						suma_wf = suma_wf + oceny_wf[numer_studenta - 1][j];
					}
					cout << "\n\nSrednie oceny studenta " << dane_studentow[numer_studenta - 1] << ":\n\n";
					cout << "Matematyka - " << suma_matematyka / 10 << "\n";
					cout << "Polski - " << suma_polski / 10 << "\n";
					cout << "Historia - " << suma_historia / 10 << "\n";
					cout << "WOS - " << suma_wos / 10 << "\n";
					cout << "WF - " << suma_wf / 10 << "\n";
					do {
						cout << "\n\nCzy chcesz policzyc srednie innego studenta?\n\n0 - Nie, powrot go glownego menu\n1 - Tak\n\n";
						cin >> powrot;
						skip_login = true;
					} while (powrot != 0 && powrot != 1);
				} while (powrot != 0);
			}
			if (wybor_dla_czego_liczyc_srednia == 3) {
				float suma_sredniej = 0;
				float srednia;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						suma_sredniej = suma_sredniej + oceny_matematyka[i][j];
					}
				}
				srednia = suma_sredniej / 50;
				cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[0] << " wynosi: " << srednia << "\n";
				suma_sredniej = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						suma_sredniej = suma_sredniej + oceny_polski[i][j];
					}
				}
				srednia = suma_sredniej / 50;
				cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[1] << " wynosi: " << srednia << "\n";
				suma_sredniej = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						suma_sredniej = suma_sredniej + oceny_historia[i][j];
					}
				}
				srednia = suma_sredniej / 50;
				cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[2] << " wynosi: " << srednia << "\n";
				suma_sredniej = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						suma_sredniej = suma_sredniej + oceny_wos[i][j];
					}
				}
				srednia = suma_sredniej / 50;
				cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[3] << " wynosi: " << srednia << "\n";
				suma_sredniej = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						suma_sredniej = suma_sredniej + oceny_wf[i][j];
					}
				}
				srednia = suma_sredniej / 50;
				cout << "\nSrednia dla przedmiotu " << nazwy_przedmiotow[4] << " wynosi: " << srednia << "\n";
				skip_login = true;
			}
			break;
		}
		case 3: {
			cout << "Lista studentow:\n\n";
			for (int i = 0; i < 5; i++)
			{
				cout << i + 1 << ". " << dane_studentow[i] << "\n";
			}
			skip_login = true;
			break;
		}
		case 4: {
			int nowa_ocena, numer_studenta, numer_przedmiotu, ktora_ocena;
			int powrot = 0;
			do
			{
				do {
					cout << "Podaj numer studenta (1-5): ";
					cin >> numer_studenta;
				} while (numer_studenta != 1 && numer_studenta != 2 && numer_studenta != 3 && numer_studenta != 4 && numer_studenta != 5);
				do {
					cout << "\nWybierz przedmiot z ktorego chcesz zmienic ocene:\n\n1. Matematyka\n2. Polski\n3. Historia\n4. WOS\n5. WF\n\n";
					cin >> numer_przedmiotu;
				} while (numer_przedmiotu != 1 && numer_przedmiotu != 2 && numer_przedmiotu != 3 && numer_przedmiotu != 4 && numer_przedmiotu != 5);
				cout << "\nOceny studenta: " << dane_studentow[numer_studenta - 1] << " z przedmiotu " << nazwy_przedmiotow[numer_przedmiotu - 1] << ":\n\n";
				if (numer_przedmiotu == 1) for (int i = 0; i < 10; i++) cout << oceny_matematyka[numer_studenta - 1][i] << "\t";
				if (numer_przedmiotu == 2) for (int i = 0; i < 10; i++) cout << oceny_polski[numer_studenta - 1][i] << "\t";
				if (numer_przedmiotu == 3) for (int i = 0; i < 10; i++) cout << oceny_historia[numer_studenta - 1][i] << "\t";
				if (numer_przedmiotu == 4) for (int i = 0; i < 10; i++) cout << oceny_wos[numer_studenta - 1][i] << "\t";
				if (numer_przedmiotu == 5) for (int i = 0; i < 10; i++) cout << oceny_wf[numer_studenta - 1][i] << "\t";
				do
				{
					cout << "\n\nKtora ocene chcesz zmienic? Podaj jej pozycje. (1-10) ";
					cin >> ktora_ocena;
				} while (ktora_ocena != 1 && ktora_ocena != 2 && ktora_ocena != 3 && ktora_ocena != 4 && ktora_ocena != 5 && ktora_ocena != 6 && ktora_ocena != 7 && ktora_ocena != 8 && ktora_ocena != 9 && ktora_ocena != 10);
				do
				{
					cout << "\nWprowadz nowa ocene. (1-5) ";
					cin >> nowa_ocena;
				} while (nowa_ocena != 1 && nowa_ocena != 2 && nowa_ocena != 3 && nowa_ocena != 4 && nowa_ocena != 5);
				if (numer_przedmiotu == 1)
				{
					oceny_matematyka[numer_studenta - 1][ktora_ocena - 1] = nowa_ocena;
					cout << "\nZaktualizowane oceny:\n\n";
					for (int i = 0; i < 10; i++) cout << oceny_matematyka[numer_studenta - 1][i] << "\t";
					cout << "\n";
				}
				if (numer_przedmiotu == 2)
				{
					oceny_polski[numer_studenta - 1][ktora_ocena - 1] = nowa_ocena;
					cout << "\nZaktualizowane oceny:\n\n";
					for (int i = 0; i < 10; i++) cout << oceny_polski[numer_studenta - 1][i] << "\t";
					cout << "\n";
				}
				if (numer_przedmiotu == 3)
				{
					oceny_historia[numer_studenta - 1][ktora_ocena - 1] = nowa_ocena;
					cout << "\nZaktualizowane oceny:\n\n";
					for (int i = 0; i < 10; i++) cout << oceny_historia[numer_studenta - 1][i] << "\t";
					cout << "\n";
				}
				if (numer_przedmiotu == 4)
				{
					oceny_wos[numer_studenta - 1][ktora_ocena - 1] = nowa_ocena;
					cout << "\nZaktualizowane oceny:\n\n";
					for (int i = 0; i < 10; i++) cout << oceny_wos[numer_studenta - 1][i] << "\t";
					cout << "\n";
				}
				if (numer_przedmiotu == 5)
				{
					oceny_wf[numer_studenta - 1][ktora_ocena - 1] = nowa_ocena;
					cout << "\nZaktualizowane oceny:\n\n";
					for (int i = 0; i < 10; i++) cout << oceny_wf[numer_studenta - 1][i] << "\t";
					cout << "\n";
				}
				do {
					cout << "\n\nCzy chcesz nadal edytowac oceny?\n\n0 - Nie, powrot do glownego menu\n1 - Tak\n\n";
					cin >> powrot;
					skip_login = true;
				} while (powrot != 0 && powrot != 1);
			} while (powrot != 0);
			skip_login = true;
			break;
		}
		case 8: {
			skip_login = false;
			break;
		}
		case 9: {
			system("PAUSE");
			return 0;
		}

		}
	} while (blad = 1);
	system("PAUSE");
}