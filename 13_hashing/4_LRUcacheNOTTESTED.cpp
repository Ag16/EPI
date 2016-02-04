#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <utility>

using namespace std;

class LRUcache{
	typedef unordered_map<string, pair<list<string>::iterator, float> > table;
	
	list<string> queue;
	table cache;
	unsigned int maxSize;

	bool lookup(string);
	void insert(string, float);

public:
	//constructors
	LRUcache(unsigned int);
	LRUcache();		//default size is 200

	
	float getPrice(string);
	bool erase(string);
};

LRUcache::LRUcache(unsigned int s){
	maxSize = s;
}

LRUcache::LRUcache(){;}

bool LRUcache::lookup(string s){
	table::iterator i = cache.find(s);
	
	//return false if not found
	if(i == cache.end())
		return false;

	//if found, move the entry to the front of the queue and return true
	queue.erase((i->second).first);
	queue.push_front(i->first);
	cache[s].first = queue.begin();
	return true;
}

float LRUcache::getPrice(string s){
	//return -1 if the price is not in the cache
	bool t = lookup(s);
	if(!t)		//originally this should look up in the disk storage, insert that element into the cache and return the price
		return -1;
	return cache[s].second;
}

void LRUcache::insert(string s, float price){
	if(cache.find(s) != cache.end()){
		//case when the element already exists in the cache
		//simply push it to the front of the queue
		queue.erase(cache[s].first);
		queue.push_front(s);
		//update the cache[s] values
		cache[s] = make_pair(queue.begin(), price);
	}
	else{
		//case when element is not already in the cache
		//first check whether or not the cache is full
		if(cache.size() == maxSize){
			//need to remove last used element, ie the last element of the queue
			string rs = queue.back();
			queue.pop_back();
			cache.erase(rs);
		}
		//push new element to the front of the queue
		queue.push_front(s);
		cache[s] = make_pair(queue.begin(), price);
	}
}

bool LRUcache::erase(string s){
	table::iterator i = cache.find(s);
	if(i == cache.end())		//element not a part of the cache
		return false;
	
	queue.erase((i->second).first);
	cache.erase(s);
	return true;
}

int main(){


	return 0;

}