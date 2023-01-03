#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

class Production
{
private:
    int NrMachiaj, NrTipMancare;

public:

    //Constructori - Destructori
    Production() {}
    ~Production() {};

    //Incapsulare
    void setNrMachiaj(int NrMachiaj)
    {
        this->NrMachiaj = NrMachiaj;
    }

    void setNrTipMancare(int NrTipMancare)
    {
        this->NrTipMancare = NrTipMancare;
    }

    int getNrMachiaj()
    {
        return NrMachiaj;
    }

    int getNrTipMancare(int NrTipMancare)
    {
        return NrTipMancare;
    }
    //
};

class Cast: public Production
{
public:

    string Machiaj[5] = {"Vampiri","Varcolaci","Sirene","Clarvazatori","Om"};
    string Mancare[3] = {"Omnivora","Vegetariana","Flexitariana"};
    int nrVampiri = 0, nrVarcolaci = 0, nrSirene = 0, nrClarvazatori = 0, nrOameni = 0;

    void NrCostume()
    {
        fstream fin;
        fin.open("FullCastWednesday.csv", ios::in);

        vector<string> row;
        string line, word, temp;

        while(getline(fin, line))
        {
            row.clear();
            stringstream s(line);
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            if((row[1] == "actor/actress") || (row[1] == "extra"))
            {
                string machiaj = Machiaj[rand() % 5];
                if(machiaj == "Vampiri")
                    nrVampiri++;
                else if(machiaj == "Varcolaci")
                    nrVarcolaci++;
                else if(machiaj == "Sirene")
                    nrSirene++;
                else if(machiaj == "Clarvazatori")
                    nrClarvazatori++;
                else if(machiaj == "Om")
                    nrOameni++;
            }
        }
        fin.close();
    }
};

//Functia de creeare a fisierului cu figuranti
void figuranti()
{
    remove("Extra.csv");

    fstream f1;

    f1.open("Extra.csv", ios::out | ios::app);

    srand(time(0));

    string Nume[152]= {"Adamescu","Alexe","Albu","Angelescu","Anghel","Antal","Apostol","Alexandrescu","Ardeleanu","Arghezi","Avramescu","Apostoleanu","Baciu","Badea","Baicu","Balan","Banateanu","Barbu","Barna","Basarabeanu","Basescu","Becali","Balasa","Bejenaru","Bercea","Bogza","Bujor","Borcea","Brasoveanu","Bratu","Bucur","Buzoianu","Burtea","Camataru","Calugareanu","Campeanu","Cartan","Casian","Cazacu","Calin","Ceausescu","Cernea","Chelaru","Chiriac","Christescu","Cioaba","Cioaca","Ciobanu","Cireseanu","Ciubuc","Codrut","Cojocaru","Colceru","Comaneci","Constantin","Constantinescu","Cozma","Cuza","Dascalu","Diaconu","Dobrogeanu","Dolha","Dragan","Dumitra","Dulgheru","Dumitru","Dumitrescu","Eliade","Enache","Eremia","Enescu","Enache","Firea","Florea","Filipescu","Fratila","Fluieras","Fulga","Gabor","Georgescu","Gheorghe","Gherasim","Ghita","Goga","Grecu","Grigore","Grigoras","Groza","Gruia","Gutu","Halep","Hasdeu","Hategan","Hossu","Huniade","Hanu","Haralambie","Ioan","Iliescu","Ivanescu","Ionita","Iordache","Istrate","Ispas","Jebeleanu","Lascu","Lazareanu","Lepadatu","Luca","Lucescu","Lungu","Lupu","Lazarescu","Lupsan","Manea","Mailat","Manole","Maruta","Miclaus","Mihailescu","Miron","Misu","Mocanu","Moga","Moldoveanu","Neagu","Niculae","Nita","Noica","Negoita","Neculce","Necula","Oancea","Olaru","Opris","Oprea","Paduraru","Pascu","Raceanu","Radoi","Stanciu","Stoian","Stoica","Stroe","Suciu","Surdu","Trancu","Tomita","Toader","Teodorescu","Ungureanu","Vintila"};
    string Prenume[137] = {"Ada","Adela","Alexandra","Marius","Beatrice","Alexandru","Agata","Adina","Aurora","Ana","Corina","Daniela","Ecaterina","Clara","Dana","Elena","Doina","Diana","Ion","Fabiana","Floare","Oana","Iasmina","Ionela","Geta","Francesca","Ina","Lili","Adam","Camil","Cosmin","Codrin","Bernand","Corneliu","Cezar","Ciprian","Adrian","Darius","David","Cazimir","Damian","Gheorghe","Ghita","Gherasim","Iliuta","Lica","Miron","Matei","Marian","Marin","Jean","Laurentiu","Lascar","Mihai","Mihail","Nicusor","Nicolae","Plesu","Petru","Octav","Radu","Rares","Paul","Robert","Sebastian","Sergiu","Relu","Serban","Stefan","Rafael","Rafaela","Raul","Silviu","Zamfir","Zaharia","Vlad","Vladimir","Viorel","Valentin","Teodor","Vasile","Trandafir","Virgil","Vlad","Toma","Traian","Valeriu","Victor","Vincentiu","Valentina","Veronica","Verona","Viorica","Viorela","Veta","Virginia","Simona","Sabina","Sabrina","Sanda","Sandra","Valeria","Teodora","Timea","Sonia","Ramona","Roxana","Raluca","Rebeca","Ramonca","Silvia","Paulina","Paul","Tudora","Stefania","Olga","Olimpia","Otilia","Speranta","Savina","Roberta","Suzana","Steluta","Nina","Nicoleta","Dinu","George","Horia","Grigore","Ionel","Ghita","Georgian","Gelu","Gabriel","Ilie","Madalin","Laurentiu"};

    for(int i = 1; i <= 132; i++)
        f1<<Nume[rand() % 152]<<" "<<Prenume[rand() % 137]<<","<<"extra"<<"\n";
    f1.close();
}

//Functie de creeare a fisierului cu intreg castul
void fullCast()
{
    remove("FullCastWednesday.csv");

    ifstream file1("wednesdayCast.csv");
    ifstream file2("Extra.csv");

    ofstream outfile("FullCastWednesday.csv");

    string line;
    while (getline(file1, line))
    {
        outfile << line << endl;
    }

    while (getline(file2, line))
    {
        outfile << line << endl;
    }

    file1.close();
    file2.close();
    outfile.close();
}

int main()
{
    //Functia de creeare a fisierului cu figuranti
    figuranti();

    //Functie de creeare a fisierului cu intreg castul
    fullCast();

    Production Wednesday;
    Wednesday.setNrMachiaj(5);
    Wednesday.setNrTipMancare(3);
    Cast cast;
    cast.NrCostume();

    return 0;
}
