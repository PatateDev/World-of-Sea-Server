#include "Main.h"
#include "SQL/SQLDatabase.h"
#include "SQL/UsersTable.h"
#include "LoginService.h"
#include "GameServer.h"

int main(int argc, char **argv)
{
	logger << "Starting World of Sea Server v" << SERVER_VERSION_MAJOR <<
	        "." << SERVER_VERSION_MINOR << "." << SERVER_VERSION_PATCH << endl;

	if (argc != 5)
	{
	    logger << "The server must be started with the following MySQL arguments : ";
	    logger << "<username> <password> <address> <database>" << endl;
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
	logger << "Looking for mathdu07 in users .." << endl;
	if (table.isRegistered("mathdu07"))
	{
	    logger << "Find !" << endl;
	    logger << "Password MD5 : " << table.getPassword("mathdu07") << " | ";
	    logger << "Last IP : " << table.getIP("mathdu07").toString() << " | ";
	    logger << "Session : " << table.getSession("mathdu07") << endl;
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
	        logger << "TPS : " << gameServer.getTicksPerSecond() << endl;
	    }
	    else
	        logger << cmd << " : unknown command" << endl;
	}
	
	gameThread.wait();
	loginThread.wait();

	return EXIT_SUCCESS;
}
