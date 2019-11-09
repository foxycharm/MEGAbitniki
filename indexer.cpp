#include <iostream>
#include <map>
#include <vector>
#include <string>

// Элемент инвертированного списка
class Inverted_list_item {
	unsigned long int url_id; // id web-страницы
	unsigned long int term_frequency; // Частота термина на этой web-транице
	unsigned long int weignt; // Вес термина на странице term_frequency - inverted_document_frequency
	std::vector<unsigned long int> postings_list; // Список позиций термина на web-странице
public:
	unsigned long int get_Url_id();
	unsigned long int get_term_frequency();
	unsigned long int get_weight() {}; // Вес термина на странице term_frequency - inverted_document_frequency
	std::vector<unsigned long int> get_postings_list() {};
	void set_Url_id(unsigned long int _url_id) {};
	void set_term_frequency(unsigned long int tf) {};
	void update_weight(unsigned long int idf) {}; // Вес термина на странице term_frequency - inverted_document_frequency
	void add_posting(unsigned long int posting) {};
};

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

int main() {

}