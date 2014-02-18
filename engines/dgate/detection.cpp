/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "dgate/dgate.h"
#include "engines/advancedDetector.h"

static const PlainGameDescriptor deathGateGames[] = {
	{ "deathgate", "Death Gate" },
	{ 0, 0 }
};

#include "dgate/detection_tables.h"

class DGateMetaEngine : public AdvancedMetaEngine {
public:
	DGateMetaEngine() : AdvancedMetaEngine(DGate::gameDescriptions, sizeof(ADGameDescription), deathGateGames) {
		_singleId = "deathgate";
	}

	virtual const char *getName() const {
		return "Death Gate Engine";
	}

	virtual const char *getOriginalCopyright() const {
		return "Death Gate (C) 1994 Legend Entertainment Company";
	}

	virtual bool createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const;
};

bool DGateMetaEngine::createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const {
	if (desc) {
		*engine = new DGate::DGateEngine(syst);
	}
	return desc != 0;
}

#if PLUGIN_ENABLED_DYNAMIC(DREAMWEB)
	REGISTER_PLUGIN_DYNAMIC(DGATE, PLUGIN_TYPE_ENGINE, DGateMetaEngine);
#else
	REGISTER_PLUGIN_STATIC(DGATE, PLUGIN_TYPE_ENGINE, DGateMetaEngine);
#endif

namespace DGate {

} // End of namespace DGate
