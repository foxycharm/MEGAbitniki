#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

class SyncTCPClient {
public:
	SyncTCPClient(const std::string& raw_ip_address,
		unsigned short port_num) :
		m_ep(asio::ip::address::from_string(raw_ip_address),
		port_num),
		m_sock(m_ios);

	void connect();

	void close();

private:
	void sendRequest(const std::string& request);
	std::string receiveResponse();

private:
	asio::io_service m_ios;
	asio::ip::tcp::endpoint m_ep;
	asio::ip::tcp::socket m_sock;
};
