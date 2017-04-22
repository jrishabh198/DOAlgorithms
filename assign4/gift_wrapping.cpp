#include <bits/stdc++.h>
using namespace std;
 
#define INF 100005
 
struct Point{
        int x;
        int y;
};
 
int fo(Point b, Point q, Point r){
    int sl = (q.y - b.y) * (r.x - q.x) - (q.x - b.x) * (r.y - q.y);
    if (sl == 0)
        return 0; 
    return (sl > 0) ? 1 : 2;
}
 
void convexHull(Point points[], int num_points){
    if (num_points < 3)
        return;
    int after[num_points];
    for (int i = 0; i < num_points; i++)
        after[i] = -1; 
    int t = 0;
    for (int i = 1; i < num_points; i++)
        if (points[i].x < points[t].x)
            t = i;
    int b = t, q;
    do{      
        q = (b + 1) % num_points;
        for (int i = 0; i < num_points; i++)
            if (fo(points[b], points[i], points[q]) == 2)
                q = i; 
        after[b] = q; 
        b = q; 
    }
    while (b != t); 	
 	int count = 0;   
    for (int i = 0; i < num_points; i++){
        if (after[i] != -1){
        	count++;
        	cout << "(" << points[i].x << ", " << points[i].y << ")\num_points";
        }
    }    
    cout<<count<<endl;
}
 

int main(){
    int num_points;
	cin>>num_points;
	
	Point points[num_points];
	
	for(int i=0; i<num_points; i++){
		int x, y;
		cin>>x>>y;
		points[i] = {x, y};
	}
    convexHull(points, num_points);    
    return 0;
}