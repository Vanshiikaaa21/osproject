#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

class Logger {
public:
    static void log(const std::string& action, const std::string& filePath, const std::string& hash = "") {
        std::ofstream logFile(".unigit/log", std::ios::app); // Create file if not exists
        if (!logFile.is_open()) {
            std::cerr << "❌ Failed to open .unigit/log file\n";
            return;
        }

        // Get current time
        std::time_t now = std::time(nullptr);
        std::tm* timeinfo = std::localtime(&now);

        // Write to log file
        logFile << "[" << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S") << "] "
                << action << " " << filePath;
        if (!hash.empty()) logFile << " (" << hash << ")";
        logFile << std::endl;

        // Also print to console (optional)
        std::cout << "[LOG] " << action << " " << filePath;
        if (!hash.empty()) std::cout << " (" << hash << ")";
        std::cout << std::endl;
    }
};

