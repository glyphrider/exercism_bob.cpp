// vim: ts=4:sts=4

#include "bob.h"
#include <regex>

namespace bob
{
	std::string hey(const std::string& message)
	{
		static Responder responder;
		return responder.respond(message);
	}
	Responder::Responder() {};
	std::string Responder::respond(const std::string& message)
	{
		std::smatch m;
		static std::regex silence_regex("^\\s*$");
		static std::regex shouting_regex(".*(!|\\?)$");
		static std::regex contains_lowercase_regex("[a-z]");
		static std::regex contains_uppercase_regex("[A-Z]");
		static std::regex asking_a_question_regex(".*\\?\\s*$");
		if (std::regex_search(message,m,silence_regex))
			return "Fine. Be that way!";
		if (std::regex_search(message,m,contains_uppercase_regex) &&
		   !std::regex_search(message,m,contains_lowercase_regex))
			return "Whoa, chill out!";
		if (std::regex_search(message,m,asking_a_question_regex))
			return "Sure.";
		return "Whatever.";
	}
}
