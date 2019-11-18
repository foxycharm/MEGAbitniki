#include <iostream>
#include <map>
#include <vector>
#include <string>

// Словарь
class Dictionary {
	std::string term; // термин
	unsigned long int document_frequency; // Популярность слова (среди всех документов) - документная частота
	unsigned long int inverted_document_frequency; // Обратная документная частота log(N/document_frequency), где N - размер коллекции web-страниц
	std::vector<Inverted_list_item> inverted_list; // Инвертированный список web-страниц, в которых встречается term
public:
	std::string get_term() {};
	unsigned long int get_document_frequency() {};
	unsigned long int get_inverted_document_frequency() {};
	std::vector<Inverted_list_item> get_inverted_list() {};
	void sort();
	void set_term(std::string) {};
	void set_document_frequency(unsigned long int df) {};
	void update_inverted_document_frequency(unsigned long int N) {};
	void add_inverted_list_item(Inverted_list_item item) {};
};