#include <boost/asio.hpp>

#include <thread>
#include <iostream>

#include "Acceptor.h"

class Server {
public:

	Server();

	void Start(unsigned short port_num,
		unsigned int thread_pool_size,
		const std::string& db_raw_ip_address,
		unsigned short db_port_num);

	void Stop();

private:
	asio::io_service m_ios;
	std::unique_ptr<asio::io_service::work> m_work;
	std::unique_ptr<Acceptor> acc;
	std::vector<std::unique_ptr<std::thread>> m_thread_pool;

	const std::string& db_raw_ip_address;
	unsigned short db_port_num;
};