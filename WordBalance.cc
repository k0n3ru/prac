#include <iostream>
#include <map>
#include <string>

std::map<char,short> weights;

std::map<char,short> init_weights(){
	
	std::map<char,short> ret;
	short i;
	char c; // Cannot initialize multiple types in for !!
	for(i=1,c='A';i<=26;i++,c++) {
		ret.insert(std::pair<char,short>(c,i));
	}
	/*for(auto it = weights.begin();it!=weights.end();it++){
		std::cout << it->first <<":"<<it->second<<std::endl;
	}*/
	return ret;
}

int lhs_weight(std::string lhs_sub_string){
	int distance = 1;
	int weight = 0;
	for(auto it=lhs_sub_string.rbegin();it!=lhs_sub_string.rend();it++,distance++) {
		//std::cout << *it << ":" << weights[*it] << "*" << distance << std::endl;
		weight += weights[*it] * distance;
	}
	//std::cout << "Weight of '"<< lhs_sub_string <<"' :"<< weight << std::endl;
	return weight;
}

int rhs_weight(std::string rhs_sub_string){
	int distance = 1;
	int weight = 0;
	for(auto it=rhs_sub_string.begin();it!=rhs_sub_string.end();it++,distance++) {
		//std::cout << *it << ":" << weights[*it] << "*" << distance << std::endl;
		weight += weights[*it] * distance;
	}
	//std::cout << "Weight of '"<< rhs_sub_string <<"' :"<< weight << std::endl;
	return weight;
}

void balance(std::string inp) {

	int size = inp.length();
	int balance_point = 1; // we start checking from 2nd letter
	
	for( balance_point = 1 ; balance_point < size ;  balance_point++ ){
		auto lweight = lhs_weight(inp.substr(0,balance_point));
		auto rweight = rhs_weight(inp.substr(balance_point+1));
		if (  lweight == rweight ) {
			std::cout << inp.substr(0,balance_point) <<" " << inp[balance_point] << " " << inp.substr(balance_point+1) << " - " << lweight<<std::endl;
			break;
		}
	}
	if( balance_point >= size ) {
		std::cout << inp << " DOES NOT BALANCE"<<std::endl;
	}
}
int main(){

	weights = init_weights();
	balance("STEAD");
	balance("CONSUBSTANTIATION");
	balance("WRONGHEADED");
	balance("UNINTELLIGIBILITY");
	//balance("");
return 0;
}



	

