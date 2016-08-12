// vim: ts=4:sts=4:sw=4

#ifndef __bob_h__
#define __bob_h__

#include <string>
#include <regex>

namespace bob
{
	std::string hey(const std::string& message);

	class Responder
	{
		private:
			std::regex silence_regex;
			std::regex shouting_regex;
			std::regex contains_lowercase_regex;
			std::regex contains_uppercase_regex;
			std::regex asking_a_question_regex;
			std::smatch m;
		public:
			Responder();
			std::string respond(const std::string& message);
	};
};

#endif
