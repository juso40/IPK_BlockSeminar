//Justin Sostmann


// wir k�nnen �berall annehmen, dass std:: bekannt ist und alle includes korrekt ausgef�hrt wurden.

//Abschnitt 1
{
    //a wurde keinen wert zugeschrieben, hätte Anfangs definiert werden müssen.
    int a;
    for (int i=0; i<10; i++) {
        a += i;
    }
}

//Abschnitt 2
{
    //In der for schleife wird bis zum [4] eintrag im array durchgelaufen, der existiert jedoch nicht!
    //Arrays fangen bei null an, deswegen hat dieser als höchsten index die 3 und nihct 4

    int sum = 0;
    int numbers[4] = {1, 7, 2, 8};
    for (int i=0; i <= 4; i++ ) {
        sum += numbers[i];
    }
    cout << sum << endl;
}

//Abschnitt 3
{
    //c pointed auf die Referenz von a und nicht auf a, bzw. b
    int a=0;
    int &b=a;
    int *c=&b;
    c = 7;
}

//Abschnitt 4
{
    //Es hätte delete i; sein müssen, da wir das objekt auf das der pointer zeigt löschen wollen
    int *i = new int(5);
    *i = 10;
    delete *i;
}

//Abschnitt 5
{
    //pos ist ein pointer auf den array
    //der array hat als höchsten index die 3, in der schleife wird jedoch auf 7 hochgezählt
    double  array[4] = {3.3, 7.5, 1.9, 9.1};
    double sum = 0;
    for (double *pos=array; pos<array+4; pos++) {
        sum += pos;
    }
}

//Abschnitt 6
{
    //in der ersten if abfrage steht nur ein einfaches "="
    //das schreibt dem c den wert '3' zu, returnt so zu sagen ein true und cout dann "drei"
    char c = '0';
    if (c = '3') {
        cout << "drei" << endl;
    }
    else if (c == '7') {
        cout << "sieben" << endl;
    }
}

//Abschnitt 7
{
    //b sollte in * anstelle des & haben und dann muss c ein pointer pointer sein, spich 2* anstelle eines *
    int a = 10;
    int &b = a;
    int *c = *b;
}

//Abschnitt 8
{
    //nach den einzelnen cases ist es in diesem fall sehr sinnvoll ein break zu setzen
    //ansonsten wird sobald ein case zutrifft die anderen auch ausgegeben
    int a = 1;
    switch(a)
    {
    case 1:
        cout << "a ist eins." << endl;
    case 2:
        cout << "a ist zwei." << endl;
    default:
        cout << "a ist weder eins noch zwei." << endl;
    }
}

//Abschnitt 9
{
    //vor zahl fehlt der Datentyp, bsp "int"

    // gib A aus wenn die Zahl durch 3 teilbar ist
    // gib zus�tzlich B aus wenn die Zahl durch 4 teilbar ist
    zahl = 12;
    if(zahl % 3 == 0)
        cout << "A";
    else if(zahl % 4 == 0)
        cout << "B";
}

//Abschnitt 10
{
    //der Vector wird auf 10 resized, sprich höchster index = 9
    //mit v[v.size()]  wird jedoch auf den 10 index zugegriffen!
    vector<int> v;
    v.resize(10);
    v[v.size()] = 3;
}