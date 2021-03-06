#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <iostream>
#include <cstring>
#include <ctime>

namespace fs = boost::filesystem;

class Logger{

        fs::path logsPath;

    public:

        Logger(std::string fileName);

        bool setNewLogFile(std::string fileName);

        bool logToFile(std::string msg);

        fs::path getLogsPath(){ return logsPath; }

};