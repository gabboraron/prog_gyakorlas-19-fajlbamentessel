#include "enor.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>

using namespace std;

enor::enor(string& fname)
{
    x.open(fname.c_str());
    if(x.fail()) throw OpenError;
    cout<<fname<<" file feldolgozasa megkezdodott.\n";

    /* kimenet keszitese */
    //fname = fname + "_OUT";
    //if ( fname.size()<1 ) {
        cout << "Add meg a kimenet fajl nevet:" ;
        cin >> fname;
    //}
    f.open(fname.c_str());
    if ( f.fail() ){
        cerr << "Nem jott letre a fajl!" <<endl;
        char ch; cin>>ch;
        exit(2);
    }
}

void enor::first()
{
    cout<<endl<<"Az alabbiak nem vettek 'arukod22'-t: "<<endl;
    f<<endl<<"Az alabbiak nem vettek 'arukod22'-t: "<<endl;
    next();
}

void enor::next()
{
    read();
//    osszegez();
}


void enor::read()
{
    vasarlo vasarlas;
    string tmp2;
    voltarukod22 = false;
    int c = 0;

    string tmp;
    getline(x,tmp);
    istringstream ss(tmp);
    sx = x.fail()? abnorm : norm;

    /* linker valtozok */
    bool voltMar;
    int j;
    /* *** */

    if(sx==norm){
        ss>>vasarlas.time;
        ss>>vasarlas.id;
        while(ss>>tmp2)
        {
            vasarlas.items.push_back(tmp2);
            if(tmp2 == "arukod22")
                voltarukod22 = true;
        }

            /* linker, hogy volt-e mar ilyen elem */
           voltMar = false;
           for(int i=1;i<vasarlas.items.size(); ++i)
           {

                j = 0;

                while((voltMar == false) && (j<i))
                {
                    if(vasarlas.items[i] == vasarlas.items[j])
                        voltMar = true;
                    j = j+1;
                }

                if(voltMar == false)
                {
                    c = c + 1;
                }
           }
            /* *** */
            //c=c+1;

        if(voltarukod22 == false)
        {
            cout<<endl<<vasarlas.time<<"    "<<vasarlas.id;
            f<<endl<<vasarlas.time<<"    "<<vasarlas.id;
        }
        if(elsovasarlo)
        {
            elsovasarlo = false;
            minOfItems = c;

            minvasarlo.id = vasarlas.id;
            minvasarlo.items = vasarlas.items;
            minvasarlo.time = vasarlas. time;
        } else if(minOfItems>c){
            minOfItems = c;

            minvasarlo.id = vasarlas.id;
            minvasarlo.items = vasarlas.items;
            minvasarlo.time = vasarlas. time;
        }
    }
}

bool enor::end()
{
    if(sx==abnorm)
    {
        cout<<endl<<endl<<"A legkevesebbet ("<<minOfItems<<" darabot) "<<minvasarlo.id<<" vasarolta "<< minvasarlo.time<<"-kor";
        f << endl << "A legkevesebbet (" << minOfItems << " darabot) "<<minvasarlo.id<<" vasarolta "<< minvasarlo.time<<"-kor";
    }
    return sx==abnorm;
}
