/* main.cpp
 *
 * Copyright 2025 Dimi, dimimalinov123@gmail.com
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
 * along with this program (Located ./LICENSE).  If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */
#include <iostream>
#include <string>

int lives = 19; // Declare a global variable for lives.

int main() {
    std::string command;
    std::string progress;
    std::string start_msg = std::string("You are stranded on your home planet, called Rimth. A meteor is about to strike and you don't have time. You make your destiny. Good luck."); // I'm not in the mood to write this again so im declaring a variable. Yes, copy paste doesn't exist.
    std::cout << start_msg << std::endl;
    while (lives >= 0){ // keeps the program running until lives aren't wasted
        std::cout << "> "; // the little thing before you write a paragraph.
        std::getline(std::cin, command);
        if (
            command.find("flee") != std::string::npos ||
            (command.find("run") != std::string::npos && command.find("away") != std::string::npos)) {
            progress += "You decided to flee ";
            std::cout << "Where are you fleeing? Maybe another planet?" << std::endl;
        }
        else if ((command.find("another") != std::string::npos && command.find("planet") != std::string::npos) && progress.compare("You decided to flee ") == 0) { // shitty if statement. don't touch. and don't get confused.
            std::cout << "Great! I'll get the rocket ready! Try *fly*ing?" << std::endl;
            progress += "to another planet. ";

        }
        else if (command.find("progress") != std::string::npos) {
            std::cout << start_msg << std::endl;
            std::cout << progress << std::endl;
        }
        else if ((command.find("fly") != std::string::npos) && (progress.compare("You decided to flee to another planet. ") == 0)) {
            std::cout << "You somehow came to a new planet, called 'Earth'. Looks diffrent here doesn't it? try to look around." << std::endl;
            progress += "You arrived to Earth. ";
        }
        else if ((command.find("look") != std::string::npos) && (command.find("around") != std::string::npos) && (progress.compare("You decided to flee to another planet. You arrived to Earth. ") == 0)) {
            std::cout << "Looking arround... You see a bunch of wierd looking creatures, you've never seen such before!"
        }
        else { // if no valid commands are inputed.
            std::cout << "Pardon me? (You have " << lives << " lives left!)" << std::endl;
            lives--; // The only good and optimized part of this code.
        }



    }
}

