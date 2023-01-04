#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

template <typename T>
T produs(T a, T b)
{
    return a * b;
}

class Production
{
public:

    virtual void NrCostume() = 0;
    virtual void NrTipMancare() = 0;
    virtual void NrCamere() = 0;
    virtual void LitriiBautura() = 0;
    virtual void NrAutocare() = 0;
};


class Cast: public Production
{
protected:
    string Machiaj[5] = {"Vampiri","Varcolaci","Sirene","Clarvazatori","Om"};
    string Mancare[3] = {"Omnivora","Vegetariana","Flexitariana"};
    static int nrVampiri, nrVarcolaci, nrSirene, nrClarvazatori, nrOameni, nrOmnivori, nrVegetarieni, nrFlexitarieni, i, j, nrCamere3, nrCamere2, nrPersoane, LitriiApa, nrAutocare;
    static float LitriiSuc, LitriiCafea;
    int trei = 3, doi = 2;
public:

    Cast() {};
    ~Cast() {};

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

    void NrTipMancare()
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
            string mancare = Mancare[rand() % 3];
            if(mancare == "Omnivora")
                nrOmnivori++;
            else if(mancare == "Vegetariana")
                nrVegetarieni++;
            else if(mancare == "Flexitariana")
                nrFlexitarieni++;
        }
        fin.close();
    }

    void NrCamere()
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

            if(row[1] == "extra")
                i++;
            else if(row[1] != "extra")
                j++;
        }

        try
        {
            if(trei == 0)
            {
                throw "Impartire cu 0";
            }
            if(i%trei == 0)
                nrCamere3 = i/trei;
            else
                nrCamere3 = (i-1)/trei + 1;
        }
        catch(const char* msg)
        {
            cerr<<msg;
        }

        try
        {
            if(doi == 0)
            {
                throw "Impartire cu 0";
            }
            if(j % doi == 0)
                nrCamere2 = j/doi;
            else nrCamere2 = (j-1)/doi + 1;
        }
        catch(const char* msg)
        {
            cerr<<msg;
        }

        fin.close();
    }

    void LitriiBautura()
    {
        nrPersoane = i + j;
        LitriiApa = nrPersoane * 1;
        LitriiCafea = nrPersoane * 0.5;
        LitriiSuc = nrPersoane * 0.8;
    }

    void NrAutocare()
    {
        if(nrPersoane % 50 == 0)
            nrAutocare = nrPersoane / 50;
        else
            nrAutocare = (nrPersoane - (nrPersoane % 50))/50 + 1;
    }
};

int Cast::nrVampiri = 0;
int Cast::nrVarcolaci = 0;
int Cast::nrSirene = 0;
int Cast::nrClarvazatori = 0;
int Cast::nrOameni = 0;
int Cast::nrOmnivori = 0;
int Cast::nrVegetarieni = 0;
int Cast::nrFlexitarieni = 0;
int Cast::nrCamere2 = 0;
int Cast::nrCamere3 = 0;
int Cast::i = 0;
int Cast::j = 0;
int Cast::nrPersoane = 0;
int Cast::LitriiApa = 0;
float Cast::LitriiCafea = 0;
float Cast::LitriiSuc = 0;
int Cast::nrAutocare = 0;

class Cost: public Cast
{
private:
    int pretOmnivor, pretVegetarian, pretFlexitarian;
    int pretApa, pretCafea, pretSuc;
    int sumaMancare, sumaCostume, sumaCazare, sumaTransport;
    float sumaBautura, sumaMancareBautura;
    int inchiriere = 10000;
    int PretAutocar;

public:
    Cost(int PretAutocar)
    {
        this -> PretAutocar = PretAutocar;
        sumaTransport = produs(2,produs(nrAutocare,PretAutocar));
    };
    ~Cost() {};
    //setters
    void setPretOmnivor(int pretOmnivor)
    {
        this -> pretOmnivor = pretOmnivor;
    }

    void setPretVegetarian(int pretVegetarian)
    {
        this -> pretVegetarian = pretVegetarian;
    }

    void setPretFlexitarian(int pretFlexitarian)
    {
        this-> pretFlexitarian = pretFlexitarian;
    }

    void setPretApa(int pretApa)
    {
        this-> pretApa = pretApa;
    }

    void setPretCafea(int pretCafea)
    {
        this-> pretCafea = pretCafea;
    }

    void setPretSuc(int pretSuc)
    {
        this-> pretSuc = pretSuc;
    }

    //getters
    int getPretOmnivor()
    {
        return this->pretOmnivor;
    }

    int getPretVegetarian()
    {
        return this->pretVegetarian;
    }

    int  getPretFlexitarian()
    {
        return this->pretFlexitarian;
    }

    int  getPretApa()
    {
        return this->pretApa;
    }

    int  getPretCafea()
    {
        return this->pretCafea;
    }

    int  getPretSuc()
    {
        return this->pretSuc;
    }

    void SumaMancareBautura()
    {
        sumaMancare = produs(pretOmnivor,nrOmnivori) + produs(pretVegetarian,nrVegetarieni) + produs(pretFlexitarian,nrFlexitarieni);
        sumaBautura = produs((pretApa/2),LitriiApa) + produs((float)pretCafea,LitriiCafea) + produs((float)(pretSuc/2), LitriiSuc);
        sumaMancareBautura = sumaMancare + sumaBautura;
    }

    void Suma(int CostVampir, int CostVarcolac, int CostSirena, int CostClarvazator, int CostOm)
    {
        sumaCostume = produs(CostVampir,nrVampiri) + produs(CostVarcolac,nrVarcolaci) + produs(CostSirena,nrSirene) + produs(CostClarvazator,nrClarvazatori) + produs(CostOm,nrOameni);
    }

    void Suma(int PretCamera2, int PretCamera3)
    {
        sumaCazare = produs(PretCamera2,nrCamere2) + produs(PretCamera3,nrCamere3);
    }

    void DocumentCost()
    {
        fstream f1, f2;

        remove("Cost [ro].csv");
        remove("Cost [en].csv");

        f1.open("Cost [ro].csv", ios::out | ios::app);
        f2.open("Cost [en].csv", ios::out | ios::app);

        //1 dolar = 4.64 lei

        f1<<"Zile"<<","<<"Transport"<<","<<"Cazare"<<","<<"Machiaj"<<","<<"Mancare si apa"<<","<<"Inchiriere spatiu"<<","<<"Total"<<"\n";
        f1<<"30"<<","<<(30 * (float)sumaTransport)/4.64<<","<<(30 * (float)sumaCazare)/4.64<<","<<(30 * (float)sumaCostume)/4.64<<","<<(30 * sumaMancareBautura)/4.64<<","<<(30 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<","<<(30 * (float)sumaTransport)/4.64 + (30 * (float)sumaCazare)/4.64 + (30 * (float)sumaCostume)/4.64 + (30 * sumaMancareBautura)/4.64 + (30 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<"\n";
        f1<<"45"<<","<<(45 * (float)sumaTransport)/4.64<<","<<(45 * (float)sumaCazare)/4.64<<","<<(45 * (float)sumaCostume)/4.64<<","<<(45 * sumaMancareBautura)/4.64<<","<<(45 * (float)(inchiriere - (float)inchiriere*8/100))/4.64<<","<<(45 * (float)sumaTransport)/4.64 + (45 * (float)sumaCazare)/4.64 + (45 * (float)sumaCostume)/4.64 + (45 * sumaMancareBautura)/4.64 + (45 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<"\n";
        f1<<"60"<<","<<(60 * (float)sumaTransport)/4.64<<","<<(60 * (float)sumaCazare)/4.64<<","<<(60 * (float)sumaCostume)/4.64<<","<<(60 * sumaMancareBautura)/4.64<<","<<(60 * (float)(inchiriere - (float)inchiriere*12/100))/4.64<<","<<(60 * (float)sumaTransport)/4.64 + (60 * (float)sumaCazare)/4.64 + (60 * (float)sumaCostume)/4.64 + (60 * sumaMancareBautura)/4.64 + (60 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<"\n";
        f1<<"100"<<","<<(100 * (float)sumaTransport)/4.64<<","<<(1000 * (float)sumaCazare)/4.64<<","<<(100 * (float)sumaCostume)/4.64<<","<<(100 * sumaMancareBautura)/4.64<<","<<(100 * (float)(inchiriere - (float)inchiriere*20/100))<<","<<(100 * (float)sumaTransport)/4.64 + (100 * (float)sumaCazare)/4.64 + (100 * (float)sumaCostume)/4.64 + (100 * sumaMancareBautura)/4.64 + (100 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<"\n";

        f2<<"Days"<<","<<"Transport"<<","<<"Hotel"<<","<<"Makeup"<<","<<"Food"<<","<<"Rent"<<","<<"Total"<<"\n";
        f2<<"30"<<","<<(30 * (float)sumaTransport)/4.64<<","<<(30 * (float)sumaCazare)/4.64<<","<<(30 * (float)sumaCostume)/4.64<<","<<(30 * sumaMancareBautura)/4.64<<","<<(30 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<","<<(30 * (float)sumaTransport)/4.64 + (30 * (float)sumaCazare)/4.64 + (30 * (float)sumaCostume)/4.64 + (30 * sumaMancareBautura)/4.64 + (30 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<"\n";
        f2<<"45"<<","<<(45 * (float)sumaTransport)/4.64<<","<<(45 * (float)sumaCazare)/4.64<<","<<(45 * (float)sumaCostume)/4.64<<","<<(45 * sumaMancareBautura)/4.64<<","<<(45 * (float)(inchiriere - (float)inchiriere*8/100))/4.64<<","<<(45 * (float)sumaTransport)/4.64 + (45 * (float)sumaCazare)/4.64 + (45 * (float)sumaCostume)/4.64 + (45 * sumaMancareBautura)/4.64 + (45 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<"\n";
        f2<<"60"<<","<<(60 * (float)sumaTransport)/4.64<<","<<(60 * (float)sumaCazare)/4.64<<","<<(60 * (float)sumaCostume)/4.64<<","<<(60 * sumaMancareBautura)/4.64<<","<<(60 * (float)(inchiriere - (float)inchiriere*12/100))/4.64<<","<<(60 * (float)sumaTransport)/4.64 + (60 * (float)sumaCazare)/4.64 + (60 * (float)sumaCostume)/4.64 + (60 * sumaMancareBautura)/4.64 + (60 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<"\n";
        f2<<"100"<<","<<(100 * (float)sumaTransport)/4.64<<","<<(1000 * (float)sumaCazare)/4.64<<","<<(100 * (float)sumaCostume)/4.64<<","<<(100 * sumaMancareBautura)/4.64<<","<<(100 * (float)(inchiriere - (float)inchiriere*20/100))<<","<<(100 * (float)sumaTransport)/4.64 + (100 * (float)sumaCazare)/4.64 + (100 * (float)sumaCostume)/4.64 + (100 * sumaMancareBautura)/4.64 + (100 * (float)(inchiriere - (float)inchiriere*6/100))/4.64<<"\n";

        f1.close();
        f2.close();
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

void Meniu()
{
    fstream f1, f2;

    remove("Menu [ro].csv");
    remove("Menu [en].csv");

    f1.open("Menu [ro].csv", ios::out | ios::app);
    f2.open("Menu [en].csv", ios::out | ios::app);

    string roSupaCiorbaOmnivor[11] = {"Supa de pui cu taitei si galuste", "Bors de gaina cu taitei", "Ciorba de perisoare", "Ciorba de burta", "Ciorba radauteana", "Ciorba de vacuta", "Ciorba de fasole cu ciolan afumat", "Ciorba de pui a la grec", "Bors din oase si carne de porc", "Ciorba ardeleneasca de cartofi cu afumatura", "Supa limpede din oase si rasol de vita"};
    string roSupaCiorbaVegetarian[7] = {"Supa de linte", "Supa crema de legume", "Supa cu galuste", "Supa cu taitei", "Ciorba cu taitei", "Supa crema de ardei copt", "Supa de fasole"};
    string roSupaCiorbaFlexitarian[6] = {"Ciorba de peste cu somn", "Ciorba de peste cu macrou", "Ciorba de peste cu somon", "Ciorba de peste cu crap", "Bors de peste moldovenesc", "Ciorba de peste"};

    string roFelPrincipalOmnivor[6] = {"Piept de rata in sos de rodii", "Tocanita de vita cu ciuperci", "Sandwich cu chiftele in stil american", "Chiftele keto", "Tochitura de porc", "Pomana porcului"};
    string roFelPrincipalVegetarian[7] = {"Pancakes cu spanac", "Kimchi – varza murata picanta", "Sarmale cu orez", "Falafel", "Seitan - carne vegetariana", "Paste suedeze", "Vinete umplute cu ciuperci"};
    string roFelPrincipalFlexitarian[7] = {"Calcan cu legume si lamaie", "Macrou la cuptor", "Peste la gratar cu mirodenii", "Peste cu legume", "Peste cu orez","Peste cu migdale", "Peste cu parmezan, lamaie si plante aromatice"};

    string roDesertOmnivor[12] = {"Clatite", "Gris cu lapte", "Cozonac", "Tiramisu", "Papanasi", "Gogosi", "Amadina", "Coltunasi", "Lapte de pasare", "Inghetata", "Strudel", "Orez cu lapte"};
    string roDesertVegetarian[7] = {"Galeta vegana cu capsuni", "Prajitura cu mere si gris, fara aluat", "Turta cu mac", "Galeta cu piersici", "Briosa cu morcov", "Salata cu ananas si casatravete", "Porridge cu mar si cocos"};
    string roDesertFlexitarian[7] = {"Galeta vegana cu capsuni", "Prajitura cu mere si gris, fara aluat", "Turta cu mac", "Galeta cu piersici", "Briosa cu morcov", "Salata cu ananas si casatravete", "Porridge cu mar si cocos"};

    f1<<"Meniu"<<","<<"Apta sa manance orice"<<","<<"Vegetarian"<<","<<"Flexitarian"<<"\n";
    f1<<"Supa/Ciorba"<<","<<roSupaCiorbaOmnivor[rand() % 11]<<","<<roSupaCiorbaVegetarian[rand() % 7]<<","<<roSupaCiorbaFlexitarian[rand() % 6]<<"\n";
    f1<<"Fel principal"<<","<<roFelPrincipalOmnivor[rand() % 6]<<","<<roFelPrincipalVegetarian[rand() % 7]<<","<<roFelPrincipalFlexitarian[rand() %7]<<"\n";
    f1<<"Desert"<<","<<roDesertOmnivor[rand() % 12]<<","<<roDesertVegetarian[rand() % 7]<<","<<roDesertFlexitarian[rand() % 7];

    string enSupaCiorbaOmnivor[11] = {"Chicken soup with noodles and dumplings", "Chicken soup with noodles", "Perisoare soup", "Belly soup", "Radauteana soup", "Beef soup", "Bean soup with smoked fennel", "Greek chicken soup", "Bone and pork borscht", "Transylvanian smoked potato soup", "Clear bone soup and beef gravy"};
    string enSupaCiorbaVegetarian[7] = {"Lentil soup", "Vegetable cream soup", "Doughnut soup", "Noodle soup", "Noodle soup", "Cream of roasted peppers", "Bean soup"};
    string enSupaCiorbaFlexitarian[6] = {"Catfish soup", "Mackerel fish soup", "Salmon fish soup", "Carp fish soup", "Moldovan fish bream", "Fish soup"};

    string enFelPrincipalOmnivor[6] = {"Duck breast in pomegranate sauce", "Beef stew with mushrooms", "Sandwich with American-style meatballs", "Keto meatballs", "Pork stew", "Pig alms"};
    string enFelPrincipalVegetarian[7] = {"Spinach pancakes", "Kimchi - spicy sauerkraut", "Sarmale with rice", "Falafel", "Seitan - vegetarian meat", "Swedish pasta", "Eggplant stuffed with mushrooms"};
    string enFelPrincipalFlexitarian[7] = {"Telder with vegetables and lemon", "Baked mackerel", "Grilled fish with spices", "Fish with vegetables", "Fish with rice", "Fish with almonds", "Fish with parmesan, lemon and herbs "};

    string enDesertOmnivor[12] = {"Pancakes", "Gris with milk", "Cozonac", "Tiramisu", "Papanasi", "Gogosi", "Amadina", "Coltunasi", "Bird's milk", "Ice cream", "Strudel", " Milk with rice"};
    string enDesertVegetarian[7] = {"Vegan strawberry pie", "Apple and semolina cake, without dough", "Poppy cake", "Peach pie", "Carrot muffin", "Pineapple and castor bean salad", "Porridge with apple and cock"};
    string enDesertFlexitarian[7] = {"Vegan strawberry pie", "Apple and semolina cake, without dough", "Poppy cake", "Peach pie", "Carrot muffin", "Pineapple and castor bean salad", "Porridge with apple and cock"};

    f2<<"Menu"<<","<<"Can eat anything"<<","<<"Vegetarian"<<","<<"Flexitarian"<<"\n";
    f2<<"Soup"<<","<<enSupaCiorbaOmnivor[rand() % 11]<<","<<enSupaCiorbaVegetarian[rand() % 7]<<","<<enSupaCiorbaFlexitarian[rand() % 6]<<"\n";
    f2<<"Main dish"<<","<<enFelPrincipalOmnivor[rand() % 6]<<","<<enFelPrincipalVegetarian[rand() % 7]<<","<<enFelPrincipalFlexitarian[rand() %7]<<"\n";
    f2<<"Desert"<<","<<enDesertOmnivor[rand() % 12]<<","<<enDesertVegetarian[rand() % 7]<<","<<enDesertFlexitarian[rand() % 7];

    f1.close();
    f2.close();
}

int main()
{
    //Functia de creeare a fisierului cu figuranti
    figuranti();

    //Functie de creeare a fisierului cu intreg castul
    fullCast();

    //Functie de creeare a meniului
    Meniu();

    Cast cast;
    cast.NrCostume();
    cast.NrTipMancare();
    cast.NrCamere();
    cast.LitriiBautura();
    cast.NrAutocare();

    Cost costul(5680);
    costul.setPretOmnivor(40);
    costul.setPretVegetarian(33);
    costul.setPretFlexitarian(46);
    costul.setPretApa(6);
    costul.setPretCafea(30);
    costul.setPretSuc(8);
    costul.SumaMancareBautura();
    costul.Suma(230,555,345,157,55);
    costul.Suma(350,420);
    costul.DocumentCost();

    return 0;
}
