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
};

#endif
