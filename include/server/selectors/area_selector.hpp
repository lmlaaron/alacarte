/**
 *  This file is part of alaCarte.
 *
 *  alaCarte is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  alaCarte is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with alaCarte. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright alaCarte 2012-2013 Simon Dreher, Florian Jacob, Tobias Kahlert, Patrick Niklaus, Bernhard Scheirle, Lisa Winter
 *  Maintainer: Florian Jacob
 */

#pragma once
#ifndef AREA_SELECTOR_HPP
#define AREA_SELECTOR_HPP
/*
 * =====================================================================================
 *
 *       Filename:  area_selector.hpp
 *
 *    Description:  "area" - starting selector selecting only ways with area=yes
 * 					or where the start node is the same as the end node
 *
 * =====================================================================================
 */

/*
offen und area ungesetzt:        - Nein
geschlossen und area ungesetzt:  - Ja
offen und area = yes:            - Nein (invalide Daten)
geschlossen und area = yes:      - Ja
offen und area = no:             - Nein
geschlossen und area = no:       - Nein
*/

#include "settings.hpp"

#include "server/selectors/selector.hpp"

class AreaSelector : public Selector {
public:
	AreaSelector(const std::shared_ptr<Rule>& rule, const std::shared_ptr<Selector>& next);
	
	virtual void matchNode(NodeId nodeID, const std::shared_ptr<TileIdentifier>& ti, RenderAttributes* attributes) const;
	virtual void matchWay(WayId wayID, const std::shared_ptr<TileIdentifier>& ti, RenderAttributes* attributes) const;
	virtual void matchRelation(RelId relID, const std::shared_ptr<TileIdentifier>& ti, RenderAttributes* attributes) const;

};

#endif
