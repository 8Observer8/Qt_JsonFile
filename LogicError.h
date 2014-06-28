#ifndef LOGICERROR_H
#define LOGICERROR_H

#include <stdexcept>
#include <string>

class LogicError : public std::logic_error {
public:

    LogicError( const std::string &functionName ) :
        std::logic_error( "" ),
        m_functionName( functionName ),
        m_message( "" )
    {

    }

    virtual ~LogicError( ) throw( ) {

    }

    virtual const char *what( ) const throw( ) {
        return m_message.c_str( );
    }

    std::string message( ) const {
        return m_message;
    }

protected:
    std::string m_functionName;
    std::string m_message;
};

#endif // LOGICERROR_H
