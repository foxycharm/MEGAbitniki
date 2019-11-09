#include <boost/asio.hpp>
#include <boost/filesystem.hpp>

#include <fstream>
#include <atomic>
#include <iostream>

using namespace boost;

const std::map<unsigned int, std::string>
Service::http_status_table =
{
	{ 200, "200 OK" },
	{ 404, "404 Not Found" },
	{ 413, "413 Request Entity Too Large" },
	{ 500, "500 Server Error" },
	{ 501, "501 Not Implemented" },
	{ 505, "505 HTTP Version Not Supported" }
};

class Service {
	static const std::map<unsigned int, std::string>
	http_status_table;

public:
	Service(std::shared_ptr<boost::asio::ip::tcp::socket> sock, 
			const std::string& db_raw_ip_address;
			unsigned short db_port_num) :
		m_sock(sock),
		m_request(4096), //stream buffer member is initialized with the value of 4096 bytes
		m_response_status_code(200), // Assume success.
		m_resource_size_bytes(0),

	void start_handling(); // read http status from m_sock -> on_request_line_received

private:

	/* 	errors deliniter not found -> send_responce with code 413
		errors -> on_finish
		parse request
		errors HTTP not 1.1 -> send_responce with code 505
		errors method not GET -> send_responce with code 501
		read headers -> on_headers_received
	*/
	void on_request_line_received(
		const boost::system::error_code& ec,
		std::size_t bytes_transferred);

	/* 
		errors deliniter not found -> send_responce with code 413
		errors -> on_finish
		parse headers
		process_request();
		send_response();
	*/
	void on_headers_received(const boost::system::error_code& ec,
		std::size_t bytes_transferred);

	/*	process 
		construct headers
	*/
	void process_request();

	void send_response(); // -> on_responce_sent

	void on_response_sent(const boost::system::error_code& ec,
		std::size_t bytes_transferred); // -> on_finish
	
	// Here we perform the cleanup.
	void on_finish();

private:
	// This is a shared pointer to a TCP socket object connected to the client
	std::shared_ptr<boost::asio::ip::tcp::socket> m_sock;
	//This is a buffer into which the request message is read
	boost::asio::streambuf m_request;

	SearchEngine engine;
	HttpParser parser;
};
