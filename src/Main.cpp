#include "Main.h"
#include "SQL/SQLDatabase.h"
#include "SQL/UsersTable.h"
#include "LoginService.h"
#include "GameServer.h"

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
	
	//Initialize random seed
	srand(time(NULL));

	//Testing database
	UsersTable table(database);
	std::cout << "Looking for mathdu07 in users .." << std::endl;
	if (table.isRegistered("mathdu07"))
	{
	    std::cout << "Find !" << std::endl;
	    std::cout << "Password MD5 : " << table.getPassword("mathdu07") << " | ";
	    std::cout << "Last IP : " << table.getIP("mathdu07").toString() << " | ";
	    std::cout << "Session : " << table.getSession("mathdu07") << std::endl;
	}
	
	LoginService login(database);
	GameServer gameServer(database);
	sf::Thread loginThread(&LoginService::run, &login), gameThread(&GameServer::run, &gameServer);
	loginThread.launch();
	gameThread.launch();
	
	while (true)
	{
	    std::string cmd;
	    std::cout << "> ";
	    std::cin >> cmd;
	    
	    if (cmd.compare("exit") == 0)
	    {
	        gameServer.stop();
	        login.stop();
	        break;
	    }
	    else if (cmd.compare("ticks") == 0)
	    {
	        std::cout << "TPS : " << gameServer.getTicksPerSecond() << std::endl;
	    }
	    else
	        std::cout << cmd << " : unknown command" << std::endl;
	}
	
	gameThread.wait();
	loginThread.wait();

	return EXIT_SUCCESS;
}
