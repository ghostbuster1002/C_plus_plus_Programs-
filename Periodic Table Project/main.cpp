#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

char name[20], symbol[20];
string atomicno;

void output()
{
    cout<<"\nAtomic number : "<<atomicno<<"\nSymbol : "<<symbol<<"\nName : "<<name<<"\n\n\n";
}

void atomic()
{
    int i=0;
    string a,t;
    cout<<"\nEnter the atomic number : ";
    cin>>a;
    ifstream fin("elements.txt");
    while(i==0)
    {
        fin.eof() ? i=2: i=0 ;
        fin>>t;
        if(a.compare(t)==0)
                i++;
    }
    if(i==1)
    {
        atomicno=a;
        fin>>symbol;
        fin>>name;
        output();
    }
    else
        cout<<"\nElement of this atomic number not found\n\n";
        fin.close();

}

void namechk()
{
     int j=0,pos;
     char s[20],r[20];
     cout<<"\n\nEnter the element's name : ";
     cin>>s;
     ifstream fin2 ("elements.txt");
     for(int k=0;j==0;k++)
     {
        if(k%3==0)
          pos = fin2.tellg();
        fin2.eof() ? j=2: j=0 ;
        fin2>>r;
        if(strcasecmp(s,r)==0)
                j=1;
     }
     if(j==1)
    {
       strcpy(name,r);
       fin2.seekg(pos,ios::beg);
       fin2>>atomicno;
       fin2>>symbol;
       output();
    }
    else
        cout<<"\nElement of this atomic number not found\n\n";
        fin2.close();
}


void symbolchk()
{
     int l=0,pos2;
     char u[20],v[20];
     cout<<"\n\nEnter the symbol : ";
     cin>>u;
     ifstream fin3 ("elements.txt");
     for(int p=0;l==0;p++)
     {
        if(p%3==0)
          pos2 = fin3.tellg();
        fin3.eof() ? l=2: l=0 ;
        fin3>>v;
        if(strcasecmp(u,v)==0)
                l=1;
     }
     if(l==1)
    {
       strcpy(symbol,v);
       fin3>>name;
       fin3.seekg(pos2,ios::beg);
       fin3>>atomicno;
       output();
    }
    else
        cout<<"\nElement of this atomic number not found\n\n";
        fin3.close();
}

int main(){

    cout<<"\t\t\t\tHello Friend!\n"<<endl;
    cout<<"\t\tThis program is a Periodic table catalogue\n\n"<<endl;
    int y=0;
    while (y!=4)
    {
        cout<<"Enter one of them to know more about the element : "<<endl<<endl;
        cout<<"1.Atomic Number \t 2.Name \t 3.Symbol\t4.Exit\n"<<endl;
        cin>>y;
        switch(y)
        {
            case 1 : atomic();
            break;
            case 2 : namechk();
            break;
            case 3 : symbolchk();
            break;
        }
    }

    cout<<"\n\n";
    return 0;

}

