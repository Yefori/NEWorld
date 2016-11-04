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

#ifndef RATEMETER_H_
#define RATEMETER_H_

#include <chrono>

class RateMeter
{
public:
    void refresh()
    {
        if (!mValid)
        {
            mValid = true;
            return;
        }
        auto now = std::chrono::steady_clock::now();
        mDeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - mLastRefreshTime).count();
        mLastRefreshTime = now;
    }
    double getRate()
    {
        return 1000.0 / mDeltaTime;
    }
    long long getDeltaTimeMs()
    {
        return mDeltaTime;
    }

private:
    std::chrono::steady_clock::time_point mLastRefreshTime;
    long long mDeltaTime = 0ll;
    bool mValid = false;
};

#endif // !RATEMETER_H_
