#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Illness
{
	public:
		string name;
		string symptoms[7];
	public:
		Illness(const string& n, const string* s) : name(n)
		{
			for(int i = 0; i < 7; ++i)
			{
				symptoms[i] = s[i];
			}
		}
		virtual ~Illness() {}
		virtual bool checkSymptoms() const = 0;
};

class COVID19 : public Illness
{
	public:
		COVID19() : Illness("COVID-19", new string[7]{"*", "*", "*", "+", "+", "-", "+"}) {}
		bool checkSymptoms() const override
		{
			return(symptoms[0] == "+" && symptoms[1] == "+" &&
			       symptoms[2] == "+"&& symptoms[3] == "+" &&
				   symptoms[4] == "+" && symptoms[5] == "-" && symptoms[6] == "+");
		}
};

class Cold : public Illness
{
	public:
		Cold() : Illness("Cold", new string[7]{"+", "+", "-", "*", "+", "*", "+"}) {}
		bool checkSymptoms() const override 
		{
			return(symptoms[0] == "+" && symptoms[1] == "+" &&
			       symptoms[2] == "-" && symptoms[3] == "+" &&
				   symptoms[4] == "+" && symptoms[5] == "+" && symptoms[6] == "+");
		}
};

class Flu : public Illness
{
	public:
		Flu() : Illness("Flu", new string[7]{"*", "*", "-", "+", "*", "-", "*"}) {}
		bool checkSymptoms() const override
		{			
			return(symptoms[0] == "+" && symptoms[1] == "+ " &&
			       symptoms[2] == "-" && symptoms[3] == "+" &&
				   symptoms[4] == "+" && symptoms[5] == "-" && symptoms[6] == "+");
		}
};

int main()
{
	srand(static_cast<unsigned>(time(0)));
	
	cout << "Welcom to the Symptoms Checker\n" << endl;
	cout << "\n" << endl;
	cout << "Guide:           * Common            + Sometimes/Rarely            - NO\n" << endl;
	cout << "=============================================================================\n" << endl;
	cout << "Symptoms               |      COVID-19      |      Cold      |     Flu      |\n" << endl;
	cout << "=============================================================================\n" << endl;
	cout << "Fever                  |         *          |        +       |      *       |\n" << endl;
	cout << "Cough                  |         *          |        +       |      *       |\n" << endl;
	cout << "Shortness of Breath    |         *          |        -       |      -       |\n" << endl;
	cout << "Runny Nose             |         +          |        *       |      +       |\n" << endl;
	cout << "Headaches              |         +          |        +       |      *       |\n" << endl;
	cout << "Sneezing               |         -          |        *       |      -       |\n" << endl;
	cout << "Fatigue                |         +          |        +       |      *       |\n" << endl;
	
	int numPatients;
	cout << "Enter the number of patients: ";
	cin >> numPatients;
	cout << "Thank you. . .\n";
	
	int covidCount = 0, coldCount = 0, fluCount = 0, otherCount = 0;
	
	for(int i = 0; i < numPatients; ++i)
	{
		COVID19 covid19;
		Cold cold;
		Flu flu;

		for(int j = 0; j < 6; ++j)
		{
			if(rand() % 2 == 0)
			{
				covid19.symptoms[j] = "+";
				cold.symptoms[j] = "+";
				flu.symptoms[j] = "+";
			}
			else
			{
				covid19.symptoms[j] = "-";
				cold.symptoms[j] = "-";
				flu.symptoms[j] = "-";
			}
		}
		
		if(covid19.checkSymptoms())
		{
			covidCount++;
		}
		else if(cold.checkSymptoms())
		{
			coldCount++;
		}
		else if(flu.checkSymptoms())
		{
			fluCount++;
		}
		else
		{
			otherCount++;
		}
	}
	
	int totalPatients = numPatients;
	double covidPercentage = (static_cast<double>(covidCount) / totalPatients) * 100;
	double coldPercentage = (static_cast<double>(coldCount) / totalPatients) * 100;
	double fluPercentage = (static_cast<double>(fluCount) / totalPatients) * 100;
	double otherPercentage = (static_cast<double>(otherCount) / totalPatients) * 100;
	
    cout << "=============================================================================" << endl;
    cout << "Symptoms Checker. . . ." << endl;
    cout << covidCount << " patients have symptoms of COVID-19" << endl;
    cout << coldCount << " patients have symptoms of Cold" << endl;
    cout << fluCount << " patients have symptoms of Flu" << endl;
    cout << otherCount << " patients may have some other illness" << endl;
    cout << "=============================================================================" << endl;
    
    cout << "Percentage of each illness:" << endl;
    cout << "COVID-19:      [" << static_cast<int>(covidPercentage) << "%]";
    for (int i = 0; i < static_cast<int>(covidPercentage); ++i) cout << "+";
    cout << endl;
    cout << "Cold:          [" << static_cast<int>(coldPercentage) << "%]";
    for (int i = 0; i < static_cast<int>(coldPercentage); ++i) cout << "+";
    cout << endl;
    cout << "Flu:           [" << static_cast<int>(fluPercentage) << "%]";
    for (int i = 0; i < static_cast<int>(fluPercentage); ++i) cout << "+";
    cout << endl;
    cout << "Other illness:[" << static_cast<int>(otherPercentage) << "%]";
    for (int i = 0; i < static_cast<int>(otherPercentage); ++i) cout << "+";
    cout << endl;
    cout << "=============================================================================" << endl;
    
	return 0;
}
