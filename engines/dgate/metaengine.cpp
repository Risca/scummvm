/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "base/plugins.h"

#include "common/translation.h"

#include "engines/advancedDetector.h"
#include "gui/message.h"

#include "dgate/dgate.h"

namespace DGate {
const char *DGateEngine::getGameId() const { return _gameDescription->gameId; }
Common::Platform DGateEngine::getPlatform() const { return _gameDescription->platform; }
} // End of namespace DGate

class DGateMetaEngine : public AdvancedMetaEngine<ADGameDescription> {
	const char *getName() const override {
		return "deathgate";
	}

	Common::Error createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const override;
	bool hasFeature(MetaEngineFeature f) const override;
};

Common::Error DGateMetaEngine::createInstance(OSystem *syst, Engine **engine, const ADGameDescription *desc) const {
	*engine = new DGate::DGateEngine(syst, desc);
	return Common::kNoError;
}

bool DGateMetaEngine::hasFeature(MetaEngineFeature f) const {
	return false;
}

#if PLUGIN_ENABLED_DYNAMIC(DGATE)
	REGISTER_PLUGIN_DYNAMIC(DGATE, PLUGIN_TYPE_ENGINE, DGateMetaEngine);
#else
	REGISTER_PLUGIN_STATIC(DGATE, PLUGIN_TYPE_ENGINE, DGateMetaEngine);
#endif
