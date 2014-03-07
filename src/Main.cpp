#include "Main.h"
#include "SQL/SQLDatabase.h"

int main(int argc, char **argv)
{
	std::cout << "Starting World of Sea Server v" << SERVER_VERSION_MAJOR <<
	        "." << SERVER_VERSION_MINOR << "." << SERVER_VERSION_PATCH << std::endl;

	if (argc != 5)
	{
	    std::cout << "The server must be started with the following MySQL arguments : ";
	    std::cout << "<username> <password> <address> <database>" << std::endl;
	    return EXIT_FAILURE;
	}

	SQLDatabase database;
	if (!database.init(argv[1], argv[2], argv[3], argv[4]))
	{
	    return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
