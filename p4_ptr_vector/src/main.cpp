#include <iostream>
#include <vector>
#include <memory>
#include "circle.hpp"


int main(){
	/*
	auto buf_1 = make_unique<unsigned char[]>(512);//512 is the size of thechar
	buf_1[0] ='A';
	std::cout << buf_1[0] << std::endl;
	
	auto buf_2 = make_shared<unsigned char[]>(512); //gcc doesnot suport this kind array
	*/
	
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	//v.insert(v.at(0),100); //v.at(0) is not a pointer
	
	std::vector<int>::iterator it;
	
	it=v.begin();
	v.insert(it,100);
	
	for(int n : v){
		std::cout << n << std::endl;
		std::cout << "+++++++++++++++++" << std::endl;
	}
	
	for (it=v.begin();it !=v.end();it++){
		std::cout << *it << std::endl;
	}
	
	auto sc1 = std::make_shared<circle>(10);
	auto sc2 = std::make_shared<circle>(20);
	auto sc3 = std::make_shared<circle>(30);
	
	std::vector<std::shared_ptr<circle>> circles;
	circles.push_back(sc1);
	circles.push_back(sc2);
	circles.push_back(sc3);
	circles.push_back(sc3);
	
	
	std::cout << sc3.use_count() << std::endl;
	
	
	
	for(std::shared_ptr<circle> &sc: circles){
	std::cout << sc->getX() <<", " << sc->getY() << "Radius "<<sc->getRadius()<< std::endl;
	}
	
	circles.push_back(std::move(sc3));
	std::cout << sc3.use_count() << std::endl;
	
	
	
	return 0;

}
