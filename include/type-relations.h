/*
 * %injeqt copyright begin%
 * Copyright 2014 Rafał Malinowski (rafal.przemyslaw.malinowski@gmail.com)
 * %injeqt copyright end%
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once

#include "implemented-by-mapping.h"
#include "injeqt-global.h"
#include "types.h"

namespace injeqt { namespace v1 {

class INJEQT_API type_relations final
{

public:
	const implemented_by_mapping & unique() const;
	const types & ambiguous() const;

private:
	explicit type_relations(implemented_by_mapping unique, types ambiguous);
	friend type_relations make_type_relations(const std::vector<type> &main_types);

	implemented_by_mapping _unique;
	types _ambiguous;

};

INJEQT_API bool operator == (const type_relations &x, const type_relations &y);
INJEQT_API bool operator != (const type_relations &x, const type_relations &y);

INJEQT_API type_relations make_type_relations(const std::vector<type> &main_types);

}}