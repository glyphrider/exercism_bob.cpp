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
			std::string _message;
			std::regex _silence_regex;
			std::regex _shouting_regex;
			std::regex _contains_lowercase_regex;
			std::regex _contains_uppercase_regex;
			std::regex _asking_a_question_regex;
			std::smatch m;
		protected:
			bool is_silence();
			bool is_yelling();
			bool is_question();
		public:
			Responder(const std::string& message);
			std::string respond();
	};
};

#endif
