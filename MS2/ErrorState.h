// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name   Seungmin Yun            Date                 Reason
/////////////////////////////////////////////////////////////////

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

namespace AMA {
	class ErrorState {
		char *addMsg; //address of msg
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& , const ErrorState& );
}
#endif // !ERRORSTATE_H
