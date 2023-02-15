#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numStates, alphNum, finalStateNum;
    char startState, epsilon = 'e';
    vector <char> alphabets;
    map<int, bool>finalState;

    cout<<"------e-NFA-----"<<endl<<endl;

    cout<<"Enter number of states: ";
    cin>>numStates;
    cout<<"Enter number of alphabets: ";
    cin>>alphnum;
    cout<<"Enter Alphabets: "<<endl;
    for(int i=0; i<alphnum; i++)
    {
        char x;
        cin>>x;
        alphabets.push_back(x);
    }
    alphabets.push_back(epsilon);

    cout<<"Enter start state: ";
    cin>>startState;
    cout<<"Enter Number of final states: ";
    cin>>finalStateNum;
    cout<<"Enter the final states: ";
    for(int i=0; i<finalStateNum; i++)
    {
        char f;
        cin>>f;
        finalState[f] = true;
    }

    for(int i=0; i<numStates; i++)
    {
        cout<<"Enter transition for state "<< (char) ('a' + i) <<endl;
        for(auto itr: alphabets)
        {
            cout<<"For input "<<itr<<": (# for break)"<<endl;

        }
    }

}
