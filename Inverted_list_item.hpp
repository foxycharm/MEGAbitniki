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