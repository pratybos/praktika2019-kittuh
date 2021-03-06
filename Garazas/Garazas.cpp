
#include "pch.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <ostream>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <windows.h> 
int itemKiekis = 10;
int masinos = 7;
int detaliuKiekis = 35;
int mapheight = 20;
int mapwidth = 20;
using namespace std;
struct item
{
	string pavadinimas;
	int kaina;
	int damage;
	bool ar_nupirkta;
	bool ar_uzdeta;
};
struct masina
{
	string pavadinimas;
	int gyvybes;
	int levelis;
};
struct masinudetales
{
	string pavadinimas;
	int verte;
	int kiekis;
	bool ar_turiu;
};
struct vartotojas
{
	string vardas;
	int lygis;
	int saskaita;
	int sunkumas;
	int exp;
};
struct pasiekimai
{
	string pavadinimas;
	int ar_ivygdyta;
};
void iteminfo(item a[], vartotojas d[], int &k, int &vieta);
void inventorius(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta);
void parduotuve(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta);
void pirktiDaiktus(item a[], vartotojas d[], int vieta);
void parduotiDaiktus(item a[], vartotojas d[], int vieta);
void nuimti(item a[]);
void uzdeti(item a[]);
void masinuinfo(masina b[]);
void detaliuinfo(masinudetales c[]);
void levelingsystem(vartotojas d[], int &k);
void masinuardymas(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta);
void mapas(item a[], char map[][20], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta, int &isardyta);
void printmap(char map[][20]);
void atliktasejimas(char map[][20]);
void ardaumasina(item a[], int &atspawnino, masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &daromaZala, int &masinosvieta);
void hud(vartotojas d[], int vieta);
void parduotiDetales(masinudetales c[], vartotojas d[], int vieta);
void savegame(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta);
void issaugotozaidejouzkrovimas(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta);
void pasiekimas( int &isardyta, vartotojas d[], pasiekimai e[], int vieta, item a[], masinudetales c[]);
void pasiekimoinfo(pasiekimai e[]);
int main()
{
	int daromaZala = 0, masinosvieta,isardyta=0;
	int k, vieta, atspawnino = 0;
	char map[20][20];
	item a[10];
	masina b[25];
	masinudetales c[350];
	vartotojas d[10];
	pasiekimai e[50];

	cout << "Issaugoto zaidimo uzkrovimas - 1" << endl;
	cout << "Naujo zaidimo uzkrovimas - 2 " << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		issaugotozaidejouzkrovimas(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
	}
	else if (x == 2)
	{
		pasiekimoinfo(e);
		levelingsystem(d, k);
		iteminfo(a, d, k, vieta);
		detaliuinfo(c);
	}
	
	masinuinfo(b);
	masinuardymas(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
	mapas(a, map, b, c, d, e, vieta, atspawnino, daromaZala, masinosvieta,isardyta);
}
void iteminfo(item a[], vartotojas d[], int &k, int &vieta)
{
	cout << "Pasirinkite su kurio zaideju zaisite" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << d[i].vardas << endl;
	}
	string zaidejas;
	cin >> zaidejas;

	for (int i = 0; i < k; i++)
	{
		if (d[i].vardas == zaidejas)
		{
			vieta = i;
		}
	}
	if (d[vieta].sunkumas == 1)
	{
		ifstream in("iteminfo1.txt");
		for (int i = 0; i < itemKiekis; i++)
		{
			in >> a[i].pavadinimas;
			in >> a[i].kaina;
			in >> a[i].damage;
			in >> a[i].ar_nupirkta;
			in >> a[i].ar_uzdeta;
		}
	}
	if (d[vieta].sunkumas == 2)
	{
		ifstream in("iteminfo2.txt");
		for (int i = 0; i < itemKiekis; i++)
		{
			in >> a[i].pavadinimas;
			in >> a[i].kaina;
			in >> a[i].damage;
			in >> a[i].ar_nupirkta;
			in >> a[i].ar_uzdeta;
		}
	}
	if (d[vieta].sunkumas == 3)
	{
		ifstream in("iteminfo3.txt");
		for (int i = 0; i < itemKiekis; i++)
		{
			in >> a[i].pavadinimas;
			in >> a[i].kaina;
			in >> a[i].damage;
			in >> a[i].ar_nupirkta;
			in >> a[i].ar_uzdeta;
		}
	}



}
void inventorius(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta)
{
	cout << "1 - Turimi daiktai" << endl;
	cout << "2 - Uzdeti daiktai" << endl;
	cout << "3 - Daiktu uzdejimas" << endl;
	cout << "4 - Daiktu nuemimas" << endl;
	cout << "5 - Grizti atgal i zaidima" << endl;
	int pasirinkimas;
	cin >> pasirinkimas;
	bool re = true;
	while (re == true)
	{
		if (pasirinkimas > 0 && pasirinkimas <= 5)
		{
			switch (pasirinkimas)
			{
			case 1:
				for (int i = 0; i < itemKiekis; i++)
				{
					if (a[i].ar_nupirkta == 1)
					{
						cout << a[i].pavadinimas << endl;
					}
				}
				break;
			case 2:
				for (int i = 0; i < itemKiekis; i++)
				{
					if (a[i].ar_uzdeta == 1)
					{
						cout << a[i].pavadinimas << endl;
					}
				}
				break;
			case 3:
				uzdeti(a);
				break;
			case 4:
				nuimti(a);
				break;
			case 5:
				re = false;
				masinuardymas(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
				break;
			}
		}
		else cout << "Blogas pasirinkimas" << endl;
		if (pasirinkimas != 5)
		{
			cin >> pasirinkimas;
		}
	}
}
void parduotuve(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta)
{
	int pasirinkimas;
	cout << "Parduotuves meniu " << endl;
	cout << "1 - Pirkti daiktus" << endl;
	cout << "2 - Parduoti daiktus" << endl;
	cout << "3 - Parduoti automobiliu detales " << endl;
	cout << "4- Grizti atgal" << endl;
	cin >> pasirinkimas;
	bool re = true;
	while (re == true)
	{
		if (pasirinkimas > 0 && pasirinkimas <= 4)
		{
			switch (pasirinkimas)
			{
			case 1:
				pirktiDaiktus(a, d, vieta);
				break;

			case 2:
				parduotiDaiktus(a, d, vieta);
				break;

			case 3:
				parduotiDetales(c, d, vieta);
				break;

			case 4:
				re = false;
				masinuardymas(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
				break;
			}
		}
		else cout << "Blogas pasirinkimas" << endl;
		if (pasirinkimas != 4)
		{
			cin >> pasirinkimas;
		}
	}
}
void pirktiDaiktus(item a[], vartotojas d[], int vieta)
{
	cout << "Jusu saskaitoje - " << d[vieta].saskaita << endl;
	cout << "1 - Atsuktuvas - 5" << endl;
	cout << "2 - Plaktukas - 10 " << endl;
	cout << "3 - verzliaraktis - 10" << endl;
	cout << "4 - Reples - 25" << endl;
	cout << "5 - Kampinis Slifuoklis - 50" << endl;
	cout << "6 - Kaltas - 5" << endl;
	cout << "7 - Dilde - 10" << endl;
	cout << "8 - vamzdis - 5" << endl;

	int pasirinkimas;
	cout << "Daikas kuri pirksite?" << endl;
	cin >> pasirinkimas;
	while (pasirinkimas != 0)
	{
		if (pasirinkimas > 0 && pasirinkimas <= 8)
		{
			switch (pasirinkimas)
			{
			case 1:
				if (a[0].ar_nupirkta == 0)
				{
					if (d[vieta].saskaita >= a[0].kaina)
					{
						d[vieta].saskaita = d[vieta].saskaita - a[0].kaina;
						a[0].ar_nupirkta = 1;
						cout << "Daiktas sekmingai nupirktas" << endl;
					}
					else cout << "Nepakanka pinigu" << endl;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 2:
				if (a[1].ar_nupirkta == 0)
				{
					if (d[vieta].saskaita >= a[1].kaina)
					{
						d[vieta].saskaita = d[vieta].saskaita - a[1].kaina;
						a[1].ar_nupirkta = 1;
						cout << "Daiktas sekmingai nupirktas" << endl;
					}
					else cout << "Nepakanka pinigu" << endl;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 3:
				if (a[2].ar_nupirkta == 0)
				{
					if (d[vieta].saskaita >= a[2].kaina)
					{
						d[vieta].saskaita = d[vieta].saskaita - a[2].kaina;
						a[2].ar_nupirkta = 1;
						cout << "Daiktas sekmingai nupirktas" << endl;
					}
					else cout << "Nepakanka pinigu" << endl;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 4:
				if (a[3].ar_nupirkta == 0)
				{
					if (d[vieta].saskaita >= a[3].kaina)
					{
						d[vieta].saskaita = d[vieta].saskaita - a[3].kaina;
						a[3].ar_nupirkta = 1;
						cout << "Daiktas sekmingai nupirktas" << endl;
					}
					else cout << "Nepakanka pinigu" << endl;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 5:
				if (a[4].ar_nupirkta == 0)
				{
					if (d[vieta].saskaita >= a[4].kaina)
					{
						d[vieta].saskaita = d[vieta].saskaita - a[4].kaina;
						a[4].ar_nupirkta = 1;
						cout << "Daiktas sekmingai nupirktas" << endl;
					}
					else cout << "Nepakanka pinigu" << endl;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 6:
				if (a[5].ar_nupirkta == 0)
				{
					if (d[vieta].saskaita >= a[5].kaina)
					{
						d[vieta].saskaita = d[vieta].saskaita - a[5].kaina;
						a[5].ar_nupirkta = 1;
						cout << "Daiktas sekmingai nupirktas" << endl;
					}
					else cout << "Nepakanka pinigu" << endl;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 7:
				if (a[6].ar_nupirkta == 0)
				{
					if (d[vieta].saskaita >= a[6].kaina)
					{
						d[vieta].saskaita = d[vieta].saskaita - a[6].kaina;
						a[6].ar_nupirkta = 1;
						cout << "Daiktas sekmingai nupirktas" << endl;
					}
					else cout << "Nepakanka pinigu" << endl;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 8:
				if (a[7].ar_nupirkta == 0)
				{
					if (d[vieta].saskaita >= a[7].kaina)
					{
						d[vieta].saskaita = d[vieta].saskaita - a[7].kaina;
						a[7].ar_nupirkta = 1;
						cout << "Daiktas sekmingai nupirktas" << endl;
					}
					else cout << "Nepakanka pinigu" << endl;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			}
		}
		else cout << "Tokio daikto sarase nera" << endl;
		cin >> pasirinkimas;
	}

}
void parduotiDaiktus(item a[], vartotojas d[], int vieta)
{
	cout << "1 - Atsuktuvas - 5" << endl;
	cout << "2 - Plaktukas - 10 " << endl;
	cout << "3 - verzliaraktis - 10" << endl;
	cout << "4 - Reples - 25" << endl;
	cout << "5 - Kampinis Slifuoklis - 50" << endl;
	cout << "6 - Kaltas - 5" << endl;
	cout << "7 - Dilde - 10" << endl;
	cout << "8 - vamzdis - 5" << endl;
	int pasirinkimas;
	cout << "Daikas kuri parduosite?" << endl;
	cin >> pasirinkimas;
	while (pasirinkimas != 0)
	{
		if (pasirinkimas > 0 && pasirinkimas <= 8)
		{
			switch (pasirinkimas)
			{
			case 1:
				if (a[0].ar_nupirkta == 1 && a[0].ar_uzdeta == 0)
				{
					d[vieta].saskaita = d[vieta].saskaita + a[0].kaina;
					a[0].ar_nupirkta = 0;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 2:
				if (a[1].ar_nupirkta == 1 && a[1].ar_uzdeta == 0)
				{
					d[vieta].saskaita = d[vieta].saskaita + a[1].kaina;
					a[1].ar_nupirkta = 0;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 3:
				if (a[2].ar_nupirkta == 1 && a[2].ar_uzdeta == 0)
				{
					d[vieta].saskaita = d[vieta].saskaita + a[2].kaina;
					a[2].ar_nupirkta = 0;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 4:
				if (a[3].ar_nupirkta == 1 && a[3].ar_uzdeta == 0)
				{
					d[vieta].saskaita = d[vieta].saskaita + a[3].kaina;
					a[3].ar_nupirkta = 0;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 5:
				if (a[4].ar_nupirkta == 1 && a[4].ar_uzdeta == 0)
				{
					d[vieta].saskaita = d[vieta].saskaita + a[4].kaina;
					a[4].ar_nupirkta = 0;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 6:
				if (a[5].ar_nupirkta == 1 && a[5].ar_uzdeta == 0)
				{
					d[vieta].saskaita = d[vieta].saskaita + a[5].kaina;
					a[5].ar_nupirkta = 0;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 7:
				if (a[6].ar_nupirkta == 1 && a[6].ar_uzdeta == 0)
				{
					d[vieta].saskaita = d[vieta].saskaita + a[6].kaina;
					a[6].ar_nupirkta = 0;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 8:
				if (a[7].ar_nupirkta == 1 && a[7].ar_uzdeta == 0)
				{
					d[vieta].saskaita = d[vieta].saskaita + a[7].kaina;
					a[7].ar_nupirkta = 0;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			}
		}
		else cout << "Tokio daikto sarase nera" << endl;
		cin >> pasirinkimas;
	}
	cout << "Jusu saskaitoje - " << d[vieta].saskaita << endl;
}
void nuimti(item a[])
{
	char x;
	for (int i = 0; i < itemKiekis; i++)
	{
		if (a[i].ar_nupirkta == 1)
		{
			cout << a[i].pavadinimas << endl;
			if (a[i].ar_uzdeta == 1)
			{
				cout << "Ar norite nuimti ? y/n" << endl;
				cin >> x;
				if (x == 'y' || x == 'Y')
				{
					a[i].ar_uzdeta = 0;
				}

			}

		}
	}
}
void uzdeti(item a[])
{
	char x;
	for (int i = 0; i < itemKiekis; i++)
	{
		if (a[i].ar_nupirkta == 1)
		{
			cout << a[i].pavadinimas << endl;
			if (a[i].ar_uzdeta == 0)
			{
				cout << "Ar norite uzdeti ? y/n" << endl;
				cin >> x;
				if (x == 'y' || x == 'Y')
				{
					a[i].ar_uzdeta = 1;

				}

			}

		}
	}
}
void masinuinfo(masina b[])
{
	ifstream in("masinos.txt");
	for (int i = 0; i < masinos; i++)
	{
		in >> b[i].pavadinimas;
		in >> b[i].gyvybes;
		in >> b[i].levelis;
	}

}
void detaliuinfo(masinudetales c[])
{
	ifstream in("detales.txt");
	for (int i = 0; i < detaliuKiekis; i++)
	{
		in >> c[i].pavadinimas;
		in >> c[i].verte;
		in >> c[i].kiekis;
		in >> c[i].ar_turiu;
	}

}
void levelingsystem(vartotojas d[], int &k)
{
	cout << "Naujo vartotojo sukurimas" << endl;

	cout << "Kiek zaideju norite sukurti?" << endl;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cout << "Iveskite zaidejo varda" << endl;
		cin >> d[i].vardas;
		d[i].exp = 0;
		d[i].lygis = 0;
		d[i].saskaita = 0;
		cout << "Pasirinkite sunkumo lygi: 1 - Pradedantysis, 2 - patyres, 3 - ekspertas " << endl;
		cin >> d[i].sunkumas;
	}
}
void masinuardymas(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta)
{
	int x_pos, y_pos;
	daromaZala = 0;
	atspawnino = 0;
	for (int i = 0; i < itemKiekis; i++)
	{
		if (a[i].ar_uzdeta == 1)
		{
			daromaZala = daromaZala + a[i].damage;
		}
	}
	cout << "Zaisti toliau? Y/n" << endl;
	char yesno;
	cin >> yesno;
	if (yesno == 'y' || yesno == 'n')
	{
		switch (yesno)
		{
		case 'y':
			printmap(map);
			hud(d, vieta);
			if (d[vieta].lygis >= 0 && d[vieta].lygis < 3)
			{
				masinosvieta = 0;
			}
			else if (d[vieta].lygis >= 3 && d[vieta].lygis < 5)
			{
				masinosvieta = 1;
			}
			else if (d[vieta].lygis >= 5 && d[vieta].lygis < 7)
			{
				masinosvieta = 2;
			}
			else if (d[vieta].lygis >= 7 && d[vieta].lygis < 10)
			{
				masinosvieta = 3;
			}
			else if (d[vieta].lygis >= 10 && d[vieta].lygis < 13)
			{
				masinosvieta = 4;
			}
			else if (d[vieta].lygis >= 13 && d[vieta].lygis < 16)
			{
				masinosvieta = 5;
			}
			else if (d[vieta].lygis >= 16)
			{
				masinosvieta = 6;
			}
			if (atspawnino < 1)
			{
				masinuinfo(b);
				x_pos = rand() % 18 + 1;
				y_pos = rand() % 18 + 1;
				map[x_pos][y_pos] = 'M';
				atspawnino++;
				atliktasejimas(map);
			}
			break;
		case 'n':
			cout << "Inventorius spauskite - 1" << endl;
			cout << "Parduotuves meniu spauskite - 2" << endl;
			cout << "Issaugoti zaidimo progresa spauskite - 3 " << endl;
			int pasirinkimas;
			cin >> pasirinkimas;
			if (pasirinkimas > 0 && pasirinkimas <= 3)
			{
				switch (pasirinkimas)
				{
				case 1:
					inventorius(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
					break;
				case 2:
					parduotuve(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
					break;
				case 3:
					savegame(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
					break;
				}
			}
			break;
		}
	}
}
void mapas(item a[], char map[][20], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta, int &isardyta)
{
	
	
	int y_move = 10;
	int x_move = 10;
	char move;
	cin >> move;
	while (move == 'w' || move == 'W' || move == 'a' || move == 'A' || move == 'D' || move == 'd' || move == 's' || move == 'S')
	{
		switch (move)
		{
		case 'w':
			atliktasejimas(map);
			if (x_move > 0 && x_move < 20)
			{
				x_move = x_move - 1;
				if (x_move == 0 || x_move == 19)
				{
					x_move = x_move + 1;
					atliktasejimas(map);
					cout << "Apsisukite!" << endl;
				}
				for (int i = 0; i < 19; i++)
				{
					if (i == x_move)
					{
						for (int j = 0; j < 19; j++)
						{
							if (j == y_move)
							{
								if (map[i][j] == 'M')
								{
									map[i + 1][j] = ' ';
									ardaumasina(a, atspawnino, b, c, d, e, map, vieta, daromaZala, masinosvieta);
									isardyta++;
									pasiekimas(isardyta, d, e, vieta, a, c);
								}
								else
								{
									map[i][j] = 'O';
									map[i + 1][j] = ' ';
									atliktasejimas(map);
								}
							}
						}
					}
				}
			}
			break;
		case 'a':
			atliktasejimas(map);
			if (y_move > 0 && y_move < 20)
			{
				y_move = y_move - 1;
				if (y_move == 0 || y_move == 19)
				{
					y_move = y_move + 1;
					atliktasejimas(map);
					cout << "Apsisukite!" << endl;
				}
				for (int i = 0; i < 19; i++)
				{
					if (i == x_move)
					{
						for (int j = 0; j < 19; j++)
						{
							if (j == y_move)
							{
								if (map[i][j] == 'M')
								{
									map[i][j + 1] = ' ';
									ardaumasina(a, atspawnino, b, c, d, e, map, vieta, daromaZala, masinosvieta);
									isardyta++;
									pasiekimas(isardyta, d, e, vieta, a, c);
								}
								else
								{
									map[i][j] = 'O';
									map[i][j + 1] = ' ';
									atliktasejimas(map);
								}
							}

						}
					}
				}
			}
			break;
		case 's':
			atliktasejimas(map);
			if (x_move > 0 && x_move < 20)
			{
				x_move = x_move + 1;
				if (x_move == 1 || x_move == 19)
				{
					x_move = x_move - 1;
					atliktasejimas(map);

					cout << "Apsisukite!" << endl;
				}
				for (int i = 0; i < 19; i++)
				{
					if (i == x_move)
					{
						for (int j = 0; j < 19; j++)
						{
							if (j == y_move)
							{
								if (map[i][j] == 'M')
								{
									map[i - 1][j] = ' ';
									ardaumasina(a, atspawnino, b, c, d, e, map, vieta, daromaZala, masinosvieta);
									isardyta++;
									pasiekimas(isardyta, d, e, vieta, a, c);
								}
								else
								{
									map[i][j] = 'O';
									map[i - 1][j] = ' ';
									atliktasejimas(map);
								}

							}

						}
					}
				}
			}
			break;
		case 'd':
			atliktasejimas(map);

			if (y_move > 0 && y_move < 20)
			{
				y_move = y_move + 1;
				if (y_move == 1 || y_move == 19)
				{
					y_move = y_move - 1;
					atliktasejimas(map);

					cout << "Apsisukite!" << endl;
				}
				for (int i = 0; i < 19; i++)
				{
					if (i == x_move)
					{
						for (int j = 0; j < 19; j++)
						{
							if (j == y_move)
							{
								if (map[i][j] == 'M')
								{

									map[i][j - 1] = ' ';
									ardaumasina(a, atspawnino, b, c, d, e, map, vieta, daromaZala, masinosvieta);
									isardyta++;
									pasiekimas(isardyta, d, e, vieta, a, c);
								}
								else
								{
									map[i][j] = 'O';
									map[i][j - 1] = ' ';
									atliktasejimas(map);
								}
							}

						}
					}

				}
			}
			break;
		}
		cin >> move;
	}
}
void printmap(char map[][20])
{
	system("CLS");
	int i, j;

	for (i = 0; i < 20; i++)
	{
		if (i > 0 && i < 19)
		{
			map[i][j] = '|';
			for (j = 1; j < 19; j++)
			{
				map[i][j] = ' ';
			}
			map[i][j] = '|';
		}
		else
		{
			for (j = 0; j < 20; j++)
			{
				map[i][j] = '-';
			}

		}
	}
}
void atliktasejimas(char map[][20])
{
	system("CLS");
	for (int d = 0; d < 20; d++)
	{
		for (int e = 0; e < 20; e++)
		{
			cout << map[d][e];
		}
		cout << endl;
	}
}
void ardaumasina(item a[], int &atspawnino, masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &daromaZala, int &masinosvieta)
{
	
	int drop;
	cout << "Masina ardoma" << endl;
	
	masinuinfo(b);
	while (b[masinosvieta].gyvybes > 0)
	{
		b[masinosvieta].gyvybes = b[masinosvieta].gyvybes - daromaZala;
		cout << ".";
		Sleep(100);
		if (b[masinosvieta].gyvybes <= 0)
		{
			cout << endl;
			atspawnino--;
			if (b[masinosvieta].levelis == 0)
			{
				d[vieta].exp = d[vieta].exp + 10;
				for (int i = 0; i < 2; i++)
				{
					drop = rand() & 34 + 0;

					c[drop].kiekis = c[drop].kiekis + 1;
					c[drop].ar_turiu = true;
					cout << "Gavote sias detales :" << endl;
					cout << c[drop].pavadinimas << endl;

				}Sleep(1500);

			}
			if (b[masinosvieta].levelis == 3)
			{
				d[vieta].exp = d[vieta].exp + 20;
				for (int i = 0; i < 3; i++)
				{
					drop = rand() & 34 + 0;

					c[drop].kiekis = c[drop].kiekis + 1;
					c[drop].ar_turiu = true;
					cout << "Gavote sias detales :" << endl;
					cout << c[drop].pavadinimas << endl;
				}Sleep(2500);
			}
			if (b[masinosvieta].levelis == 5)
			{
				d[vieta].exp = d[vieta].exp + 30;
				for (int i = 0; i < 4; i++)
				{
					drop = rand() & 34 + 0;

					c[drop].kiekis = c[drop].kiekis + 1;
					c[drop].ar_turiu = true;
					cout << "Gavote sias detales :" << endl;
					cout << c[drop].pavadinimas << endl;
				}Sleep(2500);
			}
			if (b[masinosvieta].levelis == 7)
			{
				d[vieta].exp = d[vieta].exp + 40;
				for (int i = 0; i < 5; i++)
				{
					drop = rand() & 34 + 0;

					c[drop].kiekis = c[drop].kiekis + 1;
					c[drop].ar_turiu = true;
					cout << "Gavote sias detales :" << endl;
					cout << c[drop].pavadinimas << endl;
				}Sleep(2500);
			}
			if (b[masinosvieta].levelis == 10)
			{
				d[vieta].exp = d[vieta].exp + 50;
				for (int i = 0; i < 6; i++)
				{
					drop = rand() & 34 + 0;

					c[drop].kiekis = c[drop].kiekis + 1;
					c[drop].ar_turiu = true;
					cout << "Gavote sias detales :" << endl;
					cout << c[drop].pavadinimas << endl;
				}Sleep(2500);
			}
			if (b[masinosvieta].levelis == 13)
			{
				d[vieta].exp = d[vieta].exp + 60;
				for (int i = 0; i < 7; i++)
				{
					drop = rand() & 34 + 0;

					c[drop].kiekis = c[drop].kiekis + 1;
					c[drop].ar_turiu = true;
					cout << "Gavote sias detales :" << endl;
					cout << c[drop].pavadinimas << endl;
				}Sleep(2500);
			}
			if (b[masinosvieta].levelis == 16)
			{
				d[vieta].exp = d[vieta].exp + 70;
				for (int i = 0; i < 8; i++)
				{
					drop = rand() & 34 + 0;

					c[drop].kiekis = c[drop].kiekis + 1;
					c[drop].ar_turiu = true;
					cout << "Gavote sias detales :" << endl;
					cout << c[drop].pavadinimas << endl;
				}Sleep(2500);
			}


		}
	}
	hud(d, vieta);
	if (atspawnino == 0)
	{
		masinuardymas(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
	}


}
void hud(vartotojas d[], int vieta)
{
	if (d[vieta].exp >= 100)
	{
		d[vieta].lygis = d[vieta].lygis + 1;
		d[vieta].exp = 0;
	}
}
void parduotiDetales(masinudetales c[], vartotojas d[], int vieta)
{
	cout << "Detaliu parduotuve, ar norite parduoti visas detales? y/n" << endl;
	char yesno;
	cin >> yesno;
	if (yesno == 'y' || yesno == 'Y')
	{
		for (int i = 0; i < detaliuKiekis; i++)
		{
			if (c[i].ar_turiu == true)
			{
				d[vieta].saskaita = d[vieta].saskaita + (c[i].kiekis*c[i].verte);
			}
		}
		cout << "Detales parduotos" << endl;
		cout << "Jusu saskaitoje - " << d[vieta].saskaita << endl;
	}
}
void savegame(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta)
{
	ofstream out("savegame.txt");

	out << d[vieta].vardas << endl;
	out << d[vieta].lygis << endl;
	out << d[vieta].saskaita << endl;
	out << d[vieta].sunkumas << endl;
	for (int i = 0; i < itemKiekis; i++)
	{
		out << a[i].pavadinimas << " " << a[i].kaina << " " << a[i].damage << " " << a[i].ar_nupirkta << " " << a[i].ar_uzdeta << endl;

	}
	for (int i = 0; i < detaliuKiekis; i++)
	{
		out << c[i].pavadinimas << " " << c[i].verte << " " << c[i].kiekis << " " << c[i].ar_turiu << endl;

	}
	for (int i = 0; i < 15; i++)
	{
		out << e[i].ar_ivygdyta << " " << e[i].pavadinimas << endl;
	}
	cout << "Zaidimas issaugotas!" << endl;

	cout << "Testi zaidima? y/n" << endl;
	char yesno;
	cin >> yesno;
	if (yesno == 'y')
	{
		masinuardymas(a, b, c, d, e, map, vieta, atspawnino, daromaZala, masinosvieta);
	}
	
}
void issaugotozaidejouzkrovimas(item a[], masina b[], masinudetales c[], vartotojas d[], pasiekimai e[], char map[][20], int &vieta, int &atspawnino, int &daromaZala, int &masinosvieta)
{
	ifstream in("savegame.txt");
	vieta = 0;
	daromaZala = 0;

	in >> d[vieta].vardas;
	in >> d[vieta].lygis;
	in >> d[vieta].saskaita;
	in >> d[vieta].sunkumas;
	for (int i = 0; i < itemKiekis; i++)
	{
		in >> a[i].pavadinimas;
		in >> a[i].kaina;
		in >> a[i].damage;
		in >> a[i].ar_nupirkta;
		in >> a[i].ar_uzdeta;
	}
	for (int i = 0; i < itemKiekis; i++)
	{
		if (a[i].ar_uzdeta == 1)
		{
			daromaZala = daromaZala + a[i].damage;
		}
	}
	for (int i = 0; i < detaliuKiekis; i++)
	{
		in >> c[i].pavadinimas;
		in >> c[i].verte;
		in >> c[i].kiekis;
		in >> c[i].ar_turiu;
	}
	for (int i = 0; i < 15; i++)
	{
		in >> e[i].ar_ivygdyta;
		getline(in, e[i].pavadinimas, '.');
	}
}
void pasiekimas(int &isardyta, vartotojas d[], pasiekimai e[], int vieta, item a[],masinudetales c[])
{

	
	if (d[vieta].lygis == 5)
	{
		e[0].ar_ivygdyta = 1;
	}
	if (d[vieta].lygis == 10)
	{
		e[1].ar_ivygdyta = 1;
	}
	if (d[vieta].lygis == 15)
	{
		e[2].ar_ivygdyta = 1;
	}
	if (d[vieta].lygis == 20)
	{
		e[3].ar_ivygdyta = 1;
	}
	if (isardyta == 5)
	{
		e[4].ar_ivygdyta = 1;
	}
	if (isardyta == 10)
	{
		e[5].ar_ivygdyta = 1;
	}
	if (isardyta == 15)
	{
		cout << "Ivygdyte pasiekima ir gavote kelta, galite ji uzsideti ir pradeti naudoti" << endl;
		a[8].ar_nupirkta = 1;
		e[6].ar_ivygdyta = 1;
	}
	if (isardyta == 20)
	{
		e[7].ar_ivygdyta = 1;
	}
	if (d[vieta].saskaita == 50)
	{
		e[8].ar_ivygdyta = 1;
	}
	if (d[vieta].saskaita == 100)
	{
		e[9].ar_ivygdyta = 1;
	}
	if (d[vieta].saskaita == 200)
	{
		e[10].ar_ivygdyta = 1;
	}
	if (d[vieta].saskaita == 500)
	{
		cout << "Ivygdyte pasiekima ir gavote kampini slifuokli, galite ji uzsideti" << endl;
		a[7].ar_nupirkta = 1;
		e[11].ar_ivygdyta = 1;
	}
	if (c[32].ar_turiu == 1)
	{
		e[12].ar_ivygdyta = 1;
	}
	if (a[3].ar_nupirkta == 1)
	{
		e[13].ar_ivygdyta = 1;
	}
	if (d[vieta].sunkumas == 3)
	{
		e[14].ar_ivygdyta = 1;
	}
	
}
void pasiekimoinfo(pasiekimai e[])
{
	ifstream in("pasiekimai.txt");
	for (int i = 0; i < 15; i++)
	{
		in >> e[i].ar_ivygdyta;
		getline(in, e[i].pavadinimas, '.');

	}
}

