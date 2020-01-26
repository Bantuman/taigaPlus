/*
MIT License

Copyright (c) 2017 Eren Okka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <string>
#include <vector>

namespace anisthesia {

enum class Strategy {
  WindowTitle,
  OpenFiles,
  UiAutomation,
};

enum class PlayerType {
  Default,
  WebBrowser,
};

struct Player {
  PlayerType type = PlayerType::Default;
  std::string name;
  std::string window_title_format;
  std::vector<std::string> windows;
  std::vector<std::string> executables;
  std::vector<Strategy> strategies;
};

bool ParsePlayersData(const std::string& data, std::vector<Player>& players);
bool ParsePlayersFile(const std::string& path, std::vector<Player>& players);

}  // namespace anisthesia
