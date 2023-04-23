class Positions
{
private:
	int NeedSoldier;
	string NamePositions;
public:
	int GetNeedSoldier()
	{
		return NeedSoldier;
	}
	void SetNeedSoldier(int NeedSoldier)
	{
		this->NeedSoldier = NeedSoldier;
	}
	string GetNamePositions()
	{
		return NamePositions;
	}
	void SetNamePositions(string NamePositions)
	{
		this->NamePositions = NamePositions;
	}
	void Karaul(int NeedSoldier, string NamePositions)
	{
		if (this->NeedSoldier >= NeedSoldier && NeedSoldier >= 2)
		{
			cout << "Karaul complited" << endl;
		}
		else
		{
			cout << "NeedSoldier >= 2" << endl;
		}
	}
	void Patrul(int NeedSoldier, string NamePositions)
	{
		if (this->NeedSoldier >= NeedSoldier && NeedSoldier >= 3)
		{
			cout << "Patrul complited" << endl;
		}
		else
		{
			cout << "NeedSoldier >= 2" << endl;
		}

	}
	void Sekret(int NeedSoldier, string NamePositions)
	{
		if (this->NeedSoldier >= NeedSoldier && NeedSoldier >= 2)
		{
			cout << "Sekret complited" << endl;
		}
		else
		{
			cout << "NeedSoldier >= 2" << endl;
		}
	}
	void Viezd(int NeedSoldier, string NamePositions)
	{
		if (this->NeedSoldier >= NeedSoldier && NeedSoldier >= 12)
		{
			cout << "Viezd complited" << endl;
		}
		else
		{
			cout << "NeedSoldier >= 12" << endl;
		}
	}
	void SetInfoPositions(int NeedSoldier, string NamePositions)
	{
		this->NeedSoldier = NeedSoldier;
		this->NamePositions = NamePositions;
	}
	void info()
	{
		cout << NeedSoldier << " NeedSoldier " << NamePositions << " NamePositions " << endl;
	}

	friend ostream& operator <<(ostream& os, const Positions& positions);
	friend istream& operator >>(istream& is, Positions& positions);
};

ostream& operator <<(ostream& os, const Positions& positions)//Перегрузка оператора "<<" Для записи обьекта класса в файл
{
	os << positions.NeedSoldier << " " << positions.NamePositions << "\n" ;

	return os;
}

istream& operator >>(istream& is, Positions& positions)//Перегрузка оператора ">>" Для записи обьекта из файла в класс
{
	is >> positions.NeedSoldier >> positions.NamePositions;

	return is;
}