

class HttpParser {

public:
	Parser(boost::asio::streambuf &m_request) : 
		request_line_stream(&m_request);

	std::map<std::string, std::string> GetRequestHeaders();
	std::string GetRequestMethod();
	std::string GetRequestProtocol();
	std::string GetContentLenghtHeader(std::size_t length);
	std::string GetStatusLine(unsigned int status);

	void AddResponseHeader(std::string header);
	void AddResourceSize(size_t size);
	void AddStatusLine(std::string line);
	std::unique_ptr<char[]> GetResponse();


private:
	std::istringstream request_line_stream;
	//This is a map where request headers are put when the HTTP request headers block is parsed
	std::map<std::string, std::string> m_request_headers;
	std::string request_method;
	std::string request_http_version;

	//This is a buffer where the contents of a requested resource is stored 
	//before being sent to the client as a part of the response message
	std::unique_ptr<char[]> m_resource_buffer;
	//This is the HTTP response status code
	unsigned int m_response_status_code;
	//This is the size of the contents of the requested resource
	std::size_t m_resource_size_bytes;
	//This is a string containing a properly formatted response headers block
	std::string m_response_headers;
	//This contains a response status line
	std::string m_response_status_line;
};
