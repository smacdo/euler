#include "projecteuler.h"
#include <cassert>
#include <iostream>

Registry * Registry::m_singleton = NULL;

Registry::Registry()
{
}

Registry& Registry::singleton()
{
    if ( m_singleton == NULL )
    {
        m_singleton = new Registry();
    }

    return *m_singleton;
}

void Registry::add( const EulerEntry& entry )
{
    m_entries.insert(std::pair<int, EulerEntry>( entry.id(), entry ));
}

bool Registry::has( int id ) const
{
    return m_entries.find( id ) != m_entries.end();
}

EulerEntry Registry::get( int id ) const
{
    assert( has(id) );

    return (m_entries.find( id ))->second;
}

std::map<int, EulerEntry> Registry::getList() const
{
    return std::map<int, EulerEntry>( m_entries );
}

EulerEntry::EulerEntry()
    : m_id( 0 ),
      m_name( "<nil>" ),
      m_func( NULL )
{
}

EulerEntry::EulerEntry( int id, const char* name, EulerFunc func )
    : m_id( id ),
      m_name( name ),
      m_func( func )
{
    // Auto register
    Registry::singleton().add( *this );
}

int EulerEntry::id() const
{
    return m_id;
}

std::string EulerEntry::name() const
{
    return m_name;
}

EulerFunc EulerEntry::func() const
{
    return m_func;
}
