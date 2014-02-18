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

#include "common/debug.h"
#include "common/debug-channels.h"
#include "common/error.h"
#include "engines/util.h"

#include "dgate/dgate.h"

namespace DGate {

DGateEngine::DGateEngine(OSystem *syst, const ADGameDescription *gameDesc) :
		Engine(syst), _gameDescription(gameDesc), _console(nullptr) {
	// Put your engine in a sane state, but do nothing big yet;
	// in particular, do not load data from files; rather, if you
	// need to do such things, do them from run().
 
	// Do not initialize graphics here
	// Do not initialize audio devices here
 
	// Here is the right place to set up the engine specific debug channels
	DebugMan.addDebugChannel(kDGateDebugExample, "example", "this is just an example for a engine specific debug channel");
	DebugMan.addDebugChannel(kDGateDebugExample2, "example2", "also an example");
 
	// Don't forget to register your random source
	_rnd = new Common::RandomSource("deathgate");
 
	debug("DGateEngine::DGateEngine");
}

DGateEngine::~DGateEngine() {
	debug("DGateEngine::~DGateEngine");

	// Dispose your resources here
	//_console is deleted by Engine
	delete _rnd;
}

Common::Error DGateEngine::run()
{
	// Initialize graphics using following:
	initGraphics(640, 480);
 
	// You could use backend transactions directly as an alternative,
	// but it isn't recommended, until you want to handle the error values
	// from OSystem::endGFXTransaction yourself.
	// This is just an example template:
	//_system->beginGFXTransaction();
	//	// This setup the graphics mode according to users seetings
	//	initCommonGFX(false);
	//
	//	// Specify dimensions of game graphics window.
	//	// In this example: 320x200
	//	_system->initSize(320, 200);
	//FIXME: You really want to handle
	//OSystem::kTransactionSizeChangeFailed here
	//_system->endGFXTransaction();
 
	// Create debugger console. It requires GFX to be initialized
	_console = new Console();
 
	// Additional setup.
	debug("DGateEngine::init");
 
	// Your main event loop should be (invoked from) here.
	debug("DGateEngine::go: Hello, World!");
 
	// This test will show up if -d1 and --debugflags=example are specified on the commandline
	debugC(1, kDGateDebugExample, "Example debug call");
 
	// This test will show up if --debugflags=example or --debugflags=example2 or both of them and -d3 are specified on the commandline
	debugC(3, kDGateDebugExample | kDGateDebugExample2, "Example debug call two");
 
	return Common::kNoError;
}

} // End of namespace DGate
