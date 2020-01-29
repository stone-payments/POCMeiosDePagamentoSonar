#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/stream_buffer.hpp>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
 // atualizado
namespace io = boost::iostreams;
 
class ex {};
 
int main ()
{
	int fd = open("/my/file", O_WRONLY|O_CREAT|O_EXCL, 0600);
	if (fd == -1)
		throw ex();
	io::stream_buffer<io::file_descriptor_sink> fp (fd);
	std::ostream out(&fp);
 
	out << "Hello, world" << std::endl;
	return 0;
}