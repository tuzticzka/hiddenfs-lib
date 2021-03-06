/**
 * @author Martin Pavlásek (xpavla07@stud.fit.vutbr.cz)
 *
 * Created on 15. březen 2012
 */

#ifndef EXCEPTIONS_H
#define	EXCEPTIONS_H

#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>

#include "types.h"

namespace HiddenFS {

    #ifndef _E
    /*
    #define _E _eXc(__FILE__, __LINE__, __FUNCTION__)
    std::string _eXc(std::string file, int l, std::string fn) {
        std::stringstream ss;
        ss << fn << "() -> " << file << ":" << l << " ";
        return ss.str();
    }
    */
    #endif


    class ExceptionFileNotFound: public std::runtime_error {
    public:
        ExceptionFileNotFound(inode_t inode) : std::runtime_error("ExceptionFileNotFound") {
            std::stringstream s;
            s << "Soubor s inode " << inode << " nenalezen";
        }
        ExceptionFileNotFound(std::string filename) : std::runtime_error("ExceptionFileNotFound") {
            std::stringstream s;
            s << "Soubor s názvem" << filename << " nenalezen";
        }
    };

    class ExceptionNotImplemented: public std::runtime_error {
    public:
        ExceptionNotImplemented(std::string msg) : std::runtime_error(msg) {}
    };

    class ExceptionBlockNotFound: public std::runtime_error {
    public:
        ExceptionBlockNotFound(std::string msg) : std::runtime_error(msg) {}
        ExceptionBlockNotFound() : std::runtime_error("ExceptionBlockNotFound") {}
    };

    class ExceptionBlockNotUsed: public std::runtime_error {
    public:
        ExceptionBlockNotUsed(std::string msg) : std::runtime_error(msg) {}
        ExceptionBlockNotUsed() : std::runtime_error("ExceptionBlockNotFound") {}
    };

    class ExceptionInodeExists: public std::runtime_error {
    public:
        ExceptionInodeExists(inode_t inode) : std::runtime_error("") {
            std::stringstream s;
            s << "Inode " << inode << " již existuje!";
        }
    };

    class ExceptionBlockOutOfRange: public std::runtime_error {
    public:
        ExceptionBlockOutOfRange(block_number_t b) : std::runtime_error("") {
            std::stringstream s;
            s << "Blok " << b << " je mimo rozsah aktuálního souboru!";
        }
    };

    class ExceptionRuntimeError: public std::runtime_error {
    public:
        ExceptionRuntimeError(std::string str) : std::runtime_error(str) {}
        ExceptionRuntimeError(const char* str) : std::runtime_error(str) {}
    };

    class ExceptionDiscFull: public std::runtime_error {
    public:
        ExceptionDiscFull(std::string str) : std::runtime_error(str) {}
        ExceptionDiscFull() : std::runtime_error("ExceptionDiscFull") {}
    };
}


#endif	/* EXCEPTIONS_H */

