/*
Copyright (C) 2014 Bastien Oudot

This file is part of Softbloks.
Softbloks is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Softbloks is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Softbloks.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SB_ABSTRACTEXECUTIVE_H
#define SB_ABSTRACTEXECUTIVE_H

#include <sb-core/sb-abstractobject.h>

namespace sb
{

class AbstractBlok;

class SB_CORE_API AbstractExecutive : public AbstractObject
{

    SB_DECLARE_OBJECT(AbstractExecutive, "sb::AbstractExecutive")

public:

    class Private;

    virtual
    ~AbstractExecutive
    (
    );

    virtual
    void
    on_input_pushed
    (
        size_t index_
    )
    = 0;

    virtual
    void
    on_output_pulled
    (
        size_t index_
    )
    = 0;

protected:

    AbstractBlok*
    get_blok
    (
    )
    const;

    void
    execute
    (
    );

private:

    static
    void
    construct
    (
        AbstractExecutive* this_
    );

    Private*
    d_ptr;

};

typedef
    std::unique_ptr<AbstractExecutive, UniqueObject::deleter_type>
    UniqueExecutive;

SB_CORE_API
inline
UniqueExecutive
create_unique_executive
(
    const std::string& name_
)
{
    return create_unique<AbstractExecutive>(name_);
}

}

#endif // SB_ABSTRACTEXECUTIVE_H