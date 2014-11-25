#include <iostream>
using namespace std;
char oznaka2[50];
bool alocirano2=false;
bool pronadjen;
struct ele {
    char naziv[50];
    ele*lijevi,*desni;
    ele() {
        lijevi=NULL,desni=NULL;
    }
};
void init(char naziv[50],ele*stablo) {
    strcpy(stablo->naziv,naziv);
}
void root(ele*stablo) {
    strcpy(oznaka2,stablo->naziv);
}
bool lijevodijete(char naziv[50],ele*stablo) {
    ele*novi=new ele;
    novi=stablo;
    if(novi->lijevi) {
        if(!strcmp(naziv,novi->naziv)) {
            strcpy(oznaka2,novi->lijevi->naziv);
            cout<<"Pronadjeno je lijevo dijete\n";
            pronadjen=true;
            return 1;
        }
        lijevodijete(naziv,novi->lijevi);
    }
    if(novi->desni)
        lijevodijete(naziv,novi->desni);
    return 0;
}
bool desnodijete(char naziv[50],ele*stablo) {
    ele*novi=new ele;
    novi=stablo;
    if(novi->lijevi)
        lijevodijete(naziv,novi->lijevi);
    if(novi->desni) {
        if(!strcmp(naziv,novi->naziv)) {
            strcpy(oznaka2,novi->desni->naziv);
            cout<<"Pronadjeno je desno dijete\n";
            pronadjen=true;
            return 1;
        }
        lijevodijete(naziv,novi->desni);
    }
    return 0;
}
bool novolijevo(char naziv2[50],char naziv[50],ele*stablo) {
    ele*novi=new ele;
    novi=stablo;
    if(!strcmp(naziv2,novi->naziv)) {
        if(novi->lijevi) {
            cout<<"POGRESKA\n";
            return 0;
        }
        ele*novi3=new ele;
        strcpy(novi3->naziv,naziv);
        novi->lijevi=novi3;
        pronadjen=true;
        cout<<"Uspjesno je kreirano novo dijete\n";
        return 1;
    }

    if(novi->lijevi) {
        if(!strcmp(naziv2,novi->naziv)) {
            if(novi->lijevi) {
                cout<<"POGRESKA\n";
                return 0;
            }
            ele*novi3=new ele;
            strcpy(novi3->naziv,naziv);
            novi->lijevi=novi3;
            pronadjen=true;
            cout<<"Uspjesno je kreirano novo dijete\n";
            return 1;
        }
        novolijevo(naziv2,naziv,novi->lijevi);
    }
    if(novi->desni) {
        if(!strcmp(naziv2,novi->naziv)) {
            if(novi->lijevi) {
                cout<<"POGRESKA\n";
                return 0;
            }
            ele*novi2=new ele;
            strcpy(novi2->naziv,naziv);
            novi->lijevi=novi2;
            pronadjen=true;
            cout<<"Uspjesno je kreirano novo dijete\n";
            return 1;
        }
        novolijevo(naziv2,naziv,novi->desni);
    }
    return 0;
}
bool novodesno(char naziv2[50],char naziv[50],ele*stablo) {
    ele*novi=new ele;
    novi=stablo;
    if(!strcmp(naziv2,novi->naziv)) {
        if(novi->desni) {
            cout<<"Error\n";
            return 0;
        }
        ele*novi3=new ele;
        strcpy(novi3->naziv,naziv);
        novi->desni=novi3;
        pronadjen=true;
        cout<<"Uspjesno je kreirano novo dijete\n";
        return 1;
    }

    if(novi->desni) {
        if(!strcmp(naziv2,novi->naziv)) {
            if(novi->desni) {
                cout<<"Error\n";
                return 0;
            }
            ele*novi3=new ele;
            strcpy(novi3->naziv,naziv);
            novi->desni=novi3;
            pronadjen=true;
            cout<<"Uspjesno je kreirano novo dijete\n";
            return 1;
        }
        novolijevo(naziv2,naziv,novi->desni);
    }
    if(novi->lijevi) {
        if(!strcmp(naziv2,novi->naziv)) {
            if(novi->desni) {
                cout<<"Error\n";
                return 0;
            }
            ele*novi2=new ele;
            strcpy(novi2->naziv,naziv);
            novi->desni=novi2;
            pronadjen=true;
            cout<<"Uspjesno je kreirano novo dijete\n";
            return 1;
        }
        novolijevo(naziv2,naziv,novi->lijevi);
    }
    return 0;
}
bool roditelj(char naziv[50],ele*stablo) {
    ele*novi=new ele;
    novi=stablo;
    if(novi->lijevi) {
        if(!strcmp(novi->lijevi->naziv,naziv)) {
            cout<<"Uspjesno pronaden roditelj: "<<novi->naziv<<endl;
            pronadjen=true;
            return 1;
        }
        roditelj(naziv,novi->lijevi);
    }
    if(novi->desni) {
        if(!strcmp(novi->desni->naziv,naziv)) {
            cout<<"Uspjesno pronaden roditelj: "<<novi->naziv<<endl;
            pronadjen=true;
            return 1;
        }
        roditelj(naziv,novi->desni);
    }
    return 0;
}
bool brisanje(char naziv[50],ele*stablo) {
    ele*novi=new ele;
    novi=stablo;
    if(!strcmp(novi->naziv,naziv)) {
        cout<<"Uspjesno prisanje potomaka!\n";
        novi->lijevi=NULL;
        novi->desni=NULL;
        pronadjen=true;
        return 1;
    }
    if(novi->lijevi) {
        if(!strcmp(novi->lijevi->naziv,naziv)) {
            cout<<"Uspjesno prisanje potomaka!"<<endl;
            novi->lijevi=NULL;
            novi->desni=NULL;
            pronadjen=true;
            return 1;
        }
        brisanje(naziv,novi->lijevi);
    }
    if(novi->desni) {
        if(!strcmp(novi->desni->naziv,naziv)) {
            cout<<"Uspjesno brisanje potomaka!"<<endl;
            novi->lijevi=NULL;
            novi->desni=NULL;
            pronadjen=true;
            return 1;
        }
        brisanje(naziv,novi->desni);
    }
    return 0;
}
bool mijenjanje(char naziv[50],char naziv2[50],ele*stablo) {
    ele*novi=new ele;
    novi=stablo;
    if(!strcmp(novi->naziv,naziv)) {
        cout<<"Cvor je pronaden | uspjesno mu je dodjenjen novi naziv: "<<naziv2<<endl;
        strcpy(novi->naziv,naziv2);
        pronadjen=true;
        return 1;
    }
    if(novi->lijevi) {
        if(!strcmp(novi->lijevi->naziv,naziv)) {
            cout<<"Cvor je pronaden | uspjesno mu je dodjenjen novi naziv: "<<naziv2<<endl;
            strcpy(novi->naziv,naziv2);
            pronadjen=true;
            return 1;
        }
        mijenjanje(naziv,naziv2,novi->lijevi);
    }
    if(novi->desni) {
        if(!strcmp(novi->desni->naziv,naziv)) {
            cout<<"Cvor je pronaden | uspjesno mu je dodjenjen novi naziv: "<<naziv2<<endl;
            strcpy(novi->naziv,naziv2);
            pronadjen=true;
            return 1;
        }
        mijenjanje(naziv,naziv2,novi->desni);
    }
    return 0;
}
