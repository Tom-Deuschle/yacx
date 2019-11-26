#pragma once

#include <iostream>
#include <map>

namespace cudaexecutor {

enum class loglevel {
    NONE,    /**< don't log at all */
    ERROR,   /**< an ERROR which should not be ignored */
    WARNING, /**< a WARNING which might be ignored */
    INFO,    /**< a INFO which can be ignored */
    DEBUG,   /**< verbose INFO which can be ignored */
    DEBUG1   /**< verbose DEBUG which can be ignored */
};
std::map<loglevel,std::string> loglevel_name = {
        {cudaexecutor::loglevel::   NONE, "   NONE"},
        {cudaexecutor::loglevel::  ERROR, "  ERROR"},
        {cudaexecutor::loglevel::WARNING, "WARNING"},
        {cudaexecutor::loglevel::   INFO, "   INFO"},
        {cudaexecutor::loglevel::  DEBUG, "  DEBUG"},
        {cudaexecutor::loglevel:: DEBUG1, " DEBUG1"}
};

class Log {
    std::ostream _stream;
    loglevel _level;
    loglevel _cur_level;


public:
    Log(std::ostream& stream, loglevel level) : _stream(stream.rdbuf()), _level(level){}

    void setStream(std::ostream& ostream) {
        _stream.rdbuf(ostream.rdbuf());
    }

    void setLevel(loglevel level) {
        _level = level;
    }

    template <typename T>
    Log &operator<<(T const &value) {
        if (static_cast<int>(_cur_level) > static_cast<int>(_level))
            _stream << loglevel_name.find(_cur_level)->second << ":" << value << std::endl;
    }

    Log &print(const loglevel level, const char* file, const int line) {
        _cur_level = level;
        return *this;
    }

};

Log LOGGER {std::cerr, loglevel::DEBUG};

#define logger(level) LOGGER.print(level, __FILE__, __LINE__)

} // namespace cudaexecutor

