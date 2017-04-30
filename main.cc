/**
 * @file main.cc
 *
 *   Copyright 2017 R.COHEN-SCALI
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <stdlib.h>

#include <iostream>

#include "carafe.h"

Carafe c1(7);
Carafe c2(4);
int but = 5;

void
help(void)
{
  std::cout << "** Carafe game !\n\n";
  std::cout << "    >You have two carafes: carafe1 and carafe2.\n";
  std::cout << "      - carafe1 has a " << c1.capacite () << " liters capacity.\n";
  std::cout << "      - carafe2 has a " << c2.capacite () << " liters capacity.\n\n";
  std::cout << "    >You may Fill (command 'f'/'r') or Empty (command 'e'/'v') carafes.\n\n";
  std::cout << "    >You may also transfer water from one carafe to another\n";
  std::cout << "     with the command 't': 't<src><tgt>' with <src> & <tgt>\n";
  std::cout << "     being the carafe index. (ex. t21 / t12)\n\n";
  std::cout << "    >You may also exit the game with the Quit/Kill ('q'/'k') command.\n\n";
  std::cout << "    >You may also display this message with the Help/Aide ('h'/'a') command.\n\n";
  std::cout << "    >Note that command are case insensitives\n\n";
  std::cout << "    >Your goal is to have a carafe with " << but << " liters.\n\n";
  std::cout << "    >At each round, the carafe states are displayed as:\n\n";
  std::cout << "       Carafe #<index>: <content>l / <capacity>l\n";
  std::cout << "     example 1:\n";
  std::cout << "       Carafe #1: 0l / 7l     Carafe #2: 0l / 4l\n";
  std::cout << "     means carafe 1 is empty and can have 7 liters\n";
  std::cout << "     and carafe 2 is empty and can have 4 liters\n\n";
  std::cout << "     example 2:\n";
  std::cout << "       Carafe #1: 3l / 7l     Carafe #2: 4l / 4l\n";
  std::cout << "     means carafe 1 has 3 liters and can have 7 liters\n";
  std::cout << "     and carafe 2 is full (contains 4 liters)\n\n";
  std::cout << "    >Let's go ...\n\n";
}

void
cmderror ()
{
  std::cerr << "** Invalid command\n";
}

int
main (int argc, char *argv[])
{
  char choix [4];

  c1.m_index = 1;
  c2.m_index = 2;

  help ();

  while (true)
    {
      std::cout << "Carafe #1: "
                << c1.contenu () << "l / "
                << c1.capacite () << "l     "
                << "Carafe #2: "
                << c2.contenu () << "l / "
                << c2.capacite () << "l "
                << "[goal is to reach " << but
                << "l in any carafe]" << std::endl;
      if (c1.contenu () == but || c2.contenu () == but)
        break;

      std::cout << "Choix ? ";
      std::cin >> choix;

      // Handle command
      Carafe *src = (Carafe*)NULL;
      Carafe *tgt = (Carafe*)NULL;

      // Upper first char (from 'a' to 'A' for ex) 
      choix[0] &= ~0x20;

      // Handle second and third number
      src = (choix[1] ? (choix[1] == '1' ? &c1 : (choix[1] == '2' ? &c2 : (Carafe*)NULL)) : (Carafe*)NULL);
      tgt = (choix[2] ? (choix[2] == '1' ? &c1 : (choix[2] == '2' ? &c2 : (Carafe*)NULL)) : (Carafe*)NULL);

      switch (choix[0])
        {
        case 'A':
        case 'H':
          if (choix[1] != 0)
            std::cerr << "Warning !  don't know how to handle extra '"
                      << &choix[1] << "' after <" << choix[0]
                      << ">!\n";
          help ();
          break;

          // Fill command
        case 'R':
        case 'F':
          if (choix[2] != 0)
            std::cerr << "Warning !  don't know how to handle extra '"
                      << &choix[2] << "' after <" << choix[0] << choix[1]
                      << ">!\n";
          if (!src)
            cmderror ();

          else
            {
              std::cout << "Filing carafe #" << src->m_index << "\n";
              src->remplir ();
            }
          break;

          // Empty command
        case 'V':
        case 'E':
          if (choix[2] != 0)
            std::cerr << "Warning !  don't know how to handle extra '"
                      << &choix[2] << "' after <" << choix[0] << choix[1]
                      << ">!\n";
          if (!src)
            cmderror ();

          else
            {
              std::cout << "Emptying carafe #" << src->m_index << "\n";
              src->vider ();
            }
          break;

          // Transfer command
        case 'T':
          if (choix[3] != 0)
            std::cerr << "Warning !  don't know how to handle extra '"
                      << &choix[3] << "' after <" << choix[0] << choix[1] << choix[2]
                      << ">!\n";
          if (!src && !tgt)
            cmderror ();
          else
            {
              std::cout << "Transfer carafe #" << src->m_index
                        << " content in carafe #" << tgt->m_index << "\n";
              src->transvaserDans (*tgt);
            }
          break;

        case 'Q':
        case 'K':
          if (choix[1] != 0)
            std::cerr << "Warning !  don't know how to handle extra '"
                      << &choix[1] << "' after <" << choix[0]
                      << ">!\n";
          std::cout << "Bye bye !\n";
          exit (0);

        default:
          std::cout << "Unknown command '" << choix << "'" << std::endl;
        }
    }
  std::cout << "Bravo !" << std::endl;

  return (0);
}
