#include <map>
#include <iostream>
#include <string>

class Token_dictionary {
	std::map<std::string, size_t> tk_d;

	Token_dictionary();	
public:
	void add_item(string token, uint url_id);
	size_t get_item();
	void parse(string text, uint url_id);
	void delete_item(string token);
};