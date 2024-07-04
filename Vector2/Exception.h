#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <string>

class Exception : public std::exception
{
private:
    std::string m_message;
public:
    Exception(const std::string& message);
    ~Exception();
    const char* what() const noexcept;
};
#endif //EXCEPTION_H