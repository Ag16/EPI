/*Program to find the inersection fo two rectangles whose sidea are paralle to the axes*/

#include <iostream>

using namespace std;

class rectangle{
	public:
		int x;
		int y;
		int w;
		int h;
		bool isSet;
		
		bool printVertices();
		rectangle(int x, int y, int w, int h);
		rectangle();
		bool setVertices(int x, int y, int w, int h);
};

bool rectangle::printVertices(){
	//function will print the vertices of the rectangle if the vertices have been set
	//it also reuturns the value of the isSet variable
	if(isSet){
		cout<<x<<","<<y<<endl;
		cout<<x+w<<","<<y<<endl;
		cout<<x+w<<","<<y+h<<endl;
		cout<<x<<","<<y+h<<endl;
	}
	return isSet;
}

rectangle::rectangle(int x, int y, int w, int h){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	isSet = true;
}

rectangle::rectangle(){
	this->x = this->y = 0;
	this->w = this->h = -1;
	isSet = false;
}

bool rectangle::setVertices(int x, int y, int w, int h){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	isSet = true;

}

bool isIntersect(rectangle &r1, rectangle &r2);
bool findIntersect(rectangle &r1, rectangle &r2, rectangle &r3);

int main(){
	rectangle r1 = rectangle(1,1,4,7);
	rectangle r2 = rectangle(11,11,6,9);
	rectangle r3 = rectangle();

	if(findIntersect(r1,r2,r3)){
		r3.printVertices();
	}
	else
		cout<<"The recrtangles do not intersect";
	cout<<endl;
	return 0;
}

bool isIntersect(rectangle &r1, rectangle &r2){
	return (r1.x <= r2.x+r2.w && r1.x+r1.w >= r2.x && r1.y <= r2.y+r2.h && r1.y+r1.h >= r2.y);
}

bool findIntersect(rectangle &r1, rectangle &r2, rectangle &r3){
	//function returns true if there is an intersecation of the two rectanlges and false otherwise 
	//In case of intersection r3 will contain the rectangle that represents the intersection of the two
	if(isIntersect(r1,r2)){
		int x, y, w ,h;
		x = max(r1.x,r2.x);
		w = min(r1.x+r1.w, r2.x+r2.w) - x;
		y= max(r1.y,r2.y);
		h = min(r1.y+r1.h, r2.y+r2.h) - y;
		r3.setVertices(x,y,w,h);
		return true;
	}
	else
		return false;
}