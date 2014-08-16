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

#include "implementation.h"

#include "extract-interfaces.h"

#include <QtCore/QObject>

namespace injeqt { namespace internal {

implementation::implementation(type interface_type, QObject *object) :
	_interface_type{std::move(interface_type)},
	_object{object}
{
}

const type & implementation::interface_type() const
{
	return _interface_type;
}

QObject * implementation::object() const
{
	return _object;
}

void validate(const implementation &i)
{
	validate(i.interface_type());

	if (!i.object())
		throw invalid_implementation_availability_exception{};

	auto implements = extract_interfaces(type{i.object()->metaObject()});
	if (!implements.contains(i.interface_type()))
		throw invalid_interface_type_exception{};
}

bool operator == (const implementation &x, const implementation &y)
{
	if (x.interface_type() != y.interface_type())
		return false;

	if (x.object() != y.object())
		return false;

	return true;
}

bool operator != (const implementation &x, const implementation &y)
{
	return !(x == y);
}

}}
