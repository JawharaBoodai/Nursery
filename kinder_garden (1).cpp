#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
#define SIZE 100
#define SIZE2 20

struct child
{
 string name[SIZE];
 string ID[SIZE];
 string parentphnum[SIZE];
 string gender [SIZE]; 
 int BabySitter_Index [SIZE];
}ch;

struct BabySitter
{
 string name[SIZE2];
 string ID[SIZE2];
 string phnum[SIZE2];
 string Experience[SIZE2];
 string gender [SIZE2]; 
}Bs;

void getChild(int&);
void getBabysitter(int&);
void assign(int, int);
void removeSitter(int, int);
void removeChild(int);
void deleteSitter(int, int&);
void deleteChild(int&);
void updateSitter(int);
void updateChild(int);
void searchSitter(int);
void searchChild(int);
void showSitter(int);
void showChild(int);
void save(int, int);
void Initialize(int&, int&);
int main ()
{
 int input, bage, bnumber, bID, input2, kID, kage, knumber, choice, input3, input4;
 string name,Experience, gender,ID,parentphnum,phnum;
 int BsCounter =0;
 int childCounter =0;
 
 Initialize(childCounter, BsCounter);

 cout<<"\t\t////////////////////////////////////////////////////////////////\n";
 cout<<"\t\t\t\t..:Welcome to Happy Kid Nursery:..\n";
 cout<<"\t\t////////////////////////////////////////////////////////////////\n";
 cout<<"\n";
 cout<<"\n";
 
 while(input!=10){
 
 cout<<"\n\nWhat do you want to do?\n";
 cout<<"[1]Add new child/babysitter\n";
 cout<<"[2]Assign babysitter to child\n";
 cout<<"[3]Remove babysitter from child\n";
 cout<<"[4]Remove child from babysitter\n";
 cout<<"[5]Update child/babysitter details\n";
 cout<<"[6]Delete child/babysitter records\n";
 cout<<"[7]Show child/babysitter lists\n";
 cout<<"[8]Search child/babysitter details\n";
 cout<<"[9]Save\n";
 cout<<"[10]Exit\n";
 
 cin>>input;
 
 switch(input){
         
  case 1:
   cout<<"Who do you want add? [1] Child [2] Babysitter\n";
   cin>>input2;
   if (input2==1)
   {
    getChild(childCounter);   
   }
   else if (input2==2)
   {
    getBabysitter(BsCounter);
   }
   else cout<<"Invalid Value";
   break;
   
   
   
   case 2:
         assign(childCounter, BsCounter);
         break;
   
     
   
   case 3:
         removeSitter(childCounter, BsCounter);
    break;
   
   case 4:
         removeChild(childCounter);
    break;
   
    case 5:
         cout<<"Who do you want update? [1] Child [2] Babysitter\n";
   cin>>input2;
   if (input2==1)
   {
    updateChild(childCounter);
   }
   else if (input2==2)
   {
    updateSitter(BsCounter);
   }
   else cout<<"Invalid Value";
    break;
   
   
   
    case 6:
                 cout<<"Who do you want delete? [1] Child [2] Babysitter\n";
   cin>>input2;
   if (input2==1)
   {
    deleteChild(childCounter);
   }
   else if (input2==2)
   {
    deleteSitter(childCounter, BsCounter);
   }
   else cout<<"Invalid Value";
    break;
 
   
   
    case 7:
    cout<<"Do you want to show a list of [1] Children [2] Babysitters\n";
    cin>>input4;
    if (input4==1)
   {
        showChild(childCounter);
   }
   else if (input4 ==2)
   {
		showSitter(BsCounter);
   }
   else cout<<"Invalid Value";
    break;
   
   
   
    case 8:
         cout<<"Who do you want search? [1] Child [2] Babysitter\n";
   cin>>input2;
   if (input2==1)
   {
    searchChild(childCounter);
   }
   else if (input2==2)
   {
    searchSitter(BsCounter);
   }
   else cout<<"Invalid Value";
    break;
         break;
   
   case 9:
         save(childCounter, BsCounter);
    break;
   
}//end switch
}//end while loop
save(childCounter, BsCounter);
}// end main
void getChild(int &childCounter)
{
 cout<<"Please enter name of child: ";
 cin>>ch.name[childCounter];
//getline(cin, >ch.name[childCounter]);
 cout<<"Please enter ID of child: ";
 cin>>ch.ID[childCounter];
 
 cout<<"Please enter gender of child: ";
 cin>>ch.gender[childCounter];
 
 cout<<"Please enter phone number of child parent: ";
 cin>>ch.parentphnum[childCounter];   
 ch.BabySitter_Index[childCounter]=-1;
    childCounter++;
}
void getBabysitter(int &BsCounter)
{
 cout<<"Please enter name of Babysitter:" ;
 cin>>Bs.name[BsCounter];
 
 cout<<"Please enter ID of Babysitter: ";
 cin>>Bs.ID[BsCounter];
 
 cout<<"Please enter gender of Babysitter: ";
 cin>>Bs.gender[BsCounter];
 
 cout<<"Please enter phone number of Babysitter: ";
 cin>>Bs.phnum[BsCounter];
 
 cout<<"Please enter years of experience of the Babysitter: ";
 cin>>Bs.Experience[BsCounter];
 BsCounter++;
}
void assign(int childCounter, int BsCounter){
	int ChildIndex;
	ChildIndex = -1;
	searchChild(childCounter);
	cout<<"\nEnter its index:\n";
	cin>>ChildIndex;
	cout<<"\nAsign to a Babysitter:\n";
	searchSitter(BsCounter);
	cout<<"\nEnter Babysitter index:\n";
	cin>>ch.BabySitter_Index[ChildIndex];
}
void removeSitter(int childCounter, int BsCounter){
	int i,j;
	searchSitter(BsCounter);
	cout<<"\nEnter Baby Sitter index to Unassign:\n";
	cin>>i;

	cout<<"Index"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Phone#"<<"     "<<"Experience"<<"     "<<"gender"<<endl;
	cout<<"======================================================================="<<endl;
	cout<<i<<"     "<<Bs.name[i]<<"     "<<Bs.ID[i]<<"     "<<Bs.phnum[i]<<"     "<<Bs.Experience[i]<<"     "<<Bs.gender[i]<<endl;

		cout<<"\nChildren assigned to this Baby Sitter index are:\n";
	cout<<"\nIndex"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Gender"<<"     "<<"Parent Phone#"<<endl;
	cout<<"======================================================================="<<endl;

        j=0;
        while (j<childCounter){
                if(ch.BabySitter_Index[j]==i){
					cout<<j<<"     "<<ch.name[j]<<"     "<<ch.ID[j]<<"     "<<ch.gender[j]<<"     "<<ch.parentphnum[j]<<endl;
				}
                j++;
        }
	cout<<"\nDo you want to UNASSING these children [1]Yes\n";
	cin>>j;
		if (j==1){
			j=0;
			while (j<childCounter){
                if(ch.BabySitter_Index[j]==i){
					ch.BabySitter_Index[j] = -1;
				}
                j++;
			}
		}
}
void removeChild(int childCounter){	
	int i, j;
	searchChild(childCounter);
	cout<<"\nEnter Child index to Unassign:\n";
	cin>>i;

	cout<<"\nIndex"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Gender"<<"     "<<"Parent Phone#"<<endl;
	cout<<"======================================================================="<<endl;
	cout<<i<<"     "<<ch.name[i]<<"     "<<ch.ID[i]<<"     "<<ch.gender[i]<<"     "<<ch.parentphnum[i]<<endl;

	j=ch.BabySitter_Index[i];
	cout<<"\nBaby Sitter Info:\n";
	cout<<"Index"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Phone#"<<"     "<<"Experience"<<"     "<<"gender"<<endl;
	cout<<"======================================================================="<<endl;
	cout<<j<<"     "<<Bs.name[j]<<"     "<<Bs.ID[j]<<"     "<<Bs.phnum[j]<<"     "<<Bs.Experience[j]<<"     "<<Bs.gender[j]<<endl;

	cout<<"\nDo you want to UNASSING this Baby Sitter [1]Yes\n";
	cin>>j;
		if (j==1){
			ch.BabySitter_Index[i] = -1;
		}
}
void deleteSitter(int childCounter, int &BsCounter){	
	int i,j;
	bool Delete;
	Delete = true;

	searchSitter(BsCounter);
	cout<<"\nEnter Baby Sitter index to Delete:\n";
	cin>>i;

	cout<<"Index"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Phone#"<<"     "<<"Experience"<<"     "<<"gender"<<endl;
	cout<<"======================================================================="<<endl;
	cout<<i<<"     "<<Bs.name[i]<<"     "<<Bs.ID[i]<<"     "<<Bs.phnum[i]<<"     "<<Bs.Experience[i]<<"     "<<Bs.gender[i]<<endl;

		cout<<"\nChildren assigned to this Baby Sitter index are:\n";
	cout<<"\nIndex"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Gender"<<"     "<<"Parent Phone#"<<endl;
	cout<<"======================================================================="<<endl;
		j=0;
        while (j<childCounter){
                if(ch.BabySitter_Index[j]==i){
					cout<<j<<"     "<<ch.name[j]<<"     "<<ch.ID[j]<<"     "<<ch.gender[j]<<"     "<<ch.parentphnum[j]<<endl;
					Delete=false;
				}
                j++;
        }
		if (Delete)
		{
			cout<<"\nAre you sure you want to DELETE this baby sitter: [1]Yes\n";
			cin>>j;
				if (j==1)
				{
					BsCounter--;
					for (j=i; j<BsCounter; ++j)
					{
						Bs.name[j] = Bs.name[j+1];
						Bs.ID[j] = Bs.ID[j+1];
						Bs.phnum[j] = Bs.phnum[j+1];
						Bs.Experience[j] = Bs.Experience[j+1];
						Bs.gender[j] = Bs.gender[j+1];
					}
				}
		}
		else
		{
			cout<<"\nYou cant delete this Baby sitter because there is Children ASSIGNED to her/his\n Please UNASSIGN all the children first by choosing 3\n";
		}
}
void deleteChild(int &childCounter){	
	int i,j;
	bool Delete;
	Delete = false;
	
	searchChild(childCounter);
	cout<<"\nEnter Child index to Delete:\n";
	cin>>i;

	cout<<"\nIndex"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Gender"<<"     "<<"Parent Phone#"<<endl;
	cout<<"======================================================================="<<endl;
	cout<<i<<"     "<<ch.name[i]<<"     "<<ch.ID[i]<<"     "<<ch.gender[i]<<"     "<<ch.parentphnum[i]<<endl;

	cout<<"\nAre you sure you want to DELETE this Child: [1]Yes\n";
			cin>>j;
				if (j==1)
				{
					childCounter--;
					for (j=i; j<childCounter; ++j)
					{
						ch.name[j] = ch.name[j+1];
						ch.ID[j] = ch.ID[j+1];
						ch.gender[j] = ch.gender[j+1];
						ch.parentphnum[j] = ch.parentphnum[j+1];
					}
				}

}
void updateSitter(int BsCounter){
	int i;
	searchSitter(BsCounter);
	cout<<"\nEnter Baby Sitter index to Update:\n";
	cin>>i;

	cout<<"Index"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Phone#"<<"     "<<"Experience"<<"     "<<"gender"<<endl;
	cout<<"======================================================================="<<endl;
	cout<<i<<"     "<<Bs.name[i]<<"     "<<Bs.ID[i]<<"     "<<Bs.phnum[i]<<"     "<<Bs.Experience[i]<<"     "<<Bs.gender[i]<<endl;

cout<<"Please enter NEW name of Babysitter:" ;
 cin>>Bs.name[i];
 
 cout<<"Please enter NEW ID of Babysitter: ";
 cin>>Bs.ID[i];
 
 cout<<"Please enter NEW gender of Babysitter: ";
 cin>>Bs.gender[i];
 
 cout<<"Please enter NEW phone number of Babysitter: ";
 cin>>Bs.phnum[i];
 
 cout<<"Please enter NEW years of experience of the Babysitter: ";
 cin>>Bs.Experience[i];
}
void updateChild(int childCounter){
	int i;
	searchChild(childCounter);
	cout<<"\nEnter Child index to Update:\n";
	cin>>i;

	cout<<"\nIndex"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Gender"<<"     "<<"Parent Phone#"<<endl;
	cout<<"======================================================================="<<endl;
	cout<<i<<"     "<<ch.name[i]<<"     "<<ch.ID[i]<<"     "<<ch.gender[i]<<"     "<<ch.parentphnum[i]<<endl;

cout<<"Please enter NEW name of child: ";
 cin>>ch.name[i];

 cout<<"Please enter NEW ID of child: ";
 cin>>ch.ID[i];
 
 cout<<"Please enter NEW gender of child: ";
 cin>>ch.gender[i];
 
 cout<<"Please enter NEW phone number of child parent: ";
 cin>>ch.parentphnum[i];
}
void searchSitter(int BsCounter){
        string name;
		cout<<"Enter the name of the babysitter you want to search\nBabysitter's Name: ";
        cin>>name;
		
	cout<<"Index"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Phone#"<<"     "<<"Experience"<<"     "<<"gender"<<endl;
	cout<<"======================================================================="<<endl;

        int i=0;
        while (i<BsCounter){
                if(Bs.name[i]==name){
                  cout<<i<<"     "<<Bs.name[i]<<"     "<<Bs.ID[i]<<"     "<<Bs.phnum[i]<<"     "<<Bs.Experience[i]<<"     "<<Bs.gender[i]<<endl;
				  i=BsCounter;
				}
                i++;
                       
		}
}
void searchChild(int childCounter){
        string name;
		cout<<"Enter the name of the child you want to search\nChild Name: ";
        cin>>name;

		
	cout<<"\nIndex"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Gender"<<"     "<<"Parent Phone#"<<endl;
	cout<<"======================================================================="<<endl;

        int i=0;
        while (i<childCounter){
                if(ch.name[i]==name){
					cout<<i<<"     "<<ch.name[i]<<"     "<<ch.ID[i]<<"     "<<ch.gender[i]<<"     "<<ch.parentphnum[i]<<endl;
					i=childCounter;
				}
                i++;
        }
}
void showChild(int childCounter){

	cout<<"We Have "<<childCounter<<" child"<<endl;
	cout<<"Index"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Gender"<<"     "<<"Parent Phone#"<<endl;
	cout<<"======================================================================="<<endl;
	
	for(int i=0 ; i<childCounter; ++i)
	{
		cout<<i<<"     "<<ch.name[i]<<"     "<<ch.ID[i]<<"     "<<ch.gender[i]<<"     "<<ch.parentphnum[i]<<endl;
	}

	cout<<endl;
cout<<endl;
cout<<endl;
}
void showSitter(int BsCounter){

	cout<<"We Have "<<BsCounter<<" Baby Sitter"<<endl;
	cout<<"Index"<<"     "<<"Name"<<"     "<<"ID"<<"     "<<"Phone#"<<"     "<<"Experience"<<"     "<<"gender"<<endl;
	cout<<"======================================================================="<<endl;
	
	for(int i=0 ; i<BsCounter; ++i)
	{
		cout<<i<<"     "<<Bs.name[i]<<"     "<<Bs.ID[i]<<"     "<<Bs.phnum[i]<<"     "<<Bs.Experience[i]<<"     "<<Bs.gender[i]<<endl;
	}

	cout<<endl;
cout<<endl;
cout<<endl;
}

void save(int childCounter, int BsCounter){
	ofstream file;
	int i;

	file.open("Children.txt",ios::out);
	for (i=0; i<childCounter; ++i)
	{
		file<<ch.name[i]<<","<<ch.ID[i]<<","<<ch.gender[i]<<","<<ch.parentphnum[i]<<","<<ch.BabySitter_Index[i]<<endl;
	}
  file.close();

	file.open("Baby Sitters.txt",ios::out);
	for (i=0; i<BsCounter; ++i)
	{
		file<<Bs.name[i]<<","<<Bs.ID[i]<<","<<Bs.phnum[i]<<","<<Bs.Experience[i]<<","<<Bs.gender[i]<<endl;
	}
  file.close();

}

void Initialize(int &childCounter, int &BsCounter){	
	ifstream file;
	string tempString="";

 file.open("Children.txt",ios::in);	
--childCounter;
    while(file.good()) // To get you all the lines.
    {        
		childCounter++;
		getline(file, ch.name[childCounter], ',');
		getline(file, ch.ID[childCounter], ',');
		getline(file, ch.gender[childCounter], ',');
		getline(file, ch.parentphnum[childCounter], ',');
		getline(file, tempString, '\n');
		std::istringstream convert(tempString);
		convert>>ch.BabySitter_Index[childCounter];
    }
file.close();  
file.clear();

 file.open("Baby Sitters.txt",ios::in);
--BsCounter;
    while(file.good()) // To get you all the lines.
    {
		BsCounter++;
		getline(file, Bs.name[BsCounter], ',');
		getline(file, Bs.ID[BsCounter], ',');
		getline(file, Bs.phnum[BsCounter], ',');
		getline(file, Bs.Experience[BsCounter], ',');
		getline(file, Bs.gender[BsCounter]);
    }
	file.close();
file.clear();
 }
