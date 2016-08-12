// vim: ts=4:sts=4:sw=4

#ifndef __bob_h__
#define __bob_h__

#include <string>

namespace bob
{
	std::string hey(const std::string& message);

	class Responder
	{
		public:
			Responder();
			std::string respond(const std::string& message);
	};
};

#endif
