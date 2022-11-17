#include<iostream>
#include<string>

struct Transaction{
	int price;
	std::string order_name;
};

class Coffe_Machine{
	private:
		int prices_list[7];
		std::string names[7];
	public:	
		Coffe_Machine():
		prices_list{100, 200, 300, 150, 250, 400, 50},
		names{"Black Coffe", "Mac Cofee", "Capuccino", "Milk", "Espresso", "Glasse", "empty cup"}	
		{};
	
		void print_list(){
			for(int i = 0; i < 7; i++){
				std::cout<<prices_list[i]<<"--------"<<names[i]<<std::endl;	
			}
		}
		Transaction my_pay(Transaction& p){
			bool key = false;
			bool price_key = true;
			int i = 0;
			for(; i < 7; ++i){
				if(p.order_name == names[i] && p.price >= prices_list[i]){	
					key = true;
					price_key = true;
					break;
				}if(p.order_name == names[i] && p.price < prices_list[i]){
					price_key = false;
					break;
				}
			}
			if(!key){
				std::cout<<"This Type of hot drink was not in List"<<std::endl;
				return p;
			}
			if(!price_key){
				std::cout<<"The balance was little then price of order"<<std::endl;
				return p;
			}
			else{
				p.price =  p.price - prices_list[i];
				p.order_name = names[i];
				return p;
			}
	}
};

int main(){

	Coffe_Machine order;
	order.print_list();
	

	Transaction my_order;
	std::cout<<"Press money for transaction"<<std::endl;
	std::cin>>my_order.price;
	
	int pricer = my_order.price;
	std::cout<<"Press name your choosed drink"<<my_order.order_name<<std::endl;
	std::cin>>my_order.order_name;

	order.my_pay(my_order);
	if(pricer != my_order.price){
		std::cout<<"Your balance is: "<<my_order.price<<std::endl;
		std::cout<<"Your Order was ready: "<<my_order.order_name<<std::endl;
	}
return 0;
}
