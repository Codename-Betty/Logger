#pragma once

#include <string.h>
#include <iostream>
#include <Windows.h>
#include <mutex>

//defining priorities

const enum LogPriority
{
	DebugPriority,
	InfoPriority,
	WarnPriority,
	ErrorPriority,
	FatalPriority
};

//get std output handle

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


//define the colors

const WORD debugcolor = 0x08; //grey
const WORD infocolor = 0x0f; //white
const WORD warncolor = 0x0c; //light red
const WORD errorcolor = 0x04; //red
const WORD fatalcolor = 0x4F; // background red

const WORD defaultcolor = 0x0F; //black bg white fg


using namespace std;

class Logger
{
private:
	
	

	static void log(LogPriority priority, const char* message) {
		//check which priority was given when the function was called and send the according message
		switch (priority)
		{
		case DebugPriority:										
			SetConsoleTextAttribute(h, debugcolor);
			std::cout << "[DEBUG]: \t" << message << endl;
			break;
		case InfoPriority:
			SetConsoleTextAttribute(h, infocolor);
			std::cout << "[INFO]:  \t" << message << endl;
			break;
		case WarnPriority:
			SetConsoleTextAttribute(h, warncolor);
			std::cout << "[WARN]:  \t" << message << endl;
			break;
		case ErrorPriority:
			SetConsoleTextAttribute(h, errorcolor);
			std::cout << "[ERROR]: \t" << message << endl;
			break;
		case FatalPriority:
			SetConsoleTextAttribute(h, fatalcolor);
			std::cout << "[FATAL]:\t" << message << endl;
			break;
		default:
			SetConsoleTextAttribute(h, errorcolor);
			std::cout << "[ERROR]:  \t" << "no valid priority given." << endl;
			break;
		}

		//resetting the color to default
		SetConsoleTextAttribute(h, defaultcolor);

	}

public:
	//defining public logging functions
	static void Debug(const char* message) {
		log(DebugPriority, message);
	}
	static void Info(const char* message) {
		log(InfoPriority, message);
	}
	static void Warn(const char* message) {
		log(WarnPriority, message);
	}
	static void Error(const char* message) {
		log(ErrorPriority, message);
	}
	static void Fatal(const char* message) {
		log(FatalPriority, message);
	}
};
