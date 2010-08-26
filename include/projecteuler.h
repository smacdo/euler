#ifndef SCOTT_PROJECT_EULER_H
#define SCOTT_PROJECT_EULER_H

#include <vector>
#include <string>
#include <map>

///////////////////////////////////////////////////////////////////////////
// Project euler problems registry - Enables ability to simply add new
// solutions to the project
///////////////////////////////////////////////////////////////////////////
typedef long (*EulerFunc)( const std::vector<std::string>& args );

#define REGISTER_PROBLEM(id,desc) \
    long problem_##id(const std::vector<std::string>&); \
    EulerEntry entry##id(id,desc,problem_##id);

class EulerEntry;
typedef std::map<int,EulerEntry>::const_iterator RegistryConstItr;

class Registry
{
public:
    static Registry& singleton();

    void add( const EulerEntry& entry );
    bool has( int id ) const;
    EulerEntry get( int id ) const;
    RegistryConstItr getList() const;

private:
    Registry();
    Registry( const Registry& r );

private:
    static Registry * m_singleton;
    std::map<int, EulerEntry> m_entries;
};

class EulerEntry
{
public:
    EulerEntry();
    EulerEntry( int id, const char* name, EulerFunc func );
    
    int id() const;
    std::string name() const;
    EulerFunc func() const;
 
private:
    int m_id;
    const char* m_name;
    EulerFunc m_func;
};

#endif
