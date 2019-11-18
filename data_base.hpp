#pragma comment(lib, "C:\Program Files\MySQL\MySQL Server 5.0\lib\debug\libmysql.lib")
#include <iostream>
#include <string>
#include <my_global.h>
#include <mysql.h>

class Data_base {
	std::string host;
	std::string user;
	std::string password;
	std::string dbname;
public:
	Data_base(std::string dbname_, std::string host_, std::string user_, std::string password_);
	bool connect();
	bool query(std::string q);
	bool close();
};