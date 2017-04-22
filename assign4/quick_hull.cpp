#include <bits/stdc++.h>
using namespace std;

struct point{
	double x,y;
	point(double X=0, double Y=0) : x(X), y(Y){}
};

double area(point p1, point p2, point p3){
	p2.x -= p3.x;	p2.y -= p3.y;
	p1.x -= p3.x;	p1.y -= p3.y;
	return 0.5*(p1.x*p2.y-p1.y*p2.x);
}

bool compare(const point &a, const point &b, const point &c){
	return area(a,b,c)>0;
}

point leftMost(vector<point> &hull){
	point left = hull[0];
	for(int i=1; i<hull.size(); i++){
		if(hull[i].x>left.x)	continue;
		if(hull[i].x==left.x&&hull[i].y>left.y)	continue;
		left = hull[i];
	}
	return left;
}

int lowerMost(vector<point> &hull){
	int j=0;
	for(int i=1; i<hull.size(); i++){
		if(hull[i].y>hull[j].y)	continue;
		if(hull[i].y==hull[j].y&&hull[i].x>hull[j].x)	continue;
		j=i;
	}
	return j;
}

vector<point> quick(point a, point b, vector<point> &hull){
	if(hull.size()<2)	return hull;
	vector<point> p;
	int j=0;
	for(int i=1; i<hull.size(); i++)	if(area(a,b,hull[i])>area(a,b,hull[j]))	j=i;
	point farthest = hull[j];
	vector<point> t;
	for(int i=0; i<hull.size(); i++)	if(area(farthest,b,hull[i])>0)	t.push_back(hull[i]);
	p = quick(farthest,b,t);
	p.push_back(farthest);
	t.clear();
	for(int i=0; i<hull.size(); i++)	if(area(a,farthest,hull[i])>0)	t.push_back(hull[i]);
	vector<point> ans = quick(a,farthest,t);
	p.insert(p.end(),ans.begin(),ans.end());
	t.clear();
	return p;
}
vector<point> quickHull(vector<point> &hull){
	int num_points = hull.size();
	if(num_points<4)	return hull;
	vector<point> p;
	int j = lowerMost(hull);
	swap(hull[j],hull.back());
	p.push_back(hull.back());
	hull.pop_back();
	j=0;
	for(int i=1; i<hull.size(); i++)	if(compare(p[0],hull[i],hull[j]))	j = i;
	swap(hull[j],hull.back());
	p.push_back(hull.back());
	hull.pop_back();
	vector<point> ans = quick(p[0],p[1],hull);
	p.insert(p.end(),ans.begin(),ans.end());
	return p;
}
int main() {
	int num_points=0;
	cin>>num_points;
	vector<point> hull;
	point temp;
	while(num_points--){
		cin>>temp.x>>temp.y;
		hull.push_back(temp);
	}
	vector<point> ans = quickhull(hull);
	return 0;
}