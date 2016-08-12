// vim: ts=4:sts=4

#include "bob.h"

namespace bob
{
	std::string hey(const std::string& message)
	{
		return Responder(message).respond();
	}
	Responder::Responder(const std::string& message):
		_message(message),
		_silence_regex("^\\s*$"),
		_shouting_regex(".*(!|\\?)$"),
		_contains_lowercase_regex("[a-z]"),
		_contains_uppercase_regex("[A-Z]"),
		_asking_a_question_regex(".*\\?\\s*$") {}
	std::string Responder::respond()
	{
		if (std::regex_search(_message,m,_silence_regex))
			return "Fine. Be that way!";
		if (std::regex_search(_message,m,_contains_uppercase_regex) &&
		   !std::regex_search(_message,m,_contains_lowercase_regex))
			return "Whoa, chill out!";
		if (std::regex_search(_message,m,_asking_a_question_regex))
			return "Sure.";
		return "Whatever.";
	}
}
