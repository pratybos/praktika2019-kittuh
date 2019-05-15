
#include "pch.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
int itemKiekis = 10;
struct item
{
	std::string pavadinimas;
	int kaina;
	int damage;
	bool ar_nupirkta;
	bool ar_uzdeta;
};
using namespace std;
void iteminfo(item a[], int sunkumas);
void inventorius(item a[]);
void parduotuve(item a[], int &saskaita);
void pirktiDaiktus(item a[], int &saskaita);
void parduotiDaiktus(item a[], int &saskaita);
void nuimti(item a[]);
void uzdeti(item a[]);
//void parduotiDetales(item a[], int &saskaita);
int main()
{
	cout << "Pasirinkite sunkuma:" << endl;
	cout << "1 - Pradedantysis" << endl;
	cout << "2 - Patyres" << endl;
	cout << "3 - Ekspertas" << endl;
	int sunkumas;
	cin >> sunkumas;
	item a[10];
	iteminfo(a, sunkumas);
	inventorius(a);
	int x, saskaita;


}
void iteminfo(item a[], int sunkumas)
{
	if (sunkumas == 1)
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
	if (sunkumas == 2)
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
	if (sunkumas == 3)
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
void inventorius(item a[])
{
	cout << "1 - Turimi daiktai" << endl;
	cout << "2 - Uzdeti daiktai" << endl;
	cout << "3 - Daiktu uzdejimas" << endl;
	cout << "4 - Daiktu nuemimas" << endl;
	int pasirinkimas;
	cin >> pasirinkimas;
	while (pasirinkimas != 0)
	{
		if (pasirinkimas > 0 && pasirinkimas <= 4)
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
				
			}cin >> pasirinkimas;
		

		}else cout << "Blogas pasirinkimas" << endl;
	}
}
void parduotuve(item a[], int &saskaita)
{
	int pasirinkimas;
	cout << "Parduotuves meniu " << endl;
	cout << "1 - Pirkti daiktus" << endl;
	cout << "2 - Parduoti daiktus" << endl;
	cout << "3 - Parduoti automobiliu detales " << endl;
	cout << "4- Grizti atgal" << endl;
	cin >> pasirinkimas;
	while (pasirinkimas != 0)
	{
		if (pasirinkimas > 0 && pasirinkimas <= 4)
		{
			switch (pasirinkimas)
			{
			case 1:
				pirktiDaiktus(a, saskaita);
				break;

			case 2:
				parduotiDaiktus(a, saskaita);
				break;

			case 3:
				//parduotiDetales(a, saskaita);
				break;

			case 4:

				break;
			}
		}
		else cout << "Blogas pasirinkimas" << endl;
		cin >> pasirinkimas;
	}

}
void pirktiDaiktus(item a[], int &saskaita)
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
					saskaita = saskaita - a[0].kaina;
					a[0].ar_nupirkta = 1;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 2:
				if (a[1].ar_nupirkta == 0)
				{
					saskaita = saskaita - a[1].kaina;
					a[1].ar_nupirkta = 1;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 3:
				if (a[2].ar_nupirkta == 0)
				{
					saskaita = saskaita - a[2].kaina;
					a[2].ar_nupirkta = 1;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 4:
				if (a[3].ar_nupirkta == 0)
				{
					saskaita = saskaita - a[3].kaina;
					a[3].ar_nupirkta = 1;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 5:
				if (a[4].ar_nupirkta == 0)
				{
					saskaita = saskaita - a[4].kaina;
					a[4].ar_nupirkta = 1;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 6:
				if (a[5].ar_nupirkta == 0)
				{
					saskaita = saskaita - a[5].kaina;
					a[5].ar_nupirkta = 1;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 7:
				if (a[6].ar_nupirkta == 0)
				{
					saskaita = saskaita - a[6].kaina;
					a[6].ar_nupirkta = 1;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			case 8:
				if (a[7].ar_nupirkta == 0)
				{
					saskaita = saskaita - a[7].kaina;
					a[7].ar_nupirkta = 1;

				}
				else cout << "Toki daikta jau turite inventoriuje" << endl;
				break;
			}
		}
		else cout << "Tokio daikto sarase nera" << endl;
		cin >> pasirinkimas;
	}

}
void parduotiDaiktus(item a[], int &saskaita)
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
				if (a[0].ar_nupirkta == 0 && a[0].ar_uzdeta == 0)
				{
					saskaita = saskaita + a[0].kaina;
					a[0].ar_nupirkta = 1;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 2:
				if (a[1].ar_nupirkta == 0 && a[1].ar_uzdeta == 0)
				{
					saskaita = saskaita + a[1].kaina;
					a[1].ar_nupirkta = 1;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 3:
				if (a[2].ar_nupirkta == 0 && a[2].ar_uzdeta == 0)
				{
					saskaita = saskaita + a[2].kaina;
					a[2].ar_nupirkta = 1;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 4:
				if (a[3].ar_nupirkta == 0 && a[3].ar_uzdeta == 0)
				{
					saskaita = saskaita + a[3].kaina;
					a[3].ar_nupirkta = 1;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 5:
				if (a[4].ar_nupirkta == 0 && a[4].ar_uzdeta == 0)
				{
					saskaita = saskaita + a[4].kaina;
					a[4].ar_nupirkta = 1;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 6:
				if (a[5].ar_nupirkta == 0 && a[5].ar_uzdeta == 0)
				{
					saskaita = saskaita + a[5].kaina;
					a[5].ar_nupirkta = 1;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 7:
				if (a[6].ar_nupirkta == 0 && a[6].ar_uzdeta == 0)
				{
					saskaita = saskaita + a[6].kaina;
					a[6].ar_nupirkta = 1;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			case 8:
				if (a[7].ar_nupirkta == 0 && a[7].ar_uzdeta == 0)
				{
					saskaita = saskaita + a[7].kaina;
					a[7].ar_nupirkta = 1;

				}
				else cout << "Sio daikto neturite savo inventoriuje, arba jis yra naudojamas" << endl;
				break;
			}
		}
		else cout << "Tokio daikto sarase nera" << endl;
		cin >> pasirinkimas;
	}

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