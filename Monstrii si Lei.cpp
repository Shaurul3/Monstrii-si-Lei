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
    int nrVampiri = 0, nrVarcolaci = 0, nrSirene = 0, nrClarvazatori = 0, nrOameni = 0, nrOmnivori = 0, nrVegetarieni = 0, nrFlexitarieni = 0;

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

    string enSupaCiorbaOmnivor[11] = {"Chicken soup with noodles and dumplings", "Chicken soup with noodles", "Perisoare soup", "Belly soup", "Radauteana soup", "Beef soup", "Bean soup with smoked fennel" , "Greek chicken soup", "Bone and pork borscht", "Transylvanian smoked potato soup", "Clear bone soup and beef gravy"};
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

    Production Wednesday;
    Wednesday.setNrMachiaj(5);
    Wednesday.setNrTipMancare(3);
    Cast cast;
    cast.NrCostume();
    cast.NrTipMancare();
    return 0;
}
