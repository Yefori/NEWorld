/*
* NEWorld: A free game with similar rules to Minecraft.
* Copyright (C) 2016 NEWorld Team
*
* This file is part of NEWorld.
* NEWorld is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* NEWorld is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with NEWorld.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "neworld.h"
#include "texture.h"
#include <pluginapi.h>
#include "window.h"
#include "game.h"

NEWorld::NEWorld() : mPlugins(true)
{
    // Initialize
    Logger::init("client");
    infostream << "Initializing...";
    Window& window = Window::getInstance("NEWorld", 852, 480);
    Renderer::init();
    Texture::init();
    PluginAPI::Blocks = &mBlocks;
    PluginAPI::Plugins = &mPlugins;
    mPlugins.loadPlugins();

    // Run
    Game game(mPlugins, mBlocks);
    while(!window.shouldQuit())
    {
        window.pollEvents();
        window.newFrame();
        game.update();
        game.render();
        Renderer::checkError();
        window.swapBuffers();
    }

    // Terminate
    infostream << "Terminating...";
    mPlugins.unloadPlugins();
    Texture::free();
}
