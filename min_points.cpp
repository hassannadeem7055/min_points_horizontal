//  AUTHOR: hassannadeem7055, hassannadeem705@gmail.com
//  min points need to represent sets of horizontal-axis range points
//  part of an online test
#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

int minpoints(int size, int arr[][2]){
    int count_points=0;     //  points needed to represent line

    set<int> points;
    set<int> temp;
    set<int> disjoint;

    //  populate the points with first set

    for (int i=0; i<size; i++){
        temp.clear();
        disjoint.clear();

        //  populate the points we need to check
        for (int pt=arr[i][0]; pt<=arr[i][1]; pt++) temp.insert(pt);
        //  get disjoint set for existing points 
        set_intersection(points.begin(), points.end(), temp.begin(), temp.end(), inserter(disjoint, disjoint.begin()));
        // cout<<"disjoin: ";
        // for (auto i:disjoint) cout<<i<<' ';cout<<endl;

        if (!disjoint.size()) count_points++;
        copy(temp.begin(), temp.end(), inserter(points, points.begin()));

        // cout<<"points: ";
        // for (auto i:points) cout<<i<<' ';cout<<endl;
    }

    return count_points;
}

int main(){

    int arr[][2]={{1,3},{3,4},{2,6}};

    int min_p = minpoints(3, arr);
    cout<<endl<<"\n\nNeed "<<min_p<<" points to represents these sets on x axis"<<endl;

    
}
