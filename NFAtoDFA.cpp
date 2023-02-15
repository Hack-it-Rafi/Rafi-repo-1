#include<bits/stdc++.h>
using namespace std;

int main()
{
    int NumberofStates, alphNumber;
    vector<char>alphabets;
    char state;
    char startState;
    int FinalStateNumber;
    map<int, bool>finalState;
    map<pair<char, char>, vector<char>> T_table;

    cout<<"--------NFA---------"<<endl;

    cout<<"Enter number of states: ";
    cin>>NumberofStates;
    cout<<"Enter number of alphabets: ";
    cin>>alphNumber;
    cout<<"Enter alphabets: ";
    for(int i=0; i<alphNumber; i++)
    {
        char alph;
        cin>>alph;
        alphabets.push_back(alph);
    }
    cout<<"Enter start state: ";
    cin>> startState;
    cout<<"Enter number of final states: ";
    cin>> FinalStateNumber;
    cout<<"Enter the final states: ";
    for(int i =0; i<FinalStateNumber; i++)
    {
        char f;
        cin>>f;
        finalState[f]=true;
    }

    for(int i=0; i<NumberofStates; i++)
    {
        cout<<"Enter transition for state "<< (char) ('a' + i) <<endl;
        for(auto itr: alphabets)
        {
            cout<<"For input "<<itr<<": (# for break)"<<endl;
            while(1)
            {
                cin>>state;
                if(state=='#')break;
                T_table[{(char) ('a' + i) , itr}].push_back(state);
            }
        }
    }


    cout<<endl<<"-----------DFA-----------"<<endl;

    set<char>current;
    queue<set<char>>q;
    map<set<char>,bool>check;
    current.insert(startState);
    q.push(current);
    check[current]=true;

    do{
        current=q.front();
        q.pop();
        for(auto itr1:alphabets)
        {
            set<char>Dfa_state;
            cout<<"(";
            for(auto itr2:current)
            {
                cout<<itr2<<",";
                for(auto itr3:T_table[{itr2,itr1}])
                    {
                        Dfa_state.insert(itr3);
                    }
            }
            if(Dfa_state.size()==0)
                Dfa_state.insert(NumberofStates+1);

            if(check[Dfa_state]==false)
            {
                q.push(Dfa_state);
                check[Dfa_state]=true;
            }
            cout<<") | "<<itr1<<" |-------------|(";
            for(auto itr:Dfa_state)
                cout<<itr<<",";
            cout<<")|"<<endl;
        }
    }while(!q.empty());

}
