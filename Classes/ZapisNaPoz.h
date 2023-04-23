#pragma once



void ZapisNaPoz (int NeedSoldier, string NamePositions, int peresmenkas)
{
	Positions avrora_21;
	
	avrora_21.SetInfoPositions(NeedSoldier, NamePositions);
	string PositionsList = FileUtils::getInstance()->getWritablePath() + "pozicion.txt";
	string SoldierList = FileUtils::getInstance()->getWritablePath() + "Soldierlist.txt";
	string PositionsListBusy = FileUtils::getInstance()->getWritablePath() + "PositionsListBusy.txt";
	string SoldierListFree = FileUtils::getInstance()->getWritablePath() + "SoldierlistFree2.txt";


	fstream fsf;
	fstream fsp;
	fstream fss;
	fstream fspb;

	ofstream clear;

	fspb.open(PositionsListBusy, fstream::in | fstream::out | fstream::app);
	fsp.open(PositionsList, fstream::in | fstream::out | fstream::app);
	fss.open(SoldierList, fstream::in | fstream::out | fstream::app);
	fsf.open(SoldierListFree, fstream::in | fstream::out | fstream::app);

	cout << "Peresmenka 1 Raz vo skolko chasov? Min 1 max 4" << endl;
	int time_solger, peresmenka;
	peresmenka = peresmenkas;
	if (peresmenka == 0 || peresmenka > 4)
	{
		while (peresmenka == 0 || peresmenka > 4)
		{
			cout << "Peresmenka Min 1 max 4!!!\nPeresmenka 1 Raz vo skolko chasov?\n";
			cin >> peresmenka;
		}
	}
	time_solger = peresmenka;
	peresmenka = 24 / peresmenka;
	vector <Soldier> list;
	vector <Soldier> listBusy;


	Soldier Tomas;

	int zero = 0;
	int Exception = 0;

	int task;
	int t = 24;
	int min = 0;
	vector <int> TimeLine(t);

	for (int i = 0; i < t; i++)
	{
		TimeLine[i] = i;
	}
	fspb << avrora_21;
	fspb << peresmenka << endl;
	for (int j = 0; j < peresmenka; j++)
	{
		cout << TimeLine[min] << ":00" << endl;

		
		if (min <= 0 && min + time_solger <= 4)
		{
			task = 0;
		}
		else if (min >= 4 && min + time_solger <= 8)
		{
			task = 1;
		}
		else if (min >= 8 && min + time_solger <= 12)
		{
			task = 2;
		}
		else if (min >= 12 && min + time_solger <= 16)
		{
			task = 3;
		}
		else if (min >= 16 && min + time_solger <= 20)
		{
			task = 4;
		}
		else if (min >= 20 && min + time_solger <= 24)
		{
			task = 5;

		}

		for (int i = 0; i < NeedSoldier; i++)
		{
			
			fsf >> Tomas;

			if (Tomas.GetThereIsATask(task) == false && Tomas.GetThereIsATask(task + 1) == false || task == 5 && Tomas.GetThereIsATask(0) == false)
			{


				Tomas.SetThereIsATask(task, true);
				if (time_solger == 3 || time_solger == 4 && task == 5)
				{
					Tomas.SetThereIsATask(task - 5, true);
				}
				if (time_solger == 3 || time_solger == 4)
				{
					Tomas.SetThereIsATask(task + 1, true);
				}

				fspb << Tomas << "\n";
				cout << Tomas << endl;

				listBusy.emplace_back(Tomas);
				zero = 0;

				if (i + 1 == NeedSoldier && j + 1 == peresmenka)
				{
					while (true)
					{
						fsf >> Tomas;
						if (fsf.eof())
						{
							for (int i = 0; i < listBusy.size(); i++)
							{
								cout << "$$$$$$$$$" << listBusy[i] << endl;
							}
							break;
						}
						else
						{
							listBusy.emplace_back(Tomas);
						}
					}
					fsf.close();
					clear.open(SoldierListFree, ofstream::out | ofstream::trunc);
					clear.close();

					fsf.open(SoldierListFree, fstream::in | fstream::out | fstream::app);

					for (auto i = listBusy.cbegin(); i != listBusy.cend(); i++)
					{
						cout << *i << endl;

						fsf << *i << endl;
					}

				}

				

				
			}
			else if (Exception != 0)
			{
				i = NeedSoldier;
				j = peresmenka;
			}
			else
			{
				i--;
				
				
				if (fsf.eof())
				{
					fsf.close();
					clear.open(SoldierListFree, ofstream::out | ofstream::trunc);
					clear.close();
					fsf.open(SoldierListFree, fstream::in | fstream::out | fstream::app);
					for (auto i = listBusy.cbegin(); i != listBusy.cend(); i++)
					{

						fsf << *i << endl;
					}
					fsf.clear();
					fsf.seekg(0);
					listBusy.resize(0);

					zero ++;
					if (zero == peresmenka)
					{
						Exception++;
						cout << "Na danniy post nehvataet ludei\n";
					}
				}
				else
				{
					listBusy.emplace_back(Tomas);
				}
			}

		}
		min += time_solger;
	}
	fsp.close();
	fss.close();
	fspb.close();
	fsf.close();
}