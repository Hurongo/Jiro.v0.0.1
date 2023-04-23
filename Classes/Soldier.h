class Soldier
{
	private:
		string callsign;
		bool ThereIsATask[24]{false ,false ,false ,false, false, false, false, false, false, false, false, false, false ,false ,false ,false, false, false, false, false, false, false, false, false };
	public:
		string GetCallsign()
		{
			return callsign;
		}
		void SetCallsign(string callsign)
		{
			this->callsign = callsign;
		}
		bool GetThereIsATask(int task)
		{
			return ThereIsATask[task];
		}
		bool GetThereIsATaskGlobal()
		{
			for (int i = 0; i < 24; i++)
			{
				return ThereIsATask[i];
			}
		}
		void SetThereIsATask(int task, bool ThereIsATask)
		{

			this->ThereIsATask[task] = ThereIsATask;
		}
		void SetThereIsATaskGlobal()
		{
			bool rin;
			for (int i = 0; i < 24; i++)
			{
				cout << "Vvedite bool peremennuu dla ThereIsATask 4 raza\n";
				cin >> rin;
				this->ThereIsATask[i] = rin;
			}
		}
		
		void GetSoldierInformation()
		{
			cout << callsign << ThereIsATask << endl;
		}
		
		void SetSoldierInformation(string callsign, string Rank)
		{
			this->callsign = callsign;
		}
		
		friend ostream& operator <<(ostream& os, const Soldier& soldier);
		friend istream& operator >>(istream& is, Soldier& soldier);
};

ostream& operator <<(ostream& os, const Soldier& soldier)//Перегрузка оператора "<<" Для записи обьекта класса в файл
{
	os << soldier.callsign << " " ;

	for (int i = 0; i < 24; i++)
	{
		os << soldier.ThereIsATask[i] << " ";
	}

	return os;
}

istream& operator >>(istream& is, Soldier& soldier)//Перегрузка оператора ">>" Для записи обьекта из файла в класс
{
	is >> soldier.callsign ;

	for (int i = 0; i < 24; i++)
	{
		is >>soldier.ThereIsATask[i];
	}
	return is;
}