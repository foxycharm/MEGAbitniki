
class InvertedIndex {
public:
  void Add(const string& document);
  list<size_t> Lookup(const string& word) const;

private:
  map<string, list<size_t>> index;
};

class Snippets {
public:
  void Add(const string& document);
  list<size_t> Lookup(const string& word) const;

  const string& GetSnippet(std::string doc) const;
  const map<string, string> GetSnippets() const;
private:
  map<string, string> snippets;
};

class SearchEngine {
public:
  SearchServer() = default;
  explicit SearchServer(const std::string& db_raw_ip_address;
						unsigned short db_port_num) :
  			db(db_raw_ip_address, db_port_num);
  void UpdateDocumentBase();
  void AddQueriesStream(istream& query_input, ostream& search_results_output);

private:
  InvertedIndex index;
  Snippets snippets;
  DatabaseTCPClient db;
};