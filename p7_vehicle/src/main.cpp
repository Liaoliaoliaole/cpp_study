#include <iostream>
#include <memory>
#include <vector>

#include "vehicle.hpp"
#include "car.hpp"
#include "bike.hpp"


int main(int argc,char*argv[]){
	
	std::shared_ptr<vehicle> tesla1 = std::make_shared<car>("Tesla","Electrical",80.0);
	std::shared_ptr<vehicle> tesla2 = std::make_shared<car>("Tesla","Electrical",85.0);
	std::shared_ptr<vehicle> vos1 = std::make_shared<car>("Voswagon","Gasoline",90.0);
	std::shared_ptr<vehicle> vos2 = std::make_shared<car>("Voswagon","Gasoline",80.0);
	std::shared_ptr<vehicle> volvo1 = std::make_shared<car>("Volvo","Desiel",100.0);
	std::shared_ptr<vehicle> helka1 = std::make_shared<bike>("Helkaman",25.0);
	

	//std::shared_ptr<vehicle> tesla;

	std::vector<std::shared_ptr<vehicle>> vehicles;
	vehicles.push_back(tesla1);
	vehicles.push_back(vos1);
	vehicles.push_back(volvo1);
	//circles.push_back(helka1);

	std::vector<vehicle>::iterator it;
	for(it=vehicles.begin(); it != vehicles.end();it++){
		std::cout << it->get_brand() <<std::endl;
	}


	return 0;
}
