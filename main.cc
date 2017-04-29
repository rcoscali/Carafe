

#include <string.h>

#include <iostream>

#include "carafe.h"

int
main(int argc, char *argv[])
{
  Carafe c1(7);
  Carafe c2(4);

  int but = 5;

  char choix [4];

  while (true)
    {
      std::cout << c1.contenu() << "/"
                << c1.capacite() << " "
                << c2.contenu() << "/"
                << c2.capacite() << " "
                << "[but : " << but << "]" << std::endl;
      if (c1.contenu() == but || c2.contenu() == but)
        break;

      std::cout << "Choix ? ";
      std::cin >> choix;

      if (strncmp(choix, "r1",  2) == 0)
        {
          c1.remplir();
        }
      else if (strncmp(choix, "r2",  2) == 0)
        {
          c2.remplir();
        }
      else if (strncmp(choix, "v1",  2) == 0)
        {
          c1.vider();
        }
      else if (strncmp(choix, "v2",  2) == 0)
        {
          c2.vider();
        }
      else if (strncmp(choix, "t12", 3) == 0)
        {
          c1.transvaserDans(c2);
        }
      else if (strncmp(choix, "t21", 3) == 0)
        {
          c2.transvaserDans(c1);
        }
      else
        {
          std::cout << "Choix incorrect" << std::endl;
          continue;
        }
    }
  std::cout << "Bravo !" << std::endl;

  return (0);
}
