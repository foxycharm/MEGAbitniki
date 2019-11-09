#include "SyncTCPClient.h"

class DatabaseTCPClient : SyncTCPClient
{
public: 
	istream& GetDocuments(std::string request);
private:
} 