#include <bits/stdc++.h>
using namespace std;
 
struct Point{
    int x, y;
};
Point p0;
Point secondtop(stack<Point> &hull){
    Point p = hull.top();
    hull.pop();
    Point res = hull.top();
    hull.push(p);
    return res;
}
 
int swap(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int Distance(Point p1, Point p2){
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
int fo(Point p, Point q, Point r){
    int sl = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y); 
    if (sl == 0) return 0;  
    return (sl > 0)? 1: 2; 
} 

bool compare(const Point& p1, const Point& p2){
   int o = findOrientation(p0, p1, p2);
   if (o == 0)
     return (SquareDistance(p0, p2) >=  SquareDistance(p0, p1));
   return (o == 2);
}
 

void convexHull(Point arr[], int n){
   int ymin = arr[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = arr[i].y;
 
     if ((y < ymin) || (ymin == y &&
         arr[i].x < arr[min].x))
        ymin = arr[i].y, min = i;
   }
 
   swap(arr[0], arr[min]);

   p0 = arr[0];
   sort(arr+1, arr + n,  compare);
 
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++){
       while (i < n-1 && findOrientation(p0, arr[i],
                                    arr[i+1]) == 0)
          i++;
 
 
       arr[m] = arr[i];
       m++; 
   }
 
   if (m < 3) return;
 
   stack<Point> hull;
   hull.push(arr[0]);
   hull.push(arr[1]);
   hull.push(arr[2]);
   for (int i = 3; i < m; i++){
      while (findOrientation(secondtop(hull), hull.top(), arr[i]) != 2)
         hull.pop();
      hull.push(arr[i]);
   }
 
   
   while (!hull.empty())
   {
       Point p = hull.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       hull.pop();
   }
}
 

int main(){
	int n;
	cin>>n;
	
    Point arr[n];
    
    for(int i=0; i<n; i++){
    	int x, y;
    	cin>>x>>y;
    	arr[i] = {x,y};
    }
    convexHull(arr, n);
    return 0;
}