#include <bits/stdc++.h>
#include <map>
#include<utility>
#include<functional>
using namespace std;

int main()
{
    //Typedeffing
    typedef multimap<double, pair<int,int> > mapOfPair;
    typedef vector<pair<int, int> > vectorOfPair;
    //Storage for weight for corresponding edges
    mapOfPair weightTable;
    //input how many node will be there
    int n, n1,n2;
    double weight;
    cout << "How many nodes? ";
    cin >> n;
    cout << "Enter Node 1, Node 2, Weight: ";
    while(true){
            cin>>n1>>n2>>weight;
            if(n1==0&&n2==0&&weight==0)
                break;
            weightTable.insert(make_pair(weight, make_pair(n1,n2)));
    }
    //Inserting Weights and edge combos
   /* weightTable.insert(make_pair(10.0, make_pair(1,2)));
    weightTable.insert(make_pair(5.0, make_pair(2,3)));
    weightTable.insert(make_pair(3.0, make_pair(3,1)));*/

    //Boolean array for indicating availability of nodes[its not needed since it is a minimum spanning tree problem not tsp problem
    short int arr[n] = {0};

    //Storage for MST edges
     vectorOfPair edgeTable;

    //Loop[Error: no degree checking....check for cycles only]
    mapOfPair::iterator it;
    for(it = weightTable.begin(); it != weightTable.end(); ++it){
        if(arr[it->second.first] < 2 || arr[it->second.second] < 2){
            edgeTable.push_back(make_pair(it->second.first, it->second.second));
            arr[it->second.first] += 1;
            arr[it->second.second] += 1;

        }
    }
    //Display Edges
    vectorOfPair::iterator it1;
    for(it1 = edgeTable.begin(); it1 != edgeTable.end(); ++it1){
        cout << it1->first << "   " << it1->second << endl;
    }
    return 0;
}
