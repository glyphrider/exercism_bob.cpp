#include "bob.h"

namespace bob
{
	class Responder
	{
		private:
			const std::string _message;
			const std::regex _silence_regex;
			const std::regex _shouting_regex;
			const std::regex _contains_lowercase_regex;
			const std::regex _contains_uppercase_regex;
			const std::regex _asking_a_question_regex;
		protected:
			bool is_silence() const;
			bool is_yelling() const;
			bool is_question() const;
		public:
			Responder(const std::string& message);
			std::string respond();
	};

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
		if (is_silence())
			return "Fine. Be that way!";
		if (is_yelling())
			return "Whoa, chill out!";
		if (is_question())
			return "Sure.";
		return "Whatever.";
	}
	bool Responder::is_silence() const
	{
		static std::smatch m;
		return std::regex_search(_message,m,_silence_regex);
	}
	bool Responder::is_yelling() const
	{
		static std::smatch m;
		return (std::regex_search(_message,m,_contains_uppercase_regex) &&
			!std::regex_search(_message,m,_contains_lowercase_regex));
	}
	bool Responder::is_question() const
	{
		static std::smatch m;
		return std::regex_search(_message,m,_asking_a_question_regex);
	}
}
