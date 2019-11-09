#include <boost/asio.hpp>

#include <atomic>
#include <thread>
#include <iostream>

#include "Service.h"

class Acceptor {
public:

	Acceptor(asio::io_service& ios, unsigned short port_num) :
		m_ios(ios),
		m_acceptor(m_ios,
		asio::ip::tcp::endpoint(
		asio::ip::address_v4::any(),
		port_num)),
		m_isStopped(false);

	// Start accepting incoming connection requests.
	void Start();

	// Stop accepting incoming connection requests.
	void Stop(); 

private:
	void InitAccept();
	void onAccept(const boost::system::error_code& ec,
		std::shared_ptr<asio::ip::tcp::socket> sock);

private:
	asio::io_service& m_ios;
	asio::ip::tcp::acceptor m_acceptor;
	std::atomic<bool> m_isStopped;
};