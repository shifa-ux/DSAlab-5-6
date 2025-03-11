#include<iostream>
#include<string>
using namespace std;
struct Player
{
    string name;
    int score;
    Player* prev;
    Player* next;
};
class GolfTournament
{
private:
    Player* head;
    Player* tail;
public:
    GolfTournament()
	{
	head=nullptr;
	tail=nullptr;
	}
    void addPlayer(string name,int score)
	{
	    Player* newPlayer=new Player;
		newPlayer->name=name;
		newPlayer->score=score;
		newPlayer->prev=nullptr;
		newPlayer->next=nullptr;
        if(!head || score<head->score)
		{
            newPlayer->next=head;
            if(head)
			head->prev=newPlayer;
            head=newPlayer;
            if(!tail)
			tail=head;
            return;
        }
        Player* temp=head;
        while(temp->next && temp->next->score<=score) 
		temp=temp->next;
        newPlayer->next=temp->next;
        newPlayer->prev=temp;
        if(temp->next)
		temp->next->prev=newPlayer;
        temp->next=newPlayer;
        if(!newPlayer->next)
		tail=newPlayer;
    }
    void deletePlayer(string name)
	{
        Player* temp=head;
        while(temp && temp->name!=name)
		temp=temp->next;
        if(!temp)
		{
            cout<<"Player not found!"<<endl;
            return;
        }
        if(temp->prev)
		temp->prev->next=temp->next;
        else
		head=temp->next;
        if(temp->next)
		temp->next->prev=temp->prev;
        else
		tail=temp->prev;
        delete temp;
        cout<<"Player deleted."<<endl;
    }
    void displayAll()
	{
        Player* temp=head;
        while(temp)
		{
            cout<<temp->name<<" - "<<temp->score<<endl;
            temp=temp->next;
        }
    }
    void displayLowestScore()
	{
        if(!head)
		cout<<"No players available."<<endl;
        else
		cout<<"Lowest Score: "<<head->name<<" - "<<head->score<<endl;
    }
    void displayByScore(int score)
	{
        Player* temp=head;
        bool found=false;
        while(temp)
		{
            if(temp->score==score)
			{
                cout<<temp->name<<" - "<<temp->score<<endl;
                found=true;
            }
            temp=temp->next;
        }
        if(!found)
		cout<<"No player found with score "<<score<<"."<<endl;
    }
    void displayBackward(string name)
	{
        Player* temp=tail;
        while(temp && temp->name!=name)
		temp=temp->prev;
        if(!temp)
		{
            cout<<"Player not found!"<<endl;
            return;
        }
        cout<<"Players before "<<name<<":"<<endl;
        temp=temp->prev;
        while(temp)
		{
            cout<<temp->name<<" - "<<temp->score<<endl;
            temp=temp->prev;
        }
    }
};
int main()
{
    GolfTournament tournament;
    int choice;
    string name;
    int score;
    do
	{
        cout<<"1. Add Player"<<endl;
		cout<<"2. Delete Player"<<endl;
		cout<<"3. Display All"<<endl;
		cout<<"4. Display Lowest Score"<<endl;
        cout<<"5. Display Players by Score"<<endl;
		cout<<"6. Display Backward from Player"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"Choose: ";
        cin>> choice;
        cin.ignore();
        switch(choice)
		{
            case 1:
                cout<<"Enter name: ";
                getline(cin,name);
                cout<<"Enter score: ";
                cin>>score;
                tournament.addPlayer(name,score);
                break;
            case 2:
                cout<<"Enter player name to delete: ";
                getline(cin,name);
                tournament.deletePlayer(name);
                break;
            case 3:
                cout<<"Player List:"<<endl;
                tournament.displayAll();
                break;
            case 4:
                tournament.displayLowestScore();
                break;
            case 5:
                cout<<"Enter score to find players: ";
                cin>>score;
                tournament.displayByScore(score);
                break;
            case 6:
                cout<<"Enter player name to start backward display: ";
                getline(cin,name);
                tournament.displayBackward(name);
                break;
        }
    } while (choice!=0);
return 0;
}
