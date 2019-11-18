#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <string>

class Tcp_client : public boost::enable_shared_from_this<talk_to_client>, boost::noncopyable {
	ip::tcp::socket sock_;
	enum { max_msg = 1024 };
	char read_buffer_[max_msg];
	char write_buffer_[max_msg];
	bool started_;
	std::string username_;
	deadline_timer timer_;
	boost::posix_time::ptime last_ping;
	bool clients_changed_;

	Tcp_client();

public:
	typedef boost::system::error_code error_code;
	typedef boost::shared_ptr<talk_to_client> ptr;
	void start();
	static ptr new_();
	void stop();
	bool started() const;
	ip::tcp::socket & sock();
	std::string username() const;
	void set_clients_changed();
	std::string get_text();
	size_t get_url_id();
};